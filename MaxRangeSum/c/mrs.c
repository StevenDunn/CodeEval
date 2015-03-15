// max range sum soln in c for code eval by steven a dunn

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int *array;
    size_t used;
    size_t size;
} Array;

void init(Array*, size_t);
void insert(Array*, int);
int get_sum(int, int, Array*);

int main (int argc, char* argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[512];
        while (fgets(line, sizeof(line), fp))
        {
            char* tokens = strtok(line, ";");
            int n = atoi(tokens);

            tokens = strtok(NULL, ";");
            char *remainder = tokens;

            Array arr;
            init(&arr, 1);
            tokens = strtok(remainder, " ");
            while (tokens != NULL)
            {
                insert(&arr, atoi(tokens));
                tokens = strtok(NULL, " ");
            }

            int max_gain = -101;
            for (int i = 0; i < arr.used - n + 1; ++i)
            {
                int sum = get_sum(i, n, &arr);
                if (sum > max_gain)
                    max_gain = sum;
            }
            if (max_gain >= 0)
                printf("%d\n", max_gain);
            else
                printf("0\n");
        }
        fclose(fp);
    }
    return 0;
}

void init(Array* arr, size_t initSize)
{
    arr->array = (int*)malloc(initSize * sizeof(int));
    arr->used = 0;
    arr->size = initSize;
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

int get_sum(int start, int length, Array* vals)
{
    int sum = 0;
    for (int i = start; i < start + length; ++i)
        sum += vals->array[i];
    return sum;
}