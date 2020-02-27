/* MAIN.cpp
 *   by Tim Müller (11774606)
 *
 * Assignment 1
 * 
 * Created:
 *   2/19/2020, 11:19:01 AM
 * Last edited:
 *   2/27/2020, 9:07:47 PM
 * Auto updated?
 *   Yes
 *
 * Description:
 *   This file contains the supplement code that asks user input and
 *   provides a main function.
 * 
 * This file is compiled and tested on Ubuntu 18.04 and compiled with g++. See
 *   the Makefile to see the precise options.
**/

#include <iostream>
#include <time.h>
#include <string>

#include "assignment1.hpp"

using namespace std;


static string month_names[] = {
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
};
static string day_names[] = {
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday",
    "Sunday"
};


int main() {
    // Get current time
    time_t currentTime;
    time(&currentTime);
    tm* timePtr = localtime(&currentTime);
    int currentYear = timePtr->tm_year + 1900;
    int currentMonth = timePtr->tm_mon + 1;
    int currentDay = timePtr->tm_mday;
    
    // Collect information about the user's birthdate
    int birthYear, birthMonth, birthDay;

    // Collect the year, with range checks
    cout << "In what year were you born?" << endl << " > ";
    cin >> birthYear;
    if (birthYear < 1900) {
        cout << endl << "Because of thine oldeth birthyear, thine age cannot be computeth" << endl << endl;
        return -1;
    } else if (birthYear > 2100) {
        cout << endl << "Wickety wack yo, your birthyear is too far from the now, homie, cannot whiz-whaz your age" << endl << endl;
        return -1;
    } else if (birthYear > currentYear) {
        cout << "Welcome, time traveller!" << endl;
    }

    // Get the month, with range checks
    cout << "And what is your birthmonth?" << endl << " > ";
    cin >> birthMonth;
    if (birthMonth < 1 || birthMonth > 12) {
        cout << endl << "That is actually a non-existing month. Don't they do the Gregorian Calendar where you're from?" << endl << endl;
        return -1;
    }

    // Finally, fetch the day (with range checks)
    cout << "And what is the day of your birth?" << endl << " > ";
    cin >> birthDay;
    if (birthDay < 1 || birthDay > days_in_month[birthMonth - 1]) {
        cout << endl << month_names[birthMonth - 1] << " does not have " << birthDay << " days" << endl << endl;
        return -1;
    }

    // Print the user his / her age in years
    cout << endl << "That must mean you are " << yearsOld(currentYear, currentMonth, currentDay, birthYear, birthMonth, birthDay) << " years old!" << endl;
    // Similar for the number of months
    cout << "Or, to be more precise, you are " << monthsOld(currentYear, currentMonth, currentDay, birthYear, birthMonth, birthDay) << " months old!" << endl;

    // Ask the user what day he thinks he was born
    cout << endl << "Now, a one-question quiz: do you know on what day you were born? Choose from:" << endl;
    for (int i = 1; i <= 7; i++) {
        cout << "  " << i << ": " << day_names[i - 1] << endl;
    }
    cout << "(Choose one by typing the number of that day)" << endl << " > ";
    int predicted_day_of_week;
    cin >> predicted_day_of_week;
    if (predicted_day_of_week < 1 || predicted_day_of_week > 7) {
        cout << endl << "Please, enter a valid number (they are literally listed - we cannot make this anymore easy, or fun)" << endl << endl;
        return -1;
    }

    // Compute the actual day
    int actual_day_of_week = dayOfTheWeek(birthYear, birthMonth, birthDay);

    if (predicted_day_of_week == actual_day_of_week) {
        cout << endl << "Congrats! You were right!" << endl << endl;
    } else {
        cout << endl << "Alas, you were wrong - you were actually born on a " << day_names[actual_day_of_week - 1] << endl << endl;
    }
    return 0;
}