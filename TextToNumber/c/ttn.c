// text to number c soln for code eval by steven a dunn

#include <stdio.h>
#include <string.h>

#define FALSE 0
#define TRUE 1

int negative = FALSE;

void trim(char*);
long text_to_number(char*);
int is_digit(char* word, long* convertedValue);
int is_magnitude(char* word, long* convertedValue);
long combine_results(long sub_result, long prior_sub_result);
int is_negative(char* word);

int main (int argc, char* const argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[1024];
        while (fgets(line, sizeof(line), fp))
        {
            printf("%ld\n", text_to_number(line));
        }
        fclose(fp);
    }
    return 0;
}

void trim(char* line)
{
    char *c = line;
    while (*c)
    {
        if (*c == '\n')
            *c = '\0';
        ++c;
    }
}

long text_to_number(char* line)
{
    long result = 0;
    long sub_result = 0;
    long prior_sub_result = 0;
    long converted_value = 0;
    negative = FALSE;

    trim(line);

    char *token = strtok(line, " ");
    while (token != NULL)
    {
        if(is_digit(token, &converted_value))
            sub_result += converted_value;

        else if(is_magnitude(token, &converted_value))
        {
            if(sub_result == 0)
            {
                sub_result = prior_sub_result * converted_value;
                result -= prior_sub_result;
            }
            else
            {
                sub_result *= converted_value;

                if(sub_result > prior_sub_result && prior_sub_result != 0)
                {
                    result -= prior_sub_result;
                    sub_result = combine_results(sub_result, prior_sub_result);
                }
            }
            result += sub_result;
            prior_sub_result = sub_result;
            sub_result = 0;
        }

        else if (is_negative(token))
            negative = TRUE;

        token = strtok(NULL, " ");
    }

    if(sub_result != 0)
        result += sub_result;

    if(negative)
        result *= -1;

    return result;
}

int is_digit(char* word, long* converted_value)
{
  int result = TRUE;
  if (!strcmp(word, "one"))
    *converted_value = 1;
  else if (!strcmp(word, "two"))
    *converted_value = 2;
  else if (!strcmp(word, "three"))
    *converted_value = 3;
  else if (!strcmp(word, "four"))
    *converted_value = 4;
  else if (!strcmp(word, "five"))
    *converted_value = 5;
  else if (!strcmp(word, "six"))
    *converted_value = 6;
  else if (!strcmp(word, "seven"))
    *converted_value = 7;
  else if (!strcmp(word, "eight"))
    *converted_value = 8;
  else if (!strcmp(word, "nine"))
    *converted_value = 9;
  else if (!strcmp(word, "ten"))
    *converted_value = 10;
  else if (!strcmp(word, "eleven"))
    *converted_value = 11;
  else if (!strcmp(word, "twelve"))
    *converted_value = 12;
  else if (!strcmp(word, "thirteen"))
    *converted_value = 13;
  else if (!strcmp(word, "fourteen"))
    *converted_value = 14;
  else if (!strcmp(word, "fifteen"))
    *converted_value = 15;
  else if (!strcmp(word, "sixteen"))
    *converted_value = 16;
  else if (!strcmp(word, "seventeen"))
    *converted_value = 17;
  else if (!strcmp(word, "eighteen"))
    *converted_value = 18;
  else if (!strcmp(word, "nineteen"))
    *converted_value = 19;
  else if (!strcmp(word, "twenty"))
    *converted_value = 20;
  else if (!strcmp(word, "thirty"))
    *converted_value = 30;
  else if (!strcmp(word, "forty"))
    *converted_value = 40;
  else if (!strcmp(word, "fifty"))
    *converted_value = 50;
  else if (!strcmp(word, "sixty"))
    *converted_value = 60;
  else if (!strcmp(word, "seventy"))
    *converted_value = 70;
  else if (!strcmp(word, "eighty"))
    *converted_value = 80;
  else if (!strcmp(word , "ninety"))
    *converted_value = 90;
  else
    result = FALSE;

  return result;
}

int is_magnitude(char* word, long* convertedValue)
{
  int result = TRUE;
  if (!strcmp(word, "hundred"))
    *convertedValue = 100;
  else if (!strcmp(word, "thousand"))
    *convertedValue = 1000;
  else if (!strcmp(word, "million"))
    *convertedValue = 1000000;
  else
    result = FALSE;

  return result;
}

long combine_results(long sub_result, long prior_sub_result)
{
  char ss_sub[20];
  sprintf(ss_sub, "%ld", sub_result);
  int sub_len = strlen(ss_sub);

  char ss_prior[20];
  sprintf(ss_prior, "%ld", prior_sub_result);
  int prior_len = strlen(ss_prior);

  while(prior_len <= sub_len)
  {
    prior_sub_result *= 10;
    prior_len++;
  }

  return prior_sub_result + sub_result;
}

int is_negative(char* word)
{
  if (!strcmp(word, "negative"))
    negative = TRUE;
  return negative;
}