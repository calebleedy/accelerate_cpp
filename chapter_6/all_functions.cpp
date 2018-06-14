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
using std::endl;
using std::ostream;

bool space(char c)
{
  return isspace(c);
}

bool not_space(char c)
{
  return !isspace(c);
}

vector<string> split(const string& str)
{
  typedef string::const_iterator iter;
  vector<string> ret;

  iter i = str.begin();
  while(i != str.end()) {
    i = find_if(i, str.end(), not_space);
    iter j = find_if(i, str.end(), space);

    if (i != str.end()) {
      ret.push_back(string(i, j));
    }

    i = j;
  }
  return ret;
}

bool is_palindrone(const string& s)
{
  return equal(s.begin(), s.end(), s.rbegin());
}

bool not_url_char(char c)
{
  static const string url_ch = "~;/?:@=&$-_.+!*'(),";

  return !(isalnum(c) || find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
}

string::const_iterator 
url_beg(string::const_iterator b, string::const_iterator e) 
{
  static const string sep = "://";
  typedef string::const_iterator iter;

  iter i = b;

  while ((i = search(i, e, sep.begin(), sep.end())) != e) {
    if (i != b && i + sep.size() != e) {

      iter beg = i;
      while (beg != b && isalpha(beg[-1])) {
        --beg;
      }
      if (beg != i && i + sep.size() != e && !not_url_char(i[sep.size()])) {
        return beg;
      }
    }
    if (i != e) {
      i += sep.size();
    }
  }
  return e;
}

string::const_iterator 
url_end(string::const_iterator b, string::const_iterator e) 
{
  return find_if(b, e, not_url_char);
}

vector<string> find_urls(const string& s)
{
  vector<string> ret;
  typedef string::const_iterator iter;
  iter b = s.begin(), e = s.end();

  while (b != e) {
    b = url_beg(b, e);

    if (b != e) {
      iter after = url_end(b, e);
      ret.push_back(string(b, after));
      b = after;
    }
  }
  return ret;
}

// ***************************************************************************
// Student Records
// ***************************************************************************

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

void write_analysis(ostream& out, const string& name,
    double analysis(const vector<Student_info>&),
    const vector<Student_info>& did,
    const vector<Student_info>& didnt)
{
  out << name << ": median(did) = " << analysis(did) <<
                 ", median(didnt) = " << analysis(didnt) << endl;
}
