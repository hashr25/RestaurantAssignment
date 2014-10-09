#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include "Schedule.h"


class Employee
{
public:
    ///Constructors and Destructors
    Employee();
    ~Employee();

    ///Getters and Setters
    std::string getName();
    int getID();
    int getPosition();
    std::string getPositionTitle();
    float getHourlyPayRate();
    Schedule getEmployeeSchedule();

    void setName( std::string );
    void setID();
    void setIDCustom( int );
    void setPosition( int );
    void setPositionTitle( std::string );
    void setHourlyPayRate( float );
    void setEmployeeSchedule( Schedule );

    ///Methods
    void payRaise();
    void payRaise( float );
    void promote();
    void promote( int );

    Employee operator = ( const Employee& );

private:
    std::string name;
    int employeeID;
    int position;
    std::string positionTitle;
    float hourlyPayRate;
    Schedule employeeSchedule;
    static int employeeIDGenerator;
};

#endif // EMPLOYEE_H
