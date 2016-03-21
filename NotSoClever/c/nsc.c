// not so clever soln in c for code eval by steven a dunn

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    int *array;
    size_t used;
    size_t size;
} Array;

void init(Array*, size_t);
void insert(Array*, int);
void stupid_sort(Array*);

int main (int argc, char* const argv[])
{
	FILE *fp = fopen(argv[1], "r");
	if (fp)
	{
		char line[1024];
		while(fgets(line, sizeof(line), fp))
		{
			char *token, *vals;
			int iterations;
			int i, j;
			Array nums;

			init(&nums, 1);

			token = strtok(line, "|");
			vals = token;
			token = strtok(NULL, "|");
			iterations = atoi(token);

			token = strtok(vals, " ");
			while (token != NULL)
			{
				insert(&nums, atoi(token));
				token = strtok(NULL, " ");
			}
		
			for (i = 0; i < iterations; ++i)
				stupid_sort(&nums);

			for (i = 0; i < nums.used; ++i)
				printf("%d ", nums.array[i]);
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

void stupid_sort(Array* arr)
{
	int i, j, temp;
    for (i = 0; i < arr->used - 1; ++i)
    {
        if (arr->array[i] > arr->array[i+1])
        {
            temp = arr->array[i];
            arr->array[i] = arr->array[i+1];
            arr->array[i+1] = temp;
            break;
        }
    }
}