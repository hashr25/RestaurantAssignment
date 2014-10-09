#include "Employee.h"

int Employee::employeeIDGenerator = 111111;

///Constructors and Destructors
Employee::Employee()
{
    setID();
}

Employee::~Employee()
{

}

///Getters and Setters
std::string Employee::getName()
{
    return name;
}

int Employee::getID()
{
    return employeeID;
}

int Employee::getPosition()
{
    return position;
}

std::string Employee::getPositionTitle()
{
    return positionTitle;
}

float Employee::getHourlyPayRate()
{
    return hourlyPayRate;
}

Schedule Employee::getEmployeeSchedule()
{
    return employeeSchedule;
}


void Employee::setName( std::string name )
{
    this -> name = name;
}

void Employee::setID()
{
    employeeID = employeeIDGenerator;
    employeeIDGenerator++;
}

void Employee::setIDCustom( int customID )
{
    if( customID >= 111111 && customID < 1000000 )
    {
        employeeID = customID;
    }
}

void Employee::setPosition( int position )
{
    this -> position = position;
}

void Employee::setPositionTitle( std::string positionTitle )
{
    this -> positionTitle = positionTitle;
}

void Employee::setHourlyPayRate( float hourlyPayRate )
{
    this -> hourlyPayRate = hourlyPayRate;
}

void Employee::setEmployeeSchedule( Schedule newSchedule )
{
    employeeSchedule = newSchedule;
}

///Methods
void Employee::payRaise()
{
    setHourlyPayRate( hourlyPayRate + 0.25 );
}

void Employee::payRaise( float amountToRaise )
{
    setHourlyPayRate( hourlyPayRate + amountToRaise );
}

void Employee::promote()
{
    setPosition( position + 1 );
}

void Employee::promote( int positionsToPromote)
{
    setPosition( position + positionsToPromote );
}

Employee Employee::operator = ( const Employee& newEmployee )
{
    name = newEmployee.name;
    setIDCustom( newEmployee.employeeID );
    setPosition( newEmployee.position );
    positionTitle = newEmployee.positionTitle;
    setHourlyPayRate( newEmployee.hourlyPayRate );
    employeeSchedule = newEmployee.employeeSchedule;
}

