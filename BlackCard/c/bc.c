// black card soln in c for code eval by steven a dunn

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char **array;
    size_t used;
    size_t size;
} Array;

void init(Array*, size_t);
void insert(Array*, char*);
void rem(Array*, int);

int main (int argc, char* const argv[])
{
	FILE *fp = fopen(argv[1], "r");

	if (fp)
	{
		char line[512];
		while(fgets(line, sizeof(line), fp))
		{
			char *token, *people;
			int black_spot, num_people;
			Array arr;

			init(&arr, 1);

			token = strtok(line, "|");
			people = token;

			token = strtok(NULL, "|");
			black_spot = atoi(token) - 1;

			token = strtok(people, " ");
			while (token != NULL)
			{
				insert(&arr, token);
				token = strtok(NULL, " ");
			}
			
			while (arr.used > 1)
			{
				int idx = black_spot % arr.used;
				rem(&arr, idx);
			}
			printf("%s \n", arr.array[0]);
		}
		fclose(fp);
	}
	return 0;
}

void init(Array* arr, size_t initSize)
{
    arr->array = (char**)malloc(initSize * sizeof(char*));
    arr->used = 0;
    arr->size = initSize;
}

void insert(Array* arr, char* element)
{
    if (arr->used == arr->size)
    {
        arr->size *= 2;
        arr->array = (char**)realloc(arr->array, arr->size * sizeof(char*));
    }
    arr->array[arr->used++] = element;
}

void rem(Array* arr, int idx)
{
	int i;
	if (idx >= 0 && idx < arr->used)
	{
		for (i = idx; i < arr->used - 1; ++i)
			arr->array[i] = arr->array[i+1];
		arr->used--;
	}
}