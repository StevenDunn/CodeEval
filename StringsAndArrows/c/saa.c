// strings and arrows soln in c for code eval by steven a dunn

#include <stdio.h>
#include <string.h>

int main (int argc, char* const argv[]) {
  FILE *fp = fopen(argv[1], "r");
  if (fp != NULL) {
    char line[1024];
    while (fgets(line, sizeof(line), fp)) {
      int total = 0;
      int i = 0;
      for (i = 0; i <= strlen(line) - 5; i++) {
        char sub[6];
        strncpy(sub, line + i, 5);
        sub[5] = '\0';
        if (!strcmp(sub, "<--<<") || !strcmp(sub, ">>-->"))
          total++;
      }
      printf("%d\n", total);
    }
    fclose(fp);
  }
  return 0;
}