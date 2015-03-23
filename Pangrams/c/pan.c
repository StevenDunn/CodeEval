// pangrams soln in c for code eval by steven a dunn

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_LETTERS 26

void trim(char*);
void lowercase(char*);
void count(char*, int*);
void print_missing(int*);

int main (int argc, char* const argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[512];
        while (fgets(line, sizeof(line), fp))
        {
            trim(line);
            lowercase(line);
            int* letter_count = (int*)calloc(NUM_LETTERS+1, sizeof(int));
            letter_count[NUM_LETTERS] = '\0';
            count(line, letter_count);
            print_missing(letter_count);
            free(letter_count);
        }
        fclose(fp);
    }
    return 0;
}

void trim(char* line)
{
    char* c = line;
    while (*c)
    {
        if (*c == '\n')
            *c = '\0';
        ++c;
    }
}

void lowercase(char* line)
{
    char *c = line;
    while(*c)
    {
        *c = tolower(*c);
        ++c;
    }
}

void count(char* line, int* letter_count)
{
    char *c = line;
    while (*c)
    {
        if (isalpha(*c))
            ++letter_count[*c - 'a'];
        ++c;
    }
}

void print_missing(int* letter_count)
{
    int* i = letter_count;
    int is_missing = 0;
    int idx = 0;
    for (int x = 0; x < NUM_LETTERS; ++x)
    {
        if (*i == 0)
        {
            is_missing = 1;
            printf("%c", x + 'a');
        }
        ++i;
    }
    if (!is_missing)
        puts("NULL");
    else
        puts("");
}