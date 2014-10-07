// Matt Rawson
// Group
#include <math.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Check.h"

using namespace std;

int main()
{
    Check income;
    Check income2;
    Check income3;
    Check income4;

    income.setCheckNumber();
    income2.setCheckNumber();
    income3.setCheckNumber();
    income4.setCheckNumber();

    income.setNetIncome( 2000 );
    income.setGrossIncome( 1500 );
    income.setFederalTaxesWitheld( 100 );
    income.setMedicareWitheld( 100 );
    income.setSocialSecurityWitheld( 150 );
    income.setStateTaxesWitheld( 150 );

    cout << income.getCheckNumber() << endl;
    cout << income2.getCheckNumber() << endl;
    cout << income3.getCheckNumber() << endl;
    cout << income4.getCheckNumber() << endl;

    cout << "Check Number: " << income.getCheckNumber() << endl;

    return 0;

}// int main()
