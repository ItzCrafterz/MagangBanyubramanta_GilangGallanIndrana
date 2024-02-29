// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from flare:msg/Color.idl
// generated code does not contain a copyright notice

#ifndef FLARE__MSG__DETAIL__COLOR__STRUCT_H_
#define FLARE__MSG__DETAIL__COLOR__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Color in the package flare.
typedef struct flare__msg__Color
{
  int32_t red;
  int32_t yellow;
  int32_t blue;
} flare__msg__Color;

// Struct for a sequence of flare__msg__Color.
typedef struct flare__msg__Color__Sequence
{
  flare__msg__Color * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} flare__msg__Color__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FLARE__MSG__DETAIL__COLOR__STRUCT_H_
