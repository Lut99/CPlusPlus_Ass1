/* ASSIGNMENT 1.hpp
 *   by Tim Müller (11774606)
 *
 * Assignment 1
 * 
 * Created:
 *   2/5/2020, 11:52:22 AM
 * Last edited:
 *   2/27/2020, 9:08:00 PM
 * Auto updated?
 *   Yes
 *
 * Description:
 *   Header file for assignment1.cpp.
 * 
 * This file is compiled and tested on Ubuntu 18.04 and compiled with g++. See
 *   the Makefile to see the precise options.
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