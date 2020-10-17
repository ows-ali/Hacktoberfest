import datetime
def most_frequent_days(year):
    week_days = ('Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Saturday', 'Sunday')
    days = sorted(list(set([datetime.date(year, 1, 1).weekday(), datetime.date(year, 12, 31).weekday()])))
    output = [week_days[i] for i in days]
    return output