#ifndef GUARD_alt_Student_info_h
#define GUARD_alt_Student_info_h

// alt_Student_info.h

#include <iostream>
#include <string>
#include <vector>

struct Student_info {
  std::string name;
  double midterm;
  double final_grade;
  std::vector<double> homework;
};

bool compare(const Student_info&, const Student_info&);
std::istream& read(std::istream&, Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);

#endif
