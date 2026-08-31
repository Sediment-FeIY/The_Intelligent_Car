// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from mymsg:msg/MyMsg.idl
// generated code does not contain a copyright notice

#ifndef MYMSG__MSG__DETAIL__MY_MSG__STRUCT_HPP_
#define MYMSG__MSG__DETAIL__MY_MSG__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__mymsg__msg__MyMsg __attribute__((deprecated))
#else
# define DEPRECATED__mymsg__msg__MyMsg __declspec(deprecated)
#endif

namespace mymsg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MyMsg_
{
  using Type = MyMsg_<ContainerAllocator>;

  explicit MyMsg_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->voltage = 0.0f;
      this->speed_m1 = 0.0f;
      this->speed_m2 = 0.0f;
      this->speed_m3 = 0.0f;
      this->speed_m4 = 0.0f;
      this->ax = 0.0f;
      this->ay = 0.0f;
      this->az = 0.0f;
    }
  }

  explicit MyMsg_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->voltage = 0.0f;
      this->speed_m1 = 0.0f;
      this->speed_m2 = 0.0f;
      this->speed_m3 = 0.0f;
      this->speed_m4 = 0.0f;
      this->ax = 0.0f;
      this->ay = 0.0f;
      this->az = 0.0f;
    }
  }

  // field types and members
  using _voltage_type =
    float;
  _voltage_type voltage;
  using _speed_m1_type =
    float;
  _speed_m1_type speed_m1;
  using _speed_m2_type =
    float;
  _speed_m2_type speed_m2;
  using _speed_m3_type =
    float;
  _speed_m3_type speed_m3;
  using _speed_m4_type =
    float;
  _speed_m4_type speed_m4;
  using _ax_type =
    float;
  _ax_type ax;
  using _ay_type =
    float;
  _ay_type ay;
  using _az_type =
    float;
  _az_type az;

  // setters for named parameter idiom
  Type & set__voltage(
    const float & _arg)
  {
    this->voltage = _arg;
    return *this;
  }
  Type & set__speed_m1(
    const float & _arg)
  {
    this->speed_m1 = _arg;
    return *this;
  }
  Type & set__speed_m2(
    const float & _arg)
  {
    this->speed_m2 = _arg;
    return *this;
  }
  Type & set__speed_m3(
    const float & _arg)
  {
    this->speed_m3 = _arg;
    return *this;
  }
  Type & set__speed_m4(
    const float & _arg)
  {
    this->speed_m4 = _arg;
    return *this;
  }
  Type & set__ax(
    const float & _arg)
  {
    this->ax = _arg;
    return *this;
  }
  Type & set__ay(
    const float & _arg)
  {
    this->ay = _arg;
    return *this;
  }
  Type & set__az(
    const float & _arg)
  {
    this->az = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    mymsg::msg::MyMsg_<ContainerAllocator> *;
  using ConstRawPtr =
    const mymsg::msg::MyMsg_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<mymsg::msg::MyMsg_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<mymsg::msg::MyMsg_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      mymsg::msg::MyMsg_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<mymsg::msg::MyMsg_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      mymsg::msg::MyMsg_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<mymsg::msg::MyMsg_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<mymsg::msg::MyMsg_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<mymsg::msg::MyMsg_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__mymsg__msg__MyMsg
    std::shared_ptr<mymsg::msg::MyMsg_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__mymsg__msg__MyMsg
    std::shared_ptr<mymsg::msg::MyMsg_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MyMsg_ & other) const
  {
    if (this->voltage != other.voltage) {
      return false;
    }
    if (this->speed_m1 != other.speed_m1) {
      return false;
    }
    if (this->speed_m2 != other.speed_m2) {
      return false;
    }
    if (this->speed_m3 != other.speed_m3) {
      return false;
    }
    if (this->speed_m4 != other.speed_m4) {
      return false;
    }
    if (this->ax != other.ax) {
      return false;
    }
    if (this->ay != other.ay) {
      return false;
    }
    if (this->az != other.az) {
      return false;
    }
    return true;
  }
  bool operator!=(const MyMsg_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MyMsg_

// alias to use template instance with default allocator
using MyMsg =
  mymsg::msg::MyMsg_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace mymsg

#endif  // MYMSG__MSG__DETAIL__MY_MSG__STRUCT_HPP_
