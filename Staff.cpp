#include "Staff.h"

///Constructors and Destructors
Staff::Staff()
{

}

Staff::~Staff()
{
    saveStaff();
}

///Member Methods
bool Staff::ifEmployed( Employee employeeToFind )
{
    bool employeeEmployed = false;

    for( int i = 0; i < listOfEmployees.size(); i++ )
    {
        if( listOfEmployees.at(i).getName() == employeeToFind.getName() )
        {
            employeeEmployed = true;
        }
    }

    return employeeEmployed;
}

bool Staff::ifEmployed( int employeeIDToFind )
{
    bool employeeEmployed = false;

    for( int i = 0; i < listOfEmployees.size(); i++ )
    {
        if( listOfEmployees.at(i).getID() == employeeIDToFind )
        {
            employeeEmployed = true;
        }
    }

    return employeeEmployed;
}

int Staff::searchForEmployee( Employee employeeToSearch ) //Returns the index of the employee in the vector
{
    int employeeIndex;

    for( int i = 0; i < listOfEmployees.size(); i++ )
    {
        if( listOfEmployees.at(i).getName() == employeeToSearch.getName() )
        {
            employeeIndex = i;
        }
    }

    return employeeIndex;
}

int Staff::searchForEmployee( int employeeIDToSearch )
{
    int employeeIndex;

    for( int i = 0; i < listOfEmployees.size(); i++ )
    {
        if( listOfEmployees.at(i).getID() == employeeIDToSearch )
        {
            employeeIndex = i;
        }
    }

    return employeeIndex;
}

void Staff::fireEmployee( Employee employeeToFire )
{
    if( ifEmployed( employeeToFire ) )
    {
        listOfEmployees.erase( listOfEmployees.end() - ( listOfEmployees.size() - searchForEmployee( employeeToFire ) ) );
    }
}

void Staff::hireEmployee( Employee employeeToHire )
{
    listOfEmployees.push_back( employeeToHire );
}

std::vector<Employee> Staff::getStaff()
{
    return listOfEmployees;
}

void Staff::loadStaff()
{
    std::ifstream inputFile;
    inputFile.open( "SaveFiles/Staff.txt" );

    std::string line;

    while( getline( inputFile, line ) )
    {
        std::vector<int> commaPositions;

        for( int i = 0; i < line.size(); i++ )
        {
            if( line.at(i) == ',' )
            {
                commaPositions.push_back(i);
            }
        }

        ///Basic information and conversions
        std::string employeeName = line.substr( 0, ( commaPositions.at(0) ) );

        std::string employeeIDString = line.substr( commaPositions.at(0)+1, (commaPositions.at(1) - commaPositions.at(0) ) );
        std::istringstream employeeIDSS( employeeIDString );
        int employeeID;
        employeeIDSS >> employeeID;

        std::string positionString = line.substr( commaPositions.at(1)+1, (commaPositions.at(2) - commaPositions.at(1) ) );
        std::istringstream positionSS( positionString );
        int position;
        positionSS >> position;

        std::string positionTitleString = line.substr( commaPositions.at(2)+1, (commaPositions.at(3) - commaPositions.at(2) ) );

        std::string payRateString = line.substr( commaPositions.at(3)+1, (commaPositions.at(4) - commaPositions.at(3) ) );
        std::istringstream payRateSS( payRateString );
        float payRate;
        payRateSS >> payRate;

        Schedule scheduleToAdd;
        ///Schedule
        std::vector<WorkDay> workWeek1;
        for( int i = 0; i < 7; i++ )
        {
            std::string dateMonthString = line.substr( commaPositions.at(4+(i*15))+1, (commaPositions.at(5+(i*15)) - commaPositions.at(4+(i*15)) ) );
            int dateMonth = stringToInt( dateMonthString );

            std::string dateDayString = line.substr( commaPositions.at(5+(i*15))+1, (commaPositions.at(6+(i*15)) - commaPositions.at(5+(i*15)) ) );
            int dateDay = stringToInt( dateDayString );

            std::string dateYearString = line.substr( commaPositions.at(6+(i*15))+1, ( commaPositions.at(7+(i*15)) - commaPositions.at(6+(i*15)) ) );
            int dateYear = stringToInt( dateYearString );

            int scheduleInHour = stringToInt ( line.substr( commaPositions.at(7+(i*15))+1, ( commaPositions.at(8+(i*15)) - commaPositions.at(7+(i*15)) ) ) );
            int scheduleinMinute = stringToInt ( line.substr( commaPositions.at(8+(i*15))+1, ( commaPositions.at(9+(i*15)) - commaPositions.at(8+(i*15)) ) ) );
            int scheduleInSecond = stringToInt ( line.substr( commaPositions.at(9+(i*15))+1, ( commaPositions.at(10+(i*15)) - commaPositions.at(9+(i*15)) ) ) );

            int scheduleOutHour = stringToInt ( line.substr( commaPositions.at(10+(i*15))+1, ( commaPositions.at(11+(i*15)) - commaPositions.at(10+(i*15)) ) ) );
            int scheduleOutMinute = stringToInt ( line.substr( commaPositions.at(11+(i*15))+1, ( commaPositions.at(12+(i*15)) - commaPositions.at(11+(i*15)) ) ) );
            int scheduleOutSecond = stringToInt ( line.substr( commaPositions.at(12+(i*15))+1, ( commaPositions.at(13+(i*15)) - commaPositions.at(12+(i*15)) ) ) );

            int clockInHour = stringToInt ( line.substr( commaPositions.at(13+(i*15))+1, ( commaPositions.at(14+(i*15)) - commaPositions.at(13+(i*15)) ) ) );
            int clockInMinute = stringToInt ( line.substr( commaPositions.at(14+(i*15))+1, ( commaPositions.at(15+(i*15)) - commaPositions.at(14+(i*15)) ) ) );
            int clockInSecond = stringToInt ( line.substr( commaPositions.at(15+(i*15))+1, ( commaPositions.at(16+(i*15)) - commaPositions.at(15+(i*15)) ) ) );

            int clockOutHour = stringToInt ( line.substr( commaPositions.at(16+(i*15))+1, ( commaPositions.at(17+(i*15)) - commaPositions.at(16+(i*15)) ) ) );
            int clockOutMinute = stringToInt ( line.substr( commaPositions.at(17+(i*15))+1, ( commaPositions.at(18+(i*15)) - commaPositions.at(17+(i*15)) ) ) );
            int clockOutSecond = stringToInt ( line.substr( commaPositions.at(18+(i*15))+1, ( commaPositions.at(19+(i*15)) - commaPositions.at(18+(i*15)) ) ) );

            MyDate date(dateMonth, dateDay, dateYear);
            MyTime scheduleIn( scheduleInHour, scheduleinMinute, scheduleInSecond );
            MyTime scheduleOut( scheduleOutHour, scheduleOutMinute, scheduleOutSecond );
            MyTime clockIn( clockInHour, clockInMinute, clockInSecond );
            MyTime clockOut( clockOutHour, clockOutMinute, clockOutSecond );

            WorkDay workDayToAdd( date, scheduleIn, scheduleOut, clockIn, clockOut );
        }

        for( int i = 0; i < 7; i++ )
        {

        }
    }
}

int Staff::stringToInt( std::string stringToConvert )
{
    std::istringstream convertSS( stringToConvert );
    int intToReturn;
    convertSS >> intToReturn;
    return intToReturn;
}

