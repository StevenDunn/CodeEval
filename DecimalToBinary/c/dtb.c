// decimal to binary soln in c for code eval by steven a dunn

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void trim(char*);
char *decimal_to_binary(int);
int binary_trim(char*);

int main (int argc, char* const argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[128];
        while (fgets(line, sizeof(line), fp))
        {
            trim(line);
            char *binary = decimal_to_binary(atoi(line));
            int idx = binary_trim(binary);
            if (idx == strlen(binary))
            {
                puts("0");
                continue;
            }
            for (int i = idx; i < strlen(binary); ++i)
                printf("%c", binary[i]);
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

char *decimal_to_binary(int n)
{
   int c, d, count;
   char *pointer;

   count = 0;
   pointer = (char*)malloc(32+1);

   if ( pointer == NULL )
      exit(EXIT_FAILURE);

   for ( c = 31 ; c >= 0 ; c-- )
   {
      d = n >> c;

      if ( d & 1 )
         *(pointer+count) = 1 + '0';
      else
         *(pointer+count) = 0 + '0';

      count++;
   }
   *(pointer+count) = '\0';

   return  pointer;
}

int binary_trim(char* binary)
{
    char* c = binary;
    int idx = 0;
    while (*c)
    {
        if (*c == '1')
            break;
        ++c;
        ++idx;
    }
    return idx;
}