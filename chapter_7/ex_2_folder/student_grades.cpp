#include <algorithm>
#include <map>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include "grade.h"
#include "Student_info.h"

using std::map;
using std::cin;
using std::cout;
using std::endl;
using std::domain_error;
using std::max;
using std::setprecision;
using std::streamsize;
using std::setw;
using std::sort;
using std::vector;
using std::string;

string get_letter_grade(double grade)
{
  if (grade >= 90) {
    return "A";
  } else if (grade >= 80) {
    return "B";
  } else if (grade >= 70) {
    return "C";
  } else if (grade >= 60) {
    return "D";
  } else {
    return "F";
  }
}

int main() {

  // Read the data
  vector<Student_info> students;
  Student_info record;
  string::size_type maxlen = 0;

  while (read(cin, record)) {
    maxlen = max(maxlen, record.name.size());
    students.push_back(record);
  }

  sort(students.begin(), students.end(), compare);

  map<string, int> grade_report;

  for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
    string spaces(maxlen + 1 - students[i].name.size(), ' ');
    double final_grade = grade(students[i]);
    ++grade_report[get_letter_grade(final_grade)];
  }

  for (map<string, int>::const_iterator it = grade_report.begin();
      it != grade_report.end(); ++it) {
    cout << it->first << "   " << it->second << endl;
  }

  return 0;
}
