#include "pch.h"
#include "../Chapters_16_18_Report_2/templates.hpp"

using std::string;

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