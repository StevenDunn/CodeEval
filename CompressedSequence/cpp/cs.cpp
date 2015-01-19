// Compressed Sequence C++ solution for Code Eval by Steven A Dunn

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::stringstream;
using std::to_string;
using std::vector;

void print_compressed_sequence(string);
vector<int> tokenize(string);

int main(int argc, char* argv[])
{
    ifstream input_file(argv[1]);
    string line;

    if (input_file)
    {
        while (getline(input_file, line))
            print_compressed_sequence(line);
        input_file.close();
    }

    return 0;
}

void print_compressed_sequence(string line)
{
    vector<int> tokens = tokenize(line);
    int count = 0;
    int n = tokens[0];
    for (int i = 0; i < tokens.size(); ++i)
    {
        if (tokens[i] == n)
            count++;
        else
        {
            cout << count << " " << n << " ";
            count = 1;
            n = tokens[i];
        }
    }
    cout << to_string(count) << " " << n << " " << endl;
}

vector<int> tokenize(string line)
{
    stringstream ss(line);
    string s;
    vector<int> tokens;

    while (getline(ss, s, ' '))
        tokens.push_back(atoi(s.c_str()));

    return tokens;
}