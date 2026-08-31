// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from mymsg:msg/MyMsg.idl
// generated code does not contain a copyright notice

#ifndef MYMSG__MSG__DETAIL__MY_MSG__TRAITS_HPP_
#define MYMSG__MSG__DETAIL__MY_MSG__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "mymsg/msg/detail/my_msg__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace mymsg
{

namespace msg
{

inline void to_flow_style_yaml(
  const MyMsg & msg,
  std::ostream & out)
{
  out << "{";
  // member: voltage
  {
    out << "voltage: ";
    rosidl_generator_traits::value_to_yaml(msg.voltage, out);
    out << ", ";
  }

  // member: speed_m1
  {
    out << "speed_m1: ";
    rosidl_generator_traits::value_to_yaml(msg.speed_m1, out);
    out << ", ";
  }

  // member: speed_m2
  {
    out << "speed_m2: ";
    rosidl_generator_traits::value_to_yaml(msg.speed_m2, out);
    out << ", ";
  }

  // member: speed_m3
  {
    out << "speed_m3: ";
    rosidl_generator_traits::value_to_yaml(msg.speed_m3, out);
    out << ", ";
  }

  // member: speed_m4
  {
    out << "speed_m4: ";
    rosidl_generator_traits::value_to_yaml(msg.speed_m4, out);
    out << ", ";
  }

  // member: ax
  {
    out << "ax: ";
    rosidl_generator_traits::value_to_yaml(msg.ax, out);
    out << ", ";
  }

  // member: ay
  {
    out << "ay: ";
    rosidl_generator_traits::value_to_yaml(msg.ay, out);
    out << ", ";
  }

  // member: az
  {
    out << "az: ";
    rosidl_generator_traits::value_to_yaml(msg.az, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MyMsg & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: voltage
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "voltage: ";
    rosidl_generator_traits::value_to_yaml(msg.voltage, out);
    out << "\n";
  }

  // member: speed_m1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "speed_m1: ";
    rosidl_generator_traits::value_to_yaml(msg.speed_m1, out);
    out << "\n";
  }

  // member: speed_m2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "speed_m2: ";
    rosidl_generator_traits::value_to_yaml(msg.speed_m2, out);
    out << "\n";
  }

  // member: speed_m3
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "speed_m3: ";
    rosidl_generator_traits::value_to_yaml(msg.speed_m3, out);
    out << "\n";
  }

  // member: speed_m4
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "speed_m4: ";
    rosidl_generator_traits::value_to_yaml(msg.speed_m4, out);
    out << "\n";
  }

  // member: ax
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ax: ";
    rosidl_generator_traits::value_to_yaml(msg.ax, out);
    out << "\n";
  }

  // member: ay
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ay: ";
    rosidl_generator_traits::value_to_yaml(msg.ay, out);
    out << "\n";
  }

  // member: az
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "az: ";
    rosidl_generator_traits::value_to_yaml(msg.az, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MyMsg & msg, bool use_flow_style = false)
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

}  // namespace mymsg

namespace rosidl_generator_traits
{

[[deprecated("use mymsg::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const mymsg::msg::MyMsg & msg,
  std::ostream & out, size_t indentation = 0)
{
  mymsg::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use mymsg::msg::to_yaml() instead")]]
inline std::string to_yaml(const mymsg::msg::MyMsg & msg)
{
  return mymsg::msg::to_yaml(msg);
}

template<>
inline const char * data_type<mymsg::msg::MyMsg>()
{
  return "mymsg::msg::MyMsg";
}

template<>
inline const char * name<mymsg::msg::MyMsg>()
{
  return "mymsg/msg/MyMsg";
}

template<>
struct has_fixed_size<mymsg::msg::MyMsg>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<mymsg::msg::MyMsg>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<mymsg::msg::MyMsg>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MYMSG__MSG__DETAIL__MY_MSG__TRAITS_HPP_
