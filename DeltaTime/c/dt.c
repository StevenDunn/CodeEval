// delta time soln in c for code eval by steven a dunn

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char* format_time(int delta);

int main (int argc, char* const argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[512];
        while (fgets(line, sizeof(line), fp))
        {
            char* token = strtok(line, " ");
            char* date1_c = token;
            token = strtok(NULL, " ");
            char* date2_c = token;

            struct tm time_1;
            time_1.tm_mon = 0;
            time_1.tm_mday = 1;
            time_1.tm_year = 70;
            time_1.tm_wday = 0;
            time_1.tm_yday = 0;

            token = strtok(date1_c, ":");
            time_1.tm_hour = atoi(token);
            token = strtok(NULL, ":");
            time_1.tm_min = atoi(token);
            token = strtok(NULL, ":");
            time_1.tm_sec = atoi(token);

            struct tm time_2;
            time_2.tm_mon = 0;
            time_2.tm_mday = 1;
            time_2.tm_year = 70;
            time_2.tm_wday = 0;
            time_2.tm_yday = 0;

            token = strtok(date2_c, ":");
            time_2.tm_hour = atoi(token);
            token = strtok(NULL, ":");
            time_2.tm_min = atoi(token);
            token = strtok(NULL, ":");
            time_2.tm_sec = atoi(token);

            double seconds = difftime(mktime(&time_1), mktime(&time_2));
            if (seconds < 0)
                seconds = seconds * -1;

            char* result = format_time(seconds);
            puts(result);
            free(result);
        }
        fclose(fp);
    }
    return 0;
}

char* format_time(int delta)
{
    int hours = delta / 3600;
    int rem = delta % 3600;

    int minutes = rem / 60;
    int seconds = rem % 60;

    char formatted_hour[3];
    sprintf(formatted_hour, "%02d", hours);
    char formatted_min[3];
    sprintf(formatted_min, "%02d", minutes);
    char formatted_sec[3];
    sprintf(formatted_sec, "%02d", seconds);

    char* result = (char*)calloc(8, sizeof(int));
    strcpy(result, "");
    strcat(result, formatted_hour);
    strcat(result, ":");
    strcat(result, formatted_min);
    strcat(result, ":");
    strcat(result, formatted_sec);

    return result;
}