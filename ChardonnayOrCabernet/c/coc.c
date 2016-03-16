// charonnday or cabernet soln in c for code eval by steven a dunn

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main (int argc, char* const argv[]) 
{
	FILE *fp = fopen(argv[1], "r");
	
	if (fp)
	{
		char line[256];
		while (fgets(line, sizeof(line), fp))
		{
			char *token, *wines, *text, *wine;
			int i, j, match_count, wine_count;
			int matches[15];

 			token = strtok(line, "|");
 			wines = token;

 			token = strtok(NULL, "|");
 			text = token;
 			while (isspace(*text))
 				++text;
 			for (i = 0; i < strlen(text); ++i)
 				if (text[i] == '\r' || text[i] == '\n')
 					text[i] = '\0';
 			
 			wine_count = 0;
			token = strtok(wines, " ");
			while (token != NULL)
			{
				wine = token;
				match_count = 0;
				for (i = 0; i < strlen(wine); ++i)
					matches[i] = 0;
				for (i = strlen(wine); i < 15; ++i)
					matches[i] = -1;

				for (i = 0; i < strlen(text); ++i)
				{
					for(j = 0; j < strlen(wine); ++j)
					{
						if (tolower(wine[j]) == tolower(text[i]) && matches[j] == 0)
						{
							matches[j] = 1;
							++match_count;
							break;
						}
					}
				}
				
				if (match_count == strlen(text))
				{
					++wine_count;
					printf("%s ", wine);
				}
				token = strtok(NULL, " ");
			}
			if (wine_count > 0)
				puts("");
			else
				puts("False");
		}
		fclose(fp);
	}
	return 0;
}