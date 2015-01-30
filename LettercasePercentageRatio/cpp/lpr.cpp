// lettercase percentage ratio soln in cpp for codeeval by steven a dunn

#include <cctype>
#include <cstdio>
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
            int upper_count = 0, lower_count = 0;
            for (int i = 0; i < line.size(); ++i)
            {
                char c = line[i];
                if (isupper(c))
                    upper_count++;
                else if (islower(c))
                    lower_count++;
            }
            int total_count = upper_count + lower_count;
            float upper_percent = ((float)upper_count / total_count) * 100.0;
            float lower_percent = ((float)lower_count / total_count) * 100.0;

            printf("lowercase: %.2f uppercase: %.2f \n", lower_percent, upper_percent);
        }
        input_file.close();
    }
    return 0;
}