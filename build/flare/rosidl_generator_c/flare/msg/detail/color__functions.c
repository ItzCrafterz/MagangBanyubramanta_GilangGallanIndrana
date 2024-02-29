// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from flare:msg/Color.idl
// generated code does not contain a copyright notice
#include "flare/msg/detail/color__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
flare__msg__Color__init(flare__msg__Color * msg)
{
  if (!msg) {
    return false;
  }
  // red
  // yellow
  // blue
  return true;
}

void
flare__msg__Color__fini(flare__msg__Color * msg)
{
  if (!msg) {
    return;
  }
  // red
  // yellow
  // blue
}

bool
flare__msg__Color__are_equal(const flare__msg__Color * lhs, const flare__msg__Color * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // red
  if (lhs->red != rhs->red) {
    return false;
  }
  // yellow
  if (lhs->yellow != rhs->yellow) {
    return false;
  }
  // blue
  if (lhs->blue != rhs->blue) {
    return false;
  }
  return true;
}

bool
flare__msg__Color__copy(
  const flare__msg__Color * input,
  flare__msg__Color * output)
{
  if (!input || !output) {
    return false;
  }
  // red
  output->red = input->red;
  // yellow
  output->yellow = input->yellow;
  // blue
  output->blue = input->blue;
  return true;
}

flare__msg__Color *
flare__msg__Color__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  flare__msg__Color * msg = (flare__msg__Color *)allocator.allocate(sizeof(flare__msg__Color), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(flare__msg__Color));
  bool success = flare__msg__Color__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
flare__msg__Color__destroy(flare__msg__Color * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    flare__msg__Color__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
flare__msg__Color__Sequence__init(flare__msg__Color__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  flare__msg__Color * data = NULL;

  if (size) {
    data = (flare__msg__Color *)allocator.zero_allocate(size, sizeof(flare__msg__Color), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = flare__msg__Color__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        flare__msg__Color__fini(&data[i - 1]);
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
flare__msg__Color__Sequence__fini(flare__msg__Color__Sequence * array)
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
      flare__msg__Color__fini(&array->data[i]);
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

flare__msg__Color__Sequence *
flare__msg__Color__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  flare__msg__Color__Sequence * array = (flare__msg__Color__Sequence *)allocator.allocate(sizeof(flare__msg__Color__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = flare__msg__Color__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
flare__msg__Color__Sequence__destroy(flare__msg__Color__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    flare__msg__Color__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
flare__msg__Color__Sequence__are_equal(const flare__msg__Color__Sequence * lhs, const flare__msg__Color__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!flare__msg__Color__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
flare__msg__Color__Sequence__copy(
  const flare__msg__Color__Sequence * input,
  flare__msg__Color__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(flare__msg__Color);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    flare__msg__Color * data =
      (flare__msg__Color *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!flare__msg__Color__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          flare__msg__Color__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!flare__msg__Color__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
