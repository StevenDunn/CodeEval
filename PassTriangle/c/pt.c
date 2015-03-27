// pass triangle soln in c for code eval by steven a dunn

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EMPTY_STACK NULL

typedef struct Node Node;

struct Node {
    char* data;
    struct Node* prev;
};

typedef struct {
    struct Node *head;
    struct Node *start;
} Stack;

void stack_init(Stack*);
void push(Stack*, char*);
char* pop(Stack*);

typedef struct {
    long *array;
    size_t used;
    size_t size;
} Array;

void init(Array*, size_t);
void insert(Array*, long);
void copy(Array*, Array*);

void calculate_sum(char*, Array*);

int main (int argc, char* const argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        Stack line_stack;
        stack_init(&line_stack);

        char line[512];
        while (fgets(line, sizeof(line), fp))
            push(&line_stack, line);
        fclose(fp);

        Array sums;
        init(&sums, 1);

        char* stack_val = pop(&line_stack);
        while (stack_val != EMPTY_STACK)
        {
            calculate_sum(stack_val, &sums);
            stack_val = pop(&line_stack);
        }
        printf("%ld\n", sums.array[0]);

        // free the memory
        Node *np = line_stack.head;
        while (np != line_stack.start)
        {
            Node *deleter = np;
            np = np->prev;
            free(deleter);
        }
        free(line_stack.start);
        free(sums.array);
    }
    return 0;
}

void stack_init(Stack* s)
{
    s->start = malloc(sizeof(Node));
    s->head = s->start;
}

void push(Stack* stack, char* element)
{
    struct Node *node = malloc(sizeof(Node));
    char* elem_alloc = (char*)malloc(strlen(element) * sizeof(char));
    strcpy(elem_alloc, "");
    strcat(elem_alloc, element);
    node->data = elem_alloc;
    node->prev = stack->head;
    stack->head = node;
}

char* pop(Stack* stack)
{
    if (stack->head == stack->start)
        return EMPTY_STACK;
    char* c = stack->head->data;
    Node *deleter = stack->head;
    stack->head = stack->head->prev;
    free(deleter);
    return c;
}

void init(Array* arr, size_t initSize)
{
    arr->array = (long*)malloc(initSize * sizeof(long));
    arr->used = 0;
    arr->size = initSize;
}

void insert(Array* arr, long element)
{
    if (arr->used == arr->size)
    {
        arr->size *= 2;
        arr->array = (long*)realloc(arr->array, arr->size * sizeof(long));
    }
    arr->array[arr->used++] = element;
}

void copy(Array* arr1, Array* arr2)
{
    arr1->array = realloc(arr1->array, arr2->size * sizeof(long));
    memcpy(arr1->array, arr2->array, arr2->size * sizeof(long));
    arr1->size = arr2->size;
    arr1->used = arr2->used;
}

void calculate_sum(char* line, Array* sums)
{
    Array line_numbers;
    init(&line_numbers, 1);

    char* token = strtok(line, " ");
    while (token != NULL)
    {
        insert(&line_numbers, atol(token));
        token = strtok(NULL, " ");
    }

    if (sums->used == 0)
    {
        copy(sums, &line_numbers);
        return;
    }

    Array new_sums;
    init(&new_sums, 1);

    for (int i = 0; i < sums->used - 1; ++i)
    {
        long max_num = 0;
        if (sums->array[i] > sums->array[i + 1])
            max_num = sums->array[i];
        else
            max_num = sums->array[i + 1];
        insert(&new_sums, max_num + line_numbers.array[i]);
    }
    copy(sums, &new_sums);

    free(line_numbers.array);
    free(new_sums.array);
}