/** Program: Day of the year
 *  Author: Wilhelm Adam
 *  Date: 25.01.2021
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Funktionsprototypen die nach der implentierung von main() deklariert wurden
 * damit der Compiler weiﬂ das es diese gibt und welche Eigenschaften diese Funktionen haben
 */
int get_days_for_month(int year, int month, int days_each_month[]);
int exists_date(int year,int day, int month, int days_each_month[]);
int is_leapyear(int year);

int main()
{
    printf("Day of the year\n");
    int day = 0, month = 0, year = 0, days = 0;
    int days_each_month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    printf("Enter the year:");
    scanf("%i", &year);

    //test on if the given year is a leap year an then replace febuary
    int leapyear = is_leapyear(year);

    if(leapyear == 1)
    {
        days_each_month[1] = 29;
    }
    else if(leapyear == -1)
    {
        printf("The year you entered is invalid. Stopping program...\n");    //force stop invalid year
        return -1;
    }

    do
    {
        printf("Enter the day:");
        scanf("%i", &day);
        printf("Enter the month:");
        scanf("%i", &month);
    }
    while(exists_date(year,day,month, days_each_month));


    for(int i = 0; i < month-1; i++)
    {
        days += days_each_month[i];
    }
    days += day;

    printf("Day in the year: %i\n",days);
}

/**
 *
 * \param day, user input of days
 * \param month, user input of month
 * \param day_each_month, the amount of days each month
 * \return 1 if the user input is incorrect, 0 if the input is correct
 *
 */
int exists_date(int year,int day, int month, int days_each_month[])
{
    month = month -1;
    if(month < 0)
    {
        printf("Month cannot be less then 0 or 0\n");
        return 1;
    }
    if(month > 12)
    {
        printf("Month cannot be greater then 12\n");
        return 1;
    }
    if(day <= 0  || day > get_days_for_month(year,month,days_each_month))
    {
        printf("your chosen month has only %i days\n",days_each_month[month]);
        return 1;
    }
    return 0;
}

/**
 * \param year, user input of year
 * \param month, user input of year
 * \return amount of days or -1 if something is invalid
 */
int get_days_for_month(int year, int month, int days_each_month[])
{
    if(month > 12 || month < 1)
    {
        return -1;
    }
    if(year <= 0)
    {
        return -1;
    }
    return days_each_month[month];
}

/**
 *
 * \param year, gets the user input of years
 * \return 1 if its an leap year, 0 if not, -1 if the year is invalid
 *
 */
int is_leapyear(int year)
{
    if(year > 0)
    {
        if(((year%4==0) && ((year%400==0) || (year%100!=0))))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return -1;
    }
}
