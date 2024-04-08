// THIS FILE WAS AUTO-GENERATED BY proj. DO NOT MODIFY IT!
// If you would like to modify this datatype, instead modify
// lib/op-attrs/include/op-attrs/ops/reduce_attrs.struct.toml

#ifndef _FLEXFLOW_LIB_OP_ATTRS_INCLUDE_OP_ATTRS_OPS_REDUCE_ATTRS_H
#define _FLEXFLOW_LIB_OP_ATTRS_INCLUDE_OP_ATTRS_OPS_REDUCE_ATTRS_H

#include "fmt/format.h"
#include "nlohmann/json.hpp"
#include "op-attrs/ff_dim.h"
#include "op-attrs/op.h"
#include "utils/stack_vector.h"
#include <functional>
#include <ostream>
#include <sstream>
#include <tuple>

namespace FlexFlow {
struct ReduceAttrs {
  ReduceAttrs() = delete;
  ReduceAttrs(::FlexFlow::stack_vector<::FlexFlow::ff_dim_t,
                                       MAX_TENSOR_DIM> const &axes,
              ::FlexFlow::Op const &op_type,
              bool const &keepdims);

  bool operator==(ReduceAttrs const &) const;
  bool operator!=(ReduceAttrs const &) const;
  bool operator<(ReduceAttrs const &) const;
  bool operator>(ReduceAttrs const &) const;
  bool operator<=(ReduceAttrs const &) const;
  bool operator>=(ReduceAttrs const &) const;
  ::FlexFlow::stack_vector<::FlexFlow::ff_dim_t, MAX_TENSOR_DIM> axes;
  ::FlexFlow::Op op_type;
  bool keepdims;
};
} // namespace FlexFlow

namespace std {
template <>
struct hash<FlexFlow::ReduceAttrs> {
  size_t operator()(FlexFlow::ReduceAttrs const &) const;
};
} // namespace std

namespace nlohmann {
template <>
struct adl_serializer<FlexFlow::ReduceAttrs> {
  static FlexFlow::ReduceAttrs from_json(json const &);
  static void to_json(json &, FlexFlow::ReduceAttrs const &);
};
} // namespace nlohmann

namespace FlexFlow {
std::string format_as(ReduceAttrs const &);
std::ostream &operator<<(std::ostream &, ReduceAttrs const &);
} // namespace FlexFlow

#endif // _FLEXFLOW_LIB_OP_ATTRS_INCLUDE_OP_ATTRS_OPS_REDUCE_ATTRS_H
