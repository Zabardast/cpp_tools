

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
		tst(foo == 0);
		foo++;
		tst(foo == 1);
		tst(foo == 0);
	}

	return error_counter;
}

int main(int, char**)
{

	// test_case_one();
	test_case_two();

	return 0;
}
