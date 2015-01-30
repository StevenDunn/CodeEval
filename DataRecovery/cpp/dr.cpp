// data recovery cpp soln for code eval by steven a dunn

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
using std::sort;
using std::string;
using std::vector;

vector<string> split(string, char);
vector<int> make_int(vector<string>);
int find_missing(vector<int>, int);

int main (int argc, char* argv[])
{
    ifstream input_file(argv[1]);
    string line;

    if (input_file)
    {
        while (getline(input_file, line))
        {
            vector<string> split_line = split(line, ';');
            vector<string> text = split(split_line[0], ' ');
            vector<int> indices = make_int(split(split_line[1], ' '));
            indices.push_back(find_missing(indices, text.size()));

            vector<int>::iterator it;
            for (int i = 1; i <= indices.size(); ++i)
            {
                it = find(indices.begin(), indices.end(), i);
                cout << text[it - indices.begin()] << " ";
            }
            cout << endl;
        }
        input_file.close();
    }
    return 0;
}

vector<string> split(string line, char delim)
{
    vector<string> split_line;
    istringstream iss(line);
    string s;
    while (getline(iss, s, delim)) {
        split_line.push_back(s);
    }
    return split_line;
}

vector<int> make_int(vector<string> s_vec)
{
    vector<int> i_vec;
    for (int i = 0; i < s_vec.size(); ++i)
        i_vec.push_back(atoi(s_vec[i].c_str()));
    return i_vec;
}

int find_missing(vector<int> vec, int text_size)
{
    int sum = 0;
    for (int i = 0; i < vec.size(); ++i)
        sum += vec[i];

    int expected_sum = text_size * (text_size + 1) / 2;
    return expected_sum - sum;
}