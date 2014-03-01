#ifndef _UTIL_VECTOR_H_
#define _UTIL_VECTOR_H_
#define DEFAULT_VECTOR_CAPACITY 5
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Dynamic Array (similar to c++ vector):
typedef struct {
	size_t elem_size;
	unsigned short size;
	unsigned short max_size;
	char *data;
} vector; 

// Allocation / Deallocation:
vector *vec_new    (const size_t);
vector *vec_copy   (const vector *const);
const int vec_init (vector *const, const size_t);
const int vec_free (vector *);

// Retrieval functions:
void *vec_get   (const vector *const, const unsigned int);
void *vec_front (const vector *const);
void *vec_back  (const vector *const);

// Mutator functions:
const int vec_push_back  (vector *const, const void *const);
const int vec_push_front (vector *const, const void *const);
const int vec_insert     (vector *const, const void *const, const unsigned int);
const int vec_remove (vector *const, const unsigned int);
const int vec_clear  (vector *const);
const int vec_reserve  (vector *const, const unsigned int);
const int vec_minimize (vector *const);
const int vec_set(vector *const, const unsigned int, const void *const );

// Meta Functions:
int vec_find (const vector *const, void *);
vector *vec_find_all  (const vector *const, void *);
unsigned int vec_size (const vector *const);
unsigned int vec_max  (const vector *const);
size_t vec_elem_size  (const vector *const);

// Loopers
const int vec_foreach (vector *const, void (*)(void *));
const int vec_foreach_that (vector *const, bool (*)(void *), void (*)(void *));

#define vec_get_as(vec, ind, type) *((type *) vec_get(vec, ind))


#endif // _UTIL_VECTOR_H_