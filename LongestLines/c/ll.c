// longest lines soln in c for code eval by steven a dunn

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char **array;
    size_t size;
    size_t used;
} Array;

void init (Array*, size_t);
void insert (Array*, char*);
void sort(Array*);
void trim(char*);

int main (int argc, char* argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[512];
        fgets(line, sizeof(line), fp);
        int output_size = atoi(line);

        Array lines;
        init(&lines, 1);
        while (fgets(line, sizeof(line), fp))
        {
            trim(line);
            insert(&lines, line);
        }

        sort(&lines);

        for (int i = 0; i < output_size; ++i)
            puts(lines.array[i]);

        fclose(fp);
    }
    return 0;
}

void init (Array* arr, size_t initSize)
{
    arr->array = (char**)malloc(initSize * sizeof(char*));
    arr->used = 0;
    arr->size = initSize;
}

void insert(Array* arr, char* element)
{
    char* element_alloc = (char*)malloc(strlen(element) * sizeof(char));
    strcpy(element_alloc, element);
    if (arr->used == arr->size)
    {
        arr->size *= 2;
        arr->array = (char**)realloc(arr->array, arr->size * sizeof(char*));
    }
    arr->array[arr->used++] = element_alloc;
}

void sort(Array* arr)
{
    for (int i = 1; i < arr->used; ++i)
        for (int j = 0; j < i; ++j)
            if (strlen(arr->array[i]) > strlen(arr->array[j]))
            {
                char *temp = arr->array[i];
                arr->array[i] = arr->array[j];
                arr->array[j] = temp;
            }
}

void trim(char* line)
{
    char *p = line;
    while (*p)
    {
        if (*p == '\n')
            *p = '\0';
        ++p;
    }
}