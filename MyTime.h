#ifndef MYTIME_H
#define MYTIME_H

#include <ctime>
#include <string>
#include <sstream>

class MyTime
{
public:
    ///Constructors and Destructors
    MyTime( int, int, int );
    MyTime( int, int );
    MyTime();
    ~MyTime();

    ///Getters and Setters
    int getHour();
    int getMinute();
    int getSecond();
    void setHour( int );
    void setMinute( int );
    void setSecond( int );
    void setTime( MyTime );

    ///Member Methods
    std::string toString();

    MyTime nextSecond();
    MyTime nextMinute();
    MyTime nextHour();
    MyTime previousSecond();
    MyTime previousMinute();
    MyTime previousHour();
    MyTime getCurrentTime();

    MyTime operator = ( const MyTime& );

private:
    ///Private Data
    int hour;
    int minute;
    int second;
};

#endif // MYTIME_H
