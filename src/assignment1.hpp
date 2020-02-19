/* ASSIGNMENT 1.hpp
 *   by Anonymous
 *
 * Created:
 *   2/5/2020, 11:52:22 AM
 * Last edited:
 *   2/19/2020, 11:21:50 AM
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
/* The reference epoch is the date 3-1-2000, specified as number of days since 1-1-1900 */
static int reference_epoch = 36527;

/* Computes how many years old the user is, given the current date (in year, month and day) and the date the user was born (in year, month and day). */
int yearsOld(int currentYear,int currentMonth,int currentDay,
             int birthYear,int birthMonth,int birthDay);
/* Computes how many months old the user is, given the current date (in year, month and day) and the date the user was born (in year, month and day). */
int monthsOld(int currentYear,int currentMonth,int currentDay,
              int birthYear,int birthMonth,int birthDay);

/* Returns the day of the week for a given date. Computes this based on a reference epoch that is globally defined. */
int dayOfTheWeek(int birthYear, int birthMonth, int birthDay);

#endif