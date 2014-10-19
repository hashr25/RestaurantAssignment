// Matt Rawson
// Group
#include "Check.h"


Check::Check()
{
    setCheckNumber();
}// Check::Check()

int Check::checkNumberGenerator = 1000;

int Check::getCheckNumber()
{

    return checkNumber;

}// int Check::getCheckNumber()

float Check::getGrossIncome()
{

    return grossIncome;

}// float Check::getGrossIncome()

float Check::getNetIncome()
{

    return netIncome;

}// float Check::getNetIncome()

float Check::getStateTaxesWitheld()
{

    return stateTaxesWitheld;

}// float Check::getStateTaxesWitheld()

float Check::getFederalTaxesWitheld()
{

    return federalTaxesWitheld;

}// float Check::getFederalTaxesWitheld()

float Check::getSocialSecurityWitheld()
{

    return socialSecurityWitheld;

}// float Check::getSocialSecurityWitheld()

float Check::getMedicareWitheld()
{

    return medicareWitheld;

}// float Check::getMedicareWitheld()

void Check::setCheckNumber()
{

    checkNumber = checkNumberGenerator;
    checkNumberGenerator++;

}// void Check::setCheckNumber()

void Check::setGrossIncome(float grossIncome)
{

    this -> grossIncome = grossIncome;

}// void Check::setGrossIncome()

void Check::setNetIncome(float netIncome)
{

    this -> netIncome = netIncome;

}// void Check::setNetIncome(float netIncome)

void Check::setStateTaxesWitheld(float stateTaxesWitheld)
{

    this -> stateTaxesWitheld = stateTaxesWitheld;

}// void Check::setStateTaxesWitheld(float stateTaxesWitheld)

void Check::setFederalTaxesWitheld(float federalTaxesWitheld)
{

    this -> federalTaxesWitheld = federalTaxesWitheld;

}// void Check::setFederalTaxesWitheld(float federalTaxesWitheld)

void Check::setSocialSecurityWitheld(float socialSecurityWitheld)
{

    this -> socialSecurityWitheld = socialSecurityWitheld;

}// void Check::setSocialSecurityWitheld(float socialSecurityWitheld)

void Check::setMedicareWitheld(float medicareWitheld)
{

    this -> medicareWitheld = medicareWitheld;

}// void Check::setMedicareWitheld(float medicareWitheld)


Check::~Check()
{

}// Check::~Check()
