// brainfuck soln by steven a dunn for code eval

#include <cstdio>
#include <fstream>
#include <string>
#include <vector>

using std::ifstream;
using std::string;
using std::vector;

int find_start(string, int);
int find_end(string, int);

int main (int argc, char* const argv[])
{
	ifstream input_file(argv[1]);
	if (input_file)
	{
		string line;
		while (getline(input_file, line))
		{
			vector<int> cells(1, 0);
			int ptr = 0;
			int idx = 0;
			vector<int> result;
			while (idx < line.size())
			{
				char cur = line[idx];
				switch (cur)
				{
					case '.': 
						result.push_back(cells[ptr]);
						break;
					case '+':
						cells[ptr] += 1;
						cells[ptr] %= 255;
						break;
					case '-':
						cells[ptr] -= 1;
						cells[ptr] %= 255;
						break;
					case '>':
						++ptr;
						if (ptr >= cells.size())
							cells.push_back(0);
						break;
					case '<':
						--ptr;
						if (ptr < 0)
						{
							cells.insert(cells.begin(), 0);
							ptr = 0;
						}
						break;
					case '[':
						if (cells[ptr] == 0)
							idx = find_end(line, idx);
						break;
					case ']':
						if (cells[ptr] != 0)
							idx = find_start(line, idx);
						break;
				}
				++idx;
			}
			for (int i = 0; i < result.size(); ++i)
			{
				printf("%c", result[i]);
			}
			puts("");
		}
		input_file.close();
	}
	return 0;
}

int find_end(string line, int start)
{
	int count = 1;
	for (int i = start + 1; i < line.size(); ++i)
	{
		if (line[i] == '[')
			++count;
		else if (line[i] == ']')
		{
			--count;
			if (count == 0)
				return i;
		}
	}
	return line.size() - 1;
}

int find_start(string line, int end)
{
	int count = 1;
	for (int i = end - 1; i >= 0; --i)
	{
		if (line[i] == ']')
			++count;
		else if (line[i] == '[')
		{
			--count;
			if (count == 0)
				return i;
		}
	}
	return 0;
}
