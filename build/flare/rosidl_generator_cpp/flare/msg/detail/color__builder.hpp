// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from flare:msg/Color.idl
// generated code does not contain a copyright notice

#ifndef FLARE__MSG__DETAIL__COLOR__BUILDER_HPP_
#define FLARE__MSG__DETAIL__COLOR__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "flare/msg/detail/color__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace flare
{

namespace msg
{

namespace builder
{

class Init_Color_blue
{
public:
  explicit Init_Color_blue(::flare::msg::Color & msg)
  : msg_(msg)
  {}
  ::flare::msg::Color blue(::flare::msg::Color::_blue_type arg)
  {
    msg_.blue = std::move(arg);
    return std::move(msg_);
  }

private:
  ::flare::msg::Color msg_;
};

class Init_Color_yellow
{
public:
  explicit Init_Color_yellow(::flare::msg::Color & msg)
  : msg_(msg)
  {}
  Init_Color_blue yellow(::flare::msg::Color::_yellow_type arg)
  {
    msg_.yellow = std::move(arg);
    return Init_Color_blue(msg_);
  }

private:
  ::flare::msg::Color msg_;
};

class Init_Color_red
{
public:
  Init_Color_red()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Color_yellow red(::flare::msg::Color::_red_type arg)
  {
    msg_.red = std::move(arg);
    return Init_Color_yellow(msg_);
  }

private:
  ::flare::msg::Color msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::flare::msg::Color>()
{
  return flare::msg::builder::Init_Color_red();
}

}  // namespace flare

#endif  // FLARE__MSG__DETAIL__COLOR__BUILDER_HPP_
