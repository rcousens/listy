#include "vector.h"

// Allocates and initializes an empty vector.
vector *vec_new(const size_t elem_size)
{
	vector *ret = malloc(sizeof(vector));
	vec_init(ret, elem_size);
	return ret;
}

// Returns pointer to a newly allocated vector with
// identical contents to the given parameter.
vector *vec_copy   (const vector *const vec){
	//TODO
	vector *ret = vec_new(vec->elem_size);
	vec_reserve(ret, vec->size);
	unsigned int i = 0;
	while(i < vec->size){
		vec_push_back(ret, vec_get(vec, vec->size));
		++i;
	}
	return ret;
}


// Initializes an already-allocated vector.
const int vec_init (vector *const vec, const size_t elem_size)
{
	// Check for lack of allocation.
	if(!vec) 
		return -1;

	// Initialize fields.
	vec->size = 0;
	vec->elem_size = elem_size;
	vec->max_size = DEFAULT_VECTOR_CAPACITY;

	// Try allocating internal array.
	vec->data = malloc(elem_size * DEFAULT_VECTOR_CAPACITY);

	// Return success / failure.
	if(vec->data)
		return 0;
	return -1;
}


// Free vector and internal array.
const int vec_free (vector *vec)
{
	free(vec->data);
	free(vec);
	return 0;
}


// Returns pointer to indicated element. If index is out of bounds,
// returns NULL.
void *vec_get (const vector *const vec, const unsigned int ind)
{
	if(ind < vec->size)
		return vec->data + vec->elem_size * ind;
	return NULL;
}


// Returns pointer to first element; NULL if vector is empty.
void *vec_front (const vector *const vec)
{
	if(vec->size)
		return vec->data;
	return NULL;
}


// Returns pointer to final element.
void *vec_back (const vector *const vec)
{
	if(vec->size)
		return vec->data + vec->size - 1;
	return NULL;
}


// Appends value. Returns non-zero
const int vec_push_back (vector *const vec, const void *const val)
{	
	return vec_insert(vec, val, vec->size - 1);
}


// Prepends value.
const int vec_push_front (vector *const vec, const void *const val)
{
	return vec_insert(vec, val, 0);
}


// Inserts <val> at givent index.
const int vec_insert (vector *const vec, const void *const val, const unsigned int ind)
{	
	// Check for valid args...
	if(ind > vec->size  ||  !vec  ||  !val) {
		return -1;
	}

	// Ensure capacity for incoming value.
	vec_reserve(vec, (vec->size + 1) * 2);

	// Shift values backward.
	unsigned int i;
	for(i = i = vec->size; i > ind; --i) {
		char *from = vec_get(vec, ind - 1);
		char *dest = vec_get(vec, ind);
		memmove(dest, from, vec->elem_size);
	}

	// Insert value
	vec_set(vec, ind, val);

	// Update size.
	vec->size += 1;

	// Return success.
	return 0;
}


// Removes given index, shifting elemtents into its place.
const int vec_remove (vector *const vec, const unsigned int ind)
{
	// Check bounds.
	if(ind >= vec->size)
		return -1;

	unsigned int i = ind;
	while(i < vec->size - 1){
		vec_set(vec, i, vec_get(vec, i + 1));
		++i;
	}
	vec->size -= 1;
	return 0;
}


// Removes all vector elements.
const int vec_clear (vector *const vec)
{
	while(vec->size)
		vec_remove(vec, 0);
	return 0;
}


// Ensures that the given vector has space for <elems> elements.
const int vec_reserve(vector *const vec, const unsigned int elems){
	if (elems > vec->size){
		char *tmp = realloc(vec->data, vec->elem_size * elems);
		if(!tmp)
			return -1;
		vec->data = tmp;
		vec->max_size = elems;
	}
	return 0;
}

// Reallocates data to minimize total memory usage.
void vec_mimimize(vector *const vec){
	vec->data = realloc(vec->data, vec->size * vec->elem_size);
	vec->max_size = vec->size;
}

// 
const int vec_set(vector *const vec, const unsigned int ind, const void *const val){
	if(ind >= vec->size)
		return -1;
	memmove(vec_get(vec, ind), val, vec->elem_size);
	return 0;
}

// Finds first occurence of val, returning -1 if none are found.
int vec_find (const vector *const vec, void *val)
{
	// Loop through elems:
	unsigned int i = 0;
	while(i < vec->size){
		void *elem = vec_get(vec, i);

		// If equal pointer addresses, return index.
		if(elem == val)
			return i;

		// If equivelent byte fields, return index.
		if(!memcmp(elem, val, vec->elem_size))
			return i;
		++i;
	}

	// Not found: return -1.
	return -1;
}


// Return vector of occurences.
vector *vec_find_all (const vector *const vec, void *val)
{
	// Allocate new vector to return.
	vector *ret = vec_new(sizeof(unsigned int));

	// Loop through elems:
	unsigned int i = 0;
	while(i < vec->size){
		// If equivelent byte fields, append index.
		if(!memcmp(vec_get(vec, i), val, vec->elem_size))
			vec_push_back(ret, &i);
		++i;
	}

	return ret;
}


// Getters
unsigned int vec_size (const vector *const vec) { return vec->size;      }
unsigned int vec_max  (const vector *const vec) { return vec->max_size;  }
size_t vec_elem_size  (const vector *const vec) { return vec->elem_size; }


// Performs <func> on all elements.
const int vec_foreach (vector *const vec, void (*func)(void *))
{
	unsigned int i = 0;
	while(i < vec->size){
		func(vec_get(vec, i));
		++i;
	}
	return 0;
}


// Performs <func> on all elements that evaluate to true with the given
// filter.
const int vec_foreach_that (vector *const vec, bool (*filter)(void *), void (*func)(void *))
{
	unsigned int i = 0;
	while(i < vec->size){
		void *elem = vec_get(vec, i);
		if(filter(elem))
			func(elem);
		++i;
	}
	return 0;
}

//