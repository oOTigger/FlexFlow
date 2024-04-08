// THIS FILE WAS AUTO-GENERATED BY proj. DO NOT MODIFY IT!
// If you would like to modify this datatype, instead modify
// lib/op-attrs/include/op-attrs/ops/softmax_attrs.struct.toml

#include "op-attrs/ops/softmax_attrs.h"

namespace FlexFlow {
SoftmaxAttrs::SoftmaxAttrs(::FlexFlow::ff_dim_t const &dim) : dim(dim) {}
bool SoftmaxAttrs::operator==(SoftmaxAttrs const &other) const {
  return std::tie(this->dim) == std::tie(other.dim);
}
bool SoftmaxAttrs::operator!=(SoftmaxAttrs const &other) const {
  return std::tie(this->dim) != std::tie(other.dim);
}
bool SoftmaxAttrs::operator<(SoftmaxAttrs const &other) const {
  return std::tie(this->dim) < std::tie(other.dim);
}
bool SoftmaxAttrs::operator>(SoftmaxAttrs const &other) const {
  return std::tie(this->dim) > std::tie(other.dim);
}
bool SoftmaxAttrs::operator<=(SoftmaxAttrs const &other) const {
  return std::tie(this->dim) <= std::tie(other.dim);
}
bool SoftmaxAttrs::operator>=(SoftmaxAttrs const &other) const {
  return std::tie(this->dim) >= std::tie(other.dim);
}
} // namespace FlexFlow

namespace std {
size_t hash<FlexFlow::SoftmaxAttrs>::operator()(
    FlexFlow::SoftmaxAttrs const &x) const {
  size_t result = 0;
  result ^= std::hash<::FlexFlow::ff_dim_t>{}(x.dim) + 0x9e3779b9 +
            (result << 6) + (result >> 2);
  return result;
}
} // namespace std

namespace nlohmann {
FlexFlow::SoftmaxAttrs
    adl_serializer<FlexFlow::SoftmaxAttrs>::from_json(json const &j) {
  return {j.at("dim").template get<::FlexFlow::ff_dim_t>()};
}
void adl_serializer<FlexFlow::SoftmaxAttrs>::to_json(
    json &j, FlexFlow::SoftmaxAttrs const &v) {
  j["__type"] = "SoftmaxAttrs";
  j["dim"] = v.dim;
}
} // namespace nlohmann

namespace FlexFlow {
std::string format_as(SoftmaxAttrs const &x) {
  std::ostringstream oss;
  oss << "<SoftmaxAttrs";
  oss << " dim=" << x.dim;
  oss << ">";
  return oss.str();
}
std::ostream &operator<<(std::ostream &s, SoftmaxAttrs const &x) {
  return s << fmt::to_string(x);
}
} // namespace FlexFlow
