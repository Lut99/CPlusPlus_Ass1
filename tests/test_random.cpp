/* TEST RANDOM.cpp
 *   by Lut99
 *
 * Created:
 *   2/26/2020, 7:55:17 PM
 * Last edited:
 *   2/27/2020, 8:22:20 PM
 * Auto updated?
 *   Yes
 *
 * Description:
 *   This file provides a way to randomly test the code in assignment1.cpp.
 *   To validate, we make use of the default date library available in C++.
 *   The percentage printed if for the function it mentions the part of
 *   tests that it succeeded.
**/

#include <iostream>
#include <cstdlib>
#include <time.h>

#include "../src/assignment1.hpp"

using namespace std;


void random_test(int* years, int* months, int* days, int* day_in_week) {
    *years = rand() % 201 + 1900;
    *months = rand() % 12 + 1;
    int max_days = days_in_month[*months - 1];
    *days = rand() % max_days + 1;
    *day_in_week = rand() % 7 + 1;
}


int main() {
    // Seed the random generator with the current time
    srand(time(NULL));

    // Run 1000 random tests and collect the results
    int total;
    int correct = 0;
    for (total = 1; total <= 1000; total++) {
        // Create the test data
        int year, month, day, day_of_week;
        random_test(&year, &month, &day, &day_of_week);

        // Verify if this prediction is correct
        if (dayOfTheWeek(year, month, day) == day_of_week) {
            correct++;
        }
    }

    // Print the accuracy of the algorithm
    printf("Ratio of correct guesses: %f\n", (float) correct / (float) total);
}