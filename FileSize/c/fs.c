// file size soln in c for code eval by steven a dunn

#include <stdio.h>

int main(int argc, char* argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        fseek(fp, 0L, SEEK_END);
        printf("%ld\n", ftell(fp));
        fclose(fp);
    }
    return 0;
}