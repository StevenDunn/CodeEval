// juggling with zeros cpp soln for code eval by steven a dunn

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::setbase;
using std::string;
using std::vector;

vector<string> tokenize(string);
string ones (string);
long to_decimal(string);

int main (int argc, char* argv[])
{
    ifstream input_file (argv[1]);
    string line;

    if (input_file)
    {
        while (getline(input_file, line))
        {
            vector<string> tokens = tokenize(line);
            string binary = "";
            for (int i = 0; i < tokens.size(); i = i + 2)
            {
                string flag = tokens[i];
                string seq = tokens[i+1];
                if (flag == "00")
                    binary += ones(seq);
                else
                    binary += seq;
            }
            cout << to_decimal(binary) << endl;
        }
        input_file.close();
    }

    return 0;
}

vector<string> tokenize (string line)
{
    vector<string> tokens;
    istringstream iss(line);
    string s;
    while (getline(iss, s, ' '))
        tokens.push_back(s);
    return tokens;
}

string ones (string seq)
{
    string result = "";
    for (int i = 0; i < seq.size(); ++i)
        result += "1";
    return result;
}

long to_decimal (string binary)
{
    int idx = 0;
    for (int i = 0; i < binary.size(); ++i)
    {
        if (binary[i] == '1')
        {
            idx = i;
            break;
        }
    }
    if (idx > 0)
        binary = binary.substr(idx-1);

    long result = 0;
    unsigned long power = 1;
    for (int i = binary.length() - 1; i >= 0; --i, power <<= 1)
        result += (binary[i] - '0') * power;

    return result;
}