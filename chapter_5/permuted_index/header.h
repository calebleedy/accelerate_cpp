#ifndef GUARD_header_h
#define GUARD_header_h

#include <vector>
#include <string>
#include <iostream>

struct line_split {
  std::string prespace;
  std::string sorted_word;
};

std::istream& read_data(std::istream& c, std::vector<std::string>& vec);

std::vector<line_split> rotate_data(const std::vector<std::string>& vec);

bool compare(const line_split& x, const line_split& y);

void print_data(const std::vector<line_split>& vec);

#endif
