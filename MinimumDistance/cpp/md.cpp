// minimum distance soln in cpp for code eval by steven a dunn

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::sort;
using std::string;
using std::vector;

vector<int> parse(string&);
long get_distance(const vector<int>&, const long&);

int main (int argc, char* const argv[])
{
    ifstream input_file(argv[1]);
    string line;

    if (input_file)
    {
        while (getline(input_file, line))
        {
            vector<int> addresses = parse(line);
            sort(addresses.begin(), addresses.end());
            int min_address = addresses[0];
            int max_address = addresses.back();
            long min_distance = 500000;
            for (long i = min_address; i <= max_address; ++i)
            {
                long distance = get_distance(addresses, i);
                if (distance < min_distance)
                    min_distance = distance;
            }
            cout << min_distance << endl;
        }
        input_file.close();
    }
    return 0;
}

vector<int> parse(string& line)
{
    vector<int> tokens;
    istringstream iss(line);
    string token;
    getline(iss, token, ' ');
    while (getline(iss, token, ' '))
        tokens.push_back(atoi(token.c_str()));
    return tokens;
}

long get_distance(const vector<int>& addresses, const long& index)
{
    long distance = 0;
    for (int i = 0; i < addresses.size(); ++i)
        distance += abs(addresses[i] - index);
    return distance;
}