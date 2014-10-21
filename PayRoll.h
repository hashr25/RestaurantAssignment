#ifndef PAYROLL_H
#define PAYROLL_H

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <fstream>

#include "check.h"
#include "Employee.h"

class PayRoll
{

public:
    PayRoll();// constructor
    ~PayRoll();// destructor
    float getBudget();// returns the budget.
    float getStateTaxRate();// returns the state tax rate.
    float getFederalTaxRate();// returns the federal tax rate.
    float getSocialSecurityRate();// returns the social security rate.
    float getMedicareRate();// returns the medical care rate.
    void setBudget(float budget);// gets the budget.
    void setStateTaxRate(float stateTaxRate);// gets the state tax rate.
    void increaseBudget(float increaseInBudget);// added an amount to the current budget.
    void decreaseBudget(float decreaseInBudget);// remove an amount from the current budget.
    Check createCheck(Employee employeeToPay);// makes a check for a specific employee.
    void deductCheckFromBudget(Check checkToRemove);// removes a check amount from the budget.

    void loadPayRoll();
    void savePayRoll();

private:
    float budget;
    float stateTaxRate;
    const float federalTaxRate = 0.12; // This is an approx. of the federal tax rate.
    const float socialSecurityRate = 0.06;// This is an approx. of the social security rate.
    const float medicareRate = 0.05;// This is an approx. of the medical care rate.

};


#endif // PAYROLL_H
