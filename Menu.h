#ifndef MENU_H
#define MENU_H

#include <vector>
#include <fstream>

#include "Inventory.h"
#include "Food.h"
#include "Combo.h"

class Menu
{
public:
    Menu();
    ~Menu();

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

    void loadMenu( Inventory );
    void loadFoods( Inventory );
    void loadCombos();
    void saveMenu();
    void saveFoods();
    void saveCombos();

private:
    std::vector<Food> foodsOnMenu;
    std::vector<Combo> combosOnMenu;
};

#endif // MENU_H
