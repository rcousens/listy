#include "../greatest.h"
#include "../../src/util/vector.h"

TEST basic_vector() {
    vector *vec = vec_new(sizeof(int));
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int i;

    // Push elements onto vector.
    for(i = 0; i < 10; ++i)
    	vec_push_back(vec, &a[i]);

    // Check if push/get worked correctly.
    for(i = 0; i < 10; ++i)
    	ASSERT_EQ(a[i], vec_get_as(vec, i, int));

    // Remove one element; check again.
    vec_remove(vec, 0);
    for(i = 1; i < 10; ++i)
        ASSERT_EQ(a[i], *((int*) vec_get(vec, i - 1)));

    return 0;
}


SUITE(vectors) {
    RUN_TEST(basic_vector);
}