// Matt Rawson
// Group
#include <math.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "restaurantInventory.h"

using namespace std;

void functionForInventory();
int main()
{

functionForInventory();

return 0;

}// int main()


void functionForInventory()
{
    Inventory stock;
    Ingredient buns("buns", 100, 0.25, "lb(s)");
    Ingredient beefPatty("beef patty", 50, 2.0, "lb(s)");
    Ingredient cheese("cheese", 500, 0.75, "lb(s)");
    Ingredient ketchup("ketchup", 600, 0.55, "oz");
    Ingredient fries("fries", 1000, 1.5, "lb(s)");

    stock.addIngredient(buns);

    stock.addIngredient(beefPatty);

    stock.addIngredient(cheese);

    stock.addIngredient(ketchup);

    stock.removeStock(ketchup, 15);

    stock.addStock(fries, 15);

    stock.ingredientQuanitityAdjustment(cheese , 100);

    stock.removeIngredient(cheese);

    stock.printInventory();

}// void functionForInventory()
