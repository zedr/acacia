#include "lib/minunit.h"
#include "acacia.h"

MU_TEST(test_check) {
	mu_fail("Finish me!");
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

