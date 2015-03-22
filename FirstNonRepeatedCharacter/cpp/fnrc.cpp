// First Non-Repeated Character solution in C++ for CodeEval.com by Steven A. Dunn

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::vector;

bool contains(vector<char>, char);

int main(int argc, char* argv[])
{
	ifstream inputFile(argv[1]);
	string line;
	
	if (inputFile)
	{
		while (getline(inputFile, line))
		{
			vector<char> visited;
			vector<char> multiples;
			int idx = -1;
			for (int i = 0; i < line.size(); ++i)
			{
				char charAt = line.at(i);
				if (!contains(visited, charAt))
					visited.push_back(charAt);
				else if (!contains(multiples, charAt))
					multiples.push_back(charAt);
				
				idx = line.size();
				for (int i = 0; i < visited.size(); ++i)
				{
					if (contains(multiples, visited[i]))
						continue;
					int indexOfChar = line.find(visited[i]);
					if (indexOfChar < idx)
						idx = indexOfChar;
				}
			}
			cout << line.at(idx) << endl;
		}
		inputFile.close();
	}
	return 0;
}

bool contains(vector<char> vec, char val)
{
	for (int i = 0; i < vec.size(); ++i)
		if (vec[i] == val)
			return true;
	return false;
}