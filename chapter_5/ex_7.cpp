#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;

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

  for (vector<string>::size_type i = 0; i != v.size(); ++i) {
    ret.push_back("* " + v[i] + string(maxlen - v[i].size(), ' ') + " *");
  }

  ret.push_back(border);
  return ret;
}

int main() 
{

  vector<string> v;
  frame(v);
  
  vector<string> final_str = frame(v);

  for(vector<string>::iterator iter = final_str.begin();
      iter != final_str.end(); ++iter) {
    cout << *iter << endl;
  }

  return 0;
}
