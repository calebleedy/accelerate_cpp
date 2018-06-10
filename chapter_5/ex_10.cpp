#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

bool is_palindrone(string s)
{
  int length = s.size();
  for(int i = 0; i < length / 2; ++i) {
    if(s[i] != s[length - 1 - i]){
      return false;
    }
  }

  return true;

}

vector<string> get_palindrones(vector<string> s_vec)
{
  vector<string> ret;
  for(vector<string>::const_iterator it = s_vec.begin();
      it != s_vec.end(); ++it){
    if(is_palindrone(*it)){
      ret.push_back(*it);
    }
  }

  return ret;

}

int main()
{
  // Read words
  string s;
  vector<string> str_vec;
  cout << "Enter words: " << endl;
  while (cin >> s) {
    str_vec.push_back(s);
  }

  // Find palindrones
  vector<string> pals = get_palindrones(str_vec);
  

  // Print palindrones
  vector<string>::size_type maxlen = 0;
  int longest_index = 0;
  for(int i = 0; i < pals.size(); ++i){
    cout << pals[i] << endl;
    if (pals[i].size() > maxlen) {
      longest_index = i;
    }
  }

  // Print longest palindrone
  cout << "The longest palindrone is: " << pals[longest_index] << endl;

  return 0;
}
