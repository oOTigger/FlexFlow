// THIS FILE WAS AUTO-GENERATED BY proj. DO NOT MODIFY IT!
// If you would like to modify this datatype, instead modify
// lib/op-attrs/include/op-attrs/ops/linear_attrs.struct.toml

#include "op-attrs/ops/linear_attrs.h"

namespace FlexFlow {
LinearAttrs::LinearAttrs(
    int const &out_channels,
    bool const &use_bias,
    ::FlexFlow::DataType const &data_type,
    ::FlexFlow::Activation const &activation,
    std::optional<::FlexFlow::RegularizerAttrs> const &regularizer)
    : out_channels(out_channels), use_bias(use_bias), data_type(data_type),
      activation(activation), regularizer(regularizer) {}
bool LinearAttrs::operator==(LinearAttrs const &other) const {
  return std::tie(this->out_channels,
                  this->use_bias,
                  this->data_type,
                  this->activation,
                  this->regularizer) == std::tie(other.out_channels,
                                                 other.use_bias,
                                                 other.data_type,
                                                 other.activation,
                                                 other.regularizer);
}
bool LinearAttrs::operator!=(LinearAttrs const &other) const {
  return std::tie(this->out_channels,
                  this->use_bias,
                  this->data_type,
                  this->activation,
                  this->regularizer) != std::tie(other.out_channels,
                                                 other.use_bias,
                                                 other.data_type,
                                                 other.activation,
                                                 other.regularizer);
}
bool LinearAttrs::operator<(LinearAttrs const &other) const {
  return std::tie(this->out_channels,
                  this->use_bias,
                  this->data_type,
                  this->activation,
                  this->regularizer) < std::tie(other.out_channels,
                                                other.use_bias,
                                                other.data_type,
                                                other.activation,
                                                other.regularizer);
}
bool LinearAttrs::operator>(LinearAttrs const &other) const {
  return std::tie(this->out_channels,
                  this->use_bias,
                  this->data_type,
                  this->activation,
                  this->regularizer) > std::tie(other.out_channels,
                                                other.use_bias,
                                                other.data_type,
                                                other.activation,
                                                other.regularizer);
}
bool LinearAttrs::operator<=(LinearAttrs const &other) const {
  return std::tie(this->out_channels,
                  this->use_bias,
                  this->data_type,
                  this->activation,
                  this->regularizer) <= std::tie(other.out_channels,
                                                 other.use_bias,
                                                 other.data_type,
                                                 other.activation,
                                                 other.regularizer);
}
bool LinearAttrs::operator>=(LinearAttrs const &other) const {
  return std::tie(this->out_channels,
                  this->use_bias,
                  this->data_type,
                  this->activation,
                  this->regularizer) >= std::tie(other.out_channels,
                                                 other.use_bias,
                                                 other.data_type,
                                                 other.activation,
                                                 other.regularizer);
}
} // namespace FlexFlow

namespace std {
size_t hash<FlexFlow::LinearAttrs>::operator()(
    FlexFlow::LinearAttrs const &x) const {
  size_t result = 0;
  result ^= std::hash<int>{}(x.out_channels) + 0x9e3779b9 + (result << 6) +
            (result >> 2);
  result ^= std::hash<bool>{}(x.use_bias) + 0x9e3779b9 + (result << 6) +
            (result >> 2);
  result ^= std::hash<::FlexFlow::DataType>{}(x.data_type) + 0x9e3779b9 +
            (result << 6) + (result >> 2);
  result ^= std::hash<::FlexFlow::Activation>{}(x.activation) + 0x9e3779b9 +
            (result << 6) + (result >> 2);
  result ^=
      std::hash<std::optional<::FlexFlow::RegularizerAttrs>>{}(x.regularizer) +
      0x9e3779b9 + (result << 6) + (result >> 2);
  return result;
}
} // namespace std

namespace nlohmann {
FlexFlow::LinearAttrs
    adl_serializer<FlexFlow::LinearAttrs>::from_json(json const &j) {
  return {j.at("out_channels").template get<int>(),
          j.at("use_bias").template get<bool>(),
          j.at("data_type").template get<::FlexFlow::DataType>(),
          j.at("activation").template get<::FlexFlow::Activation>(),
          j.at("regularizer")
              .template get<std::optional<::FlexFlow::RegularizerAttrs>>()};
}
void adl_serializer<FlexFlow::LinearAttrs>::to_json(
    json &j, FlexFlow::LinearAttrs const &v) {
  j["__type"] = "LinearAttrs";
  j["out_channels"] = v.out_channels;
  j["use_bias"] = v.use_bias;
  j["data_type"] = v.data_type;
  j["activation"] = v.activation;
  j["regularizer"] = v.regularizer;
}
} // namespace nlohmann

namespace FlexFlow {
std::string format_as(LinearAttrs const &x) {
  std::ostringstream oss;
  oss << "<LinearAttrs";
  oss << " out_channels=" << x.out_channels;
  oss << " use_bias=" << x.use_bias;
  oss << " data_type=" << x.data_type;
  oss << " activation=" << x.activation;
  oss << " regularizer=" << x.regularizer;
  oss << ">";
  return oss.str();
}
std::ostream &operator<<(std::ostream &s, LinearAttrs const &x) {
  return s << fmt::to_string(x);
}
} // namespace FlexFlow
