#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <vector>
#include "Food.h"
#include "Combo.h"

using namespace std;

class Order
{
public:
    void setCustomerName( string );
    void setOrderNumber();

    string getCustomerName();
    int getOrderNumber();
    vector<Food> getFoods();
    vector<Combo> getCombos();

    int searchForFood( Food );
    void addFood( Food );
    void removeFood( Food );

    int searchForCombo( Combo );
    void addCombo( Combo );
    void removeCombo( Combo );

private:
    string customerName;
    static int orderNumberGenerator;

    int orderNumber;
    vector<Food> foodsOrdered;
    vector<Combo> combosOrdered;
};

#endif // ORDER_H
