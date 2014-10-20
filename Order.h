#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <vector>
#include <math.h>
#include "Food.h"
#include "Combo.h"

class Order
{
public:
    Order();

    void setCustomerName( std::string );
    void setOrderNumber();

    std::string getCustomerName();
    int getOrderNumber();
    std::vector<Food> getFoods();
    std::vector<Combo> getCombos();

    bool ifFoodExists( Food );
    int searchForFood( Food );
    void addFood( Food );
    void removeFood( Food );

    bool ifComboExists( Combo );
    int searchForCombo( Combo );
    void addCombo( Combo );
    void removeCombo( Combo );

    float getSubTotalCost();
    float getTaxes();
    float getTotalCost();

private:
    std::string customerName;
    static int orderNumberGenerator;

    int orderNumber;
    std::vector<Food> foodsOrdered;
    std::vector<Combo> combosOrdered;
};

#endif // ORDER_H
