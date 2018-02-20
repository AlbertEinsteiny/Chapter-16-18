#include "pch.h"
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
TEST(Templates, memory_custom) {
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