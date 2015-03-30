// guess the number cpp soln for code eval by steven a dunn

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
using std::string;
using std::vector;

vector<string> parse(string);
void guess(int*, int*, string);
int get_midpoint(int, int);

int main (int argc, char* const argv[])
{
    ifstream input_file(argv[1]);
    string line;

    if (input_file)
    {
        while (getline(input_file, line))
        {
            vector<string> tokens = parse(line);
            int lower_bound = 0;
            int upper_bound = atoi(tokens[0].c_str());

            for (int guess_index = 1; guess_index < tokens.size(); ++guess_index)
                guess(&lower_bound, &upper_bound, tokens[guess_index]);
            cout << upper_bound << endl;
        }
        input_file.close();
    }
    return 0;
}

vector<string> parse(string line)
{
    vector<string> tokens;
    istringstream iss(line);
    string token;
    while (getline(iss, token, ' '))
        tokens.push_back(token);
    return tokens;
}

void guess(int* lower_bound, int* upper_bound, string guess_update)
{
    int midpoint = get_midpoint(*lower_bound, *upper_bound);
    if (guess_update == "Lower")
        *upper_bound = midpoint - 1;
    else if (guess_update == "Higher")
        *lower_bound = midpoint + 1;
    else
        *upper_bound = midpoint;
}

int get_midpoint(int lower_bound, int upper_bound)
{
    int midpoint = (upper_bound - lower_bound);
    if (midpoint % 2 == 0)
        midpoint /= 2;
    else
        midpoint = (midpoint + 1)/2;
    return lower_bound + midpoint;
}