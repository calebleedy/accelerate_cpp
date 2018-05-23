#include <iostream>
#include <ios>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::setprecision;
using std::streamsize;

int main() {
  // get the midterm and final grades
  double midterm, final_grade;
  cout << "Enter the midterm and final grades: ";
  cin >> midterm >> final_grade;

  // enter the homework grades
  double hw;
  double sum = 0;
  int count = 0;

  cout << "Enter your homework grades. When finished press ctrl-d: ";
  while(cin >> hw) {
    sum += hw;
    count += 1;
  }

  // print the result
  streamsize prec = cout.precision();
  cout << "The final grade is " << setprecision(3)
       << 0.2 * midterm + 0.4 * final_grade + 0.4 * sum / count 
       << setprecision(prec) << endl;

  return 0;

}
