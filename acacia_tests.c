#include "lib/minunit.h"
#include "acacia.h"

//#define TEST_KEY "abcd1111"
#define TEST_KEY "abcdefghijklmnopqrstuvwxyz"
#define TEST_VALUE "foo_bar_baz_111"

MU_TEST(test_check) {
	struct Node *cache = cache_init();
	cache_set(TEST_KEY, TEST_VALUE, cache);
	mu_check(cache_get(TEST_KEY, cache) == TEST_VALUE);
}

MU_TEST_SUITE(test_suite) {
	MU_RUN_TEST(test_check);
}

int main(int argc, const char *argv[])
{
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return 0;
}

