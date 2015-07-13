// stepwise word soln in cpp for code eval by steven a dunn

#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::sort;
using std::string;
using std::vector;

vector<string> parse(string line) {
  if (line[line.size()-1] == '\r' || line[line.size()-1] == '\n')
    line = line.substr(0, line.size() - 1);
  vector<string> tokens;
  istringstream iss(line);
  while (getline(iss, line, ' '))
    tokens.push_back(line);
  return tokens;
}

bool compare(const string& a, const string& b) {
  return a.size() < b.size();
}

vector<string> get_longest_tokens(const vector<string>& tokens, const int& max_length) {
  vector<string> longest_tokens;
  for (int i = 0; i < tokens.size(); i++)
    if (tokens[i].size() == max_length)
      longest_tokens.push_back(tokens[i]);
  return longest_tokens;
}

int main (int argc, char* const argv[]) {
  ifstream input_file(argv[1]);
  string line;

  if (input_file) {
    while (getline(input_file, line)) {
      vector<string> tokens = parse(line);
      sort(tokens.begin(), tokens.end(), compare);

      string longest = tokens.back();
      int max_length = longest.size();
      vector<string> longest_tokens = get_longest_tokens(tokens, max_length);

      longest = longest_tokens.front();
      for (int i = 0; i < longest.size(); i++) {
        for (int j = 0; j < i; j++)
          cout << '*';
        cout << longest[i] << ' ';
      }
      cout << endl;
    }
    input_file.close();
  }
  return 0;
}

