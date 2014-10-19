#include "Menu.h"

Menu::Menu()
{

}

bool Menu::ifFoodExists( Food foodToFind )
{
    bool foodExists = false;

    for( int i = 0; i < foodsOnMenu.size(); i++ )
    {
        if( foodToFind.getName() == foodsOnMenu.at(i).getName() )
        {
            foodExists = true;
        }
    }

    return foodExists;
}

int Menu::searchForFood( Food foodToSearch )
{
	int foodIndex;

	for( int i = 0; i < foodsOnMenu.size(); i++ )
    {
        if( foodsOnMenu.at(i).getName() == foodToSearch.getName() )
        {
            foodIndex = i;
        }
    }

    return foodIndex;
}

void Menu::addFood( Food foodToAdd )
{
	 foodsOnMenu.push_back(foodToAdd);
}


void Menu::removeFood( Food foodToRemove )
{
	if( ifFoodExists( foodToRemove ) )
    {
        foodsOnMenu.erase( foodsOnMenu.begin() + searchForFood( foodToRemove ) );
    }
}


std::vector<Food> Menu::getFoods()
{
	return foodsOnMenu;
}

bool Menu::ifComboExists( Combo comboToFind )
{
    bool comboExists = false;

    for( int i = 0; i < combosOnMenu.size(); i++ )
    {
        if( comboToFind.getName() == combosOnMenu.at(i).getName() )
        {
            comboExists = true;
        }
    }

    return comboExists;
}

int Menu::searchForCombo(Combo comboToSearch)
{
    int comboIndex;

	for( int i = 0; i < combosOnMenu.size(); i++ )
	{
		if( combosOnMenu.at(i).getName() == comboToSearch.getName() )
        {
            comboIndex = i;
        }
	}

	return comboIndex;
}

void Menu::addCombo( Combo comboToAdd )
{
	combosOnMenu.push_back(comboToAdd);
}

void Menu::removeCombo( Combo comboToRemove )
{
    if( ifComboExists( comboToRemove ) )
    {
        combosOnMenu.erase( combosOnMenu.begin() + searchForCombo( comboToRemove ) );
    }
}

std::vector<Combo> Menu::getCombos()
{
	return combosOnMenu;
}
