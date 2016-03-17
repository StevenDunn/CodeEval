// trick or treat soln in c for code eval by steven a dunn

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main (int argc, char* const argv[])
{
	FILE *fp = fopen(argv[1], "r");

	if (fp)
	{
		char line[64];
		while(fgets(line, sizeof(line), fp))
		{
			char *token, *vampires, *zombies, *witches, *houses, *p;
			int vals[4];

			token = strtok(line, ",");
			vampires = token;
			p = strstr(vampires, ":");
			p += 2;
			vals[0] = atoi(p);

			token = strtok(NULL, ",");
			zombies = token;
			p = strstr(zombies, ":");
			p += 2;
			vals[1] = atoi(p);

			token = strtok(NULL, ",");
			witches = token;
			p = strstr(witches, ":");
			p += 2;
			vals[2] = atoi(p);

			token = strtok(NULL, ",");
			houses = token;
			p = strstr(houses, ":");
			p += 2;
			vals[3] = atoi(p);

			printf("%d\n", (((3 * vals[0]) + (4 * vals[1]) + (5 * vals[2])) * vals[3])/(vals[0] + vals[1] + vals[2]) );
		
		}
		fclose(fp);
	}
	return 0;
}
