// Matrix rotatioan soln in cpp for code eval by steven a dunn

#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;

vector<string> get_matrix(string);

int main(int argc, char* argv[])
{
    ifstream input_file(argv[1]);
    string line;

    if (input_file)
    {
        while (getline(input_file, line))
        {
            vector<string> matrix = get_matrix(line);
            int n = (int)sqrt((float)matrix.size());

            string result = "";
            for (int j = 0; j < n; ++j)
                for (int i = n-1; i > -1; i--)
                    result += matrix[(i * n) + j] + " ";
            cout << result << endl;
        }
        input_file.close();
    }

    return 0;
}

vector<string> get_matrix(string line)
{
    vector<string> matrix;
    istringstream iss(line);
    string token;
    while(getline(iss, token, ' '))
        matrix.push_back(token.c_str());
    return matrix;
}