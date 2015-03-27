// min distance soln in c for code eval by steven a dunn

#include <math.h>
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
void sort(Array*);

long get_distance(Array*, long);

int main (int argc, char* const argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[1024];
        while (fgets(line, sizeof(line), fp))
        {
            Array addresses;
            init(&addresses, 1);

            char* token = strtok(line, " ");
            token = strtok(NULL, " ");
            while (token != NULL)
            {
                insert(&addresses, atoi(token));
                token = strtok(NULL, " ");
            }

            sort(&addresses);

            int min_address = addresses.array[0];
            int max_address = addresses.array[addresses.used-1];
            long min_distance = 500000;
            for (long i = min_address; i <= max_address; ++i)
            {
                long distance = get_distance(&addresses, i);
                if (distance < min_distance)
                    min_distance = distance;
            }
            printf("%ld\n", min_distance);
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

void sort(Array* arr)
{
    for (int i = 1; i < arr->used; ++i)
        for (int j = 0; j < i; ++j)
            if (arr->array[i] < arr->array[j])
            {
                int temp = arr->array[i];
                arr->array[i] = arr->array[j];
                arr->array[j] = temp;
            }
}

long get_distance(Array* addresses, long index)
{
    long distance = 0;
    for (int i = 0; i < addresses->used; ++i)
        distance += abs(addresses->array[i] - index);
    return distance;
}