#include "Combo.h"

Combo::Combo():
    price(0), cost(0), comboSize(0)
{

}

Combo::Combo(std::string newName, float newPrice, int newComboSize, std::vector<Food> newListOfFoods):
    name(newName), price(newPrice), listOfFoods(newListOfFoods)
 {
    setComboSize( newComboSize );
    setCost();
 }

std::string Combo::getName()
{
    return name;
}

float Combo::getPrice()
{
    return price;
}

float Combo::getCost()
{
    return cost;
}

int Combo::getComboSize()
{
    return comboSize;
}

std::vector<Food> Combo::getFoods()
{
    return listOfFoods;
}

void Combo::setName( std::string name )
{
    this -> name = name;
}

void Combo::setPrice(float price)
{
    if (price < 0)
    {
        price = 0;
    }

    else
    {
        this -> price = price;
    }
}

void Combo::setCost()
{
    float costHolder = 0;

    for( int i = 0; i < listOfFoods.size(); i++ )
    {
        costHolder = costHolder + listOfFoods.at(i).getCost();
    }

    cost = costHolder;
}

void Combo::setComboSize(int comboSize)
{
    if (comboSize >= 0 && comboSize <= 3)
    {
        comboSize = comboSize;
    }

    else
    {
        comboSize = 0;
    }
}

void Combo::calculateCost()
{
    float res = 0;
    for (int i = 0; i < listOfFoods.size(); )
    {
        res += listOfFoods[i].getCost();
    }
    cost = res;
}

void Combo::calculatePrice()
{
    float res = 0;
    for (int i = 0; i < listOfFoods.size(); )
    {
        res += listOfFoods[i].getPrice();
    }
    price = res;
}

bool Combo::foodInCombo( Food food )
{
    bool result = false;

    for( int i = 0; i < listOfFoods.size(); i++ )
    {
        if( food.getName() == listOfFoods.at(i).getName() )
        {
            result = true;
        }
    }

    return result;
}

int Combo::searchForFood(Food food)
{
    std::string name = food.getName();
    for (unsigned int i = 0; i < listOfFoods.size(); ++i)
	{
		if (listOfFoods[i].getName() == name)
			return i;
	}
	return -1;
}

void Combo::addFood(Food food)
{
    listOfFoods.push_back(food);
}

void Combo::removeFood(Food food)
{
    if( foodInCombo(food) )
    {
        int searchResult = searchForFood(food);
        if (searchResult > -1)
        {
            listOfFoods.erase(listOfFoods.begin() + searchResult);
        }
    }
}
