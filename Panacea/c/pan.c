// panacea soln in c for code eval by steven a dunn

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char* const argv[])
{
	FILE *fp = fopen(argv[1], "r");
	if (fp)
	{
		char line[1024];
		while (fgets(line, sizeof(line), fp))
		{
			char *token = strtok(line, "|");
			char* vir = token;

			token = strtok(NULL, "|");
			char* ant = token;

			int vir_sum = 0;
			token = strtok(vir, " ");
			while (token)
			{
				vir_sum += strtol(token, NULL, 16);
				token = strtok(NULL, " ");
			}

			int ant_sum = 0;
			token = strtok(ant, " ");
			while (token)
			{
				ant_sum += strtol(token, NULL, 2);
				token = strtok(NULL, " ");
			}

			if (vir_sum <= ant_sum)
				puts("True");
			else
				puts("False");
		}
		fclose(fp);
	}
	return 0;
}