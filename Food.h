#ifndef FOOD_H
#define FOOD_H

#include "Ingredient.h"
#include <string>
#include <vector>

class Food
{
public:

	///Constructors
	Food();
	Food(std::string, int, float, std::vector<Ingredient>);

	///Getters and Setters
	std::string getName();
	int getSize();
	float getPrice();
	std::vector<Ingredient> getIngredients();
	void setName(std::string);
	void setSize(int);
	void setPrice(float);
	float getCost();

	///Member Methods
	void setCost();
	bool ingredientInFood(Ingredient);
	int searchForIngredient(Ingredient);
	void addIngredient(const Ingredient&);
	void removeIngredient(const Ingredient&);

private:
	std::string name;
	int size;
	float price;
	float cost;
	std::vector<Ingredient> listOfIngredient;
};

#endif // FOOD_H
