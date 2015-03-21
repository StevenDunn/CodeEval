// stack implementation soln in c for code eval by steven a dunn

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

void init(Stack*);
void push(Stack*, int);
int pop(Stack*);

void trim(char*);

int main (int argc, char* const argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[512];
        while (fgets(line, sizeof(line), fp))
        {
            trim(line);

            Stack stack;
            init(&stack);
            char* token = strtok(line, " ");
            while (token != NULL)
            {
                int n = atoi(token);
                push(&stack, n);
                token = strtok(NULL, " ");
            }

            while (1)
            {
                int n = pop(&stack);
                if (n != EMPTY_STACK)
                    printf("%d ", n);
                n = pop(&stack);
                if (n == EMPTY_STACK)
                    break;
            }
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

void init(Stack* s)
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