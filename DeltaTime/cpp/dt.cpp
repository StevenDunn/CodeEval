// delta time cpp soln for code eval by steven a dunn

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <time.h>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::stringstream;
using std::string;
using std::to_string;
using std::vector;

vector<string> tokenize(string);
vector<int> get_date_vals(string);
string format_time(int);

int main(int argc, char* argv[])
{
    ifstream input_file(argv[1]);
    string line;

    if (input_file)
    {
        while (getline(input_file, line))
        {
            vector<string> dates = tokenize(line);

            struct tm time_1;
            vector<int> date_vals = get_date_vals(dates[0]);
            time_1.tm_hour = date_vals[0];
            time_1.tm_min = date_vals[1];
            time_1.tm_sec = date_vals[2];
            time_1.tm_mon = 0;
            time_1.tm_mday = 1;
            time_1.tm_year = 70;
            time_1.tm_wday = 0;
            time_1.tm_yday = 0;

            struct tm time_2;
            date_vals = get_date_vals(dates[1]);
            time_2.tm_hour = date_vals[0];
            time_2.tm_min = date_vals[1];
            time_2.tm_sec = date_vals[2];
            time_2.tm_mon = 0;
            time_2.tm_mday = 1;
            time_2.tm_year = 70;
            time_2.tm_wday = 0;
            time_2.tm_yday = 0;

            double seconds = difftime(mktime(&time_1), mktime(&time_2));
            if (seconds < 0)
                seconds = seconds * -1;

            cout << format_time(seconds) << endl;

        }
        input_file.close();
    }

    return 0;
}

vector<string> tokenize(string line)
{
    std::vector<string> tokens;
    stringstream ss(line);
    string s;

    while (getline(ss, s, ' '))
        tokens.push_back(s);

    return tokens;
}

vector<int> get_date_vals(string date)
{
    vector<int> date_vals;
    stringstream ss(date);
    string s;

    while (getline(ss, s, ':'))
        date_vals.push_back(atoi(s.c_str()));

    return date_vals;
}

string format_time(int delta)
{
    int hours = delta / 3600;
    int rem = delta % 3600;

    int minutes = rem / 60;
    int seconds = rem % 60;

    string formatted_hour = to_string(hours);
    string formatted_min = to_string(minutes);
    string formatted_sec = to_string(seconds);

    if (hours < 10)
        formatted_hour = "0" + formatted_hour;
    if (minutes < 10)
        formatted_min = "0" + formatted_min;
    if (seconds < 10)
        formatted_sec = "0" + formatted_sec;

    return formatted_hour + ":" + formatted_min + ":" + formatted_sec;
}