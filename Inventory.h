// Matt Rawson
// Group
#ifndef INVENTORY_H
#define INVENTORY_H

#include <math.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Ingredient.h"

class Inventory
{

public:
    Inventory();// constructor
    ~Inventory();// destructor
    int searchForIngredient(Ingredient);// searches the vector to find if the specific ingredient is in the vector.
    void printInventory();// outputs the inventory.
    void addIngredient(Ingredient);// adds a new ingredient to the vector.
    void removeIngredient(Ingredient);// removes a current ingredient from the vector.
    void addStock(Ingredient, int);// adds a set amount to the stock of a current ingredient.
    void removeStock(Ingredient, int);// removes a certain amount of a specific amount of a certain stock.
    void ingredientQuanitityAdjustment(Ingredient, int);// changes the amount of a specific ingredient.
    bool ifInStock(Ingredient);// checks to make sure ingredient is in the inventory.
    std::vector<Ingredient> getInventory();

    //void loadInventory();
    //void saveInventory();

private:
    std::vector <Ingredient> ingredientsInStock;

};

#endif // INVENTORY_H
