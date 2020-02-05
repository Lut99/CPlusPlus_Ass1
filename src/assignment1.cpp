/* ASSIGNMENT 1.cpp
 *   by Anonymous
 *
 * Created:
 *   2/5/2020, 11:56:53 AM
 * Last edited:
 *   2/5/2020, 12:44:35 PM
 * Auto updated?
 *   Yes
 *
 * Description:
 *   This is the file for the first Assignment of the C++
 *   Programmeermethoden course. This assignment focuses on implementing a
 *   system showing the user's age based on the current and birthdates.
**/

#include <time.h>

#include "assignment1.hpp"

using namespace std;


Date::Date(int year, int month, int day) {
    this->year = year;
    this->month = month;
    this->day = day;
}


Date now() {
    time_t current_time;
    time(&current_time);

    tm* timePtr = localtime(&current_time);

    return Date(timePtr->tm_year + 1900, timePtr->tm_mon + 1, timePtr->tm_mday);
}


int yearsOld(int currentYear,int currentMonth,int currentDay,
                          int birthYear,int birthMonth,int birthDay) {
    int years_old = currentYear - birthYear - 1;
    // If the month and day allow for it, add a year
    if (currentMonth >= birthMonth || (currentMonth < birthMonth && currentDay >= birthDay)) {
        years_old++;
    }
    return years_old;
}
int monthsOld(int currentYear,int currentMonth,int currentDay,
                           int birthYear,int birthMonth,int birthDay) {
    // Begin with months passed by just the difference in years
    int years_old = yearsOld(currentYear, currentMonth, currentDay,
                             birthYear, birthMonth, birthDay);
    int months_old = years_old * 12;

    // Append the months that have certainly passed
    months_old += currentMonth - birthMonth - 1;
    // If the day allows it, add the final month
    if (currentDay >= birthDay) {
        months_old++;
    }
    return months_old;
}

int dayOfWeek(int birthYear, int birthMonth, int birthDay) {
    // First, compute the total number of days gone by
    int days_old = (birthYear - 1900) * 365;
    days_old += (birthYear - 1900) / 4;
    
    // Next, compute the days of the month
    for (int i = 0; i < birthMonth; i++) {
        days_old += days_in_month[i];
    }

    // Add the birthDay
    days_old += birthDay;

    // Now return the day of the week
    
}