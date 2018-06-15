#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <iterator>

using std::domain_error;
using std::vector;
using std::string;
using std::sort;
using std::cin;
using std::cout;
using std::ostream_iterator;

template<class T> T median(vector<T> v)
{
  typedef typename vector<T>::size_type vec_sz;

  vec_sz size = v.size();
  if (size == 0) {
    throw domain_error("Median of an empty vector");
  }

  sort(v.begin(), v.end());

  vec_sz mid = size / 2;

  return size % 2 == 0 ? (v[mid] + v[mid - 1]) / 2 : v[mid];
}

template<class T> T max(const T& left, const T& right)
{
  return left > right ? left : right;
}

// Input iterator
template<class In, class X> In find(In begin, In end, const X& x)
{
  while (begin != end && *begin != x) {
    ++begin;
  }
  return begin;
}

// Output iterator
template<class In, class Out> Out copy(In begin, In end, Out dest)
{
  while (begin != end) {
    *dest++ = *begin++;
  }
  return dest;
}

// Forward iterator
template<class For, class X>
void replace(For beg, For end, const X& x, const X& y)
{
  while (beg != end) {
    if (*beg == x) {
      *beg = y;
    }
    ++beg;
  }
}

// Bidirectional iterator
template<class Bi> void reverse(Bi begin, Bi end)
{
  while (begin != end) {
    --end;
    if (begin != end) {
      swap(*begin++, *end);
    }
  }
}

// Ramdon access iterator
template<class Ran, class X> bool binary_search(Ran begin, Ran end, const X& x)
{
  while (begin < end) {
    Ran mid = begin + (end - begin) / 2;
    if (x < *mid) {
      end = mid;
    } else if (*mid < x) {
      begin = mid + 1;
    } else {
      return true;
    }
  }
  return false;
}

bool space(char c)
{
  return isspace(c);
}

bool not_space(char c)
{
  return !isspace(c);
}

template<class Out> void split(const string& str, Out os)
{
  typedef string::const_iterator iter;

  iter i = str.begin();
  while (i != str.end()) {
    i = find_if(i, str.end(), not_space);

    iter j = find_if(i, str.end(), space);

    if (i != str.end()) {
      *os++ = string(i, j);
    }

    i = j;
  }
}

int main()
{
  string s;
  while (getline(cin, s)) {
    split(s, ostream_iterator<string>(cout, "\n"));
  }
  return 0;
}
