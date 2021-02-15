#ifndef TIMELIB_H_INCLUDED
#define TIMELIB_H_INCLUDED

int get_days_for_month(int year, int month);
int exists_date(int year, int month, int day);
int is_leapyear(int year);
void input_date(int *year, int *month, int *day);
int day_of_the_year(int day, int month, int year);

#endif // TIMELIB_H_INCLUDED
