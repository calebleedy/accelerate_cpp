#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "header.h"

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::sort;

int main()
{
  // Read lines
  vector<string> data;
  read_data(cin, data);

  // Permute data
  vector<line_split> permuted_data = rotate_data(data);

  // Sort data
  sort(permuted_data.begin(), permuted_data.end(), compare);

  // Print data
  print_data(permuted_data);

  return 0;
}
