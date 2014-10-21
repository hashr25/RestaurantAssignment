#include "payRoll.h"

PayRoll::PayRoll()
{
    loadPayRoll();
}// PayRoll::PayRoll()

float PayRoll::getBudget()
{

    return budget;

}// float PayRoll::getBudget()

float PayRoll::getStateTaxRate()
{

    return stateTaxRate;

}// float PayRoll::getStateTaxRate()

float PayRoll::getFederalTaxRate()
{

    return federalTaxRate;

}// float PayRoll::getFederalTaxRate()

float PayRoll::getSocialSecurityRate()
{

    return socialSecurityRate;

}// float PayRoll::getSocialSecurityRate()

float PayRoll::getMedicareRate()
{

    return medicareRate;

}// float PayRoll::getMedicareRate()

void PayRoll::setBudget(float budget)
{

    this -> budget = budget;

}// void PayRoll::setBudget(float budget)

void PayRoll::setStateTaxRate(float stateTaxRate)
{

    this -> stateTaxRate = stateTaxRate;

}// void PayRoll::setStateTaxRate(float stateTaxRate)

void PayRoll::increaseBudget(float increaseInBudget)
{

    budget = budget + increaseInBudget;

}// void PayRoll::increaseBudget(float increaseInBudget)

void PayRoll::decreaseBudget(float decreaseInBudget)
{

    budget = budget - decreaseInBudget;

    if( budget < 0 )
    {
        budget = 0;
    }

}//void PayRoll:decreaseBudget(float decreaseInBudget)

Check PayRoll::createCheck(Employee employeeToPay)
{
    Check employeeCheck;

    float totalHoursWorked = employeeToPay.getEmployeeSchedule().getTotalWorkedHours();
    float grossPay = totalHoursWorked * employeeToPay.getHourlyPayRate();
    float socialSecurityWitheld = grossPay * socialSecurityRate;
    float medicareWitheld = grossPay * medicareRate;
    float federalTaxesWitheld = grossPay * federalTaxRate;
    float stateTaxesWitheld = grossPay * stateTaxRate;
    float netPay = grossPay - socialSecurityWitheld - medicareWitheld - federalTaxesWitheld - stateTaxesWitheld;

    employeeCheck.setGrossIncome( grossPay );
    employeeCheck.setSocialSecurityWitheld( socialSecurityWitheld );
    employeeCheck.setMedicareWitheld( medicareWitheld );
    employeeCheck.setFederalTaxesWitheld( federalTaxesWitheld );
    employeeCheck.setStateTaxesWitheld( stateTaxesWitheld );
    employeeCheck.setNetIncome( netPay );

    return employeeCheck;
}// Check PayRoll::createCheck(Employee employeeToPay)

void PayRoll::deductCheckFromBudget(Check checkToRemove)
{

    budget = budget - checkToRemove.getGrossIncome();

}// void PayRoll::deductCheckFromBudget(Check checkToRemove)

PayRoll::~PayRoll()
{
    savePayRoll();
}// PayRoll::~PayRoll()

void PayRoll::savePayRoll()
{
    std::ofstream outputFile;

    outputFile.open( "PayRoll.txt" );
    outputFile << budget << "\n";
    outputFile << stateTaxRate;

    outputFile.close();
}

void PayRoll::loadPayRoll()
{
    std::ifstream inputFile;

    float loadBudget;
    float loadStateTax;

    inputFile.open( "PayRoll.txt" );
    while( inputFile >> loadBudget >> loadStateTax )
    {
        budget = loadBudget;
        stateTaxRate = loadStateTax;
    }

    inputFile.close();
}
