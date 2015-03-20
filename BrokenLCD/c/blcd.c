// Broken LCD soln in C for Code Eval by Steven A Dunn

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char **array;
    size_t used;
    size_t size;
} Array;

typedef struct {
    int *array;
    size_t used;
    size_t size;
} iArray;

void init(Array*, size_t);
void insert(Array*, char*);
void initi(iArray*, size_t);
void inserti(iArray*, int);

// each display from 0 to 9, plus the decimal point, stored as decimals
int numbers[] = {252, 96, 218, 242, 102, 182, 190, 224, 254, 246, 1};

int main (int argc, char* const argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[1024];
        while (fgets(line, sizeof(line), fp))
        {
            for (int i = 0; i < strlen(line); ++i)
                if (line[i] == '\n')
                    line[i] = '\0';

            char *token, *displays_tok, *number;

            token = strtok(line, ";");
            displays_tok = token;
            token = strtok(NULL, ";");
            number = token;

            Array displays;
            init(&displays, 1);
            token = strtok(displays_tok, " ");
            while (token != NULL)
            {
                insert(&displays, token);
                token = strtok(NULL, " ");
            }

            iArray converted_numbers;
            initi(&converted_numbers, 1);

            for (int i = 0; i < strlen(number); ++i)
            {
                char* c = &number[i];
                if (c[0] != '.')
                {
                    int x = number[i] - '0';
                    inserti(&converted_numbers, numbers[x]);
                }
                else
                    converted_numbers.array[i-1] += 1;
            }

            int did_print = 0;
            for (int i = 0; i < (displays.used - converted_numbers.used + 1); ++i)
            {
                int match = 0;
                for (int j = 0; j < converted_numbers.used; ++j)
                {
                    char *str;
                    int converted_display = strtol (displays.array[i+j], &str, 2);
                    if ((converted_display & converted_numbers.array[j]) != converted_numbers.array[j])
                        break;
                    else
                        match += 1;
                }
                if (match == converted_numbers.used)
                {
                    puts("1");
                    did_print = 1;
                    break;
                }
            }
            if (did_print == 0)
                puts("0");

        }
        fclose(fp);
    }
    return 0;
}

void init(Array* arr, size_t initSize)
{
    arr->array = (char**)malloc(initSize * sizeof(char*));
    arr->used = 0;
    arr->size = initSize;
}

void insert(Array *arr, char* element)
{
    if (arr->used == arr->size)
    {
        arr->size *= 2;
        arr->array = (char**)realloc(arr->array, arr->size * sizeof(char*));
    }
    arr->array[arr->used++] = element;
}

void initi(iArray* arr, size_t initSize)
{
    arr->array = (int*)malloc(initSize * sizeof(int));
    arr->used = 0;
    arr->size = initSize;
}

void inserti(iArray *arr, int element)
{
    if (arr->used == arr->size)
    {
        arr->size *= 2;
        arr->array = (int*)realloc(arr->array, arr->size * sizeof(int));
    }
    arr->array[arr->used++] = element;
}