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
	int getFoodSize();
	float getPrice();
	float getCost();
	std::vector<Ingredient> getIngredients();
	void setName(std::string);
	void setFoodSize(int);
	void setPrice(float);
	void setCost();

	///Member Methods
	bool ingredientInFood(Ingredient);
	int searchForIngredient(Ingredient);
	void addIngredient(const Ingredient&);
	void removeIngredient(const Ingredient&);

private:
	std::string name;
	int foodSize;
	float price;
	float cost;
	std::vector<Ingredient> listOfIngredient;
};

#endif // FOOD_H
