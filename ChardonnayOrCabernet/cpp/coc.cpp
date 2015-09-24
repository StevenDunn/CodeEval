// charonnday or cabernet soln in cpp for code eval by steven a dunn

#include <algorithm>
#include <fstream>
#include <iostream>
#include <locale>
#include <sstream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::string;
using std::stringstream;
using std::transform;
using std::vector;

vector<string> tokenize(string, char);

int main (int argc, char* const argv[]) 
{
	ifstream input_file(argv[1]);
	string line;
	
	if (input_file)
	{
		while (getline(input_file, line))
		{
			vector<string> tokens = tokenize(line, '|');
			vector<string> wines = tokenize(tokens[0], ' ');
			string text = tokens[1];
			stringstream trimmer;
			trimmer << text;
			text.clear();
			trimmer >>text;
			
			transform(text.begin(), text.end(), text.begin(), tolower);
			
			vector<string> results;
			for (int i = 0; i < wines.size(); i++)
			{
				string wine = wines[i];
				string wine_cached = wines[i];
				transform(wine.begin(), wine.end(), wine.begin(), tolower);
				
				int textIdx = 0;
				for (int j = 0; j < wine.size(); j++)
					if (wine[j] == text[textIdx])
						++textIdx;
				
				if (textIdx == text.size())
					results.push_back(wine_cached);
			}
			
			if (results.size() == 0)
				cout << "FALSE" << endl;
			else
			{
				for (int i = 0; i < results.size(); i++)
				{
					cout << results[i] << " ";
				}
				cout << endl;
			}
		}
		input_file.close();
	}
	
	return 0;
}

vector<string> tokenize(string line, char delim)
{
	vector<string> tokens;
	istringstream iss(line);
	string buffer;
	
	while (getline(iss, buffer, delim))
		tokens.push_back(buffer);
	
	return tokens;
}
