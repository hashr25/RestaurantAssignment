#include "Schedule.h"

///Constructors and Destructors
Schedule::Schedule()
{
    WorkDay blankDay;

    for( int i = 0; i < 7; i++ )
    {
        workWeekOne.push_back( blankDay );
        workWeekTwo.push_back( blankDay );
    }
    //Nothing really to allocate
}

Schedule::~Schedule()
{
    //Nothing really to deallocate
}


///Getters
std::vector<WorkDay> Schedule::getWorkWeekOne()
{
    return workWeekOne;
}

std::vector<WorkDay> Schedule::getWorkWeekTwo()
{
    return workWeekTwo;
}

float Schedule::getWeekOneScheduledHours()
{
    float hoursScheduled = 0.0;

    for( int i = 0; i < workWeekOne.size(); i++ )
    {
        hoursScheduled += workWeekOne.at(i).calculateHoursScheduled();
    }

    return hoursScheduled;
}

float Schedule::getWeekTwoScheduledHours()
{
    float hoursScheduled = 0.0;

    for( int i = 0; i < workWeekTwo.size(); i++ )
    {
        hoursScheduled += workWeekTwo.at(i).calculateHoursScheduled();
    }

    return hoursScheduled;
}

float Schedule::getTotalScheduledHours()
{
    float hoursScheduled = 0.0;

    for( int i = 0; i < workWeekOne.size(); i++ )
    {
        hoursScheduled += workWeekOne.at(i).calculateHoursScheduled();
        hoursScheduled += workWeekTwo.at(i).calculateHoursScheduled();
    }

    return hoursScheduled;
}

float Schedule::getWeekOneWorkedHours()
{
    float hoursWorked = 0.0;

    for( int i = 0; i < workWeekOne.size(); i++ )
    {
        hoursWorked += workWeekOne.at(i).calculateHoursWorked();
    }

    return hoursWorked;
}

float Schedule::getWeekTwoWorkedHours()
{
    float hoursWorked = 0.0;

    for( int i = 0; i < workWeekTwo.size(); i++ )
    {
        hoursWorked += workWeekTwo.at(i).calculateHoursWorked();
    }

    return hoursWorked;
}

float Schedule::getTotalWorkedHours()
{
    float hoursWorked = 0.0;

    for( int i = 0; i < workWeekOne.size(); i++ )
    {
        hoursWorked += workWeekOne.at(i).calculateHoursWorked();
        hoursWorked += workWeekTwo.at(i).calculateHoursWorked();
    }

    return hoursWorked;
}

void Schedule::setWorkDay( WorkDay workDayToSet, int weekToSet, int dayToSet )
{
    if( weekToSet == 0 )
    {
        workWeekOne.at( dayToSet ).setDate( workDayToSet.getDate() );
        workWeekOne.at( dayToSet ).setScheduledStartTime( workDayToSet.getScheduledStartTime().getHour(),
                                                         workDayToSet.getScheduledStartTime().getMinute(),
                                                         workDayToSet.getScheduledStartTime().getSecond() );
        workWeekOne.at( dayToSet ).setScheduledEndTime( workDayToSet.getScheduledEndTime().getHour(),
                                                       workDayToSet.getScheduledEndTime().getMinute(),
                                                       workDayToSet.getScheduledEndTime().getSecond() );
        workWeekOne.at( dayToSet ).setClockInTime( workDayToSet.getClockInTime() );
        workWeekOne.at( dayToSet ).setClockOutTime( workDayToSet.getClockOutTime() );
    }

    else if( weekToSet == 1 )
    {
        workWeekTwo.at( dayToSet ).setDate( workDayToSet.getDate() );
        workWeekTwo.at( dayToSet ).setScheduledStartTime( workDayToSet.getScheduledStartTime().getHour(),
                                                         workDayToSet.getScheduledStartTime().getMinute(),
                                                         workDayToSet.getScheduledStartTime().getSecond() );
        workWeekTwo.at( dayToSet ).setScheduledEndTime( workDayToSet.getScheduledEndTime().getHour(),
                                                       workDayToSet.getScheduledEndTime().getMinute(),
                                                       workDayToSet.getScheduledEndTime().getSecond() );
        workWeekTwo.at( dayToSet ).setClockInTime( workDayToSet.getClockInTime() );
        workWeekTwo.at( dayToSet ).setClockOutTime( workDayToSet.getClockOutTime() );
    }

}

Schedule Schedule::operator = ( const Schedule& newSchedule )
{
    for( int i = 0; i < workWeekOne.size(); i++ )
    {
        setWorkDay( newSchedule.workWeekOne.at(i), 0, i) ;
        setWorkDay( newSchedule.workWeekTwo.at(i), 1, i);
    }
    return *this;
}
