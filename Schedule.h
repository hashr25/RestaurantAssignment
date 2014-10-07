#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <vector>
#include "WorkDay.h"

class Schedule
{
public:
    ///Constructors and Destructors
    Schedule();
    ~Schedule();

    ///Getters
    WorkDay* getWorkWeekOne();
    WorkDay* getWorkWeekTwo();
    float getWeekOneScheduledHours();
    float getWeekTwoScheduledHours();
    float getTotalScheduledHours();
    float getWeekOneWorkedHours();
    float getWeekTwoWorkedHours();
    float getTotalWorkedHours();
    void setWorkDay( WorkDay, int, int );

    Schedule operator = ( const Schedule& );

private:
    WorkDay workWeekOne[7];
    WorkDay workWeekTwo[7];
};

#endif // SCHEDULE_H
