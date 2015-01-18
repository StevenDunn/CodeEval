// Query Board solution in C++ for CodeEval.com by Steven A. Dunn

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<string> parseLine(string);
void initializeBoard();
void parseCommand(string, string, string);

int board[256][256];

int main(int argc, char* argv[])
{
	ifstream inputFile(argv[1]);
	string line;
	
	if (inputFile)
	{	
		initializeBoard();
		while (getline(inputFile, line))
		{
			vector<string> tokens = parseLine(line);
			string command = tokens[0];
			string param1 = tokens[1];
			string param2;
			if (tokens.size() > 2)
				param2 = tokens[2];
			else
				param2 = "";
			parseCommand(command, param1, param2);	
		}
		inputFile.close();
	}
}

void initializeBoard()
{
	for (int i = 0; i < 256; ++i)
		for(int j = 0; j < 256; ++j)
			board[i][j] = 0;
}

vector<string> parseLine(string line)
{
	istringstream iss(line);
	string s;
	vector<string> tokens;
	while (iss >> s)
	{
		tokens.push_back(s);
	}
	return tokens;	
}

void parseCommand(string command, string p1, string p2)
{
	int param1 = atoi(p1.c_str());
	int param2 = atoi(p2.c_str());
	int sum = 0;
	
	if (command == "SetRow") {
		for (int i = 0; i < 256; ++i)
			board[i][param1] = param2;
	}
	else if (command == "SetCol")
	{
		for (int j = 0; j < 256; ++j)
			board[param1][j] = param2;
	}
	else if (command == "QueryRow")
	{
		sum = 0;
		for (int i = 0; i < 256; ++i)
			sum += board[i][param1];
		cout << sum << endl;
	}
	else if (command == "QueryCol") 
	{
		sum = 0;
		for (int j = 0; j < 256; ++j)
			sum += board[param1][j];
		cout << sum << endl;
	}
}
