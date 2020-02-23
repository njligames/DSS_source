//
//  Date.h
//  SDLSkeleton
//
//  Created by James Folk on 2/23/20.
//

#ifndef Date_h
#define Date_h

#include <string>

namespace NJLIC {

class Date {
    int mMonth;
    int mDay;
    int mYear;
public:
    Date();
    Date(int month, int day, int year);
    Date(const Date&);
    const Date &operator=(const Date&);
    virtual ~Date();
    
    void setDate(int month, int day, int year);
    
    void setMonth(int month);
    void setDay(int day);
    void setYear(int year);
    int getDay()const;
    int getMonth()const;
    int getYear()const;
    static int getDaysInMonth(int month, int year);
    int numberOfDaysPassed()const;
    int numberOfDaysLeft()const;
    void incrementDate(int num = 1);
    void decrementDate(int num = 1);
    static bool isLeapYear(int year);
    
    Date operator++();
    Date operator++(int);
    Date operator--();
    Date operator--(int);
    operator std::string() const;
};

}

#endif /* Date_hpp */
