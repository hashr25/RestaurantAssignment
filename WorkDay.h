#ifndef WORKDAY_H
#define WORKDAY_H

#include "MyDate.h"
#include "MyTime.h"

class WorkDay
{
public:
    ///Constructors and Destructors
    WorkDay();
    WorkDay( MyTime, MyTime );
    WorkDay( MyTime, MyTime, MyTime, MyTime );
    ~WorkDay();

    ///Getters and Setters
    MyDate getDate();
    MyTime getScheduledStartTime();
    MyTime getScheduledEndTime();
    MyTime getClockInTime();
    MyTime getClockOutTime();
    float getHoursScheduled();
    float getHoursWorked();

    void setDate( MyDate );
    void setScheduledStartTime( int, int, int );
    void setScheduledEndTime( int, int, int );
    void setClockInTime( MyTime );
    void setClockOutTime( MyTime );

    ///Member Methods
    void clockIn();
    void clockOut();
    float calculateHoursScheduled();
    float calculateHoursWorked();

    WorkDay operator = ( const WorkDay& );

private:
    MyDate date;

    MyTime scheduleStartTime;
    MyTime scheduleEndTime;
    MyTime clockInTime;
    MyTime clockOutTime;

    float hoursScheduled;
    float hoursWorked;
};

#endif // WORKDAY_H
