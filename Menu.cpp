#include "Menu.h"

Menu::Menu()
{

}

Menu::~Menu()
{
    saveMenu();
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

void Menu::loadMenu( Inventory restaurantInventory )
{
    loadFoods( restaurantInventory );
    loadCombos();
}

void Menu::loadFoods( Inventory restaurantInventory )
{
    std::ifstream inputFile;
    inputFile.open( "SaveFiles/MenuFoods.txt" );

    std::string line;

    while( getline( inputFile, line ) )
    {
        std::string foodName;
        int foodSize;
        std::string foodSizeString;
        float foodPrice;
        std::string foodPriceString;
        std::vector<Ingredient> ingredientsInFood;

        std::vector<int> commaPositions;

        for( int i = 0; i < line.size(); i++ )
        {
            if( line.at(i) == ',' )
            {
                commaPositions.push_back(i);
            }
        }

        int numberOfIngredients = commaPositions.size() - 3;

        foodName = line.substr( 0, commaPositions.at(0) );

        foodSizeString = line.substr( commaPositions.at(0)+1, ( commaPositions.at(1) - commaPositions.at(0) ) );
        std::istringstream foodSizeSS( foodSizeString );
        foodSizeSS >> foodSize;

        foodPriceString = line.substr( commaPositions.at(1)+1, ( commaPositions.at(2) - commaPositions.at(1) ) );
        std::istringstream foodPriceSS( foodPriceString );
        foodPriceSS >> foodPrice;

        for( int i = 0; i < numberOfIngredients; i++ )
        {
            std::string ingredientName = line.substr( commaPositions.at(2+i)+1, ( commaPositions.at(3+i) - commaPositions.at(2+i) ) );
            Ingredient ingredentToAdd;
            ingredentToAdd.setName( ingredientName );
            ingredentToAdd = restaurantInventory.getInventory().at( restaurantInventory.searchForIngredient( ingredentToAdd ) );
            ingredientsInFood.push_back( ingredentToAdd );
        }

        Food foodToAdd( foodName, foodSize, foodPrice, ingredientsInFood );
        foodsOnMenu.push_back( foodToAdd );
    }
}

void Menu::loadCombos()
{
    std::ifstream inputFile;
    inputFile.open( "SaveFiles/MenuCombos.txt" );

    std::string line;

    while( getline( inputFile, line ) )
    {
        std::string comboName;
        float comboPrice;
        std::string comboPriceString;
        std::vector<Food> foodsInCombo;

        std::vector<int> commaPositions;

        for( int i = 0; i < line.size(); i++ )
        {
            if( line.at(i) == ',' )
            {
                commaPositions.push_back(i);
            }
        }

        int numberOfFoods = commaPositions.size() - 4;

        comboName = line.substr( 0, commaPositions.at(0) );

        comboPriceString = line.substr( commaPositions.at(0)+1, ( commaPositions.at(1) - commaPositions.at(0) )  );
        std::istringstream comboPriceSS( comboPriceString );
        comboPriceSS >> comboPrice;

        for( int i = 0; i < numberOfFoods; i++ )
        {
            std::string foodName = line.substr( commaPositions.at(1+i)+1, ( commaPositions.at(2+i) - commaPositions.at(1+i) ) );
            Food foodToAdd;
            foodToAdd.setName( foodName );
            foodToAdd = foodsOnMenu.at( searchForFood( foodToAdd ) );
            foodsInCombo.push_back( foodToAdd );
        }

        Combo comboToAdd( comboName, comboPrice, 0, foodsInCombo );
        combosOnMenu.push_back( comboToAdd );
    }
}

void Menu::saveMenu()
{
    saveFoods();
    saveCombos();
}

void Menu::saveFoods()
{
    std::ofstream outputFile;
    outputFile.open( "SaveFiles/MenuFoods.txt" );

    for( int i = 0; i < foodsOnMenu.size(); i++ )
    {
        outputFile << foodsOnMenu.at(i).getName() << ", ";
        outputFile << foodsOnMenu.at(i).getFoodSize() << ", ";
        outputFile << foodsOnMenu.at(i).getPrice() << ", ";
        for( int j = 0; j < foodsOnMenu.at(i).getIngredients().size(); j++ )
        {
            if( j == foodsOnMenu.at(i).getIngredients().size()-1 )
            {
                outputFile << foodsOnMenu.at(i).getIngredients().at(j).getName() << "\n";
            }
            else
            {
                outputFile << foodsOnMenu.at(i).getIngredients().at(j).getName() << ", ";
            }
        }
    }

    outputFile.close();
}

 void Menu::saveCombos()
 {
    std::ofstream outputFile;
    outputFile.open( "SaveFiles/MenuCombos.txt" );

    for( int i = 0; i < combosOnMenu.size(); i++ )
    {
        outputFile << combosOnMenu.at(i).getName() << ", ";
        outputFile << combosOnMenu.at(i).getPrice() << ", ";
        for( int j = 0; j < combosOnMenu.at(i).getFoods().size(); j++ )
        {
            if( j == combosOnMenu.at(i).getFoods().size()-1 )
            {
                outputFile << combosOnMenu.at(i).getFoods().at(j).getName() << "\n";
            }
            else
            {
                outputFile << combosOnMenu.at(i).getFoods().at(j).getName() << ", ";
            }
        }
    }

    outputFile.close();
 }
