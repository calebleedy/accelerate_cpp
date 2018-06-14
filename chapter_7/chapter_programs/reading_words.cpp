#include <string>
#include <iostream>
#include <map>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::map;

int main()
{
  string s;
  map<string, int> counters;

  while (cin >> s) {
    ++counters[s];
  }

  for (map<string, int>::const_iterator it = counters.begin();
      it != counters.end(); ++it) {
    cout << it->first << "   " << it->second << endl;
  }
  return 0;
}

