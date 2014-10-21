#include "Staff.h"

///Constructors and Destructors
Staff::Staff()
{

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
