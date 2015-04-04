// number operations cpp soln for code eval by steven a dunn

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::find;
using std::ifstream;
using std::istringstream;
using std::next_permutation;
using std::sort;
using std::string;
using std::vector;

vector<int> parse(string);
bool doesSum(vector<int>);

int main (int argc, char* const argv[])
{
    ifstream input_file(argv[1]);
    string line;

    if (input_file)
    {
        while (getline(input_file, line))
        {
            vector<int> nums = parse(line);
            sort(nums.begin(), nums.end());
            bool isSum = false;
            do
            {
                if (doesSum(nums))
                {
                    isSum = true;
                    break;
                }
            }
            while(next_permutation(nums.begin(), nums.end()));

            if (isSum)
                cout << "YES";
            else
                cout << "NO";
            cout << endl;
        }
        input_file.close();
    }
    return 0;
}

vector<int> parse(string line)
{
    vector<int> tokens;
    istringstream iss(line);
    string token;
    while (getline(iss, token, ' '))
        tokens.push_back(atoi(token.c_str()));
    return tokens;
}

bool doesSum(vector<int> nums)
{
    vector<int> result;
    result.push_back(nums.back());
    nums.pop_back();

    while (nums.size() > 0)
    {
        int x = nums.back();
        nums.pop_back();
        vector<int> new_result;
        for (int i = 0; i < result.size(); ++i)
        {
            int val = result[i];

            int a = val + x;
            int b = val - x;
            int c = val * x;

            new_result.push_back(a);
            new_result.push_back(b);
            new_result.push_back(c);
        }
        result = new_result;
    }
    vector<int>::iterator it = find(result.begin(), result.end(), 42);
    if (it == result.end())
        return false;
    return true;
}