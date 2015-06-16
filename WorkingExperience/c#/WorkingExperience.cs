// working experience soln in c# for code eval by steven a dunn

using System;
using System.IO;
using System.Collections.Generic;

public class WorkingExperience {
  public static List<string> parse_dates(string line) {
    string[] date_ranges = line.Trim().Split(';');
    List<string> dates = new List<string>();
    for (int i = 0; i < date_ranges.Length; ++i)
    {
        string[] entries = date_ranges[i].Split('-');
        dates.Add(entries[0]);
        dates.Add(entries[1]);
    }
    return dates;
  }

  public static void update_work_history(List<string> dates, ref int[,] work_history) {
    for (int i = 0; i < dates.Count; i = i + 2) {
      string date1 = dates[i];
      string date2 = dates[i+1];
      int start_month = 0;
      int start_year = 0;
      int finish_month = 0;
      int finish_year = 0;
      parse_date_range(date1, date2, ref start_month, ref start_year, ref finish_month, ref finish_year);
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
            work_history[year, month] = 1;
      }
    }
  }

  public static int get_month(string month) {
    int result = -1;
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

  public static void parse_date_range(string date1, string date2, ref int start_month, ref int start_year, ref int finish_month, ref int finish_year) {
    string[] tokens = date1.Trim().Split();
    start_month = get_month(tokens[0]);
    start_year = Int32.Parse(tokens[1]) - 1990;

    tokens = date2.Trim().Split();
    finish_month = get_month(tokens[0]);
    finish_year = Int32.Parse(tokens[1]) - 1990;
  }

  public static int count_months(int[,] work_history)
  {
    int months_worked = 0;
    for (int year = 0; year < 30; ++year)
        for (int month = 0; month < 12; ++month)
            if (work_history[year, month] == 1)
                months_worked++;
    return months_worked;
  }
 
  public static void Main (string[] args) {
    using (StreamReader reader = new StreamReader(args[0])) {
      while(!reader.EndOfStream) {
        string line = reader.ReadLine();
        if (line == null)
          continue;
          
          int[,] work_history = new int[30, 12];
          for (int i = 0; i < 30; ++i)
              for (int j = 0; j < 12; ++j)
                  work_history[i, j] = 0;
          
          List<string> dates = parse_dates(line);
          update_work_history(dates, ref work_history);
          Console.WriteLine(count_months(work_history)/12);
      }
    }
  }
}