// real fake soln in c for code eval by steven a dunn

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main (int argc, char* const argv[])
{
	FILE *fp = fopen(argv[1], "r");

	if (fp)
	{
		char line[32];
		while(fgets(line, sizeof(line), fp))
		{
			int cc_sum;
			int i, offset;
			int num[16];

			offset = 0;
			for (i = 0; i < 19; ++i)
			{	
				if (line[i] == ' ')
				{
					++offset;
					continue;
				}
				num[i - offset] = line[i] - '0';
			}

			cc_sum = 0;
			for (i = 0; i < 16; i += 2)
				cc_sum += 2 * num[i];
			for (i = 1; i < 16; i += 2)
 				cc_sum += num[i];
			  
 			(cc_sum % 10 == 0) ? puts("Real") : puts("Fake");
		}
		fclose(fp);
	}
	return 0;
}