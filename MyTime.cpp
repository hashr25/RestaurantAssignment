#include "MyTime.h"

/// ///////////////////////////////////////////////////////////////////////////////////////
//Constructors and Destructors
MyTime::MyTime()
{
    setHour( 0 );
    setMinute( 0 );
    setSecond( 0 );
}

MyTime::MyTime( int newHour, int newMinute, int newSecond )
{
    ///I know you specified for this function to error check for valid input, but I have this
    ///function calling the setter functions that do the error checking, so nothing passes by.
    setHour(newHour);
    setMinute(newMinute);
    setSecond(newSecond);
}

MyTime::MyTime( int newHour, int newMinute )
{
    setHour( newHour );
    setMinute( newMinute );
}

MyTime::~MyTime()
{
    //Nothing to deallocate
}

/// ////////////////////////////////////////////////////////////////////////////////////////
//Getters and Setters
int MyTime::getHour()
{
    return hour;
}

int MyTime::getMinute()
{
    return minute;
}

int MyTime::getSecond()
{
    return second;
}

void MyTime::setHour( int newHour )
{
    if( newHour >= 0 && newHour < 24 )
    {
        hour = newHour;
    }
}

void MyTime::setMinute( int newMinute )
{
    if( newMinute >= 0 && newMinute < 60 )
    {
        minute = newMinute;
    }
}

void MyTime::setSecond( int newSecond )
{
    second = newSecond;
}

void MyTime::setTime( MyTime newTime )
{
    setHour( newTime.getHour() );
    setMinute( newTime.getMinute() );
    setSecond( newTime.getSecond() );
}

/// ////////////////////////////////////////////////////////////////////////////////////////////
//Methods
std::string MyTime::toString()
{
    std::string tempString;
    std::stringstream ss1;
    std::stringstream ss2;
    std::stringstream ss3;

    if( hour < 10 )
    {
        ss1 << "0" << hour;
    }
    else
    {
        ss1 << hour;
    }

    if( minute < 10 )
    {
        ss2 << "0" << minute;
    }
    else
    {
        ss2 << minute;
    }

    if( second < 10 )
    {
        ss3 << "0" << second ;
    }
    else
    {
        ss3 << second;
    }

    tempString.append( ss1.str() );
    tempString.append( ":" );
    tempString.append( ss2.str() );
    tempString.append( ":" );
    tempString.append( ss3.str() );

    return tempString;
}

MyTime MyTime::nextHour()
{
    MyTime tempTime;

    tempTime.setSecond( second );
    tempTime.setMinute( minute );
    tempTime.setHour( (hour + 1) % 24 );

    return tempTime;
}

MyTime MyTime::nextMinute()
{
    MyTime tempTime;

    tempTime.setSecond( second );
    tempTime.setMinute(( minute + 1) % 60);
    tempTime.setHour( hour );

    if( tempTime.getMinute() == 0)
    {
        tempTime.setHour( (hour + 1) % 24);
    }

    return tempTime;
}

MyTime MyTime::nextSecond()
{
    MyTime tempTime;

    tempTime.setSecond((second + 1) % 60);
    tempTime.setMinute( minute );
    tempTime.setHour( hour );

    if( tempTime.getSecond() == 0 )
    {
        tempTime.setMinute((minute + 1) % 60);

        if( tempTime.getMinute() == 0 )
        {
            tempTime.setHour((hour + 1) % 24);
        }
    }

    return tempTime;
}

MyTime MyTime::previousHour()
{
    MyTime tempTime;

    tempTime.setHour( (hour - 1) % 24);
    if( hour == 0 )
    {
        tempTime.setHour(23);
    }

    tempTime.setMinute( minute );
    tempTime.setSecond( second );

    return tempTime;
}

MyTime MyTime::previousMinute()
{
    MyTime tempTime;

    tempTime.setHour( hour );

    tempTime.setMinute( (minute - 1) % 60 );
    if( minute == 0 )
    {
        tempTime.setMinute( 59 );
        tempTime.setHour( (hour - 1) % 24 );
        if(tempTime.getHour() < 0)
        {
            tempTime.setHour( 23 );
        }
    }

    tempTime.setSecond( second );

    return tempTime;
}

MyTime MyTime::previousSecond()
{
    MyTime tempTime;

    tempTime.setHour( hour );
    tempTime.setMinute( minute );
    tempTime.setSecond( (second - 1) % 60 );

    if( tempTime.getSecond() == -1 )
    {
        tempTime.setSecond(59);
        tempTime.setMinute( ( minute - 1 ) % 60 );
        if( tempTime.getMinute() == -1 )
        {
            tempTime.setMinute(59);
            tempTime.setHour( (hour - 1) % 24 );
            if( tempTime.getHour() == -1 )
            {
                tempTime.setHour( 23 );
            }
        }
    }

    return tempTime;
}

MyTime MyTime::getCurrentTime()
{
    MyTime currentTime;
    int currentHour;
    int currentMinute;
    int currentSecond;

    time_t rawTime;
    time( &rawTime );
    std::string timeInString = ctime( &rawTime );

    std::istringstream( timeInString.substr( 11, 2 ) ) >> currentHour;
    std::istringstream( timeInString.substr( 14, 2 ) ) >> currentMinute;
    std::istringstream( timeInString.substr( 17, 2 ) ) >> currentSecond;

    currentTime.setHour( currentHour );
    currentTime.setMinute( currentMinute );
    currentTime.setSecond( currentSecond );

    return currentTime;
}

MyTime MyTime::operator = ( const MyTime& newTime )
{
    hour = newTime.hour;
    minute = newTime.minute;
    second = newTime.second;

    return *this;
}
