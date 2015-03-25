// city blocks flyover soln in c for code eval by steven a dunn

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int *array;
    size_t size;
    size_t used;
} Array;

void init(Array*, size_t);
void insert(Array*, int);

typedef struct {
    int first;
    int second;
} Pair;

typedef struct {
    Pair *array;
    size_t size;
    size_t used;
} Pair_Array;

void pa_init(Pair_Array*, size_t);
void pa_insert(Pair_Array*, Pair);

void extract_numbers(Array*, char*);
void zip(Pair_Array*, Array*, Array*);

int main (int argc, char* const argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[1024];
        while (fgets(line, sizeof(line), fp))
        {
            char *token, *x_coord, *y_coord;

            token = strtok(line, " ");
            x_coord = token;

            token = strtok(NULL, " ");
            y_coord = token;

            Array x;
            init(&x, 1);
            extract_numbers(&x, x_coord);

            Array y;
            init(&y, 1);
            extract_numbers(&y, y_coord);

            Array x_sub;
            init(&x_sub, x.used - 1);
            for (int i = 1; i < x.used; ++i)
                insert(&x_sub, x.array[i]);

            Array y_sub;
            init(&y_sub, y.used - 1);
            for (int i = 1; i < y.used; ++i)
                insert(&y_sub, y.array[i]);

            Pair_Array xs;
            pa_init(&xs, x_sub.used);
            zip(&xs, &x, &x_sub);

            Pair_Array ys;
            pa_init(&ys, y_sub.used);
            zip(&ys, &y, &y_sub);

            float m = y.array[y.used-1]/(float)(x.array[x.used-1]);

            int total = 0;
            for (int i = 0; i < xs.used; ++i)
                for (int j = 0; j < ys.used; ++j)
                    if (!((m * xs.array[i].first >= ys.array[j].second) || (m * xs.array[i].second <= ys.array[j].first)))
                        total++;
            printf("%d\n", total);
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

void pa_init(Pair_Array* arr, size_t initSize)
{
    arr->array = (Pair*)malloc(initSize * sizeof(Pair));
    arr->size = initSize;
    arr->used = 0;
}

void pa_insert(Pair_Array* arr, Pair element)
{
    if (arr->used == arr->size)
    {
        arr->size *= 2;
        arr->array = (Pair*)realloc(arr->array, arr->size * sizeof(Pair));
    }
    arr->array[arr->used++] = element;
}

void extract_numbers(Array* arr, char* coordinate)
{
    char* token = strtok(coordinate, ",");

    while (token != NULL)
    {
        char c = token[0];
        if (c == '(' || c == ')')
            token[0] = ' ';
        insert(arr, atoi(token));
        token = strtok(NULL, ",");
    }
}

void zip(Pair_Array* p_arr, Array* arr1, Array* arr2)
{
    for (int i = 0; i < p_arr->size; ++i)
    {
        Pair *p = (Pair*)malloc(sizeof(Pair));
        p->first = arr1->array[i];
        p->second = arr2->array[i];
        pa_insert(p_arr, *p);
    }
}