# tiny-vector.h

Tiny vector utility macros for small (MCU) environments

## Usage:

``` cpp
#include <tiny-vector.h>

typedef struct foo_t {
   ...
} foo_t;

typedef VECTOR(foo_t *) foo_p_vector_t;
foo_p_vector_t foo_list;

void add(foo_t **foo) {
  if(!initialized) {
    VECTOR_init(foo_list);
  }

  VECTOR_append(foo_list, foo);
}


void loop() {
  for (size_t i = 0; i < VECTOR_size(foo_list); i++) {
    foo_t *foo = VECTOR_at(foo_list, i); 
    doStuff(foo);
  }
}
```

