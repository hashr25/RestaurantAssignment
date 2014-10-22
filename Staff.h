#ifndef STAFF_H
#define STAFF_H

#include <vector>
#include <fstream>

#include "Employee.h"

class Staff
{
public:
    Staff();
    ~Staff();

    bool ifEmployed( Employee );
    bool ifEmployed( int );
    int searchForEmployee( Employee );
    int searchForEmployee( int );
    void fireEmployee( Employee );
    void hireEmployee( Employee );
    std::vector<Employee> getStaff();

    void loadStaff();
    void saveStaff();

    int stringToInt( std::string );

private:
    std::vector<Employee> listOfEmployees;
};

#endif // STAFF_H
