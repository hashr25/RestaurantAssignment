#include "Food.h"

#ifndef COMBO_H
#define COMBO_H

using namespace std;

class Combo
{
    public:
        Combo();
        Combo(int, int, int, vector<Food>)
        ~Combo();

        float getCost();
        float getPrice();
        int getComboSize();
        void setCost(float cost);
        void setPrice(float price);
        void setComboSize(int comboSize);
        void calculatePrice();
        void calculateCost();
        int searchForFood(Food food);
        void addFood(Food food);
        void removeFood(Food food);
}
    private:
        vector<Food> m_listOfFoods;
        int m_comboSize;
        float m_price;
        float m_cost;
};

#endif // COMBO_H
