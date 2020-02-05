/* ASSIGNMENT 1.hpp
 *   by Anonymous
 *
 * Created:
 *   2/5/2020, 11:52:22 AM
 * Last edited:
 *   2/5/2020, 12:46:16 PM
 * Auto updated?
 *   Yes
 *
 * Description:
 *   Header file for assignment1.cpp.
**/

#ifndef ASSIGNMENT1_HPP
#define ASSIGNMENT1_HPP

static std::string day_of_week[] = {
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday",
    "Sunday"
};
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
static int reference

struct Date {
    int year;
    int month;
    int day;

    /* Construct the struct with given values */
    Date(int year, int month, int day);
};

/* Returns the current time as year, month and day */
Date now();

/* Computes how many years old the user is, given the current date (in year, month and day) and the date the user was born (in year, month and day). */
int yearsOld(int currentYear,int currentMonth,int currentDay,
             int birthYear,int birthMonth,int birthDay);
/* Computes how many months old the user is, given the current date (in year, month and day) and the date the user was born (in year, month and day). */
int monthsOld(int currentYear,int currentMonth,int currentDay,
              int birthYear,int birthMonth,int birthDay);

#endif