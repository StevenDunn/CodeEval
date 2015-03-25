// locks soln in c for code eval by steven a dunn

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int lock;
    int door;
} Door;

typedef struct {
    Door* array;
    size_t size;
    size_t used;
} Array;

void init(Array*, size_t);
void insert(Array*, Door);

void close(Door*);
void toggle_lock(Door*);

int main (int argc, char* const argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[512];
        while (fgets(line, sizeof(line), fp))
        {
            char *token = strtok(line, " ");
            int num_locks = atoi(token);

            token = strtok(NULL, " ");
            int repetitions = atoi(token);

            Array locks;
            init(&locks, num_locks);
            for (int i = 0; i < num_locks; ++i)
            {
                Door d;
                d.lock = 0;
                d.door = 0;
                insert(&locks, d);
            }
            for (int n = 0; n < repetitions-1; ++n)
                for (int x = 0; x < num_locks; ++x)
                {
                    if ((x+1) % 2 == 0)
                        close(&locks.array[x]);
                    if ((x+1) % 3 == 0)
                        toggle_lock(&locks.array[x]);
                }
            // final repetition
            toggle_lock(&locks.array[locks.used-1]);

            int num_unlocked = 0;
            for (int i = 0; i < num_locks; ++i)
                if (locks.array[i].lock == 0)
                    num_unlocked += 1;
            printf("%d\n", num_unlocked);
        }
        fclose(fp);
    }
    return 0;
}

void init(Array* arr, size_t initSize)
{
    arr->array = (Door*)malloc(initSize * sizeof(Door));
    arr->size = initSize;
    arr->used = 0;
}

void insert(Array* arr, Door element)
{
    if (arr->used == arr->size)
    {
        arr->size *= 2;
        arr->array = (Door*)realloc(arr->array, arr->size * sizeof(Door));
    }
    arr->array[arr->used++] = element;
}

void close(Door* d)
{
    d->lock = 1;
    d->door = 1;
}

void toggle_lock(Door* d)
{
    d->lock = !d->lock;
}