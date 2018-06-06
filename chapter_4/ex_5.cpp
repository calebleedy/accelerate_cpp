#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int main() {

  // Read input
  vector<string> words;
  string x;
  while (cin >> x) {
    words.push_back(x);
  }

  cout << "The total number of words is " << words.size() << endl;

  vector<string> unique_words;
  vector<int> word_count;
  int maxlen = 0;

  unique_words.push_back(words[0]);
  word_count.push_back(1);

  for(int i = 1; i < words.size(); ++i) {
  bool updated = false;
    for(int j = 0; j < unique_words.size(); ++j){
      if (words[i] == unique_words[j]) {
        word_count[j]++;
        updated = true;
      }
    }

    maxlen = std::max(maxlen, (int) words[i].size());

    if (!updated) {
      unique_words.push_back(words[i]);
      word_count.push_back(1);
    }
  }

  for (int i = 0; i < unique_words.size(); ++i) {
    string spaces(maxlen + 1 - unique_words[i].size(), ' ');
    cout << unique_words[i] << spaces << word_count[i] << endl;
  }

  return 0;
}

