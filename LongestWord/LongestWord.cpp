// Longest Word solution in C++ for CodeEval.com by Steven A. Dunn

#include <algorithm>
#include <iostream>
#include <fstream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

using std::back_inserter;
using std::copy;
using std::cout;
using std::endl;
using std::ifstream;
using std::istream_iterator;
using std::istringstream;
using std::string;
using std::vector;

string findLongestWord(string);
vector<string> getTokens(string);

int main(int argc, char* argv[])
{
	ifstream inputFile(argv[1]);
	string line;
	
	if(inputFile)
	{
		while(getline(inputFile, line))
			cout << findLongestWord(line) << endl;
		inputFile.close();
	}
	
	return 0;
}

string findLongestWord(string line)
{
	vector<string> words = getTokens(line);
	int maxLength = 0;
	string longestWord;
	for(int i = 0; i < words.size(); ++i)
	{
		if(words.at(i).size() > maxLength)
		{
			maxLength = words.at(i).size();
			longestWord = words.at(i);
		}
	}
	
	return longestWord;
}

vector<string> getTokens(string line)
{
  vector<string> tokens;
  istringstream iss(line);
  copy(
    istream_iterator<string>(iss),
    istream_iterator<string>(),
    back_inserter<vector<string> >(tokens));

  return tokens;
}