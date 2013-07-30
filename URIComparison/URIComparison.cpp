// URI Comparison solution in C++ for CodeEval.com by Steven A. Dunn

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

using std::cout;
using std::endl;
using std::hex;
using std::ifstream;
using std::stringstream;
using std::string;
using std::transform;

bool uriCompare(string, string);
string parseUri(string);
string getEncodedSymbol(string);

int main (int argc, char* argv[])
{
  ifstream inputFile(argv[1]);
  string line;

  if (inputFile)
  {
    while (getline(inputFile, line))
    {
      int semicolonPos = line.find(";");
      string uri1 = line.substr(0, semicolonPos);
      string uri2 = line.substr(semicolonPos + 1);
      if (uriCompare(uri1, uri2))
        cout << "True" << endl;
      else
        cout << "False" << endl;
    }
    inputFile.close();
  }

  return 0;
}

bool uriCompare(string uri1, string uri2)
{
  string parsedUri1 = parseUri(uri1);
  string parsedUri2 = parseUri(uri2);
 
  if (parsedUri1 == parsedUri2)
    return true;
  return false;
}

string parseUri(string uri)
{
  int portColonPos = uri.substr(uri.find(":") + 1).find(":");
  if (portColonPos < 0)
    uri.insert(uri.find("com") + 3, ":80");
  else if (uri.at(portColonPos + 6) == '/')
    uri.insert(portColonPos + 6, "80");

  for (int i = 0; i < uri.size(); ++i)
  {
    if (uri.at(i) == '%')
    {
      string encodedChar = uri.substr(i + 1, 2);
      uri.replace(i, 3, getEncodedSymbol(encodedChar));
    }
  }
  transform(uri.begin(), uri.end(), uri.begin(), ::tolower);  
  return uri;
}

string getEncodedSymbol(string encodedChar)
{
  stringstream ss(encodedChar);
  int val;
  ss >> hex >> val;

  string result = "";
  switch (val)
  {
    case 126: result = "~"; break;
  }

  return result;
}
