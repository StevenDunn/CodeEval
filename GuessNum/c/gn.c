// guess the number c soln for code eval by steven a dunn

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int* array;
    size_t size;
    size_t used;
} Array;

void init(Array*, size_t);
void insert(Array*, int);
int get_midpoint(int, int);

void guess(int*, int*, int);

int main (int argc, char* const argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[512];
        while (fgets(line, sizeof(line), fp))
        {
            int lower_bound = 0;

            char *token = strtok(line, " ");
            int upper_bound = atoi(token);

            Array guesses;
            init(&guesses, 1);

            while (token != NULL)
            {
                if (!strcmp(token, "Higher"))
                    insert(&guesses, 1);
                else if (!strcmp(token, "Lower"))
                    insert(&guesses, 0);
                else
                    insert(&guesses, -1);
                token = strtok(NULL, " ");
            }

            for (int guess_index = 1; guess_index < guesses.used; ++guess_index)
                guess(&lower_bound, &upper_bound, guesses.array[guess_index]);
            printf("%d\n", upper_bound);

            free(guesses.array);
        }
        fclose(fp);
    }
    return 0;
}

void init(Array* arr, size_t init_size)
{
    arr->array = (int*)malloc(init_size * sizeof(int));
    arr->size = init_size;
    arr->used = 0;
}

void insert(Array* arr, int element)
{
    if (arr->used == arr->size)
    {
        arr->size *= 2;
        arr->array = (int*)realloc(arr->array, arr->size * sizeof(int));
    }
    arr->array[arr->used++] = element;
}

void guess(int* lower_bound, int* upper_bound, int guess_update)
{
    int midpoint = get_midpoint(*lower_bound, *upper_bound);
    if (guess_update == 0)
        *upper_bound = midpoint - 1;
    else if (guess_update == 1)
        *lower_bound = midpoint + 1;
    else
        *upper_bound = midpoint;
}

int get_midpoint(int lower_bound, int upper_bound)
{
    int midpoint = (upper_bound - lower_bound);
    if (midpoint % 2 == 0)
        midpoint /= 2;
    else
        midpoint = (midpoint + 1)/2;
    return lower_bound + midpoint;
}