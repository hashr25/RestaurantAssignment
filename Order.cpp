#include "Order.h"

int Order::orderNumberGenerator = 1;

void Order::setCustomerName(string name)
{
	customerName = name;
}
void Order::setOrderNumber()
{
	orderNumber = orderNumberGenerator++;
}

string Order::getCustomerName()
{
	return customerName;
}
int Order::getOrderNumber()
{
	return orderNumber;
}
vector<Food> Order::getFoods()
{
	return foodsOrdered;
}
vector<Combo> Order::getCombos()
{
	return combosOrdered;
}

int Order::searchForFood(Food food)
{
    int i=0;
	for(vector<Food>::iterator iter = foodsOrdered.begin();iter!= foodsOrdered.end();iter++)
	{
		if(iter->getName() == food.getName()) return i;
		else i++;
	}
	return -1;
}
void Order::addFood(Food food)
{
	foodsOrdered.push_back(food);
}
void Order::removeFood(Food food)
{
	for(vector<Food>::iterator iter = foodsOrdered.begin();iter!= foodsOrdered.end();iter++)
	{
		if(iter->getName() == food.getName())
		{
			foodsOrdered.erase(iter);
			return;
		}
	}
}

int Order::searchForCombo(Combo combo)
{
    int i=0;

	for(vector<Combo>::iterator iter = combosOrdered.begin();iter!= combosOrdered.end();iter++)
	{
		if(combo.getCost() == iter->getCost() && combo.getComboSize() == iter->getComboSize()&&combo.getPrice() == iter->getPrice())
			return i;
		else i++;
	}
	return -1;

}
void Order::addCombo(Combo combo)
{
	combosOrdered.push_back(combo);
}
void Order::removeCombo(Combo combo)
{
	for(vector<Combo>::iterator iter = combosOrdered.begin();iter!= combosOrdered.end();iter++)
	{
		if(combo.getCost() == iter->getCost() && combo.getComboSize() == iter->getComboSize()&&combo.getPrice() == iter->getPrice())
		{
			combosOrdered.erase(iter);
			return;
		}
	}
}



