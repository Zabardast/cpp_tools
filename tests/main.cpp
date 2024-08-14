

#include "test.hh"

int test_case_one()
{
	int foo = 0;

	SLOT tst("main");

	tst.TEST("test 1", foo == 0, foo+1 == 1, foo == 0, foo== 0, foo == 0);
	tst.TEST("test 2", foo == 0, foo+1 == 1, foo == 0, foo== 0, foo == 0);
	tst.TEST("test 3", foo == 0, foo+1 == 1, foo == 0, foo== 0, foo == 1);
	tst.TEST("test 4", foo == 0, foo+1 == 1, foo == 0, foo== 0, foo == 0);
	tst.TEST("test 5", foo == 0, foo+1 == 1, foo == 0, foo== 0, foo == 0);
	tst.TEST("test end", foo == 0, foo+1 == 1, foo == 0, foo== 0, foo == 0);

	tst.report_from_test_runner();

	return 0;
}


int test_case_two()
{
	int error_counter = 0;
	auto tst = TESTER(error_counter);

	{

		int foo = 0;

		tst(foo == 0);
		tst(foo == 1);
		foo++;
		tst(foo == 1);
		tst(foo == 0);
		std::cout << "local error_counter: " << error_counter << std::endl;
	}

	return error_counter;
}

int main(int, char**)
{
	int error_counter = 0;
	auto GP_TEST = GROUP_TEST(error_counter);
	// test_case_one();
	GP_TEST(test_case_two);
	GP_TEST(test_case_two);
	// GROUP_TEST(test_case_two);

	return 0;
}
