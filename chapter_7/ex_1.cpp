#include <string>
#include <iostream>
#include <map>
#include <algorithm>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::map;
using std::max;

int main()
{
  string s;
  map<string, int> counters;

  while (cin >> s) {
    ++counters[s];
  }

  int max_count = 0;
  // get max_count
  for (map<string, int>::const_iterator it = counters.begin();
      it != counters.end(); ++it) {
    max_count = max(max_count, it->second);
  }

  for (int i = 1; i <= max_count; ++i) {
    for (map<string, int>::const_iterator it = counters.begin();
        it != counters.end(); ++it) {
      if (it->second == i) {
        cout << it->first << "   " << it->second << endl;
      }
    }
  }
  return 0;
}

