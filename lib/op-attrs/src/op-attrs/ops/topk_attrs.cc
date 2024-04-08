// THIS FILE WAS AUTO-GENERATED BY proj. DO NOT MODIFY IT!
// If you would like to modify this datatype, instead modify
// lib/op-attrs/include/op-attrs/ops/topk_attrs.struct.toml

#include "op-attrs/ops/topk_attrs.h"

namespace FlexFlow {
TopKAttrs::TopKAttrs(int const &k, bool const &sorted) : k(k), sorted(sorted) {}
bool TopKAttrs::operator==(TopKAttrs const &other) const {
  return std::tie(this->k, this->sorted) == std::tie(other.k, other.sorted);
}
bool TopKAttrs::operator!=(TopKAttrs const &other) const {
  return std::tie(this->k, this->sorted) != std::tie(other.k, other.sorted);
}
bool TopKAttrs::operator<(TopKAttrs const &other) const {
  return std::tie(this->k, this->sorted) < std::tie(other.k, other.sorted);
}
bool TopKAttrs::operator>(TopKAttrs const &other) const {
  return std::tie(this->k, this->sorted) > std::tie(other.k, other.sorted);
}
bool TopKAttrs::operator<=(TopKAttrs const &other) const {
  return std::tie(this->k, this->sorted) <= std::tie(other.k, other.sorted);
}
bool TopKAttrs::operator>=(TopKAttrs const &other) const {
  return std::tie(this->k, this->sorted) >= std::tie(other.k, other.sorted);
}
} // namespace FlexFlow

namespace std {
size_t
    hash<FlexFlow::TopKAttrs>::operator()(FlexFlow::TopKAttrs const &x) const {
  size_t result = 0;
  result ^= std::hash<int>{}(x.k) + 0x9e3779b9 + (result << 6) + (result >> 2);
  result ^=
      std::hash<bool>{}(x.sorted) + 0x9e3779b9 + (result << 6) + (result >> 2);
  return result;
}
} // namespace std

namespace nlohmann {
FlexFlow::TopKAttrs
    adl_serializer<FlexFlow::TopKAttrs>::from_json(json const &j) {
  return {j.at("k").template get<int>(), j.at("sorted").template get<bool>()};
}
void adl_serializer<FlexFlow::TopKAttrs>::to_json(
    json &j, FlexFlow::TopKAttrs const &v) {
  j["__type"] = "TopKAttrs";
  j["k"] = v.k;
  j["sorted"] = v.sorted;
}
} // namespace nlohmann

namespace rc {
Gen<FlexFlow::TopKAttrs> Arbitrary<FlexFlow::TopKAttrs>::arbitrary() {
  return gen::construct<FlexFlow::TopKAttrs>(gen::arbitrary<int>(),
                                             gen::arbitrary<bool>());
}
} // namespace rc

namespace FlexFlow {
std::string format_as(TopKAttrs const &x) {
  std::ostringstream oss;
  oss << "<TopKAttrs";
  oss << " k=" << x.k;
  oss << " sorted=" << x.sorted;
  oss << ">";
  return oss.str();
}
std::ostream &operator<<(std::ostream &s, TopKAttrs const &x) {
  return s << fmt::to_string(x);
}
} // namespace FlexFlow
