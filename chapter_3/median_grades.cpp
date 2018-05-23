#include <iostream>
#include <ios>
#include <iomanip>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::setprecision;
using std::streamsize;
using std::vector;
using std::sort;

int main() {
  // get the midterm and final grades
  double midterm, final_grade;
  cout << "Enter the midterm and final grades: ";
  cin >> midterm >> final_grade;

  cout << "Enter your homework grades. When finished press ctrl-d: ";
  // enter the homework grades
  vector<double> homework;
  double hw;

  while(cin >> hw) {
    homework.push_back(hw);
  }

  typedef vector<double>::size_type vec_sz;
  vec_sz size = homework.size();
  sort(homework.begin(), homework.end());

  if (size == 0) {
    cout << "You need to enter homework grades." << endl;
    return 1;
  }

  double med = size % 2 == 0 ? (homework[size / 2] + homework[size / 2 - 1]) / 2 : 
                               homework[size / 2];

  // print the result
  streamsize prec = cout.precision();
  cout << "The final grade is " << setprecision(3)
       << 0.2 * midterm + 0.4 * final_grade + 0.4 * med
       << setprecision(prec) << endl;

  return 0;

}
