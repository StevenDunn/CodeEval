// string mask soln in c for code eval by steven a dunn

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* const argv[])
{
	FILE *fp = fopen(argv[1], "r");
	if (fp)
	{
		char line[64];
		while(fgets(line, sizeof(line), fp))
		{
			char* text, *bin;
			int idx = 0;
			char* token = strtok(line, " \n\r");
			while (token)
			{
				if (idx == 0)
					text = token;
				else if (idx == 1)
					bin = token;
				token = strtok(NULL, " \n\r");
				++idx;
			}
			
			int i;
			for (i = 0; i < strlen(text); ++i)
			{
				if (bin[i] == '1')
					printf("%c", toupper(text[i]));
				else if (bin[i] == '0')
					printf("%c", tolower(text[i]));
			}
			puts("");
		}
		fclose(fp);
	}
	return 0;
}