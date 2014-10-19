// Matt Rawson
// Group
#ifndef CHECK_H
#define CHECK_H

#include <iostream>
#include <string>
#include <vector>

class Check
{
public:
    Check();// constructor
    ~Check();// destructor
    int getCheckNumber();// returns the check number.
    float getGrossIncome();// returns the gross income.
    float getNetIncome();// returns the net income.
    float getStateTaxesWitheld();// returns the withheld state taxes.
    float getFederalTaxesWitheld();// returns the withheld federal taxes.
    float getSocialSecurityWitheld();// returns the withheld social security.
    float getMedicareWitheld();// returns the withheld Medicare.
    void setCheckNumber();// gets from static int generator
    void setGrossIncome(float);// gets the gross income.
    void setNetIncome(float);// gets the net income.
    void setStateTaxesWitheld(float);// gets the state taxes.
    void setFederalTaxesWitheld(float);// gets the federal taxes.
    void setSocialSecurityWitheld(float);// gets the social security.
    void setMedicareWitheld(float);// gets the Medicare.

private:
    static int checkNumberGenerator;// = 1000
    int checkNumber;
    float grossIncome;
    float netIncome;
    float stateTaxesWitheld;
    float federalTaxesWitheld;
    float socialSecurityWitheld;
    float medicareWitheld;
};

#endif // CHECK_H
