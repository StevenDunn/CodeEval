// Lowest Unique Number solution in C++ by Steven A. Dunn

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<int> getList(string);
vector<int> getSortedList(vector<int>);
int findLowestUnique(vector<int>, vector<int>);

int main(int argc, char* argv[])
{
	ifstream inputFile(argv[1]);
	string line;
	
	if (inputFile)
	{
		while (getline(inputFile, line))
		{
			vector<int> tokens = getList(line);
			vector<int> sortedList = getSortedList(tokens);
			int lowestUnique = findLowestUnique(tokens, sortedList);
			cout << lowestUnique << endl;	
		}
		inputFile.close();
	}
}

vector<int> getList(string line)
{
	stringstream ss (line);	
	int i;
	vector<int> tokens;
	while (ss >> i)
	{
		tokens.push_back(i);
		if (ss.peek() == ' ')
			ss.ignore();
	}
	return tokens;
}

vector<int> getSortedList(vector<int> vec)
{
	sort(vec.begin(), vec.end());
	return vec;
}

int findLowestUnique(vector<int> tokens, vector<int> sortedList)
{
	int result = 0;
	int count = 1;
	int lowestUnique = -1;
	if (sortedList.size() == 1)
		lowestUnique = tokens[0];
	else
	{
		for (int i = 0; i < sortedList.size(); ++i)
		{
			if (sortedList[i] == sortedList[i+1])
				++count;
			else
			{
				if (count == 1)
				{
					lowestUnique = sortedList[i];
					for (int i = 0; i < tokens.size(); ++i)
					{
						if (tokens[i] == lowestUnique)
							result = i + 1;
					}
					break;
				}
				count = 1;
			}
		}
		if (lowestUnique == -1)
			result = 0;
	}
	return result;	
}