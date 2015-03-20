// Gronsfeld Cipher soln in cpp for code eval by steven a dunn

#include <algorithm>
#include <cstdio>
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
using std::string;
using std::stringstream;
using std::vector;

vector<char> alphabet = {' ', '!', '\"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', '<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

vector<string> parse(string&);
string decrypt(string&, string&);
int find(vector<char>, char);

int main(int argc, char* argv[])
{
    ifstream input_file(argv[1]);
    string line;

    if (input_file)
    {
        while (getline(input_file, line))
        {
            vector<string> cipher_and_text = parse(line);
            printf("%s\n", decrypt(cipher_and_text[1], cipher_and_text[0]).c_str());
        }
        input_file.close();
    }
    return 0;
}

vector<string> parse(string& input)
{
    vector<string> tokens;
    string line;
    istringstream iss(input);
    while (getline(iss, line, ';'))
        tokens.push_back(line);
    return tokens;
}

string decrypt(string& ciphertext, string& cipher)
{
    while (cipher.size() < ciphertext.size())
        cipher = cipher + cipher;
    cipher = cipher.substr(0, ciphertext.size());

    string text("");

    for (int i = 0; i < ciphertext.size(); ++i)
    {
        char* str;
        int location = find(alphabet, ciphertext[i]);
        int updated_location = location - (cipher[i] - '0');
        if (updated_location < 0)
            updated_location = alphabet.size() + updated_location;
        text += alphabet[updated_location];
    }
    return text;
}

int find(vector<char> alphabet, char element)
{
    for (int i = 0; i < alphabet.size(); ++i)
        if (element == alphabet[i])
            return i;
    return -1;
}