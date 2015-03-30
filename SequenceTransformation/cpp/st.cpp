// sequence transformation soln in cpp for codeeval by steven a dunn

#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::regex;
using std::regex_match;
using std::string;
using std::stringstream;
using std::vector;

string is_sequence_transformation(string, string);
string stringify(vector<string>);

string stringify(vector<string> vec)
{
    stringstream ss;
    for (int i = 0; i < vec.size(); ++i)
    {
        ss << vec[i];
    }
    return ss.str();
}

string is_sequence_transformation(string binary, string text)
{
    const string ZERO_REGEX = "A+";
    const string ONE_REGEX = "(A+|B+)";
    vector<string> regex_vec;

    for (int binary_idx = 0; binary_idx < binary.length(); ++binary_idx)
    {
        (binary[binary_idx] == '0') ? regex_vec.push_back(ZERO_REGEX) : regex_vec.push_back(ONE_REGEX);
    }

    string text_regex = stringify(regex_vec);

    regex reg(text_regex);
    string result;
    regex_match(text, reg) ? result = "Yes" : result = "No";

    return result;
}

int main(int argc, char* argv[])
{
    ifstream inputFile(argv[1]);
    string line;

    if (inputFile)
    {
        while (getline(inputFile, line))
        {
            string binary = line.substr(0, line.find(" "));
            string text = line.substr(line.find(" ") + 1);
            cout << is_sequence_transformation(binary, text) << endl;
        }
        inputFile.close();
    }
    return 0;
}