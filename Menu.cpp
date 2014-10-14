#include "Menu.h"

Menu::Menu()
{

}


int Menu::searchForFood(Food food)
{
	int i=0;
	for(vector<Food>::iterator iter = foodsOnMenu.begin();iter!= foodsOnMenu.end();iter++)
	{
		if(iter->getName() == food.getName()) return i;
		else i++;
	}
	return -1;
}

void Menu::addFood(Food food)
{
	 foodsOnMenu.push_back(food);
}


void Menu::removeFood(Food food)
{
	for(vector<Food>::iterator iter = foodsOnMenu.begin();iter!= foodsOnMenu.end();iter++)
	{
		if(iter->getName() == food.getName())
		{
			foodsOnMenu.erase(iter);
			return;
		}
	}
}


vector<Food> Menu::getFoods()
{
	return foodsOnMenu;
}

int Menu::searchForCombo(Combo combo)
{
    int i=0;

	for(vector<Combo>::iterator iter = combosOnMenu.begin();iter!= combosOnMenu.end();iter++)
	{
		if(combo.getCost() == iter->getCost() && combo.getComboSize() == iter->getComboSize()&&combo.getPrice() == iter->getPrice())
			return i;
		else i++;
	}
	return -1;
}
void Menu::addCombo(Combo combo)
{
	combosOnMenu.push_back(combo);
}
void Menu::removeCombo(Combo combo)
{
    for(vector<Combo>::iterator iter = combosOnMenu.begin();iter!= combosOnMenu.end();iter++)
	{
		if(combo.getCost() == iter->getCost() && combo.getComboSize() == iter->getComboSize()&&combo.getPrice() == iter->getPrice())
		{
			combosOnMenu.erase(iter);
			return;
		}
	}
}

vector<Combo> Menu::getCombos()
{
	return combosOnMenu;
}
