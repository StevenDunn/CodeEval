// card number validation soln in cpp for code eval by steven a dunn

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::ifstream;
using std::remove;
using std::reverse;
using std::string;

int main (int argc, char* const argv[])
{
    ifstream input_file(argv[1]);
    string line;

    if (input_file)
    {
        while (getline(input_file, line))
        {
            reverse(line.begin(), line.end());
            line.erase(remove(line.begin(), line.end(), ' '), line.end());

            int sum = 0;
            for (int i = 0; i < line.size(); ++i)
            {
                int digit = line[i] - '0';
                if ((i + 1) % 2 == 0)
                {
                    digit *= 2;
                    if (digit > 9)
                    {
                        int digit_1 = digit / 10;
                        int digit_2 = digit % 10;
                        digit = digit_1 + digit_2;
                    }
                }
                sum += digit;
            }
            if (sum % 10 == 0)
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }
        input_file.close();
    }
    return 0;
}