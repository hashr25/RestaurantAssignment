#include "Order.h"

int Order::orderNumberGenerator = 100;

Order::Order()
{
    setOrderNumber();
}

void Order::setCustomerName(std::string name)
{
	customerName = name;
}

void Order::setOrderNumber()
{
	orderNumber = orderNumberGenerator++;
}

std::string Order::getCustomerName()
{
	return customerName;
}

int Order::getOrderNumber()
{
	return orderNumber;
}

std::vector<Food> Order::getFoods()
{
	return foodsOrdered;
}

std::vector<Combo> Order::getCombos()
{
	return combosOrdered;
}

bool Order::ifFoodExists( Food foodToFind )
{
    bool foodExists = false;

    for( int i = 0; i < foodsOrdered.size(); i++ )
    {
        if( foodToFind.getName() == foodsOrdered.at(i).getName() )
        {
            foodExists = true;
        }
    }

    return foodExists;
}

int Order::searchForFood(Food foodToSearch)
{
    int foodIndex;

	for( int i = 0; i < foodsOrdered.size(); i++ )
    {
        if( foodsOrdered.at(i).getName() == foodToSearch.getName() )
        {
            foodIndex = i;
        }
    }

    return foodIndex;
}

void Order::addFood(Food foodToAdd)
{
	foodsOrdered.push_back(foodToAdd);
}

void Order::removeFood(Food foodToRemove)
{
	if( ifFoodExists( foodToRemove ) )
    {
        foodsOrdered.erase( foodsOrdered.begin() + searchForFood( foodToRemove ) );
    }
}

bool Order::ifComboExists( Combo comboToFind )
{
    bool comboExists = false;

    for( int i = 0; i < combosOrdered.size(); i++ )
    {
        if( comboToFind.getName() == combosOrdered.at(i).getName() )
        {
            comboExists = true;
        }
    }

    return comboExists;
}

int Order::searchForCombo( Combo comboToSearch )
{
    int comboIndex;

	for( int i = 0; i < combosOrdered.size(); i++ )
	{
		if( combosOrdered.at(i).getName() == comboToSearch.getName() )
        {
            comboIndex = i;
        }
	}

	return comboIndex;
}

void Order::addCombo(Combo comboToAdd)
{
	combosOrdered.push_back(comboToAdd);
}

void Order::removeCombo(Combo comboToRemove)
{
	if( ifComboExists( comboToRemove ) )
    {
        combosOrdered.erase( combosOrdered.begin() + searchForCombo(comboToRemove) );
    }
}



