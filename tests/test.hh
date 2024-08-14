

/*
 Parameters:
 char* name -> test name or description
 bool t1 -> first test
 ...    -> remaining test required for the function to increment passed tests
*/

#include <iostream>
#include <string>
#include<stdarg.h>


#define DEBUG

class SLOT
{
public:
	SLOT(std::string p_test_name)
	: test_name(p_test_name),
	tests_done(),
	tests_passed(),
	sec_tests_passed(1)
	{};

	template<typename... Args>	
	void TEST(std::string p_test_name,Args... p_args)
	{
		if(loop_test(p_args...))
		{
			#ifdef DEBUG
			std::cout << p_test_name << " : " << "all tests passed " << std::endl;
			#endif
			tests_passed++;
		}
		tests_done++;
	};

	void report_from_test_runner()
	{
		std::cout << "Test: " << test_name << std::endl;
        std::cout << "Tests passed: " << tests_passed << "/" << tests_done << std::endl;
        if(tests_passed!= tests_done)
        {
            std::cout << "Test failed!" << std::endl;
        }
        else
        {
            std::cout << "Test passed!" << std::endl;
		}
        std::cout << std::endl;
	};

private:
	template<typename T>
	bool loop_test(T test)
	{
		return sec_tests_passed &= test;
	}

	template<typename T, typename... Args>
	bool loop_test(T test, Args... args)
	{
		sec_tests_passed &= test;
		return loop_test(args...);
	};


private:

	std::string test_name;

	unsigned int tests_done;
	unsigned int tests_passed;
	unsigned int sec_tests_passed;
	
};

//                    █████       ████ 
//                  ███░░░███    ░░███ 
//  █████ █████    ███   ░░███    ░███ 
// ░░███ ░░███    ░███    ░███    ░███ 
//  ░███  ░███    ░███    ░███    ░███ 
//  ░░███ ███     ░░███   ███     ░███ 
//   ░░█████       ░░░█████░   ██ █████
//    ░░░░░          ░░░░░░   ░░ ░░░░░ 


/**
 * @brief in unit methods
 *  @method TEST(std::string, test...) : adds ++ to error_counter local var if all tests pass.
 *          if not, print error lines and go to next unit.
 */

// constexpr void TEST (std::string, test...)
#define TESTER(error_counter) [&error_counter](bool tests) { if (!tests) { ++error_counter; }}


/**
 * @brief supervisor functions
 *  !//@method Begin() : use begin to start a test unit (like for a class)
 *  !//@method End() : used in the main return statement to finish a test unit
 *  @method GROUP_TEST(std::function<int>) takes a function and outputs the results of the tests that happen within
 */

// todo

#include <functional>

#define GROUP_TEST(error_counter) [&error_counter](std::function<int()> func) {int tmp_counter = func(); if(tmp_counter != 0) {error_counter += tmp_counter; std::cout <<  "GTest error_counter: " << error_counter << std::endl;}}



