# working experience py2 soln for code eval by steven a dunn

import sys, datetime
#from dateutil.parser import parse
#from dateutil.tz import *

months = {
    "Jan" : 0,
    "Feb" : 1,
    "Mar" : 2,
    "Apr" : 3,
    "May" : 4,
    "Jun" : 5,
    "Jul" : 6,
    "Aug" : 7,
    "Sep" : 8,
    "Oct" : 9,
    "Nov" : 10,
    "Dec" : 11
}

def get_ranges(dates):
    ranges = set()
    for date in dates:
        print date
        print date[0]
        print date[1]
        #start = parse(date[0])
        #finish = parse(date[1])
        #date = (start, finish)
        #print finish - start
    return ranges

def parse_dates(line):
    dates = line.strip().split(';')
    dates = [x.strip().split('-') for x in dates]
    return dates

def parse_date_range(date_range):
   start = date_range[0].split()
   finish = date_range[1].split()

   start_month = months[start[0]]
   start_year = int(start[1]) - 1990

   finish_month = months[finish[0]]
   finish_year = int(finish[1]) - 1990

   return (start_month, start_year), (finish_month, finish_year)

def update_work_history(dates, work_history):
    for date_range in dates:
        start, finish = parse_date_range(date_range)
        for year in range(start[1], finish[1]+1):
            if start[1] == finish[1]:
                begin = start[0]
                end = finish[0] + 1
            elif year == start[1]:
                begin = start[0]
                end = 12
            elif year == finish[1]:
                begin = 0
                end = finish[0] + 1
            else:
                begin = 0
                end = 12
            for month in range(begin, end):
                work_history[year][month] = 1
    return work_history

def count_months(work_history):
    months_worked = 0
    for year in work_history:
        months_worked += year.count(1)
    return months_worked

f = open(sys.argv[1], 'r')
for line in f:
    # 30 b/c problem specifies all entries between 1990 and 2020
    work_history = [[0 for x in range(12)] for x in range(30)]
    dates = parse_dates(line)
    work_history = update_work_history(dates, work_history)
    print count_months(work_history)/12
f.close()