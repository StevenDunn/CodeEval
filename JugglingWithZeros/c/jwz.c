// juggling with zeros soln in C for code eval by steven a dunn

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int* array;
    size_t used;
    size_t size;
} Array;

void init(Array*, size_t);
void insert(Array*, int);

char* ones (char*);
unsigned long to_decimal(char*);

int main(int argc, char* argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[2048];
        while (fgets(line, sizeof(line), fp))
        {
            for (int i = 0; i < strlen(line); ++i)
                if (line[i] == '\n')
                    line[i] = '\0';

            Array arr;
            init(&arr, 1);

            char* token = strtok(line, " ");
            while (token != NULL)
            {
                insert(&arr, strlen(token));
                token = strtok(NULL, " ");
            }

            char binary[2048];
            strcpy(binary, "");
            for (int i = 0; i < arr.used; i = i + 2)
            {
                int flag = arr.array[i];
                int seq = arr.array[i+1];

                char seq_str[2048];
                strcpy(seq_str, "0");

                for (int i = 1; i < seq; ++i)
                    strcat(seq_str, "0");

                if (flag == 2)
                    strcat(binary, ones(seq_str));
                else
                    strcat(binary, seq_str);
            }
            printf("%lu\n", to_decimal(binary));
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

char* ones (char* seq)
{
    char *result = (char*)malloc(strlen(seq) * sizeof(char));
    for (int i = 0; i < strlen(seq); ++i)
        strcat(result, "1");
    return result;
}

// grabbed from stack overflow b/c I was feeling lazy
unsigned long to_decimal(char* bin)
{
    unsigned long i, j;
    j = sizeof(unsigned long) * 64;
    while ( (j--) && ((*bin == '0') || (*bin == '1')) )
    {
        i <<= 1;
        if (*bin == '1')
            i++;
        bin++;
    }
    return i;
}