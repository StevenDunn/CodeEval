// gronsfeld cipher soln in c for code eval by steven a dunn

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char alphabet[] = {' ', '!', '\"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', '<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

char* decrypt(char* ciphertext, char* cipher);
int find(char* alphabet, char search_element);

int main (int argc, char* const argv[])
{

    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[512];
        while (fgets(line, sizeof(line), fp))
        {
            puts(line);
            char *token, *cipher, *text;
            token = strtok(line, ";");
            cipher = token;
            token = strtok(NULL, ";");
            text = token;

            char* result = decrypt(cipher, text);
            printf("%s\n", result);
            free(result);
        }
        fclose(fp);
    }
    return 0;
}

char* decrypt(char* ciphertext, char* cipher)
{
    while (strlen(cipher) < strlen(ciphertext))
    {
        strcat(cipher, cipher);
        printf("longer cipher is: %s", cipher);
        //cipher = cipher + cipher;
    }

    cipher[strlen(ciphertext)] = '\0';


    char* text = (char*)malloc(strlen(ciphertext) * sizeof(char));
    for (int i = 0; i < strlen(ciphertext); ++i)
    {
        char search_element = ciphertext[i];
        int location = find(alphabet, search_element);
        int updated_location = location - (cipher[i] - '0');
        text[i] = alphabet[updated_location];
    }
    return text;
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