// card number validation soln in c for code eval by steven a dunn

#include <stdio.h>
#include <string.h>

void trim(char*);
void reverse(char*);
void remove_spaces(char*, char*);

int main (int argc, char* const argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[512];
        while (fgets(line, sizeof(line), fp))
        {
            trim(line);
            reverse(line);
            char parsed_line[strlen(line)+1];
            remove_spaces(line, parsed_line);

            int sum = 0;
            for (int i = 0; i < strlen(parsed_line); ++i)
            {
                int digit = parsed_line[i] - '0';
                if ((i + 1) % 2 == 0)
                {
                    digit *= 2;
                    if (digit > 9)
                    {
                        int digit_1 = digit / 10;
                        int digit_2 = digit % 10;
                        digit = digit_1 + digit_2;
                    }
                }
                sum += digit;
            }
            if (sum % 10 == 0)
                puts("1");
            else
                puts("0");
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

void reverse(char* line)
{
    char *start, *end;
    start = line;
    end = start + strlen(line) - 1;
    while (start < end)
    {
        char temp = *start;
        *start = *end;
        *end = temp;

        ++start;
        --end;
    }
}

void remove_spaces(char* line, char* parsed_line)
{
    char* line_ptr = line;
    char* parsed_ptr = parsed_line;

    while(*line_ptr)
    {
        if (*line_ptr == ' ')
            ++line_ptr;

        *parsed_ptr = *line_ptr;
        ++line_ptr;
        ++parsed_ptr;
    }
    *parsed_ptr = '\0';
}