#pragma once
#include <string>
using namespace std;
class CColor
{
public:
	 static const char* COL_Creation() { return "\033[38;5;37m"; }
	 static const char* COL_Error() { return "\033[48;5;52m"; }
	 static const char* COL_Arcs() { return "\033[38;5;166m"; }
	 static const char* COL_Ajout() { return "\033[38;5;27m"; }
	 static const char* COL_Reset() { return "\033[0m"; }
};

