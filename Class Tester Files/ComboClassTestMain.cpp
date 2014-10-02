#include <iostream>
#include "Ingredient.h"
#include "Food.h"

using namespace std;

int main() {
	Ingredient portobello, mushrooms, mayo, cheese, bread;

	portobello.setQuantity(30);
	portobello.setCostPerUnit(0.2);

	mushrooms.setQuantity(10);
	mushrooms.setCostPerUnit(0.5);

	mayo.setQuantity(5);
	mayo.setCostPerUnit(0.6);

	cheese.setQuantity(10);
	cheese.setCostPerUnit(0.7);

	bread.setQuantity(100);
	bread.setCostPerUnit(0.05);

	Food mushroom_swiss;
	mushroom_swiss.setName("Mushroom Swiss");
	mushroom_swiss.setPrice(30);
	mushroom_swiss.setFoodSize(150);

	mushroom_swiss.addIngredient(portobello);
	mushroom_swiss.addIngredient(mushrooms);
	mushroom_swiss.addIngredient(mayo);
	mushroom_swiss.addIngredient(cheese);
	mushroom_swiss.addIngredient(bread);

	mushroom_swiss.setCost();
	float cost1 = mushroom_swiss.getCost();

	mushroom_swiss.removeIngredient(mayo);
	mushroom_swiss.setCost();
	float cost2 = mushroom_swiss.getCost();

	cout << "Mushroom Swiss" << endl;
	cout << "Size: " << mushroom_swiss.getSize() << endl;
	cout << "Price: " << mushroom_swiss.getPrice() << endl;
	cout << "Cost with mayo " << cost1 << endl;
	cout << "Cost without mayo " << cost2 << endl;

	return 0;
}
