// multiply lists soln in c for code eval by steven a dunn

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

int main (int argc, char* const argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[512];
        while (fgets(line, sizeof(line), fp))
        {
            Array nums1, nums2;
            init(&nums1, 1);
            init(&nums2, 1);

            char *token, *line1, *line2;
            token = strtok(line, "|");
            line1 = token;

            token = strtok(NULL, "|");
            line2 = token;

            token = strtok(line1, " ");
            while (token != NULL)
            {
                insert(&nums1, atoi(token));
                token = strtok(NULL, " ");
            }

            token = strtok(line2, " ");
            while (token != NULL)
            {
                insert(&nums2, atoi(token));
                token = strtok(NULL, " ");
            }

            for (int i = 0; i < nums1.used; ++i)
                printf("%d ", nums1.array[i] * nums2.array[i]);
            puts("");
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