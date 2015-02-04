// Knight Moves cpp soln for code eval by Steven A Dunn

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::to_string;
using std::vector;

int convert(char);
vector<vector<int>> get_moves(char, int);
vector<string> format_moves(vector<vector<int>>);
string format_output(vector<string>);

int main(int argc, char* argv[])
{
    ifstream input_file(argv[1]);
    string line;

    if (input_file)
    {
        while (getline(input_file, line))
        {
            char c = line[0];
            int n = line[1] - '0';
            vector<vector<int>> moves = get_moves(c, n);
            vector<string> formatted_moves = format_moves(moves);
            cout << format_output(formatted_moves) << endl;
        }
    }
    return 0;
}

int convert(char c)
{
    int result;
    if (c == 'a')
        result = 1;
    else if (c == 'b')
        result = 2;
    else if (c == 'c')
        result = 3;
    else if (c == 'd')
        result = 4;
    else if (c == 'e')
        result = 5;
    else if (c == 'f')
        result = 6;
    else if (c == 'g')
        result = 7;
    else if (c == 'h')
        result = 8;
    else
        result = -1;
    return result;
}

bool isValid(int i) {
    if (i >= 1 && i <= 8)
        return true;
    return false;
}

vector<vector<int>> get_moves(char c, int n)
{
    int col = convert(c);
    int row = n;

    vector<vector<int>> possible_moves = {{col-2, row-1}, {col-2,row+1}, {col-1,row-2}, {col-1,row+2}, {col+1,row-2}, {col+1,row+2}, {col+2,row-1}, {col+2,row+1}};

    vector<vector<int>> result;
    for (int i = 0; i < possible_moves.size(); ++i)
        if (isValid(possible_moves[i][0]) && isValid(possible_moves[i][1]))
            result.push_back(possible_moves[i]);
    return result;
}

char reverse_convert(int i)
{
    char result;
    if (i == 1)
        result = 'a';
    else if (i == 2)
        result = 'b';
    else if (i == 3)
        result = 'c';
    else if (i == 4)
        result = 'd';
    else if (i == 5)
        result = 'e';
    else if (i == 6)
        result = 'f';
    else if (i == 7)
        result = 'g';
    else if (i == 8)
        result = 'h';
    else
        result = 'Z';
    return result;
}

vector<string> format_moves(vector<vector<int>> moves)
{
    vector<string> formatted_moves;
    for (int i = 0; i < moves.size(); ++i)
    {
        char c = reverse_convert(moves[i][0]);
        string formatted_move = c + to_string(moves[i][1]);
        formatted_moves.push_back(formatted_move);
    }
    return formatted_moves;
}

string format_output(vector<string> formatted_moves)
{
    string result;
    for (int i = 0; i < formatted_moves.size(); ++i)
        result += formatted_moves[i] + " ";
    return result;
}