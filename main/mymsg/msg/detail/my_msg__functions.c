// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from mymsg:msg/MyMsg.idl
// generated code does not contain a copyright notice
#include "mymsg/msg/detail/my_msg__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
mymsg__msg__MyMsg__init(mymsg__msg__MyMsg * msg)
{
  if (!msg) {
    return false;
  }
  // voltage
  // speed_m1
  // speed_m2
  // speed_m3
  // speed_m4
  // ax
  // ay
  // az
  return true;
}

void
mymsg__msg__MyMsg__fini(mymsg__msg__MyMsg * msg)
{
  if (!msg) {
    return;
  }
  // voltage
  // speed_m1
  // speed_m2
  // speed_m3
  // speed_m4
  // ax
  // ay
  // az
}

bool
mymsg__msg__MyMsg__are_equal(const mymsg__msg__MyMsg * lhs, const mymsg__msg__MyMsg * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // voltage
  if (lhs->voltage != rhs->voltage) {
    return false;
  }
  // speed_m1
  if (lhs->speed_m1 != rhs->speed_m1) {
    return false;
  }
  // speed_m2
  if (lhs->speed_m2 != rhs->speed_m2) {
    return false;
  }
  // speed_m3
  if (lhs->speed_m3 != rhs->speed_m3) {
    return false;
  }
  // speed_m4
  if (lhs->speed_m4 != rhs->speed_m4) {
    return false;
  }
  // ax
  if (lhs->ax != rhs->ax) {
    return false;
  }
  // ay
  if (lhs->ay != rhs->ay) {
    return false;
  }
  // az
  if (lhs->az != rhs->az) {
    return false;
  }
  return true;
}

bool
mymsg__msg__MyMsg__copy(
  const mymsg__msg__MyMsg * input,
  mymsg__msg__MyMsg * output)
{
  if (!input || !output) {
    return false;
  }
  // voltage
  output->voltage = input->voltage;
  // speed_m1
  output->speed_m1 = input->speed_m1;
  // speed_m2
  output->speed_m2 = input->speed_m2;
  // speed_m3
  output->speed_m3 = input->speed_m3;
  // speed_m4
  output->speed_m4 = input->speed_m4;
  // ax
  output->ax = input->ax;
  // ay
  output->ay = input->ay;
  // az
  output->az = input->az;
  return true;
}

mymsg__msg__MyMsg *
mymsg__msg__MyMsg__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mymsg__msg__MyMsg * msg = (mymsg__msg__MyMsg *)allocator.allocate(sizeof(mymsg__msg__MyMsg), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mymsg__msg__MyMsg));
  bool success = mymsg__msg__MyMsg__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
mymsg__msg__MyMsg__destroy(mymsg__msg__MyMsg * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    mymsg__msg__MyMsg__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
mymsg__msg__MyMsg__Sequence__init(mymsg__msg__MyMsg__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mymsg__msg__MyMsg * data = NULL;

  if (size) {
    data = (mymsg__msg__MyMsg *)allocator.zero_allocate(size, sizeof(mymsg__msg__MyMsg), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mymsg__msg__MyMsg__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mymsg__msg__MyMsg__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
mymsg__msg__MyMsg__Sequence__fini(mymsg__msg__MyMsg__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      mymsg__msg__MyMsg__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

mymsg__msg__MyMsg__Sequence *
mymsg__msg__MyMsg__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mymsg__msg__MyMsg__Sequence * array = (mymsg__msg__MyMsg__Sequence *)allocator.allocate(sizeof(mymsg__msg__MyMsg__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = mymsg__msg__MyMsg__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
mymsg__msg__MyMsg__Sequence__destroy(mymsg__msg__MyMsg__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    mymsg__msg__MyMsg__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
mymsg__msg__MyMsg__Sequence__are_equal(const mymsg__msg__MyMsg__Sequence * lhs, const mymsg__msg__MyMsg__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mymsg__msg__MyMsg__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mymsg__msg__MyMsg__Sequence__copy(
  const mymsg__msg__MyMsg__Sequence * input,
  mymsg__msg__MyMsg__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mymsg__msg__MyMsg);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    mymsg__msg__MyMsg * data =
      (mymsg__msg__MyMsg *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mymsg__msg__MyMsg__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          mymsg__msg__MyMsg__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!mymsg__msg__MyMsg__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
