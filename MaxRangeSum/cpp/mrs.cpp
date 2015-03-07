// max range sum cpp soln for code eval by steven a dunn

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using std::ifstream;
using std::istringstream;
using std::replace;
using std::string;
using std::vector;

vector<int> split(string);
int get_sum(const int&, const int&, const vector<int>&);

int main (int argc, char* argv[])
{
    ifstream input_file(argv[1]);
    string line;

    if (input_file)
    {
        while (getline(input_file, line))
        {
            vector<int> tokens = split(line);
            int n = tokens[0];
            vector<int> values(tokens.begin()+1, tokens.end());

            int max_gain = -101;
            for (int i = 0; i < values.size() - n + 1; ++i)
            {
                int sum = get_sum(i, n, values);
                if (sum > max_gain)
                    max_gain = sum;
            }
            if (max_gain >= 0)
                printf("%d\n", max_gain);
            else
                printf("0\n");
        }
        input_file.close();
    }
    return 0;
}

vector<int> split(string line)
{
    replace(line.begin(), line.end(), ';', ' ');
    vector<int> tokens;
    istringstream iss(line);
    string token;
    while(getline(iss, token, ' '))
        tokens.push_back(atoi(token.c_str()));
    return tokens;
}

int get_sum(const int& start, const int& length, const vector<int>& vals)
{
    int sum = 0;
    for (int i = start; i < start + length; ++i)
        sum += vals[i];
    return sum;
}