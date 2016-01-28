// compare points soln in c for code eval by steven a dunn

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char* const argv[])
{
	FILE *fp = fopen(argv[1], "r");
	if (fp)
	{
		char line[64];
		while (fgets(line, sizeof(line), fp))
		{
			int points[4] = {0, 0, 0, 0};
			int idx = 0;
			int o, p, q, r;

			char* token = strtok(line, " \n\r");
            while (token != NULL)
            {
                points[idx] = atoi(token);
                token = strtok(NULL, " \n\r");
                ++idx;
            }

            o = points[0];
			p = points[1];
			q = points[2];
			r = points[3];

			char* result;
			if (o == q)
			{
				if (p == r)
					result = "here";
				if (p < r)
					result = "N";
				if (p > r)
					result = "S";
			}
			if (o < q)
			{
				if (p == r)
					result = "E";
				if (p < r)
					result = "NE";
				if (p > r)
					result = "SE";
			}
			if (o > q)
			{
				if (p == r)
					result = "W";
				if (p < r)
					result = "NW";
				if (p > r)
					result = "SW";
			}

			puts(result);
		}
		fclose(fp);
	}
	return 0;
}