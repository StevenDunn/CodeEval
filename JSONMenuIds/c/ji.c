// json ids soln in c for code eval by steven a dunn

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char **array;
    size_t used;
    size_t size;
} Array;

void init(Array*, size_t);
void insert(Array*, char*);
Array split(char*, char*);
size_t find(char*, char*, size_t);
char* substr(char*, size_t, size_t);
int getIdValue(char*);
void erase(char*, char);

int main (int argc, char* const argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[1024];
        while (fgets(line, sizeof(line), fp))
        {
            if (line != NULL)
            {
                Array idTokens = split(line, "id");
                Array labelTokens;
                init(&labelTokens, 1);
                int sum = 0;
                printf("id tokens used: %zu id tokens: %s\n", idTokens.used, idTokens.array[0]);
                for(int i = 0; i < idTokens.used; ++i)
                {
                    labelTokens = split(idTokens.array[i], "label");
                    if (labelTokens.used > 1 &&
                        labelTokens.array[0][0] == 'd' &&
                        labelTokens.array[1][0] == 'a')
                    {
                        printf("%s", labelTokens.array[0]);
                        int idValue = getIdValue(labelTokens.array[0]);
                        sum += idValue;
                    }
                }
                printf("%d\n", sum);

                for (int i = 0; i < idTokens.used; ++i)
                    free(idTokens.array[i]);
                free(idTokens.array);
            }
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

Array split(char* line, char* delimiter)
{
    Array tokens;
    init(&tokens, 1);
    size_t prev, pos;
    prev = 0;
    pos = find(line, delimiter, prev);
    printf("pos: %zu\n", pos);
    while (pos !=  -1)
    {

        printf("pos: %zu prev: %zu\n", pos, prev);
        if (pos > prev)
           insert(&tokens, substr(line, prev, pos - prev));
        prev = pos + 1;
        pos = find(line, delimiter, prev);
    }
    if (prev < strlen(line))
        insert(&tokens, substr(line, prev, -1));

    return tokens;
}

size_t find(char* line, char* delimiter, size_t prev)
{
    printf("line: %s\n", line);
    puts(delimiter);
    line += prev;
    printf("line 2: %s\n", line);
    char* token = strtok(line, delimiter);
    puts(token);
    if (token != NULL)
        return strlen(token);
    return -1;
}

char* substr(char* line, size_t start, size_t end)
{
    if (end == -1)
        end = strlen(line);
    char* str = (char*)malloc((end - start) * sizeof(char));
    memcpy(str, line+start, end-start);
    return str;
}

int getIdValue(char* word)
{
    char chars[] = "{}abcdefghijklmnopqrstuvwxyz:\", ";
    puts(word);
    for(int i = 0; i < strlen(chars); ++i)
        erase(word, chars[i]);
    puts(word);
    int result = atoi(word);
    puts(word);
    return result;
}

void erase(char* word, char c)
{
    char *wp = word;
    char *updated_word = (char*)malloc(strlen(word) * sizeof(char));
    char *uwp = updated_word;
    while (*wp)
    {
        if (*wp == c)
            --uwp;
        else
            *uwp = *wp;
        ++wp;
        ++uwp;
    }
    *uwp = '\0';
    strncpy(word, updated_word, strlen(updated_word));
    free(updated_word);
}