// chain inspection soln in c for code eval by steven a dunn

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char** array;
    size_t size;
    size_t used;
} Array;

void init(Array*, size_t);
void insert(Array*, char*);

typedef struct {
    int x;
    int y;
} Tuple;

typedef struct {
    int* keys;
    Tuple* data;
    size_t size;
    size_t used;
} Map;

void init_map(Map*, size_t);
void insert_map(Map*, int, Tuple);

void trim(char*);
void replace_char(char*, char, char);
void parse_entry(char*, int*, int*);
int is_chain_valid(Map*);
int find_index(Map*, int);

int main (int argc, char* const argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[16384];
        while (fgets(line, sizeof(line), fp))
        {
            trim(line);

            replace_char(line, ';', ' ');

            Array entries;
            init(&entries, 1);

            char *token = strtok(line, " ");
            while (token != NULL)
            {
                insert(&entries, token);
                token = strtok(NULL, " ");
            }

            Map chain;
            init_map(&chain, 1);

            for (int i = 0; i < entries.used; ++i)
            {
                int start, end;
                parse_entry(entries.array[i], &start, &end);

                Tuple pair;
                pair.x = end;
                pair.y = 0;
                insert_map(&chain, start, pair);
            }

            int result = is_chain_valid(&chain);
            if (result)
                puts("GOOD");
            else
                puts("BAD");
        }
        fclose(fp);
    }
    return 0;
}

void init(Array* arr, size_t initSize)
{
    arr->array = (char**)malloc(initSize * sizeof(char*));
    arr->size = initSize;
    arr->used = 0;
}

void insert(Array* arr, char* element)
{
    char *element_alloc = (char*)malloc((strlen(element) + 1) * sizeof(char));
    strcpy(element_alloc, element);
    if (arr->used == arr->size)
    {
        arr->size *= 2;
        arr->array = (char**)realloc(arr->array, arr->size * sizeof(char*));
    }
    arr->array[arr->used++] = element_alloc;
}

void init_map(Map* map, size_t initSize)
{
    map->keys = (int*)malloc(initSize * sizeof(int));
    map->data = (Tuple*)malloc(initSize * sizeof(Tuple));
    map->size = initSize;
    map->used = 0;
}

void insert_map(Map* map, int start, Tuple pair)
{
    if (map->used == map->size)
    {
        map->size *= 2;
        map->keys = (int*)realloc(map->keys, map->size * sizeof(int));
        map->data = (Tuple*)realloc(map->data, map->size * sizeof(Tuple));
    }

    map->keys[map->used] = start;
    map->data[map->used] = pair;
    map->used++;
}

void trim(char* line)
{
    char *c = line;
    while (*c)
    {
        if (*c == '\n')
            *c = '\0';
        ++c;
    }
}

void replace_char(char* line, char orig, char repl)
{
    char *c = line;
    while (*c)
    {
        if (*c == orig)
            *c = repl;
        ++c;
    }
}

void parse_entry(char* entry, int* start, int* end)
{
    replace_char(entry, '-', ' ');

    char *token = strtok(entry, " ");

    if (!strcmp(token, "BEGIN"))
        *start = 0;
    else
        *start = atoi(token);

    token = strtok(NULL, " ");
    if (!strcmp(token, "END"))
        *end = -1;
    else
        *end = atoi(token);
}

int is_chain_valid(Map* chain)
{
    int element_idx;
    element_idx = find_index(chain, 0);

    int element = chain->data[element_idx].x;
    chain->data[element_idx].y = 1;
    while (element != -1)
    {
        element_idx = find_index(chain, element);
        if (element_idx == -1)
            break;
        if (chain->data[element_idx].y == 1)
            return 0;
        chain->data[element_idx].y = 1;
        element = chain->data[element_idx].x;
    }
    for (int i = 0; i < chain->used; ++i)
        if (chain->data[i].y == 0)
            return 0;
    return 1;
}

int find_index(Map* chain, int element)
{
    for (int i = 0; i < chain->used; ++i)
        if (chain->keys[i] == element)
            return i;
    return -1;
}