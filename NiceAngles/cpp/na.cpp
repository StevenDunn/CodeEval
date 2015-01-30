// nice angles cpp soln for code eval by steven a dunn

#include <cmath>
#include <cstdio>
#include <cstdlib>
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
            float angle = atof(line.c_str());
            int full_degree = floor(angle);
            float remaining_angle = angle - full_degree;
            int minutes = floor(remaining_angle * 60);
            int seconds = floor(((remaining_angle * 60) - minutes) * 60);
            printf("%d.%02d'%02d\"\n", full_degree, minutes, seconds);
        }
        input_file.close();
    }

    return 0;
}