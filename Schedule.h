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
    std::vector<WorkDay> getWorkWeekOne();
    std::vector<WorkDay> getWorkWeekTwo();
    float getWeekOneScheduledHours();
    float getWeekTwoScheduledHours();
    float getTotalScheduledHours();
    float getWeekOneWorkedHours();
    float getWeekTwoWorkedHours();
    float getTotalWorkedHours();
    void setWorkDay( WorkDay, int, int );

    Schedule operator = ( const Schedule& );

private:
    std::vector<WorkDay> workWeekOne;
    std::vector<WorkDay> workWeekTwo;
};

#endif // SCHEDULE_H
