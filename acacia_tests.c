#include <string.h>
#include "lib/minunit.h"
#include "acacia.h"

#define TEST_KEY "abcdefghijklmnopqrstuvwxyz"
#define TEST_VALUE "foo_bar_baz_111"


MU_TEST(test_store_fetch_simple) {
	struct Node *cache = cache_init();
	cache_set(TEST_KEY, TEST_VALUE, cache);
	mu_check(strcmp(cache_get(TEST_KEY, cache), TEST_VALUE) == 0);
	cache_close(cache);
}

MU_TEST(test_store_fetch_empty_string) {
	struct Node *cache = cache_init();
	cache_set("foo", "", cache);
	mu_check(strcmp(cache_get("foo", cache), "") == 0);
	cache_close(cache);
}

MU_TEST_SUITE(test_suite) {
	MU_RUN_TEST(test_store_fetch_simple);
	MU_RUN_TEST(test_store_fetch_empty_string);
}

int main(int argc, const char *argv[])
{
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return 0;
}

