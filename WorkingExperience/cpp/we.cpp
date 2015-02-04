// working experience cpp soln for code eval by steven a dunn

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::remove;
using std::string;
using std::vector;

vector<string> parse_dates(string);
void update_work_history(vector<string>, int(&)[30][12]);
void parse_date_range(string, string, int&, int&, int&, int&);
int get_month(string);
int count_months(int(&)[30][12]);

int main(int argc, char* argv[])
{
    ifstream input_file(argv[1]);
    string line;

    if (input_file)
    {
        while (getline(input_file, line))
        {
            int work_history[30][12];
            for (int i = 0; i < 30; ++i)
                for (int j = 0; j < 12; ++j)
                    work_history[i][j] = 0;

            vector<string> dates = parse_dates(line);
            update_work_history(dates, work_history);
            cout << count_months(work_history)/12 << endl;
        }
        input_file.close();
    }
    return 0;
}

vector<string> parse_dates(string raw_line)
{
    istringstream iss(raw_line);
    string line;

    vector<string> date_ranges;
    while(getline(iss, line, ';'))
        date_ranges.push_back(line);

    vector<string> dates;
    for (int i = 0; i < date_ranges.size(); ++i)
    {
        istringstream iss(date_ranges[i]);
        while (getline(iss, line, '-'))
            dates.push_back(line);
    }
    return dates;
}

void update_work_history(vector<string> dates, int(&work_history)[30][12])
{
    for (int i = 0; i < dates.size(); i = i + 2)
    {
        string date1 = dates[i];
        string date2 = dates[i+1];
        int start_month, start_year, finish_month, finish_year;
        parse_date_range(date1, date2, start_month, start_year, finish_month, finish_year);

        for (int year = start_year; year <= finish_year; ++year)
        {
            int begin, end;
            if (start_year == finish_year)
            {
                begin = start_month;
                end = finish_month + 1;
            }
            else if (year == start_year)
            {
                begin = start_month;
                end = 12;
            }
            else if (year == finish_year)
            {
                begin = 0;
                end = finish_month + 1;
            }
            else
            {
                begin = 0;
                end = 12;
            }

            for (int month = begin; month < end; ++month)
                work_history[year][month] = 1;
        }
    }
}

void parse_date_range(string date1, string date2, int& start_month, int& start_year, int& finish_month, int& finish_year)
{
    istringstream iss(date1);
    string line;
    vector<string> tokens;
    while (getline(iss, line, ' '))
        if (line != "")
            tokens.push_back(line);
    start_month = get_month(tokens[0]);
    start_year = atoi(tokens[1].c_str()) - 1990;

    istringstream iss2(date2);
    line = "";
    tokens.clear();
    while (getline(iss2, line, ' '))
        if (line != "")
            tokens.push_back(line);
    finish_month = get_month(tokens[0]);
    finish_year = atoi(tokens[1].c_str()) - 1990;
}

int get_month(string month)
{
    int result;
    if (month == "Jan")
        result = 0;
    else if (month == "Feb")
        result = 1;
    else if (month == "Mar")
        result = 2;
    else if (month == "Apr")
        result = 3;
    else if (month == "May")
        result = 4;
    else if (month == "Jun")
        result = 5;
    else if (month == "Jul")
        result = 6;
    else if (month == "Aug")
        result = 7;
    else if (month == "Sep")
        result = 8;
    else if (month == "Oct")
        result = 9;
    else if (month == "Nov")
        result = 10;
    else if (month == "Dec")
        result = 11;
    return result;
}

int count_months(int(&work_history)[30][12])
{
    int months_worked = 0;
    for (int year = 0; year < 30; ++year)
        for (int month = 0; month < 12; ++month)
            if (work_history[year][month] == 1)
                months_worked++;
    return months_worked;
}
