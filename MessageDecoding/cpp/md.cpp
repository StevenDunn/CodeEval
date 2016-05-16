// message decoding soln for code eval by steven a dunn

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <map>
#include <string>

using std::bitset;
using std::ifstream;
using std::map;
using std::min;
using std::string;

void get_header(string, int&, string&);
map<string, char> create_header_dict(string);
void get_next_key(string&, int&, int&);
string generate_key(string, int);
string parse_message(map<string, char>, string);

int main (int argc, char* const argv[])
{
	ifstream input_file(argv[1]);
	string line;

	if (input_file)
	{
		while(getline(input_file, line))
		{
			int idx;
			string header_str;
			get_header(line, idx, header_str);
			map<string, char> header = create_header_dict(header_str);
			string message = line.substr(idx);
			string parsed_message = parse_message(header, message);
			puts(parsed_message.c_str());
		}
		input_file.close();
	}
	return 0;
}

void get_header(string line, int& idx, string& header_str)
{
	idx = min(line.find('0'), line.find('1'));
	header_str = line.substr(0, idx);
}

map<string, char> create_header_dict(string header_str)
{
	map<string, char> header;
	string key = "0";
	int i = 1;
	int n = 1;
	for (int idx = 0; idx < header_str.size(); ++idx)
	{
		header[key] = header_str[idx];
		get_next_key(key, i, n);
	}
	return header;
}

void get_next_key(string& key, int& i, int& n)
{
	int key_len = key.size();
	if (i < ((int)pow(2, n) - 1))
	{
		key = generate_key(key, key_len);
		i++;
	}
	else
	{
		key = "";
		for (int idx = 0; idx < key_len+1; ++idx)
			key += "0";
		i = 1;
		n++;
	}
}

string generate_key(string key, int key_len)
{ 
	string binary = bitset<32>(strtol(key.c_str(), NULL, 2) + 1).to_string();
	binary = binary.substr(binary.find("1"));
	while (binary.size() < key_len)
		binary = "0" + binary;
	return binary;
}

string parse_message(map<string, char> header, string message)
{
	string result = "";
	while (!message.empty())
	{
		int length = strtol(message.substr(0, 3).c_str(), NULL, 2);
		message = message.substr(3);
		string terminator = "";
		for (int i = 0; i < length; ++i)
			terminator += "1";
		if (length == 0)
			break;
		for (int i = 0; i < message.size(); i += length)
		{
			string word = message.substr(i, length);
			if (word == terminator)
			{
				message = message.substr(i+length);
				break;
			}
			else
			{
				result += header[word];
			}
		}
	}
	return result;
}