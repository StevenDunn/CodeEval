// swap numbers soln in c for code eval by steven a dunn

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void trim(char*);

int main (int argc, char* const argv[]) {
	FILE* fp = fopen(argv[1], "r");
	if (fp != NULL) {
		char buf[1024];
		while(fgets(buf, sizeof(buf), fp)) {
			trim(buf);
			char* tok = strtok(buf, " ");
			while(tok) {
				char pre = tok[0];
				char suf = tok[strlen(tok)-1];
				tok++;

				char tok_buf[strlen(tok)];
				strncpy(tok_buf, tok, strlen(tok)-1);
				tok_buf[strlen(tok)-1] = '\0';

				printf("%c%s%c ", suf, tok_buf, pre);
				tok = strtok(NULL, " ");
			}
			puts("");
		}
		fclose(fp);
	}
}

void trim(char* line) {
	char* p = line;
	while (*p)
	{
		if (*p == '\n' || *p == '\r')
			*p = '\0';
		++p;
	}
}