#include "../Chapters_16_18_Report_2/templates.hpp"

using std::string;

/* A simple example function that uses a template
the function simply returns the two arguments added together
the first test works on integers
the second test works on strings
*/
TEST(Templates, simpleAdd_int) {
	int a=4, b=5;
	a = simpleTemplate_add(a, b);
	EXPECT_EQ(a, 9);
}
TEST(Templates, simpleAdd_string) {
	string a = "Hello ";
	string b = "World!";
	a = simpleTemplate_add(a, b);
	EXPECT_EQ(a, "Hello World!");
}

/* These two tests show an interesting thing of how C++ does templates
C++ makes a new copy of the function for every type and then compiles
So for the first test, it makes a copy that works with strings
Passing in the first argument doesn't do much, but the second thing passed in makes it add a to b for what is returned
The second test shows a similar thing but using integers
The third test shows a similar thing but using doubles
The memory used in the functions does not cross between the different instantiations
Also, to show that typedef does not work, the test for "custom" type uses the same memory that the integer uses
and to show that memory is persistant for all calls of the function, the proof test is at the end

things this shows
- template type deduction
- different instantiations for different types
- static follows the different instantiations (same for classes and functions)
*/
TEST(Templates, memory_string) {
	string a = "Hello ";
	string b = "World!";
	a = accumalate(a);
	EXPECT_EQ(a, "Hello ");
	b = accumalate(b);
	EXPECT_EQ(b, "Hello World!");
}
TEST(Templates, memory_int) {
	int a = 4;
	int b = 5;
	a = accumalate(a);
	EXPECT_EQ(a, 4);
	b = accumalate(b);
	EXPECT_EQ(b, 9);
}
TEST(Templates, memory_double) {
	double a = 40;
	double b = 50;
	a = accumalate(a);
	EXPECT_EQ(a, 40);
	b = accumalate(b);
	EXPECT_EQ(b, 90);
}
typedef int not_an_int;
TEST(Templates, memory_custom) { // fails on purpose
	not_an_int a = 4;
	not_an_int b = 5;
	a = accumalate(a);
	EXPECT_EQ(a, 4);
	b = accumalate(b);
	EXPECT_EQ(b, 9);
}
TEST(Templates, memory_proof) {
	int a = 4;
	a = accumalate(a);
	EXPECT_EQ(a, 22);
	double b = 4;
	b = accumalate(b);
	EXPECT_EQ(b, 94);
	string c = " Again!";
	c = accumalate(c);
	EXPECT_EQ(c, "Hello World! Again!");
}

/* The different overload functions with templates
You can have overloaded function names even if you put a template on some
Template functions are lower priority than specilized functions
That makes the string use the hand-specified version that specificly takes a string, and not the template
*/
TEST(Templates, overloads) {
	int a = 4;
	EXPECT_EQ(overloaded(a), "Template - pass by reference"); // templates work as expected
	double b = 4;
	EXPECT_EQ(overloaded(b), "Template - pass by reference");
	string c = "string";
	EXPECT_EQ(overloaded(c), "regular overload - string"); // but the string takes the specialized version and not the template
}

/*testing some things for variadic templates
The book had an excersize for testing the sizes of things
When testing the size of the variable sized argument, more arguments make it larger, even if the same type
*/
TEST(Templates, variadic_sizes) {
	//test the size of the types
	EXPECT_EQ(sizeof_types(42, 42.2, "42"), 3); //3 types
	EXPECT_EQ(sizeof_types(42,43, 42.2, "42"), 4); //3 types (int,int,double,string)
	EXPECT_EQ(sizeof_types(42, 43, 44), 3); // all the same type

	//test the size of the variable input
	EXPECT_EQ(sizeof_args(42, 42.2, "42"), 3); //3 arguments
	EXPECT_EQ(sizeof_args(42, 43, 44), 3); // all the same type
	EXPECT_EQ(sizeof_args(42), 1);
}