// strings and arrows soln in cpp for code eval by steven a dunn

#include <fstream>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;

int main (int argc, char* const argv[]) {
  ifstream input_file(argv[1]);
  string line;
  if (input_file) {
    while (getline(input_file, line)) {
      int total = 0;
      for (int i = 0; i <= line.size() - 5; i++) {
        string sub = line.substr(i, 5);
        if (sub == "<--<<" || sub == ">>-->")
          total++;
      }
      cout << total << endl;
    }
    input_file.close();
  }
  return 0;
}