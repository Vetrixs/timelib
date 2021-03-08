
/**
 * calculating the day of the year since 1 January of the given year
 *
 *
 * returning the days if the date exists, returns -1 if the date does not exists
 *
*/
int day_of_the_year(int day, int month, int year)
{
    if(!exists_date(year,month,day))
    {
       return -1;
    }

    int days = 0; // a counter to count the days
    for(int i = 1; i < month; i++)
    {
        days += get_days_for_month(year, i);    // calculates the days
    }
    return days += day;
}

/**
 *  gets the user input and writes them into the vars, the "*year"
 *  stand for a pointer which is pointing at the year var address
 *
 *  etc. for month and day
 */
void input_date(int *year, int *month, int *day)
{
    do
    {
        printf("Enter the year:");
        scanf("%i", year);
        printf("Enter the day:");
        scanf("%i", day);
        printf("Enter the month:");
        scanf("%i", month);
    }
    while(!exists_date(*year,*month,*day));
}

/**
 *
 * \param day, user input of days
 * \param month, user input of month
 * \param day_each_month, the amount of days each month
 * \return 0 if the user input is incorrect, 1 if the input is correct
 *
 */
int exists_date(int year, int month, int day)
{
    if(month < 0)
    {
        return 0;
    }
    if(month > 12)
    {
        return 0;
    }
    if(day <= 0  || day > get_days_for_month(year, month))
    {
        return 0;
    }
    return 1;
}

/**
 * \param year, user input of year
 * \param month, user input of year
 * \return amount of days or -1 if something is invalid
 */
int get_days_for_month(int year, int month)
{
    int days_each_month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};    // the array of the months

    int leapyear = is_leapyear(year);

    if(leapyear == 1)
    {
        days_each_month[1] = 29; // sets the 2 Months on 29 days if its a leapyear
    }
    else if(leapyear == -1)
    {
        return -1;
    }

    if(month > 12 || month < 1)
    {
        return -1; // invalid month
    }
    if(year <= 0)
    {
        return -1; //invalid year
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
