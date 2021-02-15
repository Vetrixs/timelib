/** Program: Day of the year
 *  Author: Wilhelm Adam
 *  Date: 25.01.2021
 */

#include <stdio.h>
#include <stdlib.h>
#include "timelib.h"
/**
 * Funktionsprototypen die nach der implentierung von main() deklariert wurden
 * damit der Compiler weiﬂ das es diese gibt und welche Eigenschaften diese Funktionen haben
 */



int main()
{
    //declaration of the vars
    int day = 0, month = 0, year = 0;

    //Pointers of the vars
    int *day_pointer = &day, *month_pointer = &month, *year_pointer = &year;

    printf("#### Day of the year calculator ####\n");

    input_date(year_pointer,month_pointer, day_pointer);

    printf("Its the %i day of the year.\n",day_of_the_year(day,month,year));
}
