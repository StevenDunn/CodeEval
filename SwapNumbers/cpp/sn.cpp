// swap numbers cpp soln for code eval by steven a dunn

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::remove;
using std::string;
using std::vector;

vector<string> split(string);

int main (int argc, char* const argv[]) {
	ifstream input_file(argv[1]);
	string line;

	if (input_file) {
		while(getline(input_file, line)) {
			line.erase(remove(line.begin(), line.end(), '\n'), line.end());
			line.erase(remove(line.begin(), line.end(), '\r'), line.end());
			vector<string> words = split(line);
			for (int i = 0; i < words.size(); ++i) {
				string word = words[i];
				cout << word[word.size()-1] + 
						word.substr(1, word.size()-2) + 
						word[0] << " ";
			}
			cout << endl;
		}
		input_file.close();
	}
	return 0;
}

vector<string> split(string s) {
	vector<string> result;
	istringstream iss(s);
	string token;

	while(getline(iss, token, ' '))
		result.push_back(token);

	return result;
}