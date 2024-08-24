
#include <iostream>
#include <string>



//                    █████       ████ 
//                  ███░░░███    ░░███ 
//  █████ █████    ███   ░░███    ░███ 
// ░░███ ░░███    ░███    ░███    ░███ 
//  ░███  ░███    ░███    ░███    ░███ 
//  ░░███ ███     ░░███   ███     ░███ 
//   ░░█████       ░░░█████░   ██ █████
//    ░░░░░          ░░░░░░   ░░ ░░░░░ 


// multiple tests

// #define DEBUG <- will use this when adding the debug options feature.
// TODO : add log messages for DEBUG and INFO
// TODO : add verbosity for witch error happend where -> give line number from the main file

template<typename T>
bool loop_test(T test)
{
	if(test)
		return 0; // test successful
	return 1;     // test failed
}

template<typename T, typename... Args>
bool loop_test(T test, Args... args)
{
	if(!test)
		return 1;   // test failed
	return loop_test(args...);
};

#define TEST(name, ...) \
{\
	bool result = loop_test(true, __VA_ARGS__); \
	error_counter += result; \
	std::cout << (result ? "Failed" : "Ok    ") << " : "  << name << "    " << __FILE__ << ":" << __LINE__ << "  " << __func__ << std::endl; \
}


// group tests
#define GROUP_TEST(func) \
{ \
	int tmp_counter = func(); \
	if(tmp_counter != 0) \
	{ \
		error_counter += tmp_counter; \
		std::cout << __FILE__ << ":" << __LINE__ << " error_counter: " << error_counter << std::endl << std::endl; \
	} \
}

