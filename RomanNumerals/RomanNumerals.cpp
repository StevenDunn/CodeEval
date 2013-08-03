// Roman Numerals solution in C++ for CodeEval.com by Steven A. Dunn

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;

void writeRomanNumerals(string);
int calc(int, int, string);

int main(int argc, char* argv[])
{
  ifstream inputFile(argv[1]);
  string line;

  if (inputFile)
  {
    while (getline(inputFile, line))
      writeRomanNumerals(line);

    inputFile.close();
  }
  return 0;
}

void writeRomanNumerals(string line)
{
  int number = atoi(line.c_str());
  number = calc (number, 1000, "M");
  number = calc (number, 900, "CM");
  number = calc (number, 500, "D");
  number = calc (number, 400, "CD");
  number = calc (number, 100, "C");
  number = calc (number, 90, "XC");
  number = calc (number, 50, "L");
  number = calc (number, 40, "XL");
  number = calc (number, 10, "X");
  number = calc (number, 9, "IX");
  number = calc (number, 5, "V");
  number = calc (number, 4, "IV");
  for (int i = 0; i < number; ++i)
    cout << "I";
  cout << endl; 
}

int calc(int number, int value, string letter)
{
  while (number >= value)
  {
    cout << letter;
    number -= value;
  }
  return number;
}
