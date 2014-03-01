#include "util/vector.c"


/* Add definitions that need to be in the test runner's main file. */
GREATEST_MAIN_DEFS();

int main(int argc, char **argv) {
    GREATEST_MAIN_BEGIN();      /* command-line arguments, initialization. */
    RUN_SUITE(the_suite);
    GREATEST_MAIN_END();        /* display results */
}