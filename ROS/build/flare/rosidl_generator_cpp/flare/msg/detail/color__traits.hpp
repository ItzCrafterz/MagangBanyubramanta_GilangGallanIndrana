// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from flare:msg/Color.idl
// generated code does not contain a copyright notice

#ifndef FLARE__MSG__DETAIL__COLOR__TRAITS_HPP_
#define FLARE__MSG__DETAIL__COLOR__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "flare/msg/detail/color__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace flare
{

namespace msg
{

inline void to_flow_style_yaml(
  const Color & msg,
  std::ostream & out)
{
  out << "{";
  // member: red
  {
    out << "red: ";
    rosidl_generator_traits::value_to_yaml(msg.red, out);
    out << ", ";
  }

  // member: yellow
  {
    out << "yellow: ";
    rosidl_generator_traits::value_to_yaml(msg.yellow, out);
    out << ", ";
  }

  // member: blue
  {
    out << "blue: ";
    rosidl_generator_traits::value_to_yaml(msg.blue, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Color & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: red
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "red: ";
    rosidl_generator_traits::value_to_yaml(msg.red, out);
    out << "\n";
  }

  // member: yellow
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yellow: ";
    rosidl_generator_traits::value_to_yaml(msg.yellow, out);
    out << "\n";
  }

  // member: blue
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "blue: ";
    rosidl_generator_traits::value_to_yaml(msg.blue, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Color & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace flare

namespace rosidl_generator_traits
{

[[deprecated("use flare::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const flare::msg::Color & msg,
  std::ostream & out, size_t indentation = 0)
{
  flare::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use flare::msg::to_yaml() instead")]]
inline std::string to_yaml(const flare::msg::Color & msg)
{
  return flare::msg::to_yaml(msg);
}

template<>
inline const char * data_type<flare::msg::Color>()
{
  return "flare::msg::Color";
}

template<>
inline const char * name<flare::msg::Color>()
{
  return "flare/msg/Color";
}

template<>
struct has_fixed_size<flare::msg::Color>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<flare::msg::Color>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<flare::msg::Color>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // FLARE__MSG__DETAIL__COLOR__TRAITS_HPP_
