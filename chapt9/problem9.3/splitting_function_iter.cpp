// source file for the splitting_function_iter.h header

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm> 

using namespace std;

bool space(char c)
{
	return isspace(c);
}
bool notspace(char c)
{
	return !isspace(c);
}
bool is_comma_space(char c)
{
	return isspace(c) || c == ',';
}
bool is_not_comma_space(char c)
{
	return !is_comma_space(c);
}
