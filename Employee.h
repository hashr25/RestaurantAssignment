#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include "Schedule.h"
#include "Check.h"


class Employee
{
public:
    ///Constructors and Destructors
    Employee();
    Employee( std::string, int, std::string, float );
    Employee( std::string, int, std::string, float, Schedule );
    ~Employee();

    ///Getters and Setters
    std::string getName();
    int getID();
    int getPosition();
    std::string getPositionTitle();
    float getHourlyPayRate();
    Schedule getEmployeeSchedule();
    Check getLastCheck();

    void setName( std::string );
    void setID();
    void setIDCustom( int );
    void setPosition( int );
    void setPositionTitle( std::string );
    void setHourlyPayRate( float );
    void setEmployeeSchedule( Schedule );
    void setLastCheck( Check );

    ///Methods
    void payRaise();
    void payRaise( float );
    void promote();
    void promote( int );

    void clockIn();
    void clockOut();

    //Employee operator = ( const Employee& );

private:
    std::string name;
    int employeeID;
    int position;
    std::string positionTitle;
    float hourlyPayRate;
    Schedule employeeSchedule;
    static int employeeIDGenerator;
    Check lastCheck;
};

#endif // EMPLOYEE_H
