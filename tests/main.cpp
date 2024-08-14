

#include "test.hh"



int main(int, char**)
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