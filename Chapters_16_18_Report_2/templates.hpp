#include "stdafx.h"

template<typename T>
T simpleTemplate_add(T a, T b) {
	return a + b;
}

template<typename T>
T accumalate(T a) {
	static T memory;
	memory += a;
	return memory;
}

using std::string;
template<typename T>
string overloaded(T *a) {
	return "Template - pointer";
}
template<typename T>
string overloaded(T &&a) {
	return "Template - pass by reference";
}
string overloaded(string a) {
	return "regular overload - string";
}