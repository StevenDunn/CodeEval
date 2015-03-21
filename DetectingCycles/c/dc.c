// detecting cycles soln in c for code eval by steven a dunn

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EMPTY_STACK -1000

typedef struct Node Node;

struct Node {
    int data;
    struct Node* prev;
};

typedef struct {
    struct Node *head;
    struct Node *start;
} Stack;

void init_stack(Stack*);
void push(Stack*, int);
int pop(Stack*);
int is_empty(Stack*);

typedef struct {
    int *array;
    size_t used;
    size_t size;
} Array;

void trim(char*);
void init(Array*, size_t);
void insert(Array*, int);
int contains(Array*, int);

int main (int argc, char* const argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[512];
        while (fgets(line, sizeof(line), fp))
        {
            trim(line);

            Stack numbers;
            init_stack(&numbers);

            char* token = strtok(line, " ");
            while (token != NULL)
            {
                push(&numbers, atoi(token));
                token = strtok(NULL, " ");
            }

            int num = 0;
            Array unique;
            init(&unique, 1);
            Array seq;
            init(&seq, 1);

            while (!is_empty(&numbers))
            {
                num = pop(&numbers);
                if (!contains(&unique, num))
                    insert(&unique, num);
                else if (!contains(&seq, num))
                   insert(&seq, num);
            }

            for (int i = seq.used - 1; i >= 0; --i)
                printf("%d ", seq.array[i]);
            puts("");
        }
        fclose(fp);
    }
    return 0;
}

void trim(char* line)
{
    char* c = line;
    while (*c)
    {
        if (*c == '\n')
            *c = '\0';
        ++c;
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

void init_stack(Stack* s)
{
    s->start = malloc(sizeof(Node));
    s->head = s->start;
}

void push(Stack* stack, int element)
{
    struct Node *node = malloc(sizeof(Node));
    node->data = element;
    node->prev = stack->head;
    stack->head = node;
}

int pop(Stack* stack)
{
    if (stack->head == stack->start)
        return EMPTY_STACK;
    int n = stack->head->data;
    Node *deleter = stack->head;
    stack->head = stack->head->prev;
    free(deleter);
    return n;
}

int is_empty(Stack* stack)
{
    if (stack->head == stack->start)
        return 1;
    return 0;
}

int contains(Array* arr, int val)
{
    for (int i = 0; i < arr->used; ++i)
        if (arr->array[i] == val)
            return 1;
    return 0;
}