#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <cctype>
#include <stdexcept>
#include <iostream>
#include "median.h"
#include "Student_info.h"
#include "grade.h"

using std::vector;
using std::string;
using std::domain_error;
using std::cout;
using std::cin;
using std::endl;
using std::ostream;

bool did_all_hw(const Student_info& s)
{
  return ((find(s.homework.begin(), s.homework.end(), 0)) == s.homework.end());
}

double grade_aux(const Student_info& s)
{
  try {
    return grade(s);
  } catch (domain_error) {
    return grade(s.midterm, s.final_grade, 0);
  }
}

double median_analysis(const vector<Student_info>& students)
{
  vector<double> grades;
  transform(students.begin(), students.end(), back_inserter(grades), grade_aux);
  return median(grades);
}

double average(const vector<double>& v)
{
  return accumulate(v.begin(), v.end(), 0.0) / v.size();
}

double average_grade(const Student_info& s)
{
  return grade(s.midterm, s.final_grade, average(s.homework));
}

double average_analysis(const vector<Student_info>& students)
{
  vector<double> grades;

  transform(students.begin(), students.end(),
      back_inserter(grades), average_grade);

  return median(grades);
}

double optimistic_median(const Student_info& s)
{
  vector<double> nonzero;
  remove_copy(s.homework.begin(), s.homework.end(), back_inserter(nonzero), 0);

  if (nonzero.empty()) {
    return grade(s.midterm, s.final_grade, 0);
  } else {
    return grade(s.midterm, s.final_grade, median(nonzero));
  }
}

double optimistic_median_analysis(const vector<Student_info>& students)
{
  vector<double> grades;

  transform(students.begin(), students.end(),
      back_inserter(grades), optimistic_median);

  return median(grades);
}

double any_analysis(const vector<Student_info>& students,
                    double analysis_fun(const Student_info&))
{
  vector<double> grades;

  transform(students.begin(), students.end(),
      back_inserter(grades), analysis_fun);

  return median(grades);
}


void write_analysis(ostream& out, const string& name,
    double analysis(const vector<Student_info>&, 
                    double analysis_fun(const Student_info&)),
    double analysis_fun_name(const Student_info&),
    const vector<Student_info>& did,
    const vector<Student_info>& didnt)
{
  out << name << ": median(did) = " <<
                 analysis(did, analysis_fun_name) <<
                 ", median(didnt) = " << 
                 analysis(didnt, analysis_fun_name) << endl;
}

int main()
{
  vector<Student_info> did, didnt;

  Student_info student;
  while (read(cin, student)) {
    if (did_all_hw(student)) {
      did.push_back(student);
    } else {
      didnt.push_back(student);
    }
  }

  if (did.empty()) {
    cout << "No student did all the homework!" << endl;
    return 1;
  }
  if (didnt.empty()) {
    cout << "Every student did all the homework!" << endl;
    return 1;
  }

  write_analysis(cout, "median", any_analysis, median_analysis, did, didnt);
  write_analysis(cout, "average", any_analysis, average_analysis, did, didnt);
  write_analysis(cout, "median of homework turned in",
      any_analysis, optimistic_median_analysis, did, didnt);

  return 0;
}
