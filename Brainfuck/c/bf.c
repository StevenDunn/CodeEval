// brainfuck soln by steven a dunn for code eval

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
void insert_front(Array*, int);
int find_end(char*, int);
int find_start(char*, int);

int main (int argc, char* argv[])
{
	FILE *fp = fopen(argv[1], "r");
	if (fp)
	{
		char line[1024];
		while (fgets(line, sizeof(line), fp))
		{
			Array cells, result;
			int ptr, idx, i;

			init(&cells, 1);
			insert(&cells, 0);
			init(&result, 1);
			ptr = 0;
			idx = 0;
			i = 0;
			
			while (idx < strlen(line))
			{
				char cur = line[idx];
				switch (cur)
				{
					case '.': 
						insert(&result, cells.array[ptr]);
						break;
					case '+':
						cells.array[ptr] += 1;
						cells.array[ptr] %= 255;
						break;
					case '-':
						cells.array[ptr] -= 1;
						cells.array[ptr] %= 255;
						break;
					case '>':
						++ptr;
						if (ptr >= cells.used)
							insert(&cells, 0);
						break;
					case '<':
						--ptr;
						if (ptr < 0)
						{
							insert_front(&cells, 0);
							ptr = 0;
						}
						break;
					case '[':
						if (cells.array[ptr] == 0)
							idx = find_end(line, idx);
						break;
					case ']':
						if (cells.array[ptr] != 0)
							idx = find_start(line, idx);
						break;
				}
				++idx;
			}
			for (i = 0; i < result.used; ++i)
			{
				printf("%c", result.array[i]);
			}
			puts("");
		}
		fclose(fp);
	}
	return 0;
}

int find_end(char* line, int start)
{
	int count = 1;
	int i = 0;
	for (i = start + 1; i < strlen(line); ++i)
	{
		if (line[i] == '[')
			++count;
		else if (line[i] == ']')
		{
			--count;
			if (count == 0)
				return i;
		}
	}
	return strlen(line) - 1;
}

int find_start(char* line, int end)
{
	int count = 1;
	int i = 0;
	for (i = end - 1; i >= 0; --i)
	{
		if (line[i] == ']')
			++count;
		else if (line[i] == '[')
		{
			--count;
			if (count == 0)
				return i;
		}
	}
	return 0;
}


void init(Array* arr, size_t initSize)
{
    arr->array = (int*)malloc(initSize * sizeof(int));
    arr->used = 0;
    arr->size = initSize;
}

void insert(Array *arr, int element)
{
    if (arr->used == arr->size)
    {
        arr->size *= 2;
        arr->array = (int*)realloc(arr->array, arr->size * sizeof(int));
    }
    arr->array[arr->used++] = element;
}

void insert_front(Array *arr, int element)
{
	int i = 0;
	if (arr->used == arr->size)
    {
        arr->size *= 2;
        arr->array = (int*)realloc(arr->array, arr->size * sizeof(int));
    }
    for (i = arr->used; i > 0; --i)
    	arr->array[i] = arr->array[i-1];
    arr->array[0] = element;  
}