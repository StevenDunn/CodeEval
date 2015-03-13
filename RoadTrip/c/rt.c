// road trip soln in c for code eval by steven a dunn

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char **array;
    size_t used;
    size_t size;
} Array;

void init(Array*, size_t);
void insert(Array*, char*);

void sort(int*, int);

int main(int argc, char* const argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[8192];
        while (fgets(line, sizeof(line), fp))
        {
            for(int i = 0; i < sizeof(line); ++i)
                if (line[i] == '\n')
                    line[i] = '\0';

            // array to hold {location, distance} pairs
            Array tok_arr;
            init(&tok_arr, 1);
            char* token = strtok(line, ";");
            while (token != NULL)
            {
                insert(&tok_arr, token);
                token = strtok(NULL, ";");
            }

            // split the {location, distance} pairs to extract distance
            int distance_arr[tok_arr.used];
            for (int i = 0; i < tok_arr.used; ++i)
            {
                token = strtok(tok_arr.array[i], ",");
                token = strtok(NULL, ",");
                distance_arr[i] = atoi(token);
            }
            sort(distance_arr, tok_arr.used);

            int curPos = 0;
            for(int i = 0; i < tok_arr.used - 1; ++i)
            {
                printf("%d,", distance_arr[i] - curPos);
                curPos = distance_arr[i];
            }
            printf("%d\n", distance_arr[tok_arr.used - 1] - curPos);
        }
        fclose(fp);
    }
    return 0;
}

void init(Array* arr, size_t initSize)
{
    arr->array = (char**)malloc(initSize * sizeof(char**));
    arr->used = 0;
    arr->size = initSize;
}

void insert(Array* arr, char* element)
{
    if (arr->used == arr->size)
    {
        arr->size *= 2;
        arr->array = (char**)realloc(arr->array, arr->size * sizeof(char**));
    }
    arr->array[arr->used++] = element;
}

void sort(int* arr, int len)
{
    for (int i = 1; i < len; ++i)
        for (int j = 0; j < i; ++j)
            if (arr[i] < arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
}