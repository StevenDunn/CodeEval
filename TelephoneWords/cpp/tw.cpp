// telephone words cpp soln for code eval by steven a dunn

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::reverse;
using std::sort;
using std::string;
using std::vector;

vector<string> convert(char);
vector<string> concat(vector<string>, string);

int main (int argc, char* const argv[])
{
    ifstream input_file(argv[1]);
    string line;

    if (input_file)
    {
        while (getline(input_file, line))
        {
            reverse(line.begin(), line.end());
            vector<char> digits;
            for (int i = 0; i < line.size(); ++i)
                digits.push_back(line[i]);
            char digit = digits.back();
            digits.pop_back();

            vector<string> results;
            vector<string> converted_digit = convert(digit);
            for (int i = 0; i < converted_digit.size(); ++i)
                results.push_back(converted_digit[i]);

            while (digits.size() > 0)
            {
                digit = digits.back();
                digits.pop_back();
                converted_digit = convert(digit);
                vector<string> new_result;
                for (int i = 0; i < converted_digit.size(); ++i)
                {
                    vector<string> concatted = concat(results, converted_digit[i]);
                    for (int j = 0; j < concatted.size(); ++j)
                        new_result.push_back(concatted[j]);
                }
                results = new_result;
            }
            sort(results.begin(), results.end());
            for (int i = 0; i < results.size() - 1; ++i)
                cout << results[i] << ",";
            cout << results.back() << endl;
        }
        input_file.close();
    }
    return 0;
}

vector<string> convert(char digit)
{
    vector<string> result;

    if (digit == '0')
        result.push_back("0");
    if (digit == '1')
        result.push_back("1");
    if (digit == '2')
    {
        result.push_back("a");
        result.push_back("b");
        result.push_back("c");
    }
    if (digit == '3')
    {
        result.push_back("d");
        result.push_back("e");
        result.push_back("f");
    }
    if (digit == '4')
    {
        result.push_back("g");
        result.push_back("h");
        result.push_back("i");
    }
    if (digit == '5')
    {
        result.push_back("j");
        result.push_back("k");
        result.push_back("l");
    }
    if (digit == '6')
    {
        result.push_back("m");
        result.push_back("n");
        result.push_back("o");
    }
    if (digit == '7')
    {
        result.push_back("p");
        result.push_back("q");
        result.push_back("r");
        result.push_back("s");
    }
    if (digit == '8')
    {
        result.push_back("t");
        result.push_back("u");
        result.push_back("v");
    }
    if (digit == '9')
    {
        result.push_back("w");
        result.push_back("x");
        result.push_back("y");
        result.push_back("z");
    }

    return result;
}

vector<string> concat(vector<string> list, string new_val)
{
    vector<string> concatted;
    for (int i = 0; i < list.size(); ++i)
        concatted.push_back(list[i] + new_val);
    return concatted;
}