#include <map>
#include <algorithm>
#include <string>
#include <iterator>
#include <vector>

using std::map;
using std::string;
using std::back_inserter;
using std::copy;
using std::vector;

int main() 
{
  map<int, string> m;
  vector<int> x;
  vector<string> y;
  map<int, string> z;

  // copy(m.begin(), m.end(), back_inserter(x));
  copy(m.begin(), m.end(), back_inserter(y));
  // copy(m.begin(), m.end(), back_inserter(z));
  
  return 0;
}


