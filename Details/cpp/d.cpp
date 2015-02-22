// Details cpp soln by Steven A Dunn for Code Eval

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::count;
using std::cout;
using std::distance;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::min_element;
using std::string;
using std::vector;

vector<string> tokenize(const string&);

int main (int argc, char* argv[])
{
    ifstream input_file(argv[1]);
    string line;

    if (input_file)
    {
        while (getline(input_file, line))
        {
            vector<string> entries = tokenize(line);
            vector<int> dots;
            for (int i = 0; i < entries.size(); ++i)
            {
                string entry = entries[i];
                if (entry == "XYYYY.Y")
                    entry = "XYYYYYY";
                dots.push_back(count(entry.begin(), entry.end(), '.'));
            }
            cout << dots[distance(dots.begin(), min_element(dots.begin(), dots.end()))] << endl;
        }
        input_file.close();
    }
    return 0;
}

vector<string> tokenize(const string& line)
{
    istringstream iss(line);
    string buffer;
    vector<string> tokens;
    while(getline(iss, buffer, ','))
        tokens.push_back(buffer);
    return tokens;
}