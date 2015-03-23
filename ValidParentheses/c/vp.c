// valid parenthese soln in c for code eval by steven a dunn

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
char* is_valid(char*);
char* compare(char, Stack*);

int main (int argc, char* const argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[1024];
        while (fgets(line, sizeof(line), fp))
        {
            trim(line);
            printf("%s\n", is_valid(line));
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

char* is_valid(char* line)
{
    Stack paren_stack;;
    init(&paren_stack);

    char* result = "True";

    for (int i = 0; i < strlen(line); ++i)
    {
        char c = line[i];
        result = compare(c, &paren_stack);
        if (!strcmp(result, "False"))
            break;
    }
    if (pop(&paren_stack) != EMPTY_STACK)
        result = "False";
    return result;
}

char* compare(char c, Stack* paren_stack)
{
    if (c == '(')
        push(paren_stack, ')');
    else if (c == '[')
        push(paren_stack, ']');
    else if (c == '{')
        push(paren_stack, '}');
    else if (c == ')' || c == ']' || c == '}')
    {
        char paren = pop(paren_stack);
        if (c != paren)
            return "False";
    }
    return "True";
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