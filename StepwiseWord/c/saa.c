// stepwise words soln in c for code eval by steven a dunn

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
    	char* token = strtok(line, " \r\n");
    	char* word = token;
   		while(token)
   		{
    		if (strlen(token) > strlen(word))
    			word = token;
    		token = strtok(NULL, " \r\n");
    	}

    	int i;
    	for (i = 0; i < strlen(word); ++i)
    	{
    		int j;
    		for (j = 0; j < i; ++j)
    			printf("*");
    		printf("%c ", word[i]);
    	}
    	puts("");
    }
    fclose(fp);
  }
  return 0;
}