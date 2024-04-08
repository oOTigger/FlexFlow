// THIS FILE WAS AUTO-GENERATED BY proj. DO NOT MODIFY IT!
// If you would like to modify this datatype, instead modify
// lib/op-attrs/include/op-attrs/ops/flat_attrs.struct.toml

#include "op-attrs/ops/flat_attrs.h"

namespace FlexFlow {
bool FlatAttrs::operator==(FlatAttrs const &other) const {
  return std::tie() == std::tie();
}
bool FlatAttrs::operator!=(FlatAttrs const &other) const {
  return std::tie() != std::tie();
}
bool FlatAttrs::operator<(FlatAttrs const &other) const {
  return std::tie() < std::tie();
}
bool FlatAttrs::operator>(FlatAttrs const &other) const {
  return std::tie() > std::tie();
}
bool FlatAttrs::operator<=(FlatAttrs const &other) const {
  return std::tie() <= std::tie();
}
bool FlatAttrs::operator>=(FlatAttrs const &other) const {
  return std::tie() >= std::tie();
}
} // namespace FlexFlow

namespace std {
size_t
    hash<FlexFlow::FlatAttrs>::operator()(FlexFlow::FlatAttrs const &x) const {
  size_t result = 0;
  return result;
}
} // namespace std

namespace nlohmann {
FlexFlow::FlatAttrs
    adl_serializer<FlexFlow::FlatAttrs>::from_json(json const &j) {
  return {};
}
void adl_serializer<FlexFlow::FlatAttrs>::to_json(
    json &j, FlexFlow::FlatAttrs const &v) {
  j["__type"] = "FlatAttrs";
}
} // namespace nlohmann

namespace rc {
Gen<FlexFlow::FlatAttrs> Arbitrary<FlexFlow::FlatAttrs>::arbitrary() {
  return gen::construct<FlexFlow::FlatAttrs>();
}
} // namespace rc

namespace FlexFlow {
std::string format_as(FlatAttrs const &x) {
  std::ostringstream oss;
  oss << "<FlatAttrs";
  oss << ">";
  return oss.str();
}
std::ostream &operator<<(std::ostream &s, FlatAttrs const &x) {
  return s << fmt::to_string(x);
}
} // namespace FlexFlow
