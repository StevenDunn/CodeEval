// Word Search solution in C++ for CodeEval.com by Steven A. Dunn

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::vector;

char grid[4][3];
bool visited[4][3];

// grid functions
void initGrid();
void clearGrid();
void clearGrid(int, int);
void markVisited(int, int);

// search functions
bool search(int, int, string);
vector<int> findContinuations(int, int, string);
bool upperMatches(int, int, char);
bool lowerMatches(int, int, char);
bool leftMatches(int, int, char);
bool rightMatches(int, int, char);
void updateIndices(int&, int&, int);

string doesWordExist(string);

enum directions{ UP, DOWN, LEFT, RIGHT };

int main(int argc, char* argv[])
{
	ifstream inputFile(argv[1]);
	string line;
	
	if(inputFile)
	{
		initGrid();
		while(getline(inputFile, line))
		{
			clearGrid();
			cout << doesWordExist(line) << endl;
		}
		inputFile.close();
	}
	return 0;
}

void initGrid()
{
	grid[0][0] = 'A';
	grid[0][1] = 'S';
	grid[0][2] = 'A';
	
	grid[1][0] = 'B';
	grid[1][1] = 'F';
	grid[1][2] = 'D';
	
	grid[2][0] = 'C';
	grid[2][1] = 'C';
	grid[2][2] = 'E';
	
	grid[3][0] = 'E';
	grid[3][1] = 'S';
	grid[3][2] = 'E';
}

void clearGrid()
{
	for(int i = 0; i < 4; ++i)
		for(int j = 0; j < 3; ++j)
			visited[i][j] = false;
}

void clearGrid(int i, int j)
{
	visited[i][j] = false;
}

void markVisited(int i, int j)
{
	visited[i][j] = true;
}

string doesWordExist(string line)
{
	char initChar = line.at(0);
	bool result = false;
	for(int i = 0; i < 4; ++i)
		for(int j = 0; j < 3; ++j)
		{
			if(grid[i][j] == initChar)
				result = search(i, j, line);
			if(result)
				return "True";
			clearGrid(i, j);
		}
			
	return "False";
} 

bool search(int i, int j, string line)
{
	markVisited(i, j);
	line = line.substr(1);
	if(line == "")
		return true;
	
	int originalI = i;
	int originalJ = j;
	vector<int> continuations = findContinuations(i, j, line);
	if(!continuations.empty())
	{
		for(int k = 0; k < continuations.size(); ++k)
		{
			updateIndices(i, j, continuations[k]);
			if(search(i, j, line))
				return true;
			clearGrid(i, j);
			i = originalI;
			j = originalJ;
		}
		return false;
	}
	else
		return false;
}

vector<int> findContinuations(int i, int j, string line)
{
	vector<int> continuations;
	char nextLetter = line.at(0);
	
	if(upperMatches(i, j, nextLetter))
		continuations.push_back(UP);
	if(lowerMatches(i, j, nextLetter))
		continuations.push_back(DOWN);
	if(leftMatches(i, j, nextLetter))
		continuations.push_back(LEFT);
	if(rightMatches(i, j, nextLetter))
		continuations.push_back(RIGHT);
	
	return continuations;
}

bool upperMatches(int i, int j, char letter) 
{
	if(j > 0 && grid[i][j - 1] == letter && visited[i][j - 1] == false)
			return true;
	else
		return false;
}

bool lowerMatches(int i, int j, char letter) 
{
	if(j < 2 && grid[i][j + 1] == letter && visited[i][j + 1] == false)
		return true;
	else
		return false;
}

bool leftMatches(int i, int j, char letter) 
{
	if(i > 0 && grid[i - 1][j] == letter && visited[i - 1][j] == false)
		return true;
	else
		return false;
}

bool rightMatches(int i, int j, char letter) 
{
	if(i < 3 && grid[i + 1][j] == letter && visited[i + 1][j] == false)
		return true;
	else
		return false;
}

void updateIndices(int& i, int& j, int continuation)
{
	if(continuation == UP) { j--; }
	else if(continuation == DOWN) { j++; }
	else if(continuation == LEFT) { i--; }
	else if(continuation == RIGHT) { i++; }
	else {}
	
	return;
}