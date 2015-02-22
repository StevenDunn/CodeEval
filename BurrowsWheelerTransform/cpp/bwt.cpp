// Burrows-Wheeler Transform cpp soln by Steven A Dunn for Code Eval

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::sort;
using std::string;
using std::vector;

vector<string> split(const string&);

int main (int argc, char* argv[])
{
    ifstream input_file(argv[1]);
    string line;

    if (input_file)
    {
        while (getline(input_file, line))
        {
            line = line.substr(0, line.find("|"));
            int N = line.size();
            vector<string> result(N, "");
            vector<string> sorted_result(N, "");
            vector<string> entry = split(line);

            for (int i = 0; i < N; ++i)
            {
                for (int i = 0; i < result.size(); ++i)
                {
                    int len = entry[i].size();
                    result[i] += entry[i][len-1];
                }
                sorted_result = result;
                sort(sorted_result.begin(), sorted_result.end());
                entry = sorted_result;
            }
            for (int i = 0; i < result.size(); ++i)
            {
                if (result[i].find("$") == result[i].size() - 1)
                {
                    cout << result[i] << endl;
                    break;
                }
            }
        }
        input_file.close();
    }
    return 0;
}

vector<string> split(const string& line)
{
    vector<string> split_line;
    for (int i = 0; i < line.size(); ++i)
        split_line.push_back(string(1, line[i]));
    return split_line;
}