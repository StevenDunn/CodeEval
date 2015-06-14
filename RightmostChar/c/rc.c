// rightmost char soln in c for code eval by steven a dunn

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void trim(char*);

int main (int argc, char* const argv[]) {
  FILE *fp = fopen(argv[1], "r");
  if (fp != NULL) {
    char line[1024];
    while (fgets(line, sizeof(line), fp)) {
      trim(line);
      char *token = strtok(line, ",");
      char *text = token;
      token = strtok(NULL, ",");
      char *c = token;

      int text_idx = 0;
      int loc = -1;
      char* d = text;
      while (*d) {
        if (*d == *c)
          loc = text_idx;
        ++d;
        ++text_idx;
      }
      printf("%d\n", loc);
    }
    fclose(fp);
  }

  return 0;
}

void trim(char* line) {
  char* c = line;
  while (*c) {
    if (*c == '\n')
      *c = '\0';
    ++c;
  }
}