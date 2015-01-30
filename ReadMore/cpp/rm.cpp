// read more cpp soln for code eval by steven a dunn

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
            int line_length = line.size();
            if (line_length > 55)
            {
                line = line.substr(0, 40);
                int last_space = line.find_last_of(" ");
                if (last_space != -1)
                    line = line.substr(0, last_space);
                line += "... <Read More>";
            }
            cout << line << endl;
        }
        input_file.close();
    }
    return 0;
}