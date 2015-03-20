// gronsfeld cipher soln in c for code eval by steven a dunn

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char alphabet[] = {' ', '!', '\"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', '<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

void decrypt(char* ciphertext, char* cipher);
int find(char* alphabet, char search_element);

int main (int argc, char* const argv[])
{

    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[2048];
        while (fgets(line, sizeof(line), fp))
        {
            for (int i = 0; i < sizeof(line); ++i)
                if (line[i] == '\n')
                    line[i] = '\0';

            char *token, *cipher_tok, *text_tok;
            token = strtok(line, ";");
            cipher_tok = token;
            token = strtok(NULL, ";");
            text_tok = token;

            char text[strlen(text_tok)];
            strcpy(text, text_tok);

            char cipher[strlen(cipher_tok)];
            strcpy(cipher, cipher_tok);

            decrypt(text, cipher);

        }
        fclose(fp);
    }
    return 0;
}

void decrypt(char* ciphertext, char* cipher)
{
    char text[strlen(ciphertext)+1];
    text[strlen(ciphertext)] = '\0';
    for (int i = 0; i < strlen(ciphertext); ++i)
    {
        int j = i % strlen(cipher);

        int location = find(alphabet, ciphertext[i]);
        int updated_location = location - (cipher[j] - '0');
         if (updated_location < 0)
            updated_location = strlen(alphabet) + updated_location;
        text[i] = alphabet[updated_location];
    }
    printf("%s\n", text);
}

int find(char* alphabet, char search_element)
{
    char *c = alphabet;
    int idx = 0;
    while (*c)
    {
        if (*c == search_element)
            return idx;
        ++c;
        ++idx;
    }
    return -1;
}