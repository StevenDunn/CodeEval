// jolly jumpers soln in cpp for code eval by steven a dunn

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using std::ifstream;
using std::istringstream;
using std::sort;
using std::string;
using std::vector;

vector<int> tokenize(string);

int main (int argc, char* const argv[])
{
    ifstream input_file(argv[1]);
    string line;

    if (input_file)
    {
        while(getline(input_file, line))
        {
            vector<int> nums = tokenize(line);
            vector<int> abs_diffs;
            bool not_jolly = false;

            for (int i = 1; i < nums[0]; ++i)
                abs_diffs.push_back(abs(nums[i] - nums[i+1]));

            sort(abs_diffs.begin(), abs_diffs.end());

            for (int i = 0; i < nums[0] - 2; ++i)
                if (abs_diffs[i] == 0 || abs_diffs[i+1] > abs_diffs[i] + 1)
                {
                    not_jolly = true;
                    break;
                }

            if (not_jolly)
                puts("Not jolly");
            else
                puts("Jolly");
        }
        input_file.close();
    }
}

vector<int> tokenize(string input)
{
    vector<int> tokens;
    istringstream iss(input);
    string line;
    while(getline(iss, line, ' '))
        tokens.push_back(atoi(line.c_str()));
    return tokens;
}