#include <vector>
#include <list>
#include <string>
#include <cctype>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using std::list;
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::domain_error;
using std::max;

vector<string> split(const string& s)
{
  vector<string> ret;
  typedef string::size_type string_size;
  string_size i = 0;

  while (i != s.size()) {
    while (i != s.size() && isspace(s[i])) {
      ++i;
    }

    string_size j = i;
    while (j != s.size() && !isspace(s[j])) {
      ++j;
    }

    if (i != j) {
      ret.push_back(s.substr(i, j - i));
      i = j;
    }
  }
  return ret;
}

string::size_type width(const vector<string>& v) 
{
  string::size_type maxlen = 0;
  for (vector<string>::size_type i = 0; i != v.size(); ++i)
  {
    maxlen = std::max(maxlen, v[i].size());
  }
  return maxlen;
}

vector<string> frame(const vector<string>& v)
{
  vector<string> ret;
  string::size_type maxlen = width(v);
  string border(maxlen + 4, '*');

  ret.push_back(border);

  for (vector<string>::const_iterator it = v.begin();
      it != v.end(); ++it) {
    ret.push_back("* " + *it + string(maxlen - (*it).size(), ' ') + " *");
  }

  ret.push_back(border);
  return ret;
}

vector<string> vcat(const vector<string>& top, const vector<string>& bottom)
{
  vector<string> ret = top;

  ret.insert(ret.end(), bottom.begin(), bottom.end());

  return ret;
}

vector<string> hcat(const vector<string>& left, const vector<string>& right)
{
  vector<string> ret;

  string::size_type width1 = width(left) + 1;
  
  vector<string>::const_iterator it = left.begin(), jt = right.begin();

  while(it != left.end() || jt != right.end()) {

    string s;
    if (it != left.end()) {
      s = *it++;
    }

    s += string(width1 - s.size(), ' ');

    if (jt != right.end()) {
      s += *jt++;
    }

    ret.push_back(s);
  }

  return ret;
}

int main()
{
  // Read some strings
  string s;
  while (getline(cin, s)) {
    vector<string> v = split(s);

    for(vector<string>::iterator iter = v.begin(); iter != v.end(); ++iter) {
      cout << *iter << endl;
    }
  }

  cout << "Frame strings" << endl;
  cin.clear();

  // Read some more strings
  string s2;
  vector<string> str_vec;
  while (getline(cin, s2)) {
    str_vec.push_back(s2);
  }

  vector<string> framed_str_vec = frame(str_vec);
  vector<string> final_str = vcat(hcat(str_vec, framed_str_vec), framed_str_vec);

  for(vector<string>::iterator iter = final_str.begin();
      iter != final_str.end(); ++iter) {
    cout << *iter << endl;
  }

  return 0;
}
