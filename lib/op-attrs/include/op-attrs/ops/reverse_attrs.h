// THIS FILE WAS AUTO-GENERATED BY proj. DO NOT MODIFY IT!
// If you would like to modify this datatype, instead modify
// lib/op-attrs/include/op-attrs/ops/reverse_attrs.struct.toml

#ifndef _FLEXFLOW_LIB_OP_ATTRS_INCLUDE_OP_ATTRS_OPS_REVERSE_ATTRS_H
#define _FLEXFLOW_LIB_OP_ATTRS_INCLUDE_OP_ATTRS_OPS_REVERSE_ATTRS_H

#include "fmt/format.h"
#include "nlohmann/json.hpp"
#include "op-attrs/ff_dim.h"
#include <functional>
#include <ostream>
#include <sstream>
#include <tuple>

namespace FlexFlow {
struct ReverseAttrs {
  ReverseAttrs() = delete;
  ReverseAttrs(::FlexFlow::ff_dim_t const &axis);

  bool operator==(ReverseAttrs const &) const;
  bool operator!=(ReverseAttrs const &) const;
  bool operator<(ReverseAttrs const &) const;
  bool operator>(ReverseAttrs const &) const;
  bool operator<=(ReverseAttrs const &) const;
  bool operator>=(ReverseAttrs const &) const;
  ::FlexFlow::ff_dim_t axis;
};
} // namespace FlexFlow

namespace std {
template <>
struct hash<FlexFlow::ReverseAttrs> {
  size_t operator()(FlexFlow::ReverseAttrs const &) const;
};
} // namespace std

namespace nlohmann {
template <>
struct adl_serializer<FlexFlow::ReverseAttrs> {
  static FlexFlow::ReverseAttrs from_json(json const &);
  static void to_json(json &, FlexFlow::ReverseAttrs const &);
};
} // namespace nlohmann

namespace FlexFlow {
std::string format_as(ReverseAttrs const &);
std::ostream &operator<<(std::ostream &, ReverseAttrs const &);
} // namespace FlexFlow

#endif // _FLEXFLOW_LIB_OP_ATTRS_INCLUDE_OP_ATTRS_OPS_REVERSE_ATTRS_H
