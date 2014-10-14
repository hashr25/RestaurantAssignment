#ifndef MENU_H
#define MENU_H

#include <vector>
#include "Food"
#include "Combo"

using namespace std;

class Menu
{
public:
    Menu();

    int searchForFood( Food );
    void addFood( Food );
    void removeFood( Food );
    vector<Food> getFoods();

    int searchForCombo( Combo );
    void addCombo( Combo );
    void removeCombo( Combo );
    vector<Combo> getCombos();

private:
    vector<Food> foodsOnMenu;
    vector<Combo> combosOnMenu;
};

#endif // MENU_H
