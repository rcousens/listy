#include "../greatest.h"
#include "../../src/util/vector.h"

TEST x_should_equal_1() {
    int x = 1;
    ASSERT_EQ(1, x);                              /* default message */
    ASSERT_EQm("yikes, x doesn't equal 1", 1, x); /* custom message */
    PASS();
}

SUITE(the_suite) {
    RUN_TEST(x_should_equal_1);
}