#ifndef STAFF_H
#define STAFF_H

#include <vector>
#include "Employee.h"

class Staff
{
public:
    Staff();

    bool ifEmployed( Employee );
    int searchForEmployee( Employee );
    void fireEmployee( Employee );
    void hireEmployee( Employee );
    std::vector<Employee> getStaff();

private:
    std::vector<Employee> listOfEmployees;
};

#endif // STAFF_H
