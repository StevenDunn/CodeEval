// morse code soln in c by steven a dunn for code eval

#include <stdio.h>
#include <string.h>

int find(char*, char*[36]);

char* morse[36] = {
    ".-",
    "-...",
    "-.-.",
    "-..",
    ".",
    "..-.",
    "--.",
    "....",
    "..",
    ".---",
    "-.-",
    ".-..",
    "--",
    "-.",
    "---",
    ".--.",
    "--.-",
    ".-.",
    "...",
    "-",
    "..-",
    "...-",
    ".--",
    "-..-",
    "-.--",
    "--..",
    ".----",
    "..---",
    "...--",
    "....-",
    ".....",
    "-....",
    "--...",
    "---..",
    "----.",
    "-----"
};

char alphanum[36] = {
    'A',
    'B',
    'C',
    'D',
    'E',
    'F',
    'G',
    'H',
    'I',
    'J',
    'K',
    'L',
    'M',
    'N',
    'O',
    'P',
    'Q',
    'R',
    'S',
    'T',
    'U',
    'V',
    'W',
    'X',
    'Y',
    'Z',
    '1',
    '2',
    '3',
    '4',
    '5',
    '6',
    '7',
    '8',
    '9',
    '0'
};

int main(int argc, char* argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[1024];
        while (fgets(line, sizeof(line), fp))
        {
            for(int i = 0; i < sizeof(line); ++i)
                if (line[i] == '\n')
                    line[i] = '\0';

            char parsed_line[1024];
            int parsed_idx = 0;
            for(int i = 0; i < sizeof(line); ++i)
            {
                if ( line[i] == ' ' && line[i+1] == ' ')
                {
                        parsed_line[parsed_idx] = '@';
                        parsed_idx++;
                        i++;
                }
                else
                {
                    parsed_line[parsed_idx] = line[i];
                    parsed_idx++;
                }
            }

            char* words[32];
            int words_idx = 0;
            char* token = strtok(parsed_line, "@");
            while (token != NULL)
            {
                words[words_idx] = token;
                words_idx++;
                token = strtok(NULL, "@");
            }

            for (int i = 0; i < words_idx; ++i)
            {
                token = strtok(words[i], " ");
                while (token != NULL)
                {
                    int morse_idx = find(token, morse);
                    if (morse_idx >= 0)
                        printf("%c", alphanum[morse_idx]);
                    else
                        printf(" ");
                    token = strtok(NULL, "  ");
                }
                printf(" ");
            }
            puts("");
        }
        fclose(fp);
    }
    return 0;
}

int find(char* token, char* arr[36])
{
    for (int i = 0; i < 36; ++i)
        if (!strcmp(token, arr[i]))
        {
            return i;
            break;
        }
    return -1;
}