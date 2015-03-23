// flavius josephus soln in c for code eval by steven a dunn

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

void get_flavius(Array*, int, int);

int main(int argc, char* const argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[512];
        while (fgets(line, sizeof(line), fp))
        {
            char *token = strtok(line, ",");
            int m = atoi(token);
            token = strtok(NULL, ",");
            int n = atoi(token);

            Array flavius_seq;
            init(&flavius_seq, 1);
            get_flavius(&flavius_seq, m, n);

            for (int i = 0; i < flavius_seq.used; ++i)
                printf("%d ", flavius_seq.array[i]);
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

void get_flavius(Array* flavius_seq, int m, int n)
{
    Array visited;
    init(&visited, m);
    for (int i = 0; i < m; ++i)
        insert(&visited, 0);

    int step_count = 0;

    for (int i = 0; i <= m; ++i)
    {
        if (i == m)
        {
            i = -1;
            continue;
        }

        if(visited.array[i] == 1)
            continue;

        if (step_count != n - 1)
        {
            ++step_count;
            continue;
        }

        if(visited.array[i] == 0)
        {
            visited.array[i] = 1;
            insert(flavius_seq, i);
            if (flavius_seq->used == m)
                break;
            step_count = 0;
            continue;
        }
    }
}