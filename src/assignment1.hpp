/* ASSIGNMENT 1.hpp
 *   by Anonymous
 *
 * Created:
 *   2/5/2020, 11:52:22 AM
 * Last edited:
 *   2/23/2020, 10:41:27 PM
 * Auto updated?
 *   Yes
 *
 * Description:
 *   Header file for assignment1.cpp.
**/

#ifndef ASSIGNMENT1_HPP
#define ASSIGNMENT1_HPP

#include <string>

static int days_in_month[] = {
    31,
    28,
    31,
    30,
    31,
    30,
    31,
    31,
    30,
    31,
    30,
    31
};

/* Computes how many years old the user is, given the current date (in year, month and day) and the date the user was born (in year, month and day). */
int yearsOld(int currentYear,int currentMonth,int currentDay,
             int birthYear,int birthMonth,int birthDay);
/* Computes how many months old the user is, given the current date (in year, month and day) and the date the user was born (in year, month and day). */
int monthsOld(int currentYear,int currentMonth,int currentDay,
              int birthYear,int birthMonth,int birthDay);

/* Returns the day of the week for a given date. Computes this based on a reference epoch that is globally defined. */
int dayOfTheWeek(int birthYear, int birthMonth, int birthDay);

#endif