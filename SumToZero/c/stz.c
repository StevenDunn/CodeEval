// sum to zero soln in c by steven a dunn for code eval

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int *array;
    size_t used;
    size_t size;
} Array;

int count;

void init(Array*, size_t);
void insert(Array*, int);
void erase(Array*, int);
void insert_at(Array*, int, int);
void count_sums(Array*, int, int);

int main (int argc, char* const argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[512];
        while (fgets(line, sizeof(line), fp))
        {
            count = 0;

            Array numbers;
            init(&numbers, 1);

            char *token = strtok(line, ",");
            while (token != NULL)
            {
                insert(&numbers, atoi(token));
                token = strtok(NULL, ",");
            }

            count_sums(&numbers, 4, 0);
            // 24 == 4! which allows us to trim the duplicate counts, since
            // we are only interested in the combinations, not the permutations
            printf("%d\n", count/24);
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

void erase(Array* arr, int index)
{
    if (arr->used > 0)
    {
        int new_idx = 0;
        for (int i = 0; i < arr->used; ++i)
        {
            if (i != index)
            {
                arr->array[new_idx] = arr->array[i];
                ++new_idx;
            }
        }
        arr->used--;
    }
}

void insert_at(Array* arr, int insert_index, int element)
{
        if (arr->used == arr->size)
        {
            arr->size *= 2;
            arr->array = (int*)realloc(arr->array, arr->size * sizeof(int));
        }

        int idx = arr->used - insert_index + 1;
        for (int i = 0; i <= idx; i++)
        {
            arr->array[arr->used - i + 2] = arr->array[arr->used - i + 1] ;
        }
        arr->array[insert_index] = element;
        arr->used++;
}

void count_sums(Array* numbers, int depth, int sum)
{
    if (depth == 0)
    {
        if (sum == 0)
            count++;
        return;
    }

  int updated_sum = 0;
  for (int i = 0; i < numbers->used; ++i)
  {
    int num = numbers->array[i];
    updated_sum = sum + num;
    erase(numbers, i);
    count_sums(numbers, depth - 1, updated_sum);
    insert_at(numbers, i, num);
  }
}