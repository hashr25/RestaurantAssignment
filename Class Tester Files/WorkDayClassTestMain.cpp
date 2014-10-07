#include <iostream>

#include "MyTime.h"
#include "MyDate.h"
#include "WorkDay.h"

using namespace std;

int main()
{
    ///Testing new .getCurrentTime() function
    MyTime testTime( 0, 0, 0 );
    cout << testTime.getCurrentTime().getHour() << endl;
    cout << testTime.getCurrentTime().getMinute() << endl;
    cout << testTime.getCurrentTime().getSecond() << endl;
    cout << testTime.getCurrentTime().toString() << endl;

    ///Testing new .getCurrentDate() function
    MyDate testDate( 0, 0, 0 );
    testDate = testDate.getCurrentDate();
    cout << testDate.getMonth() << endl;
    cout << testDate.getDay() << endl;
    cout << testDate.getYear() << endl;
    cout << testDate.toString() << endl;

    ///Testing WorkDay Class
    WorkDay testWorkDay;
    testWorkDay.setScheduledStartTime( 7, 0, 0 );
    testWorkDay.setScheduledEndTime( 12, 30, 25 );

    string junk = "";

    cout << "Press enter to set Work Date" << endl;
    cin >> junk;
    testWorkDay.setDate( testWorkDay.getDate().getCurrentDate() );

    cout << "Press enter to Clock In" << endl;
    cin >> junk;
    testWorkDay.setClockInTime( testWorkDay.getClockInTime().getCurrentTime() );

    cout << "Press enter to Clock Out" << endl;
    cin >> junk;
    testWorkDay.setClockOutTime( testWorkDay.getClockOutTime().getCurrentTime() );

    cout << "Date:            " << testWorkDay.getDate().toString() << endl;
    cout << "Schedule Start:  " << testWorkDay.getScheduledStartTime().toString() << endl;
    cout << "Schedule End:    " << testWorkDay.getScheduledEndTime().toString() << endl;
    cout << "Clock In:        " << testWorkDay.getClockInTime().toString() << endl;
    cout << "Clock Out:       " << testWorkDay.getClockOutTime().toString() << endl;
    cout << "Hours Scheduled: " << testWorkDay.calculateHoursScheduled() << endl;
    cout << "Hours Worked:    " << testWorkDay.calculateHoursWorked() << endl;

    return 0;
}
