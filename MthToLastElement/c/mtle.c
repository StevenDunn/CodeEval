// Mth to Last Element solution in C for Code Eval by Steven A Dunn

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char **array;
    size_t used;
    size_t size;
} Array;

void init(Array*, size_t);
void insert(Array*, char*);

void trim(char*);

int main (int argc, char* const argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[512];
        while (fgets(line, sizeof(line), fp))
        {
            trim(line);
            if (strlen(line) == 0)
                continue;

            Array vals;
            init(&vals, 1);
            char* token = strtok(line, " ");
            while (token != NULL)
            {
                insert(&vals, token);
                token = strtok(NULL, " ");
            }
            int final_index = atoi(vals.array[vals.used-1]);
            if (final_index > vals.used)
                continue;
            printf("%s\n", vals.array[vals.used - final_index - 1]);
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

void init(Array* arr, size_t initSize)
{
    arr->array = (char**)malloc(initSize * sizeof(char*));
    arr->used = 0;
    arr->size = initSize;
}

void insert(Array* arr, char* element)
{
    if (arr->used == arr->size)
    {
        arr->size *= 2;
        arr->array = (char**)realloc(arr->array, arr->size * sizeof(char*));
    }
    arr->array[arr->used++] = element;
}