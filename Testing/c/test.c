// testing soln in c for code eval by steven a dunn

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main (int argc, char* const argv[])
{
	FILE *fp = fopen(argv[1], "r");
	if (fp)
	{
		char line[1024];
		while(fgets(line, sizeof(line), fp))
		{
			char* token, *text1, *text2;

			token = strtok(line, "|\r\n");
			text1 = token;

			token = strtok(NULL, "|\r\n");
			text2 = token;

			int i;
			int bug_count = 0;
			for (i = 0; i < strlen(text1)-1; ++i)
			{
				// using an offset on text2 to skip left trimming it
				if (text1[i] != text2[i+1])
					++bug_count;
			}

			char* result;
			if (bug_count == 0)
				result = "Done";
			else if (bug_count <= 2)
				result = "Low";
			else if (bug_count <= 4)
				result = "Medium";
			else if (bug_count <= 6)
				result = "High";
			else
				result = "Critical";

			puts(result);
		}
		fclose(fp);
	}
	return 0;
}