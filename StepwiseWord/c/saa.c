// stepwise words soln in c for code eval by steven a dunn

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char* const argv[]) {
  FILE *fp = fopen(argv[1], "r");
  if (fp != NULL) {
    char line[1024];
    while (fgets(line, sizeof(line), fp)) {
      puts(line);
    }
    fclose(fp);
  }
  return 0;
}