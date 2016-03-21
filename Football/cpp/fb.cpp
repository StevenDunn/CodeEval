// football soln in cpp for code eval by steven a dunn

#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::map;
using std::pair;
using std::string;
using std::vector;

vector<string> tokenize(string, char=' ');

int main (int argc, char* const argv[])
{
	ifstream input_file(argv[1]);
	string line;

	if (input_file)
	{
		while(getline(input_file, line))
		{
			vector<string> countries = tokenize(line, '|');
			map<int, vector<int> > fan_map;

			for (int i = 0; i < countries.size(); ++i)
			{
				vector<string> teams = tokenize(countries[i]);

				for (int j = 0; j < teams.size(); ++j)
				{
					int team_idx = atoi(teams[j].c_str()); 
					if (fan_map.find(team_idx) != fan_map.end() )
					{
						fan_map[team_idx].push_back(i+1);
					}
					else
					{
						vector<int> data;
						data.push_back(i+1);
						fan_map.insert( pair<int, vector<int> >(team_idx, data) );
					}
				}
			}
			for (map<int, vector<int> >::const_iterator it = fan_map.begin(); it != fan_map.end(); ++it)
			{
				cout << it -> first << ":";
				vector<int> test = it->second;
				for (int i = 0; i < test.size()-1; ++i)
					cout << test[i] << ",";
				cout << test[test.size()-1] << "; ";
			}
			cout << endl;
		}
		input_file.close();
	}
	return 0;
}

vector<string> tokenize(string line, char delim)
{
	vector<string> tokens;
	istringstream iss(line);
	string token;

	while (getline(iss, token, delim))
	{
		if (token[0] == ' ')
			token = token.substr(1);
		tokens.push_back(token);
	}
	return tokens;
}