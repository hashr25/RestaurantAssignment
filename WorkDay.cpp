#include "WorkDay.h"

///Constructors and Destructors
WorkDay::WorkDay()
{
    std::cout << "Assigns the values" << std::endl;
}

WorkDay::~WorkDay()
{
    ///Nothing to do as of right now
}


///Getters and Setters
MyDate WorkDay::getDate()
{
    return date;
}

MyTime WorkDay::getScheduledStartTime()
{
    return scheduleStartTime;
}

MyTime WorkDay::getScheduledEndTime()
{
    return scheduleEndTime;
}

MyTime WorkDay::getClockInTime()
{
    return clockInTime;
}

MyTime WorkDay::getClockOutTime()
{
    return clockOutTime;
}


void WorkDay::setDate( MyDate date )
{
    this -> date = date;
}

void WorkDay::setScheduledStartTime( int hour, int minute, int second )
{
    scheduleStartTime.setHour( hour );
    scheduleStartTime.setMinute( minute );
    scheduleStartTime.setSecond( second );
}

void WorkDay::setScheduledEndTime( int hour, int minute, int second )
{
    scheduleEndTime.setHour( hour );
    scheduleEndTime.setMinute( minute );
    scheduleEndTime.setSecond( second );
}

void WorkDay::setClockInTime( MyTime clockInTime )
{
    this -> clockInTime = clockInTime;
}

void WorkDay::setClockOutTime( MyTime clockOutTime )
{
    this -> clockOutTime = clockOutTime;
}


///Member Methods
void WorkDay::clockIn()
{
    MyTime currentTime;
    currentTime.setTime( currentTime.getCurrentTime() );

    setClockInTime( currentTime );
}

void WorkDay::clockOut()
{
    MyTime currentTime;
    currentTime.setTime( currentTime.getCurrentTime() );

    setClockOutTime( currentTime );
}

float WorkDay::calculateHoursScheduled()
{
    float hoursScheduledCalculation;

    MyTime timeDifference( 0, 0, 0 );
        //This MyTime holds time difference between end time and start time.
    MyTime tempStartTime( scheduleStartTime.getHour(), scheduleStartTime.getMinute(), scheduleStartTime.getSecond() );
        //Makes a copy of the start time
    MyTime tempEndTime( scheduleEndTime.getHour(), scheduleEndTime.getMinute(), scheduleEndTime.getSecond() );
        //Makes a copy of the end time
    ///These variables are made so that the actual workdays are not changed but can be edited to make
    ///altercations to compute the hours worked.

    if( tempEndTime.getSecond() - tempStartTime.getSecond() < 0 )
    {
        timeDifference.setSecond( 60 + ( tempEndTime.getSecond() - tempStartTime.getSecond() ) );
        tempEndTime.setTime( tempEndTime.previousMinute() );
    }
    else
    {
        timeDifference.setSecond( tempEndTime.getSecond() - tempStartTime.getSecond() );
    }

    if( tempEndTime.getMinute() - tempStartTime.getMinute() < 0 )
    {
        timeDifference.setMinute( 60 + (tempEndTime.getMinute() - tempStartTime.getMinute() ) );
        tempEndTime.setTime( tempEndTime.previousMinute() );
    }
    else
    {
        timeDifference.setMinute( tempEndTime.getMinute() - tempStartTime.getMinute() );
    }

    if( tempEndTime.getHour() - tempStartTime.getHour() < 0 )
    {
        timeDifference.setHour( 24 + ( tempEndTime.getHour() - tempStartTime.getHour() ) );
        tempEndTime.setTime( ( tempEndTime.previousHour() ) );
    }
    else
    {
        timeDifference.setHour( tempEndTime.getHour() - tempStartTime.getHour() );
    }

    ///Commented out portions were used to test the output of this function
    //std::cout << timeDifference.toString() << std::endl;

    hoursScheduledCalculation = ((float(timeDifference.getSecond()) / float(60) ) / float(60) );
    //std::cout << "second: " << float(timeDifference.getSecond()) << std::endl;
    //std::cout << (float((timeDifference.getSecond()) / float(60) ) / float(60) ) << std::endl;

    hoursScheduledCalculation = hoursScheduledCalculation + ( float(timeDifference.getMinute()) / float(60) );
    //std::cout << "minute: " << float(timeDifference.getMinute()) << std::endl;
    //std::cout << ( float(timeDifference.getMinute()) / float(60) ) << std::endl;

    hoursScheduledCalculation = hoursScheduledCalculation + ( float(timeDifference.getHour()) );
    //std::cout << "hours: " << float(timeDifference.getHour()) << std::endl;
    //std::cout << ( float(timeDifference.getHour() )) << std::endl;

    hoursScheduled = hoursScheduledCalculation;
    return hoursScheduledCalculation;
}

float WorkDay::calculateHoursWorked()
{
    float hoursWorkedCalculation;

    MyTime timeDifference( 0, 0, 0 );
        //This MyTime holds time difference between end time and start time.
    MyTime tempStartTime( clockInTime.getHour(), clockInTime.getMinute(), clockInTime.getSecond() );
        //Makes a copy of the start time
    MyTime tempEndTime( clockOutTime.getHour(), clockOutTime.getMinute(), clockOutTime.getSecond() );
        //Makes a copy of the end time
    ///These variables are made so that the actual workdays are not changed but can be edited to make
    ///altercations to compute the hours worked.

    if( tempEndTime.getSecond() - tempStartTime.getSecond() < 0 )
    {
        timeDifference.setSecond( 60 + ( tempEndTime.getSecond() - tempStartTime.getSecond() ) );
        tempEndTime.setTime( tempEndTime.previousMinute() );
    }
    else
    {
        timeDifference.setSecond( tempEndTime.getSecond() - tempStartTime.getSecond() );
    }

    if( tempEndTime.getMinute() - tempStartTime.getMinute() < 0 )
    {
        timeDifference.setMinute( 60 + (tempEndTime.getMinute() - tempStartTime.getMinute() ) );
        tempEndTime.setTime( tempEndTime.previousMinute() );
    }
    else
    {
        timeDifference.setMinute( tempEndTime.getMinute() - tempStartTime.getMinute() );
    }

    if( tempEndTime.getHour() - tempStartTime.getHour() < 0 )
    {
        timeDifference.setHour( 24 + ( tempEndTime.getHour() - tempStartTime.getHour() ) );
        tempEndTime.setTime( ( tempEndTime.previousHour() ) );
    }
    else
    {
        timeDifference.setHour( tempEndTime.getHour() - tempStartTime.getHour() );
    }

    ///Commented out portions were used to test the output of this function
    //std::cout << timeDifference.toString() << std::endl;

    hoursWorkedCalculation = ((float(timeDifference.getSecond()) / float(60) ) / float(60) );
    //std::cout << "second: " << float(timeDifference.getSecond()) << std::endl;
    //std::cout << (float((timeDifference.getSecond()) / float(60) ) / float(60) ) << std::endl;

    hoursWorkedCalculation = hoursWorkedCalculation + ( float(timeDifference.getMinute()) / float(60) );
    //std::cout << "minute: " << float(timeDifference.getMinute()) << std::endl;
    //std::cout << ( float(timeDifference.getMinute()) / float(60) ) << std::endl;

    hoursWorkedCalculation = hoursWorkedCalculation + ( float(timeDifference.getHour()) );
    //std::cout << "hours: " << float(timeDifference.getHour()) << std::endl;
    //std::cout << ( float(timeDifference.getHour() )) << std::endl;

    hoursWorked = hoursWorkedCalculation;
    return hoursWorkedCalculation;
}

WorkDay WorkDay::operator = ( const WorkDay& newWorkDay )
{
    date = newWorkDay.date;

    scheduleStartTime = newWorkDay.scheduleStartTime;
    scheduleEndTime = newWorkDay.scheduleEndTime;
    clockInTime = newWorkDay.clockInTime;
    clockOutTime = newWorkDay.clockOutTime;

    hoursScheduled = newWorkDay.hoursScheduled;
    hoursWorked = newWorkDay.hoursWorked;
}
