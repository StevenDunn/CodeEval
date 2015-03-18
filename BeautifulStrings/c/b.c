// beautiful strings soln in c for code eval by steven a dunn

#include <ctype.h>
#include <stdio.h>
#include <string.h>

void sort(int*);

int main (int argc, char* const argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[512];
        while (fgets(line, sizeof(line), fp))
        {
            const int ASCII_CONVERSION_VALUE = 97;
            int counts[26];
            for (int i = 0; i < 26; ++i)
                counts[i] = 0;

            for (int i = 0; i < strlen(line); ++i)
                line[i] = tolower(line[i]);

            for (int strIdx = 0; strIdx < strlen(line); strIdx++)
                if (line[strIdx] - ASCII_CONVERSION_VALUE >= 0 &&
                    line[strIdx] - ASCII_CONVERSION_VALUE <= 25)
                    counts[line[strIdx] - ASCII_CONVERSION_VALUE]++;

            sort(counts);

            int beauty = 0;
            int weight = 26;
            for (int countsIdx = 26; countsIdx >= 0; countsIdx--)
            {
                beauty += (weight * counts[countsIdx-1]);
                weight--;
            }
            printf("%d\n", beauty);
        }
        fclose(fp);
    }
    return 0;
}

void sort(int* arr)
{
    for (int i = 1; i < 26; ++i)
        for (int j = 0; j < i; ++j)
            if (arr[i] < arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
}