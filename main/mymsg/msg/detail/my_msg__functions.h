// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from mymsg:msg/MyMsg.idl
// generated code does not contain a copyright notice

#ifndef MYMSG__MSG__DETAIL__MY_MSG__FUNCTIONS_H_
#define MYMSG__MSG__DETAIL__MY_MSG__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "mymsg/msg/rosidl_generator_c__visibility_control.h"

#include "mymsg/msg/detail/my_msg__struct.h"

/// Initialize msg/MyMsg message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * mymsg__msg__MyMsg
 * )) before or use
 * mymsg__msg__MyMsg__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_mymsg
bool
mymsg__msg__MyMsg__init(mymsg__msg__MyMsg * msg);

/// Finalize msg/MyMsg message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mymsg
void
mymsg__msg__MyMsg__fini(mymsg__msg__MyMsg * msg);

/// Create msg/MyMsg message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * mymsg__msg__MyMsg__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_mymsg
mymsg__msg__MyMsg *
mymsg__msg__MyMsg__create();

/// Destroy msg/MyMsg message.
/**
 * It calls
 * mymsg__msg__MyMsg__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mymsg
void
mymsg__msg__MyMsg__destroy(mymsg__msg__MyMsg * msg);

/// Check for msg/MyMsg message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_mymsg
bool
mymsg__msg__MyMsg__are_equal(const mymsg__msg__MyMsg * lhs, const mymsg__msg__MyMsg * rhs);

/// Copy a msg/MyMsg message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_mymsg
bool
mymsg__msg__MyMsg__copy(
  const mymsg__msg__MyMsg * input,
  mymsg__msg__MyMsg * output);

/// Initialize array of msg/MyMsg messages.
/**
 * It allocates the memory for the number of elements and calls
 * mymsg__msg__MyMsg__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_mymsg
bool
mymsg__msg__MyMsg__Sequence__init(mymsg__msg__MyMsg__Sequence * array, size_t size);

/// Finalize array of msg/MyMsg messages.
/**
 * It calls
 * mymsg__msg__MyMsg__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mymsg
void
mymsg__msg__MyMsg__Sequence__fini(mymsg__msg__MyMsg__Sequence * array);

/// Create array of msg/MyMsg messages.
/**
 * It allocates the memory for the array and calls
 * mymsg__msg__MyMsg__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_mymsg
mymsg__msg__MyMsg__Sequence *
mymsg__msg__MyMsg__Sequence__create(size_t size);

/// Destroy array of msg/MyMsg messages.
/**
 * It calls
 * mymsg__msg__MyMsg__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mymsg
void
mymsg__msg__MyMsg__Sequence__destroy(mymsg__msg__MyMsg__Sequence * array);

/// Check for msg/MyMsg message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_mymsg
bool
mymsg__msg__MyMsg__Sequence__are_equal(const mymsg__msg__MyMsg__Sequence * lhs, const mymsg__msg__MyMsg__Sequence * rhs);

/// Copy an array of msg/MyMsg messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_mymsg
bool
mymsg__msg__MyMsg__Sequence__copy(
  const mymsg__msg__MyMsg__Sequence * input,
  mymsg__msg__MyMsg__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // MYMSG__MSG__DETAIL__MY_MSG__FUNCTIONS_H_
