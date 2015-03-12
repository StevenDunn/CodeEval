// age distribution c soln for code eval by steven a dunn

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char* argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[1024];
        while (fgets(line, sizeof(line), fp))
        {
            int age = atoi(line);
            char* text;

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
            puts(text);

        }
        fclose(fp);
    }
    return 0;
}