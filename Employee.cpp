#include "Employee.h"

int Employee::employeeIDGenerator = 111111;

///Constructors and Destructors
Employee::Employee()
{
    setID();
}

Employee::Employee( std::string newName , int newPosition, std::string newPositionTitle, float newPayRate ):
    name(newName), position(newPosition), positionTitle(newPositionTitle), hourlyPayRate(newPayRate)
{
    setID();
}

Employee::Employee( std::string newName , int newPosition, std::string newPositionTitle, float newPayRate, Schedule newSchedule ):
    name(newName), position(newPosition), positionTitle(newPositionTitle),
    hourlyPayRate(newPayRate), employeeSchedule(newSchedule)
{
    setID();
}

Employee::Employee( std::string newName , int newID, int newPosition, std::string newPositionTitle, float newPayRate, Schedule newSchedule ):
    name(newName), employeeID(newID), position(newPosition), positionTitle(newPositionTitle),
    hourlyPayRate(newPayRate), employeeSchedule(newSchedule)
{

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

Check Employee::getLastCheck()
{
    return lastCheck;
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

void Employee::setLastCheck( Check lastCheck )
{
    this -> lastCheck = lastCheck;
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

void Employee::clockIn()
{
    MyTime currentTime;
    currentTime = currentTime.getCurrentTime();

    MyDate currentDate;
    currentDate = currentDate.getCurrentDate();

    WorkDay* workDayToChange;

    for( int i = 0; i < 7; i++ )
    {
        if( employeeSchedule.getWorkWeekOne().at(i).getDate().getMonth() == currentDate.getMonth() &&
            employeeSchedule.getWorkWeekOne().at(i).getDate().getDay() == currentDate.getDay()     &&
            employeeSchedule.getWorkWeekOne().at(i).getDate().getYear() == currentDate.getYear()    )
        {
            workDayToChange = &employeeSchedule.getWorkWeekOne().at(i);
        }

        if( employeeSchedule.getWorkWeekTwo().at(i).getDate().getMonth() == currentDate.getMonth() &&
            employeeSchedule.getWorkWeekTwo().at(i).getDate().getDay() == currentDate.getDay()     &&
            employeeSchedule.getWorkWeekTwo().at(i).getDate().getYear() == currentDate.getYear()    )
        {
            workDayToChange = &employeeSchedule.getWorkWeekTwo().at(i);
        }
    }

    workDayToChange -> setClockInTime( currentTime );
    workDayToChange = NULL;
}

void Employee::clockOut()
{
    MyTime currentTime;
    currentTime = currentTime.getCurrentTime();

    MyDate currentDate;
    currentDate = currentDate.getCurrentDate();

    WorkDay* workDayToChange;

    for( int i = 0; i < 7; i++ )
    {
        if( employeeSchedule.getWorkWeekOne().at(i).getDate().getMonth() == currentDate.getMonth() &&
            employeeSchedule.getWorkWeekOne().at(i).getDate().getDay() == currentDate.getDay()     &&
            employeeSchedule.getWorkWeekOne().at(i).getDate().getYear() == currentDate.getYear()    )
        {
            workDayToChange = &employeeSchedule.getWorkWeekOne().at(i);
        }

        if( employeeSchedule.getWorkWeekTwo().at(i).getDate().getMonth() == currentDate.getMonth() &&
            employeeSchedule.getWorkWeekTwo().at(i).getDate().getDay() == currentDate.getDay()     &&
            employeeSchedule.getWorkWeekTwo().at(i).getDate().getYear() == currentDate.getYear()    )
        {
            workDayToChange = &employeeSchedule.getWorkWeekTwo().at(i);
        }
    }

    workDayToChange -> setClockOutTime( currentTime );
    workDayToChange = NULL;
}

///This is not working properly
/*Employee Employee::operator = ( const Employee& newEmployee )
{
    name = newEmployee.name;std::cout << "copied employee name" << std::endl;
    setIDCustom( newEmployee.employeeID );std::cout << "copied employee id" << std::endl;
    setPosition( newEmployee.position );std::cout << "copied employee position" << std::endl;
    positionTitle = newEmployee.positionTitle;std::cout << "copied employee position title" << std::endl;
    setHourlyPayRate( newEmployee.hourlyPayRate );std::cout << "copied employee pay rate" << std::endl;
    employeeSchedule = newEmployee.employeeSchedule;std::cout << "copied employee schedule" << std::endl;
}*/

