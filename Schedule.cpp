#include "Schedule.h"

///Constructors and Destructors
Schedule::Schedule()
{
    //Nothing really to allocate
}

Schedule::~Schedule()
{
    //Nothing really to deallocate
}


///Getters
WorkDay* Schedule::getWorkWeekOne()
{
    return workWeekOne;
}

WorkDay* Schedule::getWorkWeekTwo()
{
    return workWeekTwo;
}

float Schedule::getWeekOneScheduledHours()
{
    float hoursScheduled = 0.0;

    for( int i = 0; i < 7; i++ )
    {
        hoursScheduled += workWeekOne[i].calculateHoursScheduled();
    }

    return hoursScheduled;
}

float Schedule::getWeekTwoScheduledHours()
{
    float hoursScheduled = 0.0;

    for( int i = 0; i < 7; i++ )
    {
        hoursScheduled += workWeekTwo[i].calculateHoursScheduled();
    }

    return hoursScheduled;
}

float Schedule::getTotalScheduledHours()
{
    float hoursScheduled = 0.0;

    for( int i = 0; i < 7; i++ )
    {
        hoursScheduled += workWeekOne[i].calculateHoursScheduled();
        hoursScheduled += workWeekTwo[i].calculateHoursScheduled();
    }

    return hoursScheduled;
}

float Schedule::getWeekOneWorkedHours()
{
    float hoursWorked = 0.0;

    for( int i = 0; i < 7; i++ )
    {
        hoursWorked += workWeekOne[i].calculateHoursWorked();
    }

    return hoursWorked;
}

float Schedule::getWeekTwoWorkedHours()
{
    float hoursWorked = 0.0;

    for( int i = 0; i < 7; i++ )
    {
        hoursWorked += workWeekTwo[i].calculateHoursWorked();
    }

    return hoursWorked;
}

float Schedule::getTotalWorkedHours()
{
    float hoursWorked = 0.0;

    for( int i = 0; i < 7; i++ )
    {
        hoursWorked += workWeekOne[i].calculateHoursWorked();
        hoursWorked += workWeekTwo[i].calculateHoursWorked();
    }

    return hoursWorked;
}

void Schedule::setWorkDay( WorkDay workDayToSet, int weekToSet, int dayToSet )
{
    if( weekToSet == 0 )
    {
        workWeekOne[ dayToSet ].setDate( workDayToSet.getDate() );
        workWeekOne[ dayToSet ].setScheduledStartTime( workDayToSet.getScheduledStartTime().getHour(),
                                                         workDayToSet.getScheduledStartTime().getMinute(),
                                                         workDayToSet.getScheduledStartTime().getSecond() );
        workWeekOne[ dayToSet ].setScheduledEndTime( workDayToSet.getScheduledEndTime().getHour(),
                                                       workDayToSet.getScheduledEndTime().getMinute(),
                                                       workDayToSet.getScheduledEndTime().getSecond() );
        workWeekOne[ dayToSet ].setClockInTime( workDayToSet.getClockInTime() );
        workWeekOne[ dayToSet ].setClockOutTime( workDayToSet.getClockOutTime() );
    }

    else if( weekToSet == 1 )
    {
        workWeekTwo[ dayToSet ].setDate( workDayToSet.getDate() );
        workWeekTwo[ dayToSet ].setScheduledStartTime( workDayToSet.getScheduledStartTime().getHour(),
                                                         workDayToSet.getScheduledStartTime().getMinute(),
                                                         workDayToSet.getScheduledStartTime().getSecond() );
        workWeekTwo[ dayToSet ].setScheduledEndTime( workDayToSet.getScheduledEndTime().getHour(),
                                                       workDayToSet.getScheduledEndTime().getMinute(),
                                                       workDayToSet.getScheduledEndTime().getSecond() );
        workWeekTwo[ dayToSet ].setClockInTime( workDayToSet.getClockInTime() );
        workWeekTwo[ dayToSet ].setClockOutTime( workDayToSet.getClockOutTime() );
    }

}

Schedule Schedule::operator = ( const Schedule& newSchedule )
{
    for( int i = 0; i < 7; i++ )
    {
        workWeekOne[i] = newSchedule.workWeekOne[i];
        workWeekTwo[i] = newSchedule.workWeekTwo[i];
    }
}
