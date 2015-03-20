// the major element soln in c by steven a dunn for code eval

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
int get_major_element(Array*);

int main (int argc, char* const argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[16384];
        while (fgets(line, sizeof(line), fp))
        {
            Array nums;
            init(&nums, 1);

            char* token = strtok(line, ",");
            while (token != NULL)
            {
                insert(&nums, atoi(token));
                token = strtok(NULL, ",");
            }

            sort(&nums);

            int major_element = get_major_element(&nums);
            if (major_element == -1)
                printf("None\n");
            else
                printf("%d\n", major_element);
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

int get_major_element(Array* arr)
{
    int threshold = arr->used / 2;
    int cur = -1;
    int count = 0;
    for (int i = 0; i < arr->used; ++i)
    {
        if (arr->array[i] == cur)
        {
            count++;
            if (count > threshold)
                return cur;
        }
        else
        {
            cur = arr->array[i];
            count = 1;
        }
    }

    return -1;
}