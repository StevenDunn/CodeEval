// Gronsfeld Cipher soln in cpp for code eval by steven a dunn

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using std::find;
using std::ifstream;
using std::istringstream;
using std::string;
using std::stringstream;
using std::vector;

vector<string> alphabet = {" ", "!", "\"", "#", "$", "%", "&", "'", "(", ")", "*", "+", ",", "-", ".", "/", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", ":", "<", "=", ">", "?", "@", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};

vector<string> parse(string&);
string decrypt(string&, string&);

int main(int argc, char* argv[])
{
    ifstream input_file(argv[1]);
    string line;

    if (input_file)
    {
        while (getline(input_file, line))
        {
            vector<string> cipher_and_text = parse(line);
            printf("%s\n", decrypt(cipher_and_text[0], cipher_and_text[1]).c_str());
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
    printf("%s | %s \n", ciphertext.c_str(), cipher.c_str());
    while (cipher.size() < ciphertext.size())
        cipher = cipher + cipher;
    cipher = cipher.substr(0, ciphertext.size());

    string text("");
    for (int i = 0; i < ciphertext.size(); ++i)
    {
        string search_element;
        stringstream ss;
        ss << ciphertext[i];
        ss >> search_element;
        int location = find(alphabet.begin(), alphabet.end(), search_element) - alphabet.begin();
        int updated_location = location - (cipher[i] - '0');
        text += alphabet[updated_location];
        printf("%s", text.c_str());
    }
    return text;
}