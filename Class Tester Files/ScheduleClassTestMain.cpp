#include <iostream>

#include "Schedule.h"
#include "WorkDay.h"
#include "MyTime.h"
#include "MyDate.h"

using namespace std;

int main()
{
    MyDate currentDate;
    MyTime currentTime;
    WorkDay currentWorkDay;
    MyTime clockInTime(9,0,0);
    MyTime clockOutTime(16,0,0);

    currentDate.setDate( currentDate.getCurrentDate().getYear(),
                         currentDate.getCurrentDate().getMonth(),
                         currentDate.getCurrentDate().getDay() );
    currentTime.setTime( currentTime.getCurrentTime() );
    currentWorkDay.setDate( currentDate );
    currentWorkDay.setScheduledStartTime(8,0,0);
    currentWorkDay.setScheduledEndTime(17,0,0);
    currentWorkDay.setClockInTime( clockInTime );
    currentWorkDay.setClockOutTime( clockOutTime );

    Schedule currentSchedule;
    for(int week = 0; week < 2; week++)
    {
        for(int day = 0; day < 7; day++)
        {
            currentSchedule.setWorkDay( currentWorkDay, week, day);
            currentWorkDay.getDate().nextDay();
        }
    }

    cout << "Week One Scheduled Hours: " << currentSchedule.getWeekOneScheduledHours() << endl;
    cout << "Week Two Scheduled Hours: " << currentSchedule.getWeekTwoScheduledHours() << endl;
    cout << "Total Scheduled Hours:    " << currentSchedule.getTotalScheduledHours() << endl;

    cout << "Week One Worked Hours: " << currentSchedule.getWeekOneWorkedHours() << endl;
    cout << "Week Two Worked Hours: " << currentSchedule.getWeekTwoWorkedHours() << endl;
    cout << "Total Worked Hours:    " << currentSchedule.getTotalWorkedHours() << endl;


}
