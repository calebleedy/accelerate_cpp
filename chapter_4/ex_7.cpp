#include <iostream>
#include <vector>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

double mean(vector<double> vec) {
  vector<double>::size_type size = vec.size();

  if (size == 0) {
    throw std::domain_error("Domain Error: To take the mean of a vector, the vector must have a size of at least one.");
  }

  double sum = 0;
  for(vector<double>::size_type i = 0; i < size; ++i) {
    sum += vec[i];
  }
  
  return sum / size;
}

int main() {

  // Read the input
  cout << "Input doubles for which to find the mean: ";
  double d;
  vector<double> vec;
  while(cin >> d) {
    vec.push_back(d);
  }

  try {
    d = mean(vec);
  } catch (std::domain_error e) {
    cout << e.what() << endl;
    return 1;
  }

  cout << "The average is " << d << endl;

  return 0;

}

