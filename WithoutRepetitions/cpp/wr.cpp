// Without Repetitions soln in cpp for code eval by steven a dunn

#include <fstream>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;

int main(int argc, char* argv[])
{
    ifstream input_file(argv[1]);
    string line;

    if (input_file)
    {
        while (getline(input_file, line))
        {
            string new_line = "";
            if (line.size() == 1)
            {
                cout << line << endl;
                continue;
            }
            else
            {
                int x = 0;
                int y = 1;

                while (y < line.size())
                {
                    if (line[x] != line[y])
                    {
                        new_line += line[x];
                        if (y == line.size() - 1)
                            new_line += line[y];
                    }
                    else
                    {
                        if (y == line.size() - 1)
                            new_line += line[x];
                    }
                    x += 1;
                    y += 1;
                }
                cout << new_line << endl;
            }
        }
        input_file.close();
    }
    return 0;
}

/*
# needless repetitions soln in py for codeeval by steven a dunn

import sys

f = open(sys.argv[1], 'r')

for line in f:
    line = line.strip()
    new_line = ""
    #print line
    #print len(line)
    if len(line) == 1:
        print line
        continue
    else:
        x = 0
        y = 1

        while y < len(line):
            #print line[x], line[y]
            if line[x] != line[y]:
                new_line += line[x]
                if y == len(line) - 1:
                    new_line += line[y]
            else:
                if y == len(line) - 1:
                    new_line += line[x]

            x += 1
            y += 1

        print new_line

f.close()

*/