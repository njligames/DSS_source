//
//  Date.cpp
//  SDLSkeleton
//
//  Created by James Folk on 2/23/20.
//

#include "Date.h"
#include "SDL.h"
#include <ctime>

namespace NJLIC {

    Date::Date() {
        std::time_t t = std::time(0); // get time now
        std::tm *now = std::localtime(&t);

        setDate(now->tm_mon + 1, now->tm_mday, now->tm_year + 1900);
    }

    Date::Date(int month, int day, int year) { setDate(month, day, year); }

    Date::Date(const Date &rval) {
        setDate(rval.getMonth(), rval.getDay(), rval.getYear());
    }

    const Date &Date::operator=(const Date &rval) {
            if (this != &rval) {
                setDate(rval.getMonth(), rval.getDay(), rval.getYear());
        }
        return *this;
    }

    Date::~Date() {}

    void Date::setDate(int month, int day, int year) {
            if (month < 1 || month > 12) {
                mMonth = 1;
                SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                             "Invalid month set. Defaulted to 1.\n");
            } else {
                mMonth = month;
            }

        mYear = year;

            switch (mMonth) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                    if (day < 1 || day > 31) {
                        mDay = 1;
                        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                                     "Invalid day set. Defaulted to 1.\n");
                    } else {
                        mDay = day;
                    }
                break;
            }
            switch (mMonth) {
            case 2:
                    if (isLeapYear(mYear)) {
                            if (day < 1 || day > 29) {
                                mDay = 1;
                                SDL_LogError(
                                    SDL_LOG_CATEGORY_APPLICATION,
                                    "Invalid day set. Defaulted to 1.\n");
                            } else {
                                mDay = day;
                            }
                    } else {
                            if (day < 1 || day > 28) {
                                mDay = 1;
                                SDL_LogError(
                                    SDL_LOG_CATEGORY_APPLICATION,
                                    "Invalid day set. Defaulted to 1.\n");
                            } else {
                                mDay = day;
                            }
                    }
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                    if (day < 1 || day > 30) {
                        mDay = 1;
                        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                                     "Invalid day set. Defaulted to 1.\n");
                    } else {
                        mDay = day;
                    }
                break;
            }
    }

    void Date::setMonth(int month) { mMonth = month; }
    void Date::setDay(int day) { mDay = day; }
    void Date::setYear(int year) { mYear = year; }
    int Date::getDay() const { return mDay; }
    int Date::getMonth() const { return mMonth; }
    int Date::getYear() const { return mYear; }
    int Date::getDaysInMonth(int month, int year) {
        int daysInMonth;

            if (month < 1 || month > 12) {
                month = 1;
                SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                             "Invalid month set. Defaulted to 1.\n");
        }

            switch (month) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                daysInMonth = 31;
            }
            switch (month) {
            case 2:
                    if (isLeapYear(year)) {
                        daysInMonth = 29;
                    } else {
                        daysInMonth = 28;
                    }
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                daysInMonth = 30;
                break;
            }
        return daysInMonth;
    }
    int Date::numberOfDaysPassed() const {
        int total = 0;

        int month = 0;

            for (int i = 0; i < mMonth; i++) {
                month++;
                total += getDaysInMonth(mMonth, mYear);
            }
        return total - (getDaysInMonth(mMonth, mYear) - mDay);
    }
    int Date::numberOfDaysLeft() const {
        int total = 0;
        if (isLeapYear(mYear))
            total = 366 - numberOfDaysPassed();
        else
            total = 365 - numberOfDaysPassed();
        return total;
    }
    void Date::incrementDate(int num) {
            while ((num + mDay) > getDaysInMonth(mMonth, mYear)) {
                num -= getDaysInMonth(mMonth, mYear);
                    if (mMonth == 12) {
                        mMonth = 0;
                        mYear++;
                }
                mMonth++;
            }
        mDay += num;
    }

    void Date::decrementDate(int num) {
        int month = mMonth;
        int day = mDay;
        int year = mYear;

        day = mDay - 1;
            if (day < 1) {
                month = mMonth - 1;
                    if (month < 1) {
                        month = 12;
                        year = mYear - 1;
                        day = getDaysInMonth(month, year);
                    } else {
                        day = getDaysInMonth(month, year);
                    }
        }
        mDay = day;
        mMonth = month;
        mYear = year;
    }

    bool Date::isLeapYear(int year) {
        if (year % 4 == 0)
            return true;
        else
            return false;
    }

    Date Date::operator++() {
        incrementDate(1);
        return *this;
    }

    Date Date::operator++(int) {
        Date temp(*this);
        ++(*this);
        return temp;
    }

    Date Date::operator--() {
        decrementDate(1);
        return *this;
    }

    Date Date::operator--(int) {
        Date temp(*this);
        --(*this);
        return temp;
    }

    Date::operator std::string() const {
        static char buff[4096];

        snprintf(buff, sizeof(buff), "%.2d-%.2d-%.4d", mMonth, mDay, mYear);

        return std::string(buff);
    }

} // namespace NJLIC
