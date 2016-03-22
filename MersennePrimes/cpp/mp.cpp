// mersenne primes soln in cpp for code eval by steven a dunn

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>

using std::ifstream;
using std::string;
using std::vector;

bool is_prime(int);

int main (int argc, char* const argv[])
{
	ifstream input_file(argv[1]);
	string line;

	if (input_file)
	{
		while(getline(input_file, line))
		{
			int lim = atoi(line.c_str());
			int p = 2;
			int num = pow(2, p) - 1;
			vector<int> results;

			while (num <= lim)
			{
				if (is_prime(p))
					results.push_back(num);
				++p;
				num = pow(2, p) - 1;
			}
			for (int i = 0; i < results.size() - 1; ++i)
				printf("%d, ", results[i]);
			printf("%d \n", results[results.size()-1]);
		}
		input_file.close();
	}
}

bool is_prime(int n)
{
  for (int i = 2; i <= n/2; ++i)
   	if (n % i == 0)
    	return false;
  return true;
}