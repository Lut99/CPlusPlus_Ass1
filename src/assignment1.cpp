/* ASSIGNMENT 1.cpp
 *   by Tim Müller (11774606)
 *
 * Assignment 1
 * 
 * Created:
 *   2/5/2020, 11:56:53 AM
 * Last edited:
 *   2/27/2020, 9:07:57 PM
 * Auto updated?
 *   Yes
 *
 * Description:
 *   This is the file for the first Assignment of the C++
 *   Programmeermethoden course. This assignment focuses on implementing a
 *   system showing the user's age based on the current and birthdates.
 *
 * This file is compiled and tested on Ubuntu 18.04 and compiled with g++. See
 *   the Makefile to see the precise options.
**/

#include <iostream>
#include <time.h>

#include "assignment1.hpp"

using namespace std;


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

int dayOfTheWeek(int birthYear, int birthMonth, int birthDay) {
    // Our reference days is 1-1-1900, as this is a monday

    // Compute years (and account for leap years)
    int birth_since_epoch = (birthYear - 1900 - 1) * 365;
    birth_since_epoch += (birthYear - 1900) / 4;

    // Compensate for dates divisible by 100 but not by 400 (as specified in
    //   the Gregorian calendar)
    if (birthYear % 100 == 0 && birthYear % 400 != 0) {
        birth_since_epoch--;
    }

    // However, if the birth year is in a leap year but before the end of
    //   february, remove another one
    if (birthYear % 4 == 0 && birthMonth <= 2) {
        birth_since_epoch--;
    }

    // Compute months
    for (int i = 0; i < birthMonth - 1; i++) {
        birth_since_epoch += days_in_month[i];
    }

    // Finally add the days
    birth_since_epoch += birthDay;

    // Return the day % 7, as 1-1-1900 was a monday
    return birth_since_epoch % 7 + 1;
}