/** Program: Day of the year
 *  Author: Wilhelm Adam
 *  Date: 25.01.2021
 */

#include <stdio.h>
#include <stdlib.h>
#include "timelib.h"

int main()
{
    //declaration of the vars
    int day = 0, month = 0, year = 0;

    //Pointers of the vars
    int *day_pointer = &day, *month_pointer = &month, *year_pointer = &year;

    printf("#### Day of the year calculator ####\n");

    input_date(year_pointer,month_pointer, day_pointer);

    int dayOfTheYear = day_of_the_year(day,month,year);
    printf("Its the %i day of the year.\n", dayOfTheYear);

    if (dayOfTheYear == -1)
    {
        printf("The given year does not exists!");
    }
    else
    {

    }

}
