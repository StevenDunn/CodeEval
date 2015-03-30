// lost in translation cpp soln for code eval by steven a dunn

#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::map;
using std::string;
using std::vector;

map<char, char> cipher;

void init_cipher();
vector<char> tokenize(string);

int main (int argc, char* const argv[])
{
    ifstream input_file(argv[1]);
    string line;

    if (input_file)
    {
        init_cipher();
        while (getline(input_file, line))
        {
            vector<char> letters = tokenize(line);
            for (int i = 0; i < letters.size(); ++i)
                cout << cipher[letters[i]];
            cout << endl;
        }
        input_file.close();
    }

    return 0;
}

void init_cipher()
{
    cipher['y'] = 'a';
    cipher['n'] = 'b';
    cipher['f'] = 'c';
    cipher['i'] = 'd';
    cipher['c'] = 'e';
    cipher['w'] = 'f';
    cipher['l'] = 'g';
    cipher['b'] = 'h';
    cipher['k'] = 'i';
    cipher['u'] = 'j';
    cipher['o'] = 'k';
    cipher['m'] = 'l';
    cipher['x'] = 'm';
    cipher['s'] = 'n';
    cipher['e'] = 'o';
    cipher['v'] = 'p';
    cipher['z'] = 'q';
    cipher['p'] = 'r';
    cipher['d'] = 's';
    cipher['r'] = 't';
    cipher['j'] = 'u';
    cipher['g'] = 'v';
    cipher['t'] = 'w';
    cipher['h'] = 'x';
    cipher['a'] = 'y';
    cipher['q'] = 'z';
    cipher[' '] = ' ';
}

vector<char> tokenize(string line)
{
    vector<char> tokens;
    for (int i = 0; i < line.size(); ++i)
        tokens.push_back(line[i]);
    return tokens;
}