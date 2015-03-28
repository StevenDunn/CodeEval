// interrupted bubble sort soln in c for code eval by steven a dunn

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

void parse_line(char*, Array*, long*);
int already_sorted(Array*);
void bubble_sort(Array*, long*);

int main (int argc, char* const argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[512];
        while (fgets(line, sizeof(line), fp))
        {
            Array nums;
            init(&nums, 1);
            long *iterations = (long*)calloc(1, sizeof(long));
            parse_line(line, &nums, iterations);

            bubble_sort(&nums, iterations);

            for (int i = 0; i < nums.used; ++i)
                printf("%d ", nums.array[i]);
            puts("");

            free(iterations);
            free(nums.array);
        }
        fclose(fp);
    }
    return 0;
}

void init(Array* arr, size_t initSize)
{
    arr->array = (int*)malloc(initSize * sizeof(int));
    arr->size = initSize;
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

void parse_line(char* line, Array* arr, long* iterations)
{
    char *line_copy = (char*)malloc((strlen(line)+1) * sizeof(char));
    strcpy(line_copy, "");
    strcat(line_copy, line);

    char *token = strtok(line, "|");
    char *nums = token;
    char *nums_token = strtok(nums, " ");
    while (nums_token != NULL)
    {
        insert(arr, atoi(nums_token));
        nums_token = strtok(NULL, " ");
    }
    token = strtok(line_copy, "|");
    token = strtok(NULL, "|");

    long l_token = atol(token);
    memcpy(iterations, &l_token, sizeof(l_token));

    free(line_copy);
}

int already_sorted(Array* nums)
{
    for (int i = 0; i < nums->used - 1; ++i)
        if (nums->array[i] > nums->array[i+1])
            return 0;
    return 1;
}

void bubble_sort(Array* nums, long* iterations)
{
    if (already_sorted(nums))
        return;
    long n = 0;
    while (n < *iterations)
    {
        for (int i = 0; i < nums->used; ++i)
        {
            int num = nums->array[i];
            if (i >= nums->used - 1 - n)
                continue;
            int next_num = nums->array[i+1];
            if (next_num < num)
            {
                nums->array[i+1] = num;
                nums->array[i] = next_num;
            }
        }
        n += 1;
    }
}