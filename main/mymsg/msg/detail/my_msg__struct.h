// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from mymsg:msg/MyMsg.idl
// generated code does not contain a copyright notice

#ifndef MYMSG__MSG__DETAIL__MY_MSG__STRUCT_H_
#define MYMSG__MSG__DETAIL__MY_MSG__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/MyMsg in the package mymsg.
/**
  * 自定义消息：设备状态数据
 */
typedef struct mymsg__msg__MyMsg
{
  float voltage;
  float speed_m1;
  float speed_m2;
  float speed_m3;
  float speed_m4;
  float ax;
  float ay;
  float az;
} mymsg__msg__MyMsg;

// Struct for a sequence of mymsg__msg__MyMsg.
typedef struct mymsg__msg__MyMsg__Sequence
{
  mymsg__msg__MyMsg * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mymsg__msg__MyMsg__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MYMSG__MSG__DETAIL__MY_MSG__STRUCT_H_
