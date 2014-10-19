#include "Food.h"
#include <algorithm>

Food::Food() :
    name(""), size(0), price(0), cost(0)
{
	///Variables set in init list.
}

Food::Food(std::string newName, int newSize, float newPrice, std::vector<Ingredient> newListOfIngredient) :
    name(newName), size(newSize), price(newPrice), listOfIngredient(newListOfIngredient)
{
	///Variables set in init list.
	setCost();
}

///Getters and Setters
std::string Food::getName()
{
	return name;
}

int Food::getSize()
{
	return size;
}

float Food::getPrice()
{
	return price;
}

float Food::getCost()
{
	return cost;
}

std::vector<Ingredient> Food::getIngredients()
{
	return listOfIngredient;
}

void Food::setName(std::string name)
{
	this->name = name;
}

void Food::setSize(int size)
{
	if (size < 0)
	{
		this->size = 0;
	}
	else
	{
		this->size = size;
	}
}

void Food::setPrice(float price)
{
	if (price < 0)
	{
		this->price = 0;
	}
	else
	{
		this->price = price;
	}
}

void Food::setCost()
{
	cost = 0;
	for (unsigned int i = 0; i < listOfIngredient.size(); ++i)
	{
		cost += listOfIngredient[i].getCostOfStock();
	}
}

bool Food::ingredientInFood( Ingredient ingredient )
{
    bool result = false;

    for( int i = 0; i < listOfIngredient.size(); i++ )
    {
        if( ingredient.getName() == listOfIngredient.at(i).getName() )
        {
            result = true;
        }
    }

    return result;
}

int Food::searchForIngredient( Ingredient ingredient )
{
    int ingredientIndex;

    for( int i = 0; i < listOfIngredient.size(); i++ )
    {
        if( ingredient.getName() == listOfIngredient.at(i).getName() )
        {
            ingredientIndex = i;
        }
    }

    return ingredientIndex;
}

void Food::addIngredient(const Ingredient& ingredient)
{
	listOfIngredient.push_back(ingredient);
}

void Food::removeIngredient(const Ingredient& ingredient)
{
	if ( ingredientInFood( ingredient ) )
	{
	    int result = searchForIngredient( ingredient );
		listOfIngredient.erase( listOfIngredient.begin()+result );
	}
}
