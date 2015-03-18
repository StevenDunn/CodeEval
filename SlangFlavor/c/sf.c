// slang flavor soln in c for code eval by steven a dunn

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, char* const argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        int is_slang = 0;
        int slang_index = 0;
        char* slang[] = {", yeah!", ", this is crazy, I tell ya.", ", can U believe this?", ", eh?", ", aw yea.", ", yo.", "? No way!", ". Awesome!"};
        char line[512];
        while (fgets(line, sizeof(line), fp))
        {
            for (int index = 0; index < strlen(line); index++)
            {
                char c = line[index];
                if (c == '.' || c == '?' || c == '!')
                {
                    if (is_slang)
                    {
                        printf("%s", slang[slang_index]);
                        slang_index += 1;
                        if (slang_index >= 8)
                            slang_index = 0;
                        is_slang = 0;
                    }
                    else
                    {
                        printf("%c", c);
                        is_slang = 1;
                    }
                }
                else
                {
                    printf("%c", c);
                }
            }
        }
        fclose(fp);
    }
    return 0;
}