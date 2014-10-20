#ifndef TERMINAL_H
#define TERMINAL_H

#include <curses.h>

#include "Inventory.h"
#include "Menu.h"
#include "Staff.h"
#include "PayRoll.h"
#include "Order.h"
#include <sstream>

const int DISPLAY_WINDOW_WIDTH = 130;
const int DISPLAY_WINDOW_HEIGHT = 40;
const int USER_INPUT_WINDOW_WIDTH = 130;
const int USER_INPUT_WINDOW_HEIGHT = 17;
const int SIDE_PANEL_WINDOW_WIDTH = 34;
const int SIDE_PANEL_WINDOW_HEIGHT = 57;

class Terminal
{
public:
    ///Constructors and Destructors
    Terminal();
    ~Terminal();

    ///Setup
    void setupCurses();
    void testWindowOutput();
    void makeWindowBorders();
    void createTestStuff();

    ///Main Menu
    void mainMenu();

    ///Point of Sale
    void pointOfSaleMenu();
    void viewMenu();
    void displayFoods();
    void displayCombos();
    void takeOrder();
    void addFoodToOrder( Order& );
    void addComboToOrder( Order& );
    void displayOrder( Order );
    bool ifOrderActive( int );
    int searchForActiveOrder( int );
    void displayActiveOrders();
    void viewActiveOrders();
    void completeOrder();

    ///Time Clock
    void timeClockMenu();
    void clockIn();
    void clockOut();

    ///Menu and Foods
    void foodsMenu();
    void addFoodToMenu();
    void removeFoodFromMenu();
    void addComboToMenu();
    void removeComboFromMenu();

    ///Inventory
    void inventoryMenu();
    void displayInventory();
    void displayIngredients();
    void addNewIngredient();
    void removeIngredient();
    void addIngredientStock();
    void removeIngredientStock();

    ///Staffing
    void staffingMenu();
    void displayStaff();
    void fireEmployee();
    void hireEmployee();
    void viewEmployeeSchedule();
    void changeEmployeeSchedule();

    ///Pay Roll
    void payRollMenu();
    void viewBudget();
    void increaseBudget();
    void decreaseBudget();
    void createCheck();

    ///Functions for User Input
    int getUserIntInput();
    int getUserLongIntInput();
    float getUserFloatInput();
    std::string getUserStringInput();

    ///Functions for User Output
    void outputString( WINDOW*, int, int, std::string );
    void outputPrice( WINDOW*, int, int, float );
    void outputInt( WINDOW*, int, int, int );

private:
    WINDOW* displayWindow;
    WINDOW* userInputWindow;
    WINDOW* sidePanelWindow;

    Staff restaurantStaff;
    Inventory restaurantInventory;
    Menu restaurantMenu;
    PayRoll restaurantPayRoll;

    std::vector<Order> activeOrders;
};

#endif // TERMINAL_H