void Staff::saveStaff()
{
    std::ofstream outputFile;
    outputFile.open( "SaveFiles/Staff.txt" );

    for( int i = 0; i < listOfEmployees.size(); i++ )
    {
        outputFile << listOfEmployees.at(i).getName() << ", ";
        outputFile << listOfEmployees.at(i).getID() << ", ";
        outputFile << listOfEmployees.at(i).getPosition() << ", ";
        outputFile << listOfEmployees.at(i).getPositionTitle() << ", ";
        outputFile << listOfEmployees.at(i).getHourlyPayRate() << ", ";

        for( int j = 0; j < 7; j++ )
        {
            outputFile << listOfEmployees.at(i).getEmployeeSchedule().getWorkWeekOne().at(j).getDate().getMonth() << ", ";
            outputFile << listOfEmployees.at(i).getEmployeeSchedule().getWorkWeekOne().at(j).getDate().getDay() << ", ";
            outputFile << listOfEmployees.at(i).getEmployeeSchedule().getWorkWeekOne().at(j).getDate().getYear() << ", ";

            outputFile << listOfEmployees.at(i).getEmployeeSchedule().getWorkWeekOne().at(j).getScheduledStartTime().getHour() << ", ";
            outputFile << listOfEmployees.at(i).getEmployeeSchedule().getWorkWeekOne().at(j).getScheduledStartTime().getMinute() << ", ";
            outputFile << listOfEmployees.at(i).getEmployeeSchedule().getWorkWeekOne().at(j).getScheduledStartTime().getSecond() << ", ";

            outputFile << listOfEmployees.at(i).getEmployeeSchedule().getWorkWeekOne().at(j).getScheduledEndTime().getHour() << ", ";
            outputFile << listOfEmployees.at(i).getEmployeeSchedule().getWorkWeekOne().at(j).getScheduledEndTime().getMinute() << ", ";
            outputFile << listOfEmployees.at(i).getEmployeeSchedule().getWorkWeekOne().at(j).getScheduledEndTime().getSecond() << ", ";

            outputFile << listOfEmployees.at(i).getEmployeeSchedule().getWorkWeekOne().at(j).getClockInTime().getHour() << ", ";
            outputFile << listOfEmployees.at(i).getEmployeeSchedule().getWorkWeekOne().at(j).getClockInTime().getMinute() << ", ";
            outputFile << listOfEmployees.at(i).getEmployeeSchedule().getWorkWeekOne().at(j).getClockInTime().getSecond() << ", ";

            outputFile << listOfEmployees.at(i).getEmployeeSchedule().getWorkWeekOne().at(j).getClockOutTime().getHour() << ", ";
            outputFile << listOfEmployees.at(i).getEmployeeSchedule().getWorkWeekOne().at(j).getClockOutTime().getMinute() << ", ";
            if( j == 6 )
            {
                outputFile << listOfEmployees.at(i).getEmployeeSchedule().getWorkWeekOne().at(j).getClockOutTime().getSecond() << "\n";
            }
            else
            {
                outputFile << listOfEmployees.at(i).getEmployeeSchedule().getWorkWeekOne().at(j).getClockOutTime().getSecond() << ", ";
            }
        }

        for( int j = 0; j < 7; j++ )
        {
            outputFile << listOfEmployees.at(i).getEmployeeSchedule().getWorkWeekTwo().at(j).getDate().getMonth() << ", ";
            outputFile << listOfEmployees.at(i).getEmployeeSchedule().getWorkWeekTwo().at(j).getDate().getDay() << ", ";
            outputFile << listOfEmployees.at(i).getEmployeeSchedule().getWorkWeekTwo().at(j).getDate().getYear() << ", ";

            outputFile << listOfEmployees.at(i).getEmployeeSchedule().getWorkWeekTwo().at(j).getScheduledStartTime().getHour() << ", ";
            outputFile << listOfEmployees.at(i).getEmployeeSchedule().getWorkWeekTwo().at(j).getScheduledStartTime().getMinute() << ", ";
            outputFile << listOfEmployees.at(i).getEmployeeSchedule().getWorkWeekTwo().at(j).getScheduledStartTime().getSecond() << ", ";

            outputFile << listOfEmployees.at(i).getEmployeeSchedule().getWorkWeekTwo().at(j).getScheduledEndTime().getHour() << ", ";
            outputFile << listOfEmployees.at(i).getEmployeeSchedule().getWorkWeekTwo().at(j).getScheduledEndTime().getMinute() << ", ";
            outputFile << listOfEmployees.at(i).getEmployeeSchedule().getWorkWeekTwo().at(j).getScheduledEndTime().getSecond() << ", ";

            outputFile << listOfEmployees.at(i).getEmployeeSchedule().getWorkWeekTwo().at(j).getClockInTime().getHour() << ", ";
            outputFile << listOfEmployees.at(i).getEmployeeSchedule().getWorkWeekTwo().at(j).getClockInTime().getMinute() << ", ";
            outputFile << listOfEmployees.at(i).getEmployeeSchedule().getWorkWeekTwo().at(j).getClockInTime().getSecond() << ", ";

            outputFile << listOfEmployees.at(i).getEmployeeSchedule().getWorkWeekTwo().at(j).getClockOutTime().getHour() << ", ";
            outputFile << listOfEmployees.at(i).getEmployeeSchedule().getWorkWeekTwo().at(j).getClockOutTime().getMinute() << ", ";
            if( j == 6 )
            {
                outputFile << listOfEmployees.at(i).getEmployeeSchedule().getWorkWeekTwo().at(j).getClockOutTime().getSecond() << "\n";
            }
            else
            {
                outputFile << listOfEmployees.at(i).getEmployeeSchedule().getWorkWeekTwo().at(j).getClockOutTime().getSecond() << ", ";
            }
        }
    }
}
