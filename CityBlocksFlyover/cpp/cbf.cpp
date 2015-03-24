// city blocks flyover soln in cpp for code eval by steven a dunn

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using std::ifstream;
using std::istringstream;
using std::remove;
using std::pair;
using std::string;
using std::vector;

vector<string> tokenize(string);
vector<int> extract_numbers(string);
vector<pair<int, int>> zip(vector<int>, vector<int>, int);

int main (int argc, char* const argv[])
{
    ifstream input_file(argv[1]);
    string line;

    if (input_file)
    {
        while (getline(input_file, line))
        {
            vector<string> coordinates = tokenize(line);
            vector<int> x = extract_numbers(coordinates[0]);
            vector<int> y = extract_numbers(coordinates[1]);

            vector<int> x_sub(x.begin() + 1, x.end());
            vector<int> y_sub(y.begin() + 1, y.end());

            vector<pair<int, int>> xs = zip(x, x_sub, x_sub.size());
            vector<pair<int, int>> ys = zip(y, y_sub, y_sub.size());

            float m = y.back()/(float)(x.back());

            int total = 0;
            for (int i = 0; i < xs.size(); ++i)
                for (int j = 0; j < ys.size(); ++j)
                    if (!((m * xs[i].first >= ys[j].second) || (m * xs[i].second <= ys[j].first)))
                        total++;
            printf("%d\n", total);
        }
        input_file.close();
    }
    return 0;
}

vector<string> tokenize(string line)
{
    vector<string> tokens;
    istringstream iss(line);
    string token;
    while (getline(iss, token, ' '))
        tokens.push_back(token);
    return tokens;
}

vector<int> extract_numbers(string coordinate)
{
    char invalid_chars[] = "() ";
    for (unsigned int i = 0; i < strlen(invalid_chars); ++i)
        coordinate.erase(remove(coordinate.begin(), coordinate.end(), invalid_chars[i]), coordinate.end());
    vector<int> numbers;
    istringstream iss(coordinate);
    string token;
    while(getline(iss, token, ','))
        numbers.push_back(atoi(token.c_str()));
    return numbers;
}

vector<pair<int, int>> zip(vector<int> arr1, vector<int> arr2, int length)
{
    vector<pair<int, int>> ret(length);
    for (int i = 0; i < length; ++i)
        ret[i] = pair<int, int>(arr1[i], arr2[i]);
    return ret;
}