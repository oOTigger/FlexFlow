// THIS FILE WAS AUTO-GENERATED BY proj. DO NOT MODIFY IT!
// If you would like to modify this datatype, instead modify
// lib/op-attrs/include/op-attrs/ops/element_binary_attrs.struct.toml

#ifndef _FLEXFLOW_LIB_OP_ATTRS_INCLUDE_OP_ATTRS_OPS_ELEMENT_BINARY_ATTRS_H
#define _FLEXFLOW_LIB_OP_ATTRS_INCLUDE_OP_ATTRS_OPS_ELEMENT_BINARY_ATTRS_H

#include "fmt/format.h"
#include "nlohmann/json.hpp"
#include "op-attrs/datatype.h"
#include "op-attrs/op.h"
#include <functional>
#include <ostream>
#include <sstream>
#include <tuple>

namespace FlexFlow {
struct ElementBinaryAttrs {
  ElementBinaryAttrs() = delete;
  ElementBinaryAttrs(::FlexFlow::Op const &type,
                     ::FlexFlow::DataType const &compute_type,
                     bool const &should_broadcast_lhs,
                     bool const &should_broadcast_rhs);

  bool operator==(ElementBinaryAttrs const &) const;
  bool operator!=(ElementBinaryAttrs const &) const;
  bool operator<(ElementBinaryAttrs const &) const;
  bool operator>(ElementBinaryAttrs const &) const;
  bool operator<=(ElementBinaryAttrs const &) const;
  bool operator>=(ElementBinaryAttrs const &) const;
  ::FlexFlow::Op type;
  ::FlexFlow::DataType compute_type;
  bool should_broadcast_lhs;
  bool should_broadcast_rhs;
};
} // namespace FlexFlow

namespace std {
template <>
struct hash<FlexFlow::ElementBinaryAttrs> {
  size_t operator()(FlexFlow::ElementBinaryAttrs const &) const;
};
} // namespace std

namespace nlohmann {
template <>
struct adl_serializer<FlexFlow::ElementBinaryAttrs> {
  static FlexFlow::ElementBinaryAttrs from_json(json const &);
  static void to_json(json &, FlexFlow::ElementBinaryAttrs const &);
};
} // namespace nlohmann

namespace FlexFlow {
std::string format_as(ElementBinaryAttrs const &);
std::ostream &operator<<(std::ostream &, ElementBinaryAttrs const &);
} // namespace FlexFlow

#endif // _FLEXFLOW_LIB_OP_ATTRS_INCLUDE_OP_ATTRS_OPS_ELEMENT_BINARY_ATTRS_H
