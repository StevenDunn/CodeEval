// big digits cpp soln for code eval by steven a dunn

#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::vector;

void printBigDigits(string);
void bigPrint(char, vector<string>&);

int main (int argc, char* argv[])
{
    ifstream inputFile(argv[1]);
    string line;

    if (inputFile)
    {
        while (getline(inputFile, line))
            printBigDigits(line);
        inputFile.close();
    }

    return 0;
}

void printBigDigits(string line)
{
    vector<string> rows(5);
    for (int i = 0; i < rows.size(); ++i)
        rows[i] = "";

    for (int i = 0; i < line.size(); ++i)
        if (isdigit(line[i]))
            bigPrint(line[i], rows);

    for (int i = 0; i < rows.size(); ++i)
        cout << rows[i] << endl;

    string spacer = "";
    for (int i = 0; i < rows[0].size(); ++i)
        spacer += "-";
    cout << spacer << endl;
}

void bigPrint(char c, vector<string>& rows)
{
    int val = c - '0';

    if (val == 1)
    {
        rows[0] += "--*--";
        rows[1] += "-**--";
        rows[2] += "--*--";
        rows[3] += "--*--";
        rows[4] += "-***-";
    }
    else if (val == 2)
    {
        rows[0] += "***--";
        rows[1] += "---*-";
        rows[2] += "-**--";
        rows[3] += "*----";
        rows[4] += "****-";
    }
    else if (val == 3)
    {
        rows[0] += "***--";
        rows[1] += "---*-";
        rows[2] += "-**--";
        rows[3] += "---*-";
        rows[4] += "***--";
    }
    else if (val == 4)
    {
        rows[0] += "-*---";
        rows[1] += "*--*-";
        rows[2] += "****-";
        rows[3] += "---*-";
        rows[4] += "---*-";
    }
    else if (val == 5)
    {
        rows[0] += "****-";
        rows[1] += "*----";
        rows[2] += "***--";
        rows[3] += "---*-";
        rows[4] += "***--";
    }
    else if (val == 6)
    {
        rows[0] += "-**--";
        rows[1] += "*----";
        rows[2] += "***--";
        rows[3] += "*--*-";
        rows[4] += "-**--";
    }
    else if (val == 7)
    {
        rows[0] += "****-";
        rows[1] += "---*-";
        rows[2] += "--*--";
        rows[3] += "-*---";
        rows[4] += "-*---";
    }
    else if (val == 8)
    {
        rows[0] += "-**--";
        rows[1] += "*--*-";
        rows[2] += "-**--";
        rows[3] += "*--*-";
        rows[4] += "-**--";
    }
    else if (val == 9)
    {
        rows[0] += "-**--";
        rows[1] += "*--*-";
        rows[2] += "-***-";
        rows[3] += "---*-";
        rows[4] += "-**--";
    }
    else if (val == 0)
    {
        rows[0] += "-**--";
        rows[1] += "*--*-";
        rows[2] += "*--*-";
        rows[3] += "*--*-";
        rows[4] += "-**--";
    }
}