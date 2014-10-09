#include <iostream>

#include "Employee.h"

using namespace std;

void printEmployee( Employee );

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
    currentWorkDay.setScheduledEndTime(16,0,0);
    currentWorkDay.setClockInTime( clockInTime );
    currentWorkDay.setClockOutTime( clockOutTime );

    Schedule currentSchedule;
    for(int week = 0; week < 2; week++)
    {
        for(int day = 0; day < 5; day++)
        {
            currentSchedule.setWorkDay( currentWorkDay, week, day);
            currentWorkDay.getDate().nextDay();
        }
    }

    cout << "starting copying schedule" << endl;
    Schedule anotherSchedule;
    anotherSchedule = currentSchedule;
    cout << "This Works." << endl;

    ///Starts first testing of the Employee Class
    Employee Bob;
    Bob.setName("Bob");
    Bob.setHourlyPayRate(7.25);
    Bob.setPosition(0);
    Bob.setPositionTitle("Grunt");
    Bob.setEmployeeSchedule( currentSchedule );

    printEmployee( Bob );
    cout << endl;

    ///Starts second testing of the Employee Class
    Employee Sue;
    Sue.setName("Sue");
    Sue.setHourlyPayRate(9.75);
    Sue.setPosition(1);
    Sue.setPositionTitle("Shift Manager");
    Sue.setEmployeeSchedule( currentSchedule );

    printEmployee( Sue );
    cout << endl;

    ///Starts third testing of the Employee Class
    Employee Joe;
    Joe.setName("Joe");
    Joe.setHourlyPayRate(15.45);
    Joe.setPosition(2);
    Joe.setPositionTitle("Restaurant Manager");
    Joe.setEmployeeSchedule( currentSchedule );

    printEmployee( Joe );

    return 0;
}

void printEmployee( Employee employeeName )
{
    cout << "Employee Name:  " << employeeName.getName() << endl;
    cout << "Employee ID:    " << employeeName.getID() << endl;
    cout << "Employee Pay:  $" << employeeName.getHourlyPayRate() << endl;
    cout << "Employee Pos:   " << employeeName.getPosition() << endl;
    cout << "Employee Pos T: " << employeeName.getPositionTitle() << endl;

    cout << "Hours Week 1:   " << employeeName.getEmployeeSchedule().getWeekOneScheduledHours() << endl;
    cout << "Hours Week 2:   " << employeeName.getEmployeeSchedule().getWeekTwoScheduledHours() << endl;
    cout << "Hours Total:    " << employeeName.getEmployeeSchedule().getTotalScheduledHours() << endl;
}
