// working experience soln in c for code eval by steven a dunn

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char **array;
    size_t used;
    size_t size;
} Array;

void init(Array*, size_t);
void insert(Array*, char*);
Array parse_dates(char*);
void update_work_history(Array, int[30][12]);
void parse_date_range(char*, char*, int[4]);
int get_month(char*);
int count_months(int[30][12]);

int main (int argc, char* const argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[512];
        while (fgets(line, sizeof(line), fp))
        {
            int work_history[30][12];
            for (int i = 0; i < 30; ++i)
                for (int j = 0; j < 12; ++j)
                    work_history[i][j] = 0;

            Array dates = parse_dates(line);
            update_work_history(dates, work_history);
            printf("%d\n", count_months(work_history)/12);
        }
        fclose(fp);
    }
    return 0;
}

Array parse_dates(char* raw_line)
{
    Array date_ranges;
    init(&date_ranges, 1);
    char* token = strtok(raw_line, ";");
    while (token != NULL)
    {
        insert(&date_ranges, token);
        token = strtok(NULL, ";");
    }

    Array dates;
    init(&dates, 1);
    for (int i = 0; i < date_ranges.used; ++i)
    {
        token = strtok(date_ranges.array[i], "-");
        while (token != NULL)
        {
            insert(&dates, token);
            token = strtok(NULL, "-");
        }
    }
    return dates;
}

void init(Array* arr, size_t initSize)
{
    arr->array = (char**)malloc(initSize * sizeof(char*));
    arr->used = 0;
    arr->size = initSize;
}

void insert(Array* arr, char* element)
{
    if (arr->used == arr->size)
    {
        arr->size *= 2;
        arr->array = (char**)realloc(arr->array, arr->size * sizeof(char*));
    }
    arr->array[arr->used++] = element;
}

void update_work_history(Array dates, int work_history[30][12])
{
    for (int i = 0; i < dates.used; i = i + 2)
    {
        char* date1 = dates.array[i];
        char* date2 = dates.array[i+1];
        int start_month, start_year, finish_month, finish_year;
        int dates[4];
        parse_date_range(date1, date2, dates);

        start_month = dates[0];
        start_year = dates[1];
        finish_month = dates[2];
        finish_year = dates[3];
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

void parse_date_range(char* date1, char* date2, int dates[4])
{
    Array tokens;
    init(&tokens, 1);
    char* token = strtok(date1, " ");
    while (token != NULL)
    {
        insert(&tokens, token);
        token = strtok(NULL, " ");
    }
    dates[0] = get_month(tokens.array[0]);
    dates[1] = atoi(tokens.array[1]) - 1990;

    Array tokens2;
    init(&tokens2, 1);
    token = strtok(date2, " ");
    while (token != NULL)
    {
        insert(&tokens2, token);
        token = strtok(NULL, " ");
    }
    dates[2] = get_month(tokens2.array[0]);
    dates[3] = atoi(tokens2.array[1]) - 1990;
}


int get_month(char* month)
{
    int result;
    if (!strcmp(month, "Jan"))
        result = 0;
    else if (!strcmp(month, "Feb"))
        result = 1;
    else if (!strcmp(month, "Mar"))
        result = 2;
    else if (!strcmp(month, "Apr"))
        result = 3;
    else if (!strcmp(month, "May"))
        result = 4;
    else if (!strcmp(month, "Jun"))
        result = 5;
    else if (!strcmp(month, "Jul"))
        result = 6;
    else if (!strcmp(month, "Aug"))
        result = 7;
    else if (!strcmp(month, "Sep"))
        result = 8;
    else if (!strcmp(month, "Oct"))
        result = 9;
    else if (!strcmp(month, "Nov"))
        result = 10;
    else if (!strcmp(month, "Dec"))
        result = 11;
    return result;
}

int count_months(int work_history[30][12])
{
    int months_worked = 0;
    for (int year = 0; year < 30; ++year)
        for (int month = 0; month < 12; ++month)
            if (work_history[year][month] == 1)
                months_worked++;
    return months_worked;
}