#pragma once
#include <string>
using namespace std;
class CColor
{
public:

	static const char* COL_turquoise() { return "\033[38;5;37m"; }
	
	static const char* COL_Reset() { return "\033[0m"; }
	
};

