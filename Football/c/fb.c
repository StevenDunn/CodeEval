// football soln in c for code eval by steven a dunn

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main (int argc, char* const argv[])
{
	FILE *fp = fopen(argv[1], "r");
	if (fp)
	{
		char line[256];
		while(fgets(line, sizeof(line), fp))
		{
			char *token;
			int country_idx;

			country_idx = 0;
			token = strtok(line, "|");
			while (token != NULL)
			{
				
				token = strtok(NULL, "|");
			}

			
		}
		fclose(fp);
	}
	return 0;
}