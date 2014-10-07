#include "Combo.h"


Combo::Combo(): m_price(0): m_cost(0): m_comboSize(0) { }

Combo::Combo(int price, int cost, int comboSize, vector<Food> listOfFoods):
m_price(price): m_cost(cost) : m_listOfFoods(listOfFoods)
 {
    if (comboSize >= 0 &&
        comboSize <= 3)
        m_comboSize = comboSize;
    else
        m_comboSize = 0;
 }

int Combo::getPrice()
{
    return m_price;
}

int Combo::getCost()
{
    return m_cost;
}

void Combo::setPrice(int price)
{
    if (price < 0)
        m_price = 0;
    else
        m_price = price;
}

void Combo::setCost(int cost)
{
    if (cost < 0)
        m_cost = 0;
    else
        m_cost = cost;
}

void Combo::setComboSize(int comboSize)
{
    if (comboSize >= 0 && comboSize <= 3)
        m_comboSize = comboSize;
    else
        m_comboSize = 0;
}

void Combo::calculateCost()
{
    float res = 0;
    for (int i = 0; i < m_listOfFoods.size(); )
    {
        res += m_listOfFoods[i].getCost();
    }
    m_cost = res;
}

void Combo::calculatePrice()
{
    float res = 0;
    for (int i = 0; i < m_listOfFoods.size(); )
    {
        res += m_listOfFoods[i].getPrice();
    }
    m_price = res;
}

int Combo::searchForFood(Food food)
{
    string name = food.getName();
    for (unsigned int i = 0; i < m_listOfFoods.size(); ++i)
	{
		if (listOfFoods[i].getName() == name)
			return i;
	}
	return -1;
}

void Combo::addFood(Food food)
{
    m_listOfFoods.push_back(food);
}

void Combo::removeFood(Food food)
{
    int searchResult = searchForFood(food);
    if (res > -1)
    {
        m_listOfFoods.erase(m_listOfFoods.begin() + searchResult);
    }
}
