

#include "test.hh"





int main(int, char**)
{

	int foo = 0;

	SLOT tst("main");

	tst.TEST("test name", foo == 0, foo+1 == 1, foo == 1, foo== 0, foo == 2);

	return 0;
}