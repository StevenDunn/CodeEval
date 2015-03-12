// roller coaster cpp soln for code eval by steven a dunn

#include <cctype>
#include <fstream>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;

int main (int argc, char* argv[])
{
    ifstream input_file(argv[1]);
    string line;

    if (input_file)
    {
        while (getline(input_file, line))
        {
            bool letter_case = true;
            string result = "";
            for (int i = 0; i < line.size(); ++i)
            {
                char c = line[i];
                if (isalpha(c))
                {
                    if (letter_case)
                        result += toupper(c);
                    else
                        result += tolower(c);
                    letter_case = !letter_case;
                }
                else
                    result += c;
            }
            cout << result << endl;
        }
    }

    return 0;
}