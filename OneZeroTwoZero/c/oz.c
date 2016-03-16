// one zero two zeros c soln for code eval by steven a dunn

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int find_start(char*);
int count_zeros(char*, int);

int main (int argc, char* const argv[])
{
	FILE *fp = fopen(argv[1], "r");
	if (fp)
	{
		char line[1024];
		while(fgets(line, sizeof(line), fp))
		{
			char *token;
			int num_zeros, max_num, num_count, one_idx, zeros;
			int i;

			token = strtok(line, " ");
			num_zeros = atoi(token);

			token = strtok(NULL, " ");
			max_num = atoi(token);

			num_count = 0;
			for (i = 1; i < max_num + 1; ++i)
			{
				unsigned int j, idx;
				char binary[33];
				binary[32] = '\0';

				idx = 0;
				for (j = 1 << 31; j > 0; j = j / 2)
				{
					if (i & j) 
						binary[idx] = '1';
					else
						binary[idx] = '0';
					++idx;
				}

			    one_idx = find_start(binary);
			    zeros = count_zeros(binary, one_idx);
			    if (zeros == num_zeros)
			      ++num_count;
			}
  			printf("%d\n", num_count);
		}
		fclose(fp);
	}
	return 0;
}

int find_start(char* string)
{
	int i;
	for (i = 0; i < strlen(string); ++i)
	{
		if (string[i] == '1')
			return i;
	}
	return -1;
}

int count_zeros(char* string, int start_idx)
{
	int sum;

	sum = 0;
	string += start_idx;
	while (*string != '\0')
	{
		if (*string == '0')
			++sum;
		++string;
	}
	return sum;
}