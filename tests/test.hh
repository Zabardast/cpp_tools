

/*
 Parameters:
 char* name -> test name or description
 bool t1 -> first test
 ...    -> remaining test required for the function to increment passed tests
*/

#include <iostream>
#include <string>
#include<stdarg.h>


class SLOT
{
public:
	SLOT(std::string p_test_name)
	: test_name(p_test_name),
	tests_done(),
	tests_passed()
	{};


	template<typename T, typename... Args>
	void TEST(std::string name, T test, Args... args){
		
		multiple_tests(test);
		multiple_tests(args...);
		// std::cout << name << tests_done << " / " << tests_passed << std::endl;
	};

	//variadic example in stack overflow
	template<typename T>
	void multiple_tests(T test)
	{
		tests_done++;
		tests_passed &= test;


		std::cout << " test:" << test << std::endl;
	};

	template<typename T, typename... Args>
	void multiple_tests(T test, Args... args)
	{
		tests_done++;
		tests_passed &= test;

		std::cout << " test:" << test << std::endl;

		multiple_tests(args...);
	};


private:

	std::string test_name;

	unsigned int tests_done;
	unsigned int tests_passed;
};


// #define TEST(char* name, bool t1, ...) {printf(name);}