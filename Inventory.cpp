// Matt Rawson
// Group
#include "Inventory.h"

Inventory::Inventory()
{
    //loadInventory();
}//Inventory()::Inventory()

Inventory::~Inventory()
{
    //saveInventory();
}// Inventory()::~Inventory()

void Inventory::printInventory()
{

    for(int tempCounter = 0; tempCounter < ingredientsInStock.size(); tempCounter++ )
    {

        ingredientsInStock.at(tempCounter).printIngredient();

    }// for( tempCounter = 0; tempCounter < ingredientInStock.size(); tempCounter++ )


}// void Inventory::printInventory()

int Inventory::searchForIngredient(Ingredient ingredientToFind)
{

    int tempCounter = 0;
    int indexOfVectorIngredient = 0;
    std::string tempNameHolder;

    for( tempCounter = 0; tempCounter < ingredientsInStock.size(); tempCounter++ )
    {

        tempNameHolder = ingredientsInStock.at(tempCounter).getName();

        if(ingredientToFind.getName() == tempNameHolder)
        {

            indexOfVectorIngredient = tempCounter;

        }//if(comparisonString == ingredientToSearchfor)

    }// for( tempCounter = 0; tempCounter < ingredientVector.size(); tempCounter++ )

    return indexOfVectorIngredient;

}// void Inventory::searchForIngredient(Ingredient ingredientToFind)

void Inventory::addStock(Ingredient ingredientToAdd, int quantityToAdd)
{


    if(ifInStock(ingredientToAdd))
    {

        ingredientsInStock.at(searchForIngredient(ingredientToAdd)).addUnits(quantityToAdd);

    }// if(ingredientToAdd.ifInStock())
    else
    {

        addIngredient(ingredientToAdd);

    }// else of if(ingredientToAdd.ifInStock())


}// void Inventory::addStock(Ingredient ingredientToAdd, int quantityToAdd)

void Inventory::addIngredient(Ingredient ingredientToAdd)
{

    ingredientsInStock.push_back(ingredientToAdd);

}// void Inventory::addIngredient(Ingredient ingredientToAdd)

void Inventory::removeIngredient(Ingredient ingredientToRemove)
{

    if(ifInStock(ingredientToRemove))
    {

        ingredientsInStock.erase(ingredientsInStock.begin() + searchForIngredient(ingredientToRemove));

    }// if(ingredientToRemove.ifInStock())

}// void Inventory::removeIngredient(Ingredient ingredientToRemove)

void Inventory::removeStock(Ingredient ingredientToRemove, int quantityToRemove)
{

    if(ifInStock(ingredientToRemove))
    {

        ingredientsInStock.at(searchForIngredient(ingredientToRemove)).removeUnits(quantityToRemove);

    }// if(ingredientToRemove.ifInStock())

}// void Inventory::removeStock(Ingredient ingredientToRemove, int quantityToRemove)

void Inventory::ingredientQuanitityAdjustment(Ingredient ingredientbeingChanged, int newQuantity)
{
    if(ifInStock(ingredientbeingChanged))
    {

        ingredientsInStock.at(searchForIngredient(ingredientbeingChanged)).setQuantity(newQuantity);

    }// if(isInStock(ingredientbeingChanged))

    else
    {

        ingredientbeingChanged.setQuantity(newQuantity);

        addIngredient(ingredientbeingChanged);

    }// if(isInStock(ingredientbeingChanged))

}// void Inventory::ingredientQuanitityAdjustment(Ingredient ingredientbeingChanged, int newQuantity)

bool Inventory::ifInStock(Ingredient ingredientToFind)
{

    bool ingredientWasFound = false;
    int tempCounter = 0;
    std::string tempNameHolder;

    for( tempCounter = 0; tempCounter < ingredientsInStock.size(); tempCounter++ )
    {

        tempNameHolder = ingredientsInStock.at(tempCounter).getName();

        if(ingredientToFind.getName() == tempNameHolder)
        {

            ingredientWasFound = true;

        }// if(ingredientToFind.getName() == tempNameHolder)

    }// for( tempCounter = 0; tempCounter < ingredientInStock.size(); tempCounter++ )

    return ingredientWasFound;

}// bool Inventory::ifInStock(Ingredient ingredientToFind)


std::vector<Ingredient> Inventory::getInventory()
{
    return ingredientsInStock;
}

void Inventory::loadInventory()
{
    std::ifstream inputFile;std::cout << "Trying to load inventory" << std::endl;
    inputFile.open( "SaveFiles/Inventory.txt" );

    if( inputFile.fail() )
    {
        std::cout << "Could not load inventory" << std::endl;
    }

    std::string loadName;
    std::string loadQuantityString;
    int loadQuantity;
    std::string loadCostString;
    float loadCost;
    std::string loadUnit;
    std::string line;
    std::stringstream lineSS ( std::stringstream::in | std::stringstream::out );

    int beginningOfSubString = 0;

    while( getline( inputFile, line ) )
    {
        std::vector< int > commaLocations;

        for( int i = 0; i < line.size(); i++ )
        {
            if( line.at(i) == ',' )
            {
                commaLocations.push_back(i);
            }
        }

        loadName = line.substr( 0, commaLocations.at(0) );
        loadQuantityString = line.substr( commaLocations.at(0)+1, ( commaLocations.at(1) - commaLocations.at(0) ) );
        loadCostString = line.substr( commaLocations.at(1)+1, ( commaLocations.at(2) - commaLocations.at(1) ) );
        loadUnit = line.substr( commaLocations.at(2)+1, ( line.size() - commaLocations.at(2) ) );

        std::istringstream quantitySS(loadQuantityString);
        quantitySS >> loadQuantity;

        std::istringstream costSS(loadCostString);
        costSS >> loadCost;

        Ingredient ingredientToAdd( loadName, loadQuantity, loadCost, loadUnit );
        ingredientsInStock.push_back( ingredientToAdd );
    }

    inputFile.close();
}

void Inventory::saveInventory()
{
    std::ofstream outputFile;
    outputFile.open( "SaveFiles/Inventory.txt" );

    for( int i = 0; i < ingredientsInStock.size(); i++ )
    {
        outputFile << ingredientsInStock.at(i).getName() << ", ";
        outputFile << ingredientsInStock.at(i).getQuantity() << ", ";
        outputFile << ingredientsInStock.at(i).getCostPerUnit() << ", ";
        outputFile << ingredientsInStock.at(i).getUnitOfMeasurement() << "\n";
    }

    outputFile.close();
}
