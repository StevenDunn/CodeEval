// Reverse Words program written in C++ for CodeEval.com by Steven A. Dunn

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
  ifstream inputFile(argv[1]);
  string line, result;
  vector<string> words;

  if(inputFile)
  {
    getline(inputFile, line);
    
    istringstream iss(line);
    copy(istream_iterator<string>(iss), 
      istream_iterator<string>(), 
      back_inserter<vector<string> >(words));  

    string result;
    for(int i = words.size()-1; i >= 0; i--)
    {
      result.append(words[i]);
      result.append(" ");
    }

    int sz = result.size();
    result.resize(sz-1);
  
    cout << result;

    while(getline(inputFile, line))
    {

      if(line.empty()) { continue; }

      cout << endl;

      stringstream ssline(line);

      words.clear();
      result.clear();
   
      ssline << line;

      copy(istream_iterator<string>(ssline), 
        istream_iterator<string>(), 
        back_inserter<vector<string> >(words));

      for(int i = words.size()-1; i >= 0; i--)
      {
        result.append(words[i]);
        result.append(" ");
      }

      sz = result.size();
      result.resize(sz-1);
  
      cout << result;
    } 
  }
  else perror("UNABLE TO OPEN INPUT FILE");

  inputFile.close();

  return 0;
}
