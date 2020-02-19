/* ASSIGNMENT 1.cpp
 *   by Anonymous
 *
 * Created:
 *   2/5/2020, 11:56:53 AM
 * Last edited:
 *   2/19/2020, 12:43:22 PM
 * Auto updated?
 *   Yes
 *
 * Description:
 *   This is the file for the first Assignment of the C++
 *   Programmeermethoden course. This assignment focuses on implementing a
 *   system showing the user's age based on the current and birthdates.
**/

#include <iostream>
#include <time.h>

#include "assignment1.hpp"

using namespace std;


// Date now() {
//     time_t current_time;
//     time(&current_time);

//     tm* timePtr = localtime(&current_time);

//     return Date(timePtr->tm_year + 1900, timePtr->tm_mon + 1, timePtr->tm_mday);
// }

int yearsOld(int currentYear,int currentMonth,int currentDay,
             int birthYear,int birthMonth,int birthDay) {
    // First, compute the years passed based on years alone
    int passed = currentYear - birthYear;

    // If passed is 0, there will never be a case where it isn't
    if (passed == 0) {
        return 0;
    } else if (passed < 0) {
        return -1 * yearsOld(birthYear, birthMonth, birthDay, currentYear, currentMonth, currentDay);
    }

    // However, if the currentMonth & currentDay are before birthMonth and day,
    //   subtract 1 to compensate
    if (currentMonth < birthMonth || (currentMonth == birthMonth && currentDay < birthDay)) {
        passed--;
    }

    return passed;
}
int monthsOld(int currentYear,int currentMonth,int currentDay,
              int birthYear,int birthMonth,int birthDay) {
    // First, compute the months passed by the amount of years
    int passed = (currentYear - birthYear) * 12;

    // Add the number of months based on the months
    passed += currentMonth - birthMonth;

    // If passed == 0, we'll never encounter non-0 result
    // If passed < 0, re-run with the swapped arguments to find out
    if (passed == 0) {
        return 0;
    } else if (passed < 0) {
        return -1 * monthsOld(birthYear, birthMonth, birthDay, currentYear, currentMonth, currentDay);
    }

    // Compensate if the day isn't far enough yet
    if (currentDay <= birthDay) {
        passed--;
    }

    return passed;
}

int daysOld(int currentYear,int currentMonth,int currentDay,
            int birthYear,int birthMonth,int birthDay) {
    // Start with the number of months
    int months = monthsOld(currentYear, currentMonth, currentDay, birthYear, birthMonth, birthDay);
}

int dayOfTheWeek(int birthYear, int birthMonth, int birthDay) {
    // First, compute the total number of days gone by from the years since the
    //   epoch (1-1-1900)
    int days_old = (birthYear - 1900) * 365;
    days_old += (birthYear - 1900) / 4;
    
    // Next, compute the days of the month
    for (int i = 0; i < birthMonth; i++) {
        days_old += days_in_month[i];
    }

    // Add the birthDay
    days_old += birthDay;

    // Compute the difference in days
    int ddays = days_old - reference_epoch;

    // Return the absolute value + 1 since we want 1-indexed answer
    return abs(ddays % 7) + 1;
}