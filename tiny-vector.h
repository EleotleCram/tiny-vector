/*
 * Copyright 2020 Marcel Toele
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software
 * and associated documentation files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or
 * substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
 * BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#pragma once

#include <stdlib.h>

#define VECTOR(T)         \
  struct {                \
    T *data;              \
    unsigned int size;    \
    unsigned int reserve; \
  }

#define VECTOR_init(vector) VECTOR_init_t(typeof(vector), vector)

#define VECTOR_init_t(T, vector)             \
  do {                                       \
    T *v = &(vector);                        \
    v->data = calloc(1, sizeof(*(v->data))); \
    v->size = 0;                             \
    v->reserve = 1;                          \
  } while (0)

#define VECTOR_new(T) calloc(1, sizeof(VECTOR(T)))

#define VECTOR_append(vector, item) VECTOR_append_t(typeof(vector), vector, item)

#define VECTOR_append_t(T, vector, item)                           \
  do {                                                             \
    T *v = &(vector);                                              \
    if (v->reserve == 0) {                                         \
      VECTOR_init(vector);                                         \
    }                                                              \
    v->data[v->size++] = item;                                     \
    if (v->size >= v->reserve) {                                   \
      v->reserve *= 2;                                             \
      v->data = realloc(v->data, sizeof(*v->data) * (v->reserve)); \
    }                                                              \
  } while (0)

#define VECTOR_size(vector) (vector).size

#define VECTOR_at(vector, index) (vector).data[index]
