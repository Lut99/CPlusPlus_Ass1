/* TEST YEARS.cpp
 *   by Lut99
 *
 * Created:
 *   2/19/2020, 11:27:27 AM
 * Last edited:
 *   2/19/2020, 12:36:57 PM
 * Auto updated?
 *   Yes
 *
 * Description:
 *   In this file, the function yearsOld is tested.
**/

#include <iostream>
#include <random>

#include "../src/assignment1.hpp"

#define ASSERT_TEST(test) if (!test) {return -1;}

using namespace std;


class RandomDateGenerator {
    private:
        mt19937 gen;

        uniform_int_distribution<> year_dist;
        uniform_int_distribution<> month_dist;
    public:
        RandomDateGenerator(int min_year=1901, int max_year=2020) {
            random_device rd;
            this->gen = mt19937(rd());

            this->year_dist = uniform_int_distribution<>(min_year, max_year);
            this->month_dist = uniform_int_distribution<>(1, 12);
        };

        void next(int& year, int& month, int& day) {
            year = this->year_dist(this->gen);
            month = this->month_dist(this->gen);
            // Now, construct a random distribution for the day
            int n_days = days_in_month[month];
            // If it's a leap year + february, increment by one
            if (year % 4 == 0 && month == 2) {
                n_days++;
            }
            day = uniform_int_distribution(1, n_days)(this->gen);
        }
};


bool test_years_constant(int birthYear, int birthMonth, int birthDay, int expected) {
    cout << "Testing constant case for years..." << endl;

    int currentYear = 2020;
    int currentMonth = 2;
    int currentDay = 19;

    cout << "   Assuming current date: " << currentYear << "-" << currentMonth << "-" << currentDay << endl;
    cout << "   Testing birthdate: " << birthYear << "-" << birthMonth << "-" << birthDay << "..." << endl;
    int result = yearsOld(
        currentYear, currentMonth, currentDay, birthYear, birthMonth, birthDay
    );
    cout << "   Years old result: " << result << endl;

    if (result == expected) {
        cout << "Success" << endl << endl;
        return true;
    } else {
        cout << "Failure: expected " << expected << ", got " << result << endl << endl;
        return false;
    }
}

bool test_months_constant(int birthYear, int birthMonth, int birthDay, int expected) {
    cout << "Testing constant case for months..." << endl;

    int currentYear = 2020;
    int currentMonth = 2;
    int currentDay = 19;

    cout << "   Assuming current date: " << currentYear << "-" << currentMonth << "-" << currentDay << endl;
    cout << "   Testing birthdate: " << birthYear << "-" << birthMonth << "-" << birthDay << "..." << endl;
    int result = monthsOld(
        currentYear, currentMonth, currentDay, birthYear, birthMonth, birthDay
    );
    cout << "   Months old result: " << result << endl;

    if (result == expected) {
        cout << "Success" << endl << endl;
        return true;
    } else {
        cout << "Failure: expected " << expected << ", got " << result << endl << endl;
        return false;
    }
}


int main() {
    cout << endl << "*** TEST FILE FOR 'assignment1.cpp' ***" << endl << endl;

    cout << "Initializing random number generator...";
    RandomDateGenerator gen;
    cout << " Done" << endl << endl;

    ASSERT_TEST(test_years_constant(2020, 1, 1, 0))
    ASSERT_TEST(test_years_constant(2019, 1, 1, 1))
    ASSERT_TEST(test_years_constant(2021, 1, 1, 0))
    ASSERT_TEST(test_years_constant(2021, 2, 19, -1))
    ASSERT_TEST(test_years_constant(2020, 2, 19, 0))
    ASSERT_TEST(test_years_constant(2019, 2, 19, 1))
    ASSERT_TEST(test_years_constant(2019, 3, 1, 0))
    ASSERT_TEST(test_years_constant(2020, 3, 19, 0))

    ASSERT_TEST(test_months_constant(2020, 1, 19, 1))
    ASSERT_TEST(test_months_constant(2020, 2, 19, 0))
    ASSERT_TEST(test_months_constant(2020, 3, 19, -1))
    ASSERT_TEST(test_months_constant(2019, 1, 19, 13))
    ASSERT_TEST(test_months_constant(2019, 2, 19, 12))
    ASSERT_TEST(test_months_constant(2019, 3, 19, 11))
}