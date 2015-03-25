// roman and arabic soln in cpp for code eval by steven a dunn

#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>

#include <iostream>
using std::cout;
using std::endl;

using std::ifstream;
using std::string;
using std::vector;

int convert(string);
int roman_to_arabic(char);
bool greater(char, char);
int calculate(vector<int>, vector<string>);

int convert(string pair)
{
    int a = pair[0] - '0';
    int r = roman_to_arabic(pair[1]);
    return a * r;
}

int roman_to_arabic(char num)
{
    int result = 0;
    if (num == 'I')
     result = 1;
    else if (num == 'V')
        result = 5;
    else if (num == 'X')
        result = 10;
    else if (num == 'L')
        result = 50;
    else if (num == 'C')
        result = 100;
    else if (num == 'D')
        result = 500;
    else if (num == 'M')
        result = 1000;
    return result;
}

bool greater(char x, char y)
{
    int a = roman_to_arabic(x);
    int b = roman_to_arabic(y);
    return a > b;
}

int calculate(vector<int> digits, vector<string> pairs)
{
    int total = 0;
    char prev_r = pairs[0].back();
    for (int i = 0; i < digits.size(); ++i)
    {
        if (i == digits.size() - 1)
        {
            total += digits[i];
            continue;
        }
        char curr_r = pairs[i].back();
        char next_r = pairs[i+1].back();

        if (greater(next_r, curr_r))
            total -= digits[i];
        else
            total += digits[i];
    }
    return total;
}

int main (int argc, char* const argv[])
{
    ifstream input_file(argv[1]);
    string line;

    if (input_file)
    {
        while (getline(input_file, line))
        {
            vector<int> digits;
            vector<string> pairs;

            for (int i = 0; i < line.size(); i += 2)
            {
                string pair = line.substr(i, 2);
                pairs.push_back(pair);
                digits.push_back(convert(pair));
            }
            cout << calculate(digits, pairs) << endl;
        }
        input_file.close();
    }
    return 0;
}