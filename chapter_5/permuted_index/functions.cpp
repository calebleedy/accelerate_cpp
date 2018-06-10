#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include "header.h"

using std::vector;
using std::string;
using std::max;
using std::cout;
using std::endl;
using std::setw;

std::istream& read_data(std::istream& c, std::vector<std::string>& vec)
{
  string s;
  while (getline(c, s)) {
    vec.push_back(s);
  }

  return c;
}

/*
struct line_split {
  std::string prespace;
  std::string sorted_word;
};
*/
std::vector<line_split> rotate_data(const std::vector<std::string>& vec)
{
  vector<line_split> ret;

  for (vector<string>::const_iterator iter = vec.begin();
       iter != vec.end(); ++iter) {

    string::size_type i = 0;
    while(i != (*iter).size()) {
      while(i != (*iter).size() && isspace((*iter)[i])) {
        ++i;
      }
      string::size_type j = i;
      while(j != (*iter).size() && !isspace((*iter)[j])) {
        ++j;
      }
      if (i != j) {
        line_split val;
        val.prespace = (*iter).substr(0, i);
        val.sorted_word = (*iter).substr(i, (*iter).size());
        ret.push_back(val);
        i = j;
      }
    }
  }

  return ret;
}


bool compare(const line_split& x, const line_split& y)
{
  return x.sorted_word  < y.sorted_word;
}

void print_data(const std::vector<line_split>& vec)
{
  vector<line_split>::size_type maxlen = 0;
  for(vector<line_split>::const_iterator iter = vec.begin();
      iter != vec.end(); ++iter) {
    maxlen = max(maxlen, iter->prespace.size());
  }

  for(vector<line_split>::const_iterator iter = vec.begin();
      iter != vec.end(); ++iter) {
    cout << setw(maxlen) << iter->prespace << "    "
         << iter->sorted_word << endl;
  }
}

