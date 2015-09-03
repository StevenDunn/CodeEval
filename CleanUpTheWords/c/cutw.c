// clean up the words soln in c for code eval by steven a dunn

#include <stdio.h>

int main (int argc, char* const argv[])
{
	FILE *fp = fopen(argv[1], "r");
	if (fp != NULL)
	{
		char line[1024];
		while (fgets(line, sizeof(line), fp))
		{
			int i;
			int print_space = 0;
			
			for (i = 0; i < sizeof(line); i++) {
				if (line[i] == '\n' || line[i] == '\0')
					break;

				if (isalpha(line[i]))
				{
					printf("%c", tolower(line[i]));
					print_space = 1;
				}
				else {
					if (print_space)
					{
						printf(" ");
						print_space = 0;
					}
				}
			}
			puts("");
		}
		fclose(fp);
	}
	
	
	return 0;
}