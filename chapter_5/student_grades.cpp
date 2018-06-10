#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include "Student_info.h"
#include "grade.h"
#include <vector>
#include <list>
#include <string>
#include <cctype>
#include <algorithm>

using std::list;
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::domain_error;
using std::max;
using std::setprecision;
using std::streamsize;
using std::setw;
using std::sort;

typedef list<Student_info> data_str;

bool fgrade(const Student_info& s)
{
  return grade(s) < 60;
}

data_str extract_fails(data_str& students)
{
  data_str fail;
  data_str::iterator iter = students.begin();

  while (iter != students.end()) {
    if (fgrade(*iter)) {
      fail.push_back(*iter);
      iter = students.erase(iter);
    } else {
      ++iter;
    }
  }
  return fail;
}

void sort(list<Student_info>& S) 
{
  S.sort(compare);
}

void sort(vector<Student_info>& S)
{
  sort(S.begin(), S.end(), compare);
}

int main() {
  // Read the data
  data_str students;
  data_str fail_students;
  Student_info record;
  string::size_type maxlen = 0;

  while (read(cin, record)) {
    maxlen = max(maxlen, record.name.size());
    students.push_back(record);
  }

  fail_students = extract_fails(students);

  sort(students);
  sort(fail_students);

  cout << "Passed: " << endl;
  for (data_str::iterator iter = students.begin();
      iter != students.end(); ++iter) {
    string spaces(maxlen + 1 - iter->name.size(), ' ');
    cout << iter->name << spaces;

    try {
      double final_grade = grade(*iter);
      streamsize prec = cout.precision();
      cout << setprecision(3) << final_grade
           << setprecision(prec);
    } catch (domain_error e) {
      cout << e.what();
    }
    cout << endl;
  }

  cout << "Failed: " << endl;
  for (data_str::iterator iter = fail_students.begin();
      iter != fail_students.end(); ++iter) {
    string spaces(maxlen + 1 - iter->name.size(), ' ');
    cout << iter->name << spaces;

    try {
      double final_grade = grade(*iter);
      streamsize prec = cout.precision();
      cout << setprecision(3) << final_grade
           << setprecision(prec);
    } catch (domain_error e) {
      cout << e.what();
    }
    cout << endl;
  }

  return 0;
}
