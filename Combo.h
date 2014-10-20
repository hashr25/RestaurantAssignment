#ifndef COMBO_H
#define COMBO_H

#include "Food.h"

class Combo
{
public:
    Combo();
    Combo(std::string, float, int, std::vector<Food>);

    std::string getName();
    float getCost();
    float getPrice();
    int getComboSize();
    std::vector<Food> getFoods();
    void setName(std::string);
    void setCost();
    void setPrice(float);
    void setComboSize(int);
    void calculatePrice();
    void calculateCost();
    bool foodInCombo(Food);
    int searchForFood(Food);
    void addFood(Food);
    void removeFood(Food);

private:
    std::vector<Food> listOfFoods;
    std::string name;
    int comboSize;
    float price;
    float cost;
};

#endif // COMBO_H
