// time to eat soln in c for code eval by steven a dunn

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
void sort(Array*);

int main (int argc, char* const argv[])
{
	FILE *fp = fopen(argv[1], "r");

	if (fp)
	{
		char line[1024];
		while (fgets(line, sizeof(line), fp))
		{
			char *token, *timestamp;
			Array arr;
			int i;

			for (i = 0; i < strlen(line); ++i)
 				if (line[i] == '\r' || line[i] == '\n')
 					line[i] = '\0';

			init(&arr, 1);
			token = strtok(line, " ");
			while (token != NULL)
			{
				insert(&arr, token);
				token = strtok(NULL, " ");
			}
			sort(&arr);
			for (i = 0; i < arr.used; ++i)
				printf("%s ", arr.array[i]);
			puts("");
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

void sort(Array* arr)
{
	int i, j;
    for (i = 1; i < arr->used; ++i)
        for (j = 0; j < i; ++j)
            if (strcmp(arr->array[i], arr->array[j]) > 0)
            {
                char* temp = arr->array[i];
                arr->array[i] = arr->array[j];
                arr->array[j] = temp;
            }
}