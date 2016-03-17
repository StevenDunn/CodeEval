// real fake soln in cpp for code eval by steven a dunn

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <string>

using std::ifstream;
using std::remove_if;
using std::string;

int main (int argc, char* const argv[])
{
	ifstream input_file(argv[1]);
	string line;

	if (input_file)
	{
		while(getline(input_file, line))
		{
			line.erase(remove_if(line.begin(), line.end(), ::isspace), line.end());
			int cc_sum = 0;
			for (int i = 0; i < line.size(); i += 2)
				cc_sum += 2 * (line[i] - '0');
			for (int i = 1; i < line.size(); i += 2)
 				cc_sum += (line[i] - '0');
			  
 			if (cc_sum % 10 == 0)
 				puts("Real");
 			else
 				puts("Fake");
 				
		}
		input_file.close();
	}
	return 0;
}