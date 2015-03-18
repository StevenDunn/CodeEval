// slang flavor cpp soln for code eval by steven a dunn

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::vector;

int main(int argc, char* argv[])
{
    ifstream input_file(argv[1]);
    string line;

    if (input_file)
    {
        bool is_slang = false;
        int slang_index = 0;
        vector<string> slang = {", yeah!", ", this is crazy, I tell ya.", ", can U believe this?", ", eh?", ", aw yea.", ", yo.", "? No way!", ". Awesome!"};
        while (getline(input_file, line))
        {
            string new_line = line;
            int offset = 0;
            for (int index = 0; index < line.size(); index++)
            {
                char c = line[index];
                if (c == '.' || c == '?' || c == '!')
                {
                    if (is_slang)
                    {
                        new_line = new_line.substr(0,index+offset) + slang[slang_index] + new_line.substr(index+offset+1);
                        offset += slang[slang_index].size() - 1;
                        slang_index += 1;
                        if (slang_index >= 8)
                            slang_index = 0;
                    }
                    is_slang = !is_slang;
                }
            }
            cout << new_line << endl;
        }
        input_file.close();
    }
    return 0;
}