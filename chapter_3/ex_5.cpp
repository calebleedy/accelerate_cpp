#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

int main() {
  // Read the data
  cout << "How many homework grades per student? ";
  int num_hw;
  cin >> num_hw;

  vector<string> stud_name;
  vector<double> mid_grade;
  vector<double> final_grade;
  vector<double> homework_grade;

  cout << "Is there another student? (y/n) ";
  string test;
  cin >> test;

  while(test.compare("y") == 0) {
    string name;
    cout << "What is the student's name? ";
    cin >> name;
    stud_name.push_back(name);

    double grade;
    cout << "What is the student's midterm grade? ";
    cin >> grade;
    mid_grade.push_back(grade);

    cout << "What is the student's final grade? ";
    cin >> grade;
    final_grade.push_back(grade);

    int sum = 0;
    int count = 0;
    cout << "Please list the student's homework grades: ";
    for(int i = 0; i < num_hw; ++i) {
      cin >> grade;
      sum += grade;
      count++;
    }
    homework_grade.push_back(sum / count);

    cout << "Is there another student? (y/n) ";
    cin >> test;
  }

  // Print result
  for(int i = 0; i < stud_name.size(); ++i) {
    cout << "Student: " << stud_name[i] << " Final Grade: "
         << 0.2 * mid_grade[i] + 0.4 * final_grade[i] + 0.4 * homework_grade[i]
         << endl;
  }

  return 0;
}
