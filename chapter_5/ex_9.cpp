#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

vector<string> sort_words(vector<string> s)
{
  vector<string> lower;
  vector<string> upper;

  for(vector<string>::const_iterator iter = s.begin(); iter != s.end(); ++iter){
    if (isupper((*iter)[0])) {
      upper.push_back(*iter);
    } else {
      lower.push_back(*iter);
    }
  }

  lower.insert(lower.end(), upper.begin(), upper.end());
  return lower;

}

int main() 
{
  // Read words
  string s;
  vector<string> str_vec;
  cout << "Enter words to sort: " << endl;
  while (cin >> s) {
    str_vec.push_back(s);
  }

  str_vec = sort_words(str_vec);

  for(vector<string>::const_iterator iter = str_vec.begin();
      iter != str_vec.end(); ++iter) {
    cout << *iter << endl;
  }

  return 0;
}



