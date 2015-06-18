// juggling with zeros soln in C for code eval by steven a dunn

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char** array;
    size_t used;
    size_t size;
} Array;

void init(Array*, size_t);
void insert(Array*, char*);

void trim(char*);
char* ones (char*);
unsigned long to_decimal(char*);

int main(int argc, char* argv[])
{
    int i, j;
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[2048];
        while (fgets(line, sizeof(line), fp))
        {
            trim(line);

            Array arr;
            init(&arr, 1);
            char* token = strtok(line, " ");
            while (token != NULL)
            {
                insert(&arr, token);
                token = strtok(NULL, " ");
            }

            char binary[2048];
            strcpy(binary, "");
            for (i = 0; i < arr.used; i = i + 2)
            {
                char* flag = arr.array[i];
                char* seq = arr.array[i+1];

                if (!strcmp(flag, "00")) {
                    char* one = ones(seq);
                    strcat(binary, one);
                }
                else
                    strcat(binary, seq);
            }
            printf("%lu\n", to_decimal(binary));
        }
        fclose(fp);
    }
    return 0;
}

void init(Array* arr, size_t initSize)
{
    arr->array = (char**)malloc(initSize * sizeof(char*));
    arr->used = 0;
    arr->size = initSize;
}

void insert(Array* arr, char* element)
{
    if (arr->used == arr->size)
    {
        arr->size *= 2;
        arr->array = (char**)realloc(arr->array, arr->size * sizeof(char*));
    }
    arr->array[arr->used++] = element;
}

void trim(char* line) {
    int i;
    for (i = 0; i < strlen(line); ++i)
        if (line[i] == '\n' || line[i] == '\r')
            line[i] = '\0';
}

char* ones (char* seq)
{
    int i;
    char *result = (char*)malloc(strlen(seq) * sizeof(char));
    for (i = 0; i < strlen(seq); ++i)
        strcat(result, "1");
    return result;
}

// grabbed from stack overflow b/c I was feeling lazy
unsigned long to_decimal(char* bin)
{
    unsigned long dec = 0;

    while (*bin) { 
        if (*bin == '1') 
            dec = dec * 2 + 1; 
        else if (*bin == '0') 
            dec *= 2;
        ++bin; 
    }
    return dec;
}