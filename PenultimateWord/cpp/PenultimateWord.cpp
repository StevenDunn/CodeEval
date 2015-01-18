// Penultimate Word solution in C++ for CodeEval.com by Steven A. Dunn

#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
  	ifstream inputFile(argv[1]);
	string line;

  	if(inputFile)
  	{
		while (getline(inputFile, line))
		{
			vector<string> words;
			stringstream ss(line);
		    copy(istream_iterator<string>(ss), 
		      istream_iterator<string>(), 
		      back_inserter<vector<string> >(words));
		
			cout << words[words.size() - 2] << endl;
		}
	}
}