// roman numerals soln in c for code eval by steven a dunn

#include <stdio.h>
#include <stdlib.h>

void print_roman_numerals(char*);
int calc(int, int, char*);

int main (int argc, char* const argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[1024];
        while (fgets(line, sizeof(line), fp))
            print_roman_numerals(line);
        fclose(fp);
    }
    return 0;
}

void print_roman_numerals(char* entry)
{
    int number = atoi(entry);
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
        printf("I");
    puts("");
}

int calc(int number, int value, char* digit)
{
  while (number >= value)
  {
    printf("%s", digit);
    number -= value;
  }
  return number;
}