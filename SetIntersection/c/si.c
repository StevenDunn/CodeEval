// set intersection soln in C for code eval by steven a dunn

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int *array;
    size_t used;
    size_t size;
} Array;

void create_list(Array*, char*);
void init(Array*, size_t);
void insert(Array*, int);

int main(int argc, char* argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[1024];
        while (fgets(line, sizeof(line), fp))
        {
            char *list1_str = strtok(line, ";");
            char *list2_str = strtok(NULL, ";");

            Array list1;
            create_list(&list1, list1_str);

            Array list2;
            create_list(&list2, list2_str);

            Array intersection_list;
            init(&intersection_list, 1);

            for (int i = 0; i < list1.used; ++i)
                for (int j = 0; j < list2.used; ++j)
                    if (list1.array[i] == list2.array[j])
                        insert(&intersection_list, list1.array[i]);

            if (intersection_list.used == 0)
                printf("\n");
            else if (intersection_list.used == 1)
                printf("%d\n", intersection_list.array[0]);
            else
            {
                printf("%d", intersection_list.array[0]);
                for (int i = 1; i < intersection_list.used; ++i)
                    printf(",%d", intersection_list.array[i]);
                printf("\n");
            }
        }
        fclose(fp);
    }
    return 0;
}

void create_list(Array *list, char* list_str)
{
    init(list, 1);
    char *token = strtok(list_str, ",");
    while (token != NULL)
    {
        insert(list, atoi(token));
        token = strtok(NULL, ",");
    }
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