// Broken LCD cpp soln for Code Eval by Steven A Dunn

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
using std::to_string;
using std::vector;

// each display from 0 to 9, plus the decimal point, stored as decimals
int numbers[] = {252, 96, 218, 242, 102, 182, 190, 224, 254, 246, 1};

vector<string> tokenize(string, char);
string& rtrim(string&);

int main (int argc, char* const argv[])
{
    ifstream input_file(argv[1]);
    string line;

    if (input_file)
    {
        while (getline(input_file, line))
        {
            vector<string> tokens = tokenize(line, ';');
            vector<string> displays = tokenize(tokens[0], ' ');
            string number = tokens[1];

            vector<int> converted_numbers;
            for (int i = 0; i < number.size(); ++i)
            {
                char* c = &number[i];
                if (c[0] != '.')
                {
                    int x = number[i] - '0';
                    converted_numbers.push_back(numbers[x]);
                }
                else
                    converted_numbers[i-1] += 1;
            }

            bool did_print = false;
            for (int i = 0; i < displays.size() - converted_numbers.size() + 1; ++i)
            {
                int match = 0;
                for (int j = 0; j < converted_numbers.size(); ++j)
                {
                    char *str;
                    int converted_display = strtol (displays[i+j].c_str(), &str, 2);
                    if ((converted_display & converted_numbers[j]) != converted_numbers[j])
                        break;
                    else
                        match += 1;
                }
                if (match == converted_numbers.size())
                {
                    puts("1");
                    did_print = true;
                    break;
                }
            }
            if (!did_print)
                puts("0");

        }
        input_file.close();
    }
    return 0;
}

vector<string> tokenize(string input, char delim)
{
    vector<string> tokens;
    istringstream iss(input);
    string line;
    while (getline(iss, line, delim))
        tokens.push_back(line);
    return tokens;
}