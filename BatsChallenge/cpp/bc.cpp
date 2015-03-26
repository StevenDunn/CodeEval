// bats challenge cpp soln for code eval by steven a dunn

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
using std::istringstream;
using std::sort;
using std::string;
using std::vector;

vector<int> tokenize(string);
bool too_close(int, vector<int>, int);

int main (int argc, char* const argv[])
{
    ifstream input_file(argv[1]);
    string line;

    if (input_file)
    {
        while (getline(input_file, line))
        {
            vector<int> tokens = tokenize(line);
            int length = tokens[0] - 6;
            int spacing = tokens[1];
            vector<int> bats(tokens.begin() + 3, tokens.end());
            sort(bats.begin(), bats.end());

            int new_bats = 0;
            for (int spot = 6; spot < length + 1; spot++)
                if (!too_close(spot, bats, spacing))
                {
                    new_bats++;
                    bats.push_back(spot);
                }
            cout << new_bats << endl;
        }
        input_file.close();
    }
    return 0;
}

vector<int> tokenize(string input)
{
    vector<int> tokens;
    istringstream iss(input);
    string line;
    while (getline(iss, line, ' '))
        tokens.push_back(atoi(line.c_str()));
    return tokens;
}

bool too_close(int spot, vector<int> bats, int spacing)
{
    for (int i = 0; i < bats.size(); ++i)
        if (abs(spot - bats[i]) < spacing)
            return true;
    return false;
}