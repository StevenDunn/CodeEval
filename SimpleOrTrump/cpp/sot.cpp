// simple or trump soln in cpp for code eval by steven a dunn

#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

vector<string> tokenize(string, char=' ');
int compare_hands(vector<string>, char);
int convert(string);

int main (int argc, char* const argv[])
{
	ifstream input_file(argv[1]);
	if (input_file)
	{
		string line;
		while (getline(input_file, line))
		{
			vector<string> tokens = tokenize(line, '|');
			string hands_tmp = tokens[0];
			char trump = tokens[1][1];
			vector<string> hands = tokenize(hands_tmp);
			int comp = compare_hands(hands, trump);
			if (comp < 0)
				printf("%s \n", hands[0].c_str());
			else if (comp > 0)
				printf("%s \n", hands[1].c_str());
			else
				printf("%s %s \n", hands[0].c_str(), hands[1].c_str());
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

	while(getline(iss, token, delim))
		tokens.push_back(token);

	return tokens;
}

int compare_hands(vector<string> hands, char trump)
{
	if (hands[0][hands[0].size()-1] != hands[1][hands[1].size()-1])
	{
		for (int idx = 0; idx < hands.size(); ++idx)
		{
			string hand = hands[idx];
			if (hand[hand.size()-1] == trump)
			{
				hands[idx][0] = 'T';
			}
		}
	}
	int val_1 = convert(hands[0].substr(0, hands[0].size()-1));
	int val_2 = convert(hands[1].substr(0, hands[1].size()-1));
	if (val_1 > val_2)
		return -1;
	else if (val_1 < val_2)
		return 1;
	return 0;
}

int convert(string val)
{
	if (val == "T")
		return 15;
	if (val == "A")
		return 14;
	if (val == "K")
		return 13;
	if (val == "Q")
		return 12;
	if (val == "J")
		return 11;
	return atoi(val.c_str());
}