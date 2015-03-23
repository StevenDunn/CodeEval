// Cash Register solution in C++ for CodeEval.com by Steven A. Dunn

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::ostringstream;
using std::remove;
using std::string;
using std::vector;

void createChangeArrays();
void getChange(int);
int calculateChange(int, vector<int>&, int);
void printChange(vector<int>);

const int NUM_CHANGE_TYPES = 12;
vector<int> changeVals;
vector<string> changeTypes;

int main(int argc, char* argv[])
{
	ifstream inputFile(argv[1]);
	string line;
	
	if (inputFile)
	{
		while (getline(inputFile, line))
		{
			createChangeArrays();

			line.erase(remove(line.begin(), line.end(), ' '), line.end());
			
			int semicolonPos = line.find(";");
			double price = atof(line.substr(0, semicolonPos).c_str());
			double cash = atof(line.substr(semicolonPos + 1).c_str());
			
			getChange(ceil((cash - price) * 100));
		}
		inputFile.close();
	}
	
	return 0;
}

void createChangeArrays()
{
	changeTypes.push_back("ONE HUNDRED");
	changeVals.push_back(10000);
	
	changeTypes.push_back("FIFTY");
	changeVals.push_back(5000);
	
	changeTypes.push_back("TWENTY");
	changeVals.push_back(2000);
	
	changeTypes.push_back("TEN");
	changeVals.push_back(1000);
	
	changeTypes.push_back("FIVE");
	changeVals.push_back(500);
	
	changeTypes.push_back("TWO");
	changeVals.push_back(200);
	
	changeTypes.push_back("ONE");
	changeVals.push_back(100);
	
	changeTypes.push_back("HALF DOLLAR");
	changeVals.push_back(50);
	
	changeTypes.push_back("QUARTER");
	changeVals.push_back(25);
	
	changeTypes.push_back("DIME");
	changeVals.push_back(10);
	
	changeTypes.push_back("NICKEL");
	changeVals.push_back(5);
	
	changeTypes.push_back("PENNY");
	changeVals.push_back(1);	
}

void getChange(int change)
{
	if (change < 0)
		cout << "ERROR" << endl;
	else if (change == 0)
		cout << "ZERO" << endl;
	else
	{
		vector<int> changeTypesUsed(NUM_CHANGE_TYPES, 0);
		for (int i = 0; i < NUM_CHANGE_TYPES; ++i)
			change = calculateChange(change, changeTypesUsed, i);
		printChange(changeTypesUsed);
	}
}

int calculateChange(int change, vector<int>& changeTypesUsed, int idx)
{	
	if (change - changeVals[idx] >= 0)
	{
		while (change - changeVals[idx] >= 0)
			change -= changeVals[idx];
		changeTypesUsed[idx]++;
	}
	return change;
}

void printChange(vector<int> changeTypesUsed)
{
	ostringstream oss;
	for (int i = 0; i < NUM_CHANGE_TYPES; ++i)
		if (changeTypesUsed[i] > 0)
			oss << changeTypes[i] << ",";
	string result = oss.str();
	result = result.substr(0, result.size() -1 );
	cout << result << endl;
}