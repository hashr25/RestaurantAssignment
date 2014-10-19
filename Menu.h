#ifndef MENU_H
#define MENU_H

#include <vector>
#include "Food.h"
#include "Combo.h"

class Menu
{
public:
    Menu();

    bool ifFoodExists( Food );
    int searchForFood( Food );
    void addFood( Food );
    void removeFood( Food );
    std::vector<Food> getFoods();

    bool ifComboExists( Combo );
    int searchForCombo( Combo );
    void addCombo( Combo );
    void removeCombo( Combo );
    std::vector<Combo> getCombos();

private:
    std::vector<Food> foodsOnMenu;
    std::vector<Combo> combosOnMenu;
};

#endif // MENU_H
