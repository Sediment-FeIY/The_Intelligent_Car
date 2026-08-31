// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from mymsg:msg/MyMsg.idl
// generated code does not contain a copyright notice

#ifndef MYMSG__MSG__DETAIL__MY_MSG__BUILDER_HPP_
#define MYMSG__MSG__DETAIL__MY_MSG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "mymsg/msg/detail/my_msg__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace mymsg
{

namespace msg
{

namespace builder
{

class Init_MyMsg_az
{
public:
  explicit Init_MyMsg_az(::mymsg::msg::MyMsg & msg)
  : msg_(msg)
  {}
  ::mymsg::msg::MyMsg az(::mymsg::msg::MyMsg::_az_type arg)
  {
    msg_.az = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mymsg::msg::MyMsg msg_;
};

class Init_MyMsg_ay
{
public:
  explicit Init_MyMsg_ay(::mymsg::msg::MyMsg & msg)
  : msg_(msg)
  {}
  Init_MyMsg_az ay(::mymsg::msg::MyMsg::_ay_type arg)
  {
    msg_.ay = std::move(arg);
    return Init_MyMsg_az(msg_);
  }

private:
  ::mymsg::msg::MyMsg msg_;
};

class Init_MyMsg_ax
{
public:
  explicit Init_MyMsg_ax(::mymsg::msg::MyMsg & msg)
  : msg_(msg)
  {}
  Init_MyMsg_ay ax(::mymsg::msg::MyMsg::_ax_type arg)
  {
    msg_.ax = std::move(arg);
    return Init_MyMsg_ay(msg_);
  }

private:
  ::mymsg::msg::MyMsg msg_;
};

class Init_MyMsg_speed_m4
{
public:
  explicit Init_MyMsg_speed_m4(::mymsg::msg::MyMsg & msg)
  : msg_(msg)
  {}
  Init_MyMsg_ax speed_m4(::mymsg::msg::MyMsg::_speed_m4_type arg)
  {
    msg_.speed_m4 = std::move(arg);
    return Init_MyMsg_ax(msg_);
  }

private:
  ::mymsg::msg::MyMsg msg_;
};

class Init_MyMsg_speed_m3
{
public:
  explicit Init_MyMsg_speed_m3(::mymsg::msg::MyMsg & msg)
  : msg_(msg)
  {}
  Init_MyMsg_speed_m4 speed_m3(::mymsg::msg::MyMsg::_speed_m3_type arg)
  {
    msg_.speed_m3 = std::move(arg);
    return Init_MyMsg_speed_m4(msg_);
  }

private:
  ::mymsg::msg::MyMsg msg_;
};

class Init_MyMsg_speed_m2
{
public:
  explicit Init_MyMsg_speed_m2(::mymsg::msg::MyMsg & msg)
  : msg_(msg)
  {}
  Init_MyMsg_speed_m3 speed_m2(::mymsg::msg::MyMsg::_speed_m2_type arg)
  {
    msg_.speed_m2 = std::move(arg);
    return Init_MyMsg_speed_m3(msg_);
  }

private:
  ::mymsg::msg::MyMsg msg_;
};

class Init_MyMsg_speed_m1
{
public:
  explicit Init_MyMsg_speed_m1(::mymsg::msg::MyMsg & msg)
  : msg_(msg)
  {}
  Init_MyMsg_speed_m2 speed_m1(::mymsg::msg::MyMsg::_speed_m1_type arg)
  {
    msg_.speed_m1 = std::move(arg);
    return Init_MyMsg_speed_m2(msg_);
  }

private:
  ::mymsg::msg::MyMsg msg_;
};

class Init_MyMsg_voltage
{
public:
  Init_MyMsg_voltage()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MyMsg_speed_m1 voltage(::mymsg::msg::MyMsg::_voltage_type arg)
  {
    msg_.voltage = std::move(arg);
    return Init_MyMsg_speed_m1(msg_);
  }

private:
  ::mymsg::msg::MyMsg msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::mymsg::msg::MyMsg>()
{
  return mymsg::msg::builder::Init_MyMsg_voltage();
}

}  // namespace mymsg

#endif  // MYMSG__MSG__DETAIL__MY_MSG__BUILDER_HPP_
