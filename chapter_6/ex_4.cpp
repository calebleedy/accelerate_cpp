#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::copy;

int main()
{

  vector<int> u(10, 100);

  cout << "The u vector" << endl;
  for (vector<int>::const_iterator it = u.begin();
      it != u.end(); ++it) {
    cout << *it << endl;
  }

  vector<int> v;
  copy(u.begin(), u.end(), back_inserter(v));

  cout << "The v vector" << endl;

  for (vector<int>::const_iterator it = v.begin();
      it != v.end(); ++it) {
    cout << *it << endl;
  }

  vector<int> w = u;

  cout << "The w vector" << endl;

  for (vector<int>::const_iterator it = w.begin();
      it != w.end(); ++it) {
    cout << *it << endl;
  }

  return 0;
}
