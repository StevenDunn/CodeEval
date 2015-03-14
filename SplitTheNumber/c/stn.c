// Split the Number C soln for Code Eval by Steven A Dunn

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void split_the_number(char*);
int find(char*, char, int);

int main(int argc, char* argv[])
{
  FILE *fp = fopen(argv[1], "r");
  if (fp != NULL)
  {
    char line[512];
    while (fgets(line, sizeof(line), fp))
      split_the_number(line);
    fclose(fp);
  }
  return 0;
}

void split_the_number(char* line)
{
  for (int i = 0; i < strlen(line); ++i)
    if (line[i] == '\n')
      line[i] = '\0';

  char *token, *nums, *expr;

  token = strtok(line, " ");
  nums = token;

  token = strtok(NULL, " ");
  expr = token;

  int operator_index = find(expr, '+', strlen(expr));
  if (operator_index == -1)
    operator_index = find(expr, '-', strlen(expr));

  char substr1[operator_index];
  strncpy(substr1, nums, operator_index + 1);
  substr1[operator_index] = '\0';

  char substr2[strlen(expr) - operator_index];
  strncpy(substr2, nums+operator_index, strlen(expr) - operator_index + 1);
  substr2[strlen(expr) - operator_index] = '\0';

  int num1 = atoi(substr1);
  int num2 = atoi(substr2);

  if (expr[operator_index] == '+')
    printf("%d\n", num1 + num2);
  else
    printf("%d\n", num1 - num2);
}

int find(char* arr, char c, int len)
{
  for(int i = 0; i < len; ++i)
  {
    if (*arr == c)
      return i;
    ++arr;
  }
  return -1;
}