/* Copyright 2023 CMU, Stanford, Facebook, LANL
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "flexflow/batch_config.h"
#include "flexflow/request_manager.h"
#include "legion.h"
#include <cassert>
#include <climits>

namespace FlexFlow {

LegionRuntime::Logger::Category log_bc("BatchConfig");
using Legion::Future;
using Legion::Memory;

// BatchConfig::BatchConfig() : model_id(0), inference_mode(INC_DECODING_MODE) {
//   std::fill(std::begin(request_available), std::end(request_available), 0);
//   // Don't need to initialize requestInfo ,tokensInfo, causalMask and
//   // committed_tokens here because they initialize themselves.
//   // Other fields are already initialized to proper value.
// }

BatchConfig::BatchConfig(InferenceMode inference_mode_, int model_id_)
    : model_id(model_id_), inference_mode(inference_mode_) {
  std::fill(std::begin(request_available), std::end(request_available), 0);
  // Don't need to initialize requestInfo ,tokensInfo, causalMask and
  // committed_tokens here because they initialize themselves.
  // Other fields are already initialized to proper value.
}

/*static*/
// BatchConfig const *BatchConfig::from_future(BatchConfigFuture const &future)
// {
//   BatchConfig const *bc = static_cast<BatchConfig const *>(
//       Future(future).get_buffer(Memory::SYSTEM_MEM));
//   // Check future size
//   if (bc->get_mode() == INC_DECODING_MODE) {
//     assert(Future(future).get_untyped_size() == sizeof(BatchConfig));
//   } else if (bc->get_mode() == TREE_SEARCH_MODE) {
//     assert(Future(future).get_untyped_size() ==
//     sizeof(TreeSearchBatchConfig));
//   } else if (bc->get_mode() == TREE_VERIFY_MODE) {
//     assert(Future(future).get_untyped_size() ==
//     sizeof(TreeVerifyBatchConfig));
//   } else {
//     assert(false && "Unsupported inference mode");
//   }
//   return bc;
// }

/*static*/
BatchConfig const *BatchConfig::from_future(BatchConfigFuture const &future) {
  return static_cast<BatchConfig const *>(
      Future(future).get_buffer(Memory::SYSTEM_MEM));
}

InferenceMode BatchConfig::get_mode() const {
  return inference_mode;
}

int BatchConfig::num_active_requests() const {
  return num_available_requests;
}

int BatchConfig::num_active_tokens() const {
  return num_tokens;
}

/*static*/
int BatchConfig::max_requests_per_batch() {
  return RequestManager::get_request_manager()->get_max_requests_per_batch();
}

/*static*/
int BatchConfig::max_tokens_per_batch() {
  return RequestManager::get_request_manager()->get_max_tokens_per_batch();
}

/*static*/
int BatchConfig::max_verify_tokens_per_batch() {
  return RequestManager::get_request_manager()
      ->get_max_verify_tokens_per_batch();
}

/*static*/
int BatchConfig::max_sequence_length() {
  return RequestManager::get_request_manager()->get_max_sequence_length();
}

int BatchConfig::max_spec_tree_token_num() {
  return RequestManager::get_request_manager()->get_max_spec_tree_token_num();
}

// Overloading the << operator for the Bitset class
std::ostream &operator<<(std::ostream &os,
                         BatchConfig::BitMask::Bitset const &bitset) {
  for (size_t i = 0; i < BatchConfig::MAX_SPEC_TREE_TOKEN_NUM; i++) {
    os << (bitset.test_bit(i) ? '1' : '0');
  }
  return os;
}

std::ostream &operator<<(std::ostream &os, BatchConfig const &bc) {
  os << "@@@@@@@@@@@@@@ Batch Config (mode " << bc.get_mode()
     << ") @@@@@@@@@@@@@@" << std::endl;
  // Current values
  os << "Number of tokens: " << bc.num_active_tokens() << std::endl;
  os << "Number of requests: " << bc.num_active_requests() << std::endl;
  os << "Prompt phase: " << bc.prompt_phase << std::endl;
  os << "Inference mode: ";
  switch (bc.inference_mode) {
    case INC_DECODING_MODE:
      os << "Incremental decoding";
      break;
    case TREE_SEARCH_MODE:
      os << "Tree search";
      break;
    case TREE_VERIFY_MODE:
      os << "Tree verify";
      break;
    default:
      os << "Unknown";
  }
  os << std::endl;
  if (bc.inference_mode == TREE_VERIFY_MODE) {
    os << "Number of tokens to commit: " << bc.num_tokens_to_commit
       << std::endl;
  }
  if (bc.inference_mode == TREE_SEARCH_MODE) {
    os << "Model id: " << bc.model_id << std::endl;
  }

  // Per-request info
  os << "Per-request info:\n";
  for (int i = 0; i < bc.max_requests_per_batch(); i++) {
    if (bc.request_available[i]) {
      os << "  Request " << i << ":\n";
      os << "    First token depth in request: "
         << bc.requestsInfo[i].first_token_index_in_request << std::endl;
      os << "    First token offset in batch: "
         << bc.requestsInfo[i].first_token_offset_in_batch << std::endl;
      os << "    Number of tokens in batch: "
         << bc.requestsInfo[i].num_tokens_in_batch << std::endl;
      os << "    Request available: " << bc.request_available[i] << std::endl;
    }
  }

  // Per-token info
  os << "Per-token info:\n";
  for (int i = 0; i < bc.num_tokens; i++) {
    os << "  Token " << i << ":\n";
    os << "    Absolute depth in request: "
       << bc.tokensInfo[i].abs_index_in_request << std::endl;
    os << "    Request index: " << bc.tokensInfo[i].request_index << std::endl;
    os << "    Token id: " << bc.tokensInfo[i].token_id << std::endl;
  }

  if (bc.inference_mode == TREE_VERIFY_MODE) {
    os << "Committed tokens info:\n";
    for (int i = 0; i < bc.num_tokens_to_commit; i++) {
      os << "  Token " << i << ":\n";
      os << "    Token index: " << bc.committed_tokens[i].token_index
         << std::endl;
      os << "    Request index: " << bc.committed_tokens[i].request_index
         << std::endl;
      os << "    Token depth: " << bc.committed_tokens[i].token_depth
         << std::endl;
    }
  }

  if (bc.inference_mode == TREE_SEARCH_MODE ||
      bc.inference_mode == TREE_VERIFY_MODE) {
    os << "Causal mask:\n";
    for (int i = 0; i < bc.max_requests_per_batch(); i++) {
      if (bc.request_available[i]) {
        os << "  Request " << i << ":\n";
        os << "    Non tree cache size: "
           << bc.causalMask[i].non_tree_cache_size << std::endl;
        os << "    Tree or prompt size: "
           << bc.causalMask[i].tree_or_prompt_size

           << std::endl;
        os << "    Current layer size: " << bc.causalMask[i].current_layer_size
           << std::endl;
        os << "    Bit mask: " << std::endl;
        for (int j = 0; j < BatchConfig::MAX_SPEC_TREE_TOKEN_NUM; j++) {
          os << "      " << bc.causalMask[i].bit_mask[j] << std::endl;
        }
      }
    }
  }

  os << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << std::endl;
  return os;
}

void BatchConfig::print() const {
  std::cout << *this << std::endl;
}

void BatchConfig::save_to_file(std::string const &filename) const {
  std::ofstream outputFile(filename);
  if (outputFile.is_open()) {
    outputFile << *this << std::endl;
    outputFile.close();
  } else {
    std::cerr << "Error: Unable to open the batch config output file: "
              << filename << std::endl;
    assert(false);
  }
}

}; // namespace FlexFlow
