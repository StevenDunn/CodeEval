// locks soln in cpp for code eval by steven a dunn

#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include <iostream>
using std::cout;
using std::endl;

using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;

bool OPEN = false;
bool CLOSED = true;

bool UNLOCKED = false;
bool LOCKED = true;

class Door
{
public:
    bool lock;
    bool door;

    Door();
    void close();
    void toggle_lock();
};

Door::Door()
{
    lock = UNLOCKED;
    door = OPEN;
}

void Door::close()
{
    lock = LOCKED;
    door = CLOSED;
}

void Door::toggle_lock()
{
    lock = !lock;
}

vector<int> parse(string input)
{
    vector<int> tokens;
    istringstream iss(input);
    string line;
    while (getline(iss, line, ' '))
        tokens.push_back(atoi(line.c_str()));
    return tokens;
}

int main (int argc, char* const argv[])
{
    ifstream input_file(argv[1]);
    string line;
    if (input_file)
    {
        while (getline(input_file, line))
        {
            vector<int> tokens = parse(line);
            int num_locks = tokens[0];
            int repetitions = tokens[1];

            vector<Door> locks(num_locks);
            for (int n = 0; n < repetitions-1; ++n)
                for (int x = 0; x < num_locks; ++x)
                {
                    if ((x+1) % 2 == 0)
                        locks[x].close();
                    if ((x+1) % 3 == 0)
                        locks[x].toggle_lock();
                }
            // final repetition
            locks.back().toggle_lock();

            int num_unlocked = 0;
            for (int i = 0; i < num_locks; ++i)
                if (locks[i].lock == UNLOCKED)
                    num_unlocked += 1;
            cout << num_unlocked << endl;
        }
        input_file.close();
    }

    return 0;
}