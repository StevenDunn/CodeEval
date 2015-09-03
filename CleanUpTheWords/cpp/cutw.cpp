// clean up the words soln in cpp for code eval by steven a dunn

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::vector;

int main (int argc, char* const argv[]) {
	ifstream input_file(argv[1]);
	string line;

	if (input_file) {
		while (getline(input_file, line)) {
			cout << line << endl;
			string result;
			vector<string> words;
			for (int i = 0; i < line.size(); i++) {
				if (isalpha(line[i]))
					result += tolower(line[i]);
				else {
					words.push_back(result);
					result = "";
				}
			}
			if (result.size() > 0)
				words.push_back(result);
			
			for (int i = 0; i < words.size(); i++)
				if (words[i].size() > 0)
					cout << words[i] << " ";
			cout << endl;
		}
		input_file.close();
	}
	return 0;
}