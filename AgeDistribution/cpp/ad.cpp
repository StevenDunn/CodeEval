// age distribution cpp soln for code eval by steven a dunn

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;

int main (int argc, char* argv[])
{
    ifstream input_file(argv[1]);
    string line;

    if (input_file)
    {
        while (getline (input_file, line))
        {
            int age = atoi(line.c_str());
            string text;

            if (age < 0)
                text = "This program is for humans";
            else if (age <= 2)
                text = "Still in Mama's arms";
            else if (age <= 4)
                text = "Preschool Maniac";
            else if (age <= 11)
                text = "Elementary school";
            else if (age <= 14)
                text = "Middle school";
            else if (age <= 18)
                text = "High school";
            else if (age <= 22)
                text = "College";
            else if (age <= 65)
                text = "Working for the man";
            else if (age <= 100)
                text = "The Golden Years";
            else
                text = "This program is for humans";

            cout << text << endl;
        }
        input_file.close();
    }
    return 0;
}