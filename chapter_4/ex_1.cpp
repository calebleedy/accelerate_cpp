#include "Student_info.h"
#include <algorithm>

int main() {

  int maxlen;
  Student_info s;
  std::cout << std::max(s.name.size(),(std::string::size_type) maxlen) << std::endl;

  return 0;
}
