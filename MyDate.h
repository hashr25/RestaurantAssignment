#ifndef MYDATE_H
#define MYDATE_H

#include <string>
#include <sstream>
#include <iostream>
#include <ctime>

class MyDate
{
public:
    MyDate( int, int, int );
    MyDate();
    ~MyDate();

    bool isLeapYear( int );
    bool isValidDate( int, int, int );
    int getDayOfWeek( int, int, int );

    void setDate( int, int, int );
    void setYear( int );
    void setMonth( int );
    void setDay( int );
    int getYear();
    int getMonth();
    int getDay();
    MyDate getCurrentDate();

    std::string toString();
    void nextDay();
    void nextMonth();
    void nextYear();
    void previousDay();
    void previousMonth();
    void previousYear();

    MyDate operator = ( const MyDate& );

private:


    int year;
    int month;
    int day;
    std::string strMonths[13] = {"", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul",
                            "Aug", "Sep", "Oct", "Nov", "Dec"};
    std::string strDays[8] = {"", "Sunday", "Monday", "Tuesday", "Wednesday",
                         "Thursday", "Friday", "Saturday"};
    int daysInMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
};

#endif // MYDATE_H
