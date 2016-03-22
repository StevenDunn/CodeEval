// mersenne primes soln in c for code eval by steven a dunn

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_prime(int);

int main (int argc, char* const argv[])
{
	FILE *fp = fopen(argv[1], "r");

	if (fp)
	{
		char line[8];
		while(fgets(line, sizeof(line), fp))
		{
			int lim, p, num, idx, i;
			int results[4];


			lim = atoi(line);
			p = 2;
			num = pow(2, p) - 1;
			results[4];
			idx = 0;

			while (num <= lim)
			{
				if (is_prime(p))
				{
					results[idx] = num;
					++idx;
				}
				++p;
				num = pow(2, p) - 1;
			}
			for (i = 0; i < idx-1; ++i)
				printf("%d, ", results[i]);
			printf("%d \n", results[idx-1]);
		}
		fclose(fp);
	}
}

int is_prime(int n)
{
	int i;
  	for (i = 2; i <= n/2; ++i)
   		if (n % i == 0)
    		return 0;
  	return 1;
}