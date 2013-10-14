// String Searching solution in C++ for CodeEval.com by Steven A. Dunn

#include <fstream>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;

void formatSourceString(string&);
void formatQueryString(string&);
string search(string, string);

int main(int argc, char* argv[])
{
  ifstream inputFile(argv[1]);
  string line;
    
  if(inputFile)
  {
	  while(getline(inputFile, line))
	  {
		  int commaPos = line.find(",");
		  string src = line.substr(0, commaPos);
		  string query = line.substr(commaPos + 1);

      formatSourceString(src);
      formatQueryString(query);

		  cout << search(src, query) << endl;
	  }
	  inputFile.close();      
  }
  return 0;
}

void formatSourceString(string& line)
{
  int starPos = line.find("*");
  while (starPos != string::npos)
  {
    line.replace(line.begin() + starPos, line.begin() + starPos + 1, "@");
    starPos = line.find("*");
  }
}

void formatQueryString(string& line)
{
  int starLiteralPos = line.find("\\*");
  while ( starLiteralPos != string::npos)
  {
    line.replace(line.begin() + starLiteralPos, line.begin() + starLiteralPos + 2, "@");
    starLiteralPos = line.find("\\*");
  }
}

string search(string src, string query)
{
  int queryIdx = 0;
  for (int i = 0; i < src.size(); ++i)
  {
    if (query[queryIdx] == '*')
    {
      ++queryIdx;
      while (i < src.size() && src[i] != query[queryIdx])
        ++i; 
    }

    if (src[i] == query[queryIdx])
      ++queryIdx;
    else
      queryIdx = 0;

    if (queryIdx == query.size())
      return "true";
  }  
	return "false";
}
