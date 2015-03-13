// hidden digits soln in c for code eval by steven a dunn

#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int printHiddenDigits(char*);
int findHiddenDigits(char);

int main(int argc, char* argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[1024];
        while(fgets(line, sizeof(line), fp))
        {
            if(!printHiddenDigits(line))
                printf("NONE");
            puts("");
        }
        fclose(fp);
    }
    return 0;
}

int printHiddenDigits(char* line)
{
    int isEmpty = TRUE;
    for(int idx = 0; idx < strlen(line); ++idx)
        if(findHiddenDigits(line[idx]))
            isEmpty = FALSE;
    return !isEmpty;
}

int findHiddenDigits(char c)
{
    int charFound = TRUE;
    switch(c)
    {
        case 'a':
        case '0':
            printf("0");
            break;
        case 'b':
        case '1':
            printf("1");
            break;
        case 'c':
        case '2':
            printf("2");
            break;
        case 'd':
        case '3':
            printf("3");
            break;
        case 'e':
        case '4':
            printf("4");
            break;
        case 'f':
        case '5':
            printf("5");
            break;
        case 'g':
        case '6':
            printf("6");
            break;
        case 'h':
        case '7':
            printf("7");
            break;
        case 'i':
        case '8':
            printf("8");
            break;
        case 'j':
        case '9':
            printf("9");
            break;
        default:
            charFound = FALSE;
            break;
    }
  return charFound;
}