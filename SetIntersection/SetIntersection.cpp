// Set Intersection solution in C++ for CodeEval.com by Steven A. Dunn

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

vector<int> getVector(stringstream&);
void sortVector(vector<int>&);

int main (int argc, char* argv[])
{
	ifstream inputFile (argv[1]);
	string line;
	
	if (inputFile)
	{
		while (getline (inputFile, line))
		{
			stringstream ss (line);	
			
			vector<int> tokens1 = getVector(ss);
			
			// dodge the semicolon that separates the lists
			ss.get();
			
			vector<int> tokens2 = getVector(ss);
			
			sortVector(tokens1);
			sortVector(tokens2);
			
			std::vector<int> intersect (tokens1.size());
			std::vector<int>::iterator it;
			it = std::set_intersection (tokens1.begin(), tokens1.end(), tokens2.begin(), tokens2.end(), intersect.begin());
			intersect.resize(it - intersect.begin());
			
			for (it = intersect.begin(); it != intersect.end(); ++it)
			{
				vector<int>::iterator peek = it;
				peek++;
				if (peek != intersect.end())
			    	cout << *it << ",";
				else
					cout << *it << endl;
			}
		} 
	}
}

vector<int> getVector(stringstream& ss)
{
	int i;
	vector<int> vec;
	while (ss >> i)
	{
		vec.push_back(i);
		if (ss.peek() == ',')
			ss.ignore();
		if (ss.peek() == ';')
			break;
	}
	return vec;
}

void sortVector(vector<int>& vec)
{
	sort (vec.begin(), vec.end());
}
