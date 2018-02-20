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