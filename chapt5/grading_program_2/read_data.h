//header file read_data.h

#ifndef GUARD_read_data
#define GUARD_read_data

#include <fstream>
#include <string>
#include <vector>

std::ifstream& read_data(std::ifstream&, std::vector<std::string>&);
std::ifstream& read_data(std::ifstream&, std::list<std::string>&);

#endif
