// racing chars cpp soln by steven a dunn for code eval

#include <fstream>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;

char update_direction(int, int);

int main(int argc, char* argv[])
{
    ifstream input_file(argv[1]);
    string line;

    if (input_file)
    {
        char direction = '|';
        int prev = -1;
        while (getline(input_file, line))
        {
            int gate_index = line.find('_');
            if (prev == -1)
                prev = gate_index;

            int checkpoint_index = line.find('C');
            if (checkpoint_index == string::npos)
            {
                direction = update_direction(prev, gate_index);
                line[gate_index] = direction;
                prev = gate_index;
            }
            else
            {
                direction = update_direction(prev, checkpoint_index);
                line[checkpoint_index] = direction;
                prev = checkpoint_index;
            }
            cout << line << endl;
        }
        input_file.close();
    }
    return 0;
}

char update_direction(int prev, int index)
{
    char direction;
    if (index < prev)
        direction = '/';
    else if (index == prev)
        direction = '|';
    else
        direction = '\\';
    return direction;
}