// interrupted bubble sort soln in cpp for codeeval by steven a dunn

#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::istream_iterator;
using std::istringstream;
using std::string;
using std::stringstream;
using std::vector;

vector<int> split(string);
vector<int> bubble_sort(vector<int>, int);
string format(vector<int>);

vector<int> split(string line)
{
    istringstream iss(line);
    vector<string> tokens;
    copy(istream_iterator<string>(iss),
     istream_iterator<string>(),
     back_inserter(tokens));

    vector<int> nums;
    for (int i = 0; i < tokens.size(); ++i)
    {
        nums.push_back(atoi(tokens[i].c_str()));
    }
    return nums;
}

vector<int> bubble_sort(vector<int> vals, int steps)
{
    int n = 0;
    while (n < steps)
    {
        for (int i = 0; i < vals.size(); ++i)
        {
            int val = vals[i];
            if (i >= vals.size() - 1 - n)
            {
                continue;
            }
            int next_val = vals[i+1];
            if (next_val < val)
            {
                vals[i+1] = val;
                vals[i] = next_val;
            }
        }
        n += 1;
    }
    return vals;
}

string format(vector<int> vals)
{
    stringstream ss;
    for (int i = 0; i < vals.size(); ++i)
    {
        ss << vals[i] << " ";
    }
    return ss.str();
}

int main(int argc, char* argv[])
{
    ifstream input_file(argv[1]);
    string line;
    if (input_file)
    {
        while (getline(input_file, line))
        {
            vector<int>vals = split(line.substr(0, line.find('|')));
            int num = atoi(line.substr(line.find('|') + 2).c_str());

            cout << format(bubble_sort(vals, num)) << endl;
        }
        input_file.close();
    }
}