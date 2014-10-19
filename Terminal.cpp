#include "Terminal.h"
#include <curses.h>

Terminal::Terminal():
    displayWindow(NULL), userInputWindow(NULL), sidePanelWindow(NULL)
{
    setupCurses();
    makeWindowBorders();
    createTestStuff();
}

Terminal::~Terminal()
{
    delwin( displayWindow );
    delwin( userInputWindow );
    delwin( sidePanelWindow );
}

///Setup
void Terminal::setupCurses()
{
    initscr();//initialize the screen
    curs_set(0);//set the cursor to be invisible
    noecho();//Don't put user input on the screen

    resize_term( 57, 165 );//Sets the terminal to the correct size

    start_color();
    init_pair(0, COLOR_RED, COLOR_BLACK);//color for Bad Stuff
    init_pair(1, COLOR_GREEN, COLOR_BLACK);//color for Good Stuff
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);//color for Borders

    displayWindow = newwin( DISPLAY_WINDOW_HEIGHT, DISPLAY_WINDOW_WIDTH, 0, 0 );
    userInputWindow = newwin( USER_INPUT_WINDOW_HEIGHT, USER_INPUT_WINDOW_WIDTH, DISPLAY_WINDOW_HEIGHT, 0 );
    sidePanelWindow = newwin( SIDE_PANEL_WINDOW_HEIGHT, SIDE_PANEL_WINDOW_WIDTH, 0, DISPLAY_WINDOW_WIDTH );

    wrefresh( stdscr );
}

void Terminal::testWindowOutput()
{
    ///This is just used for testing purposes
    mvwprintw( displayWindow, 4, 4, "Hello World!" );
    mvwaddch( displayWindow, 6, 6, '&' | COLOR_PAIR(1));
    wrefresh( displayWindow );

    mvwprintw( userInputWindow, 4, 4, "Hello World!" );
    mvwaddch( userInputWindow, 6, 6, '&' | COLOR_PAIR(1));
    wrefresh( userInputWindow );

    mvwprintw( sidePanelWindow,  4, 4, "Hello World!" );
    mvwaddch( sidePanelWindow, 6, 6, '&' | COLOR_PAIR(1));
    wrefresh( sidePanelWindow );

    getch();
}

void Terminal::makeWindowBorders()
{
    ///Turns on Color
    wattron( displayWindow, COLOR_PAIR(2) );
    wattron( userInputWindow, COLOR_PAIR(2) );
    wattron( sidePanelWindow, COLOR_PAIR(2) );

    ///Makes the borders
    wborder( displayWindow, '|', '|', '_', '_', ' ', ' ', '|', '|' );
    wborder( userInputWindow, '|', '|', '_', '_', ' ', ' ', '|', '|' );
    wborder( sidePanelWindow, '|', '|', '_', '_', ' ', ' ', '|', '|' );

    ///Turns off Color
    wattroff( displayWindow, COLOR_PAIR(2) );
    wattroff( userInputWindow, COLOR_PAIR(2) );
    wattroff( sidePanelWindow, COLOR_PAIR(2) );

    ///Refreshes the windows
    wrefresh( displayWindow );
    wrefresh( userInputWindow );
    wrefresh( sidePanelWindow );
}

void Terminal::createTestStuff()
{
    ///Inventory ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    Ingredient test1( "Ingredient1", 1, 0.1, "things" );
    Ingredient test2( "Ingredient2", 1, 0.2, "things" );
    Ingredient test3( "Ingredient3", 1, 0.3, "things" );
    Ingredient test4( "Ingredient4", 1, 0.4, "things" );
    Ingredient test5( "Ingredient5", 1, 0.5, "things" );
    Ingredient test6( "Ingredient6", 1, 0.6, "things" );

    restaurantInventory.addIngredient( test1 );
    restaurantInventory.addIngredient( test2 );
    restaurantInventory.addIngredient( test3 );
    restaurantInventory.addIngredient( test4 );
    restaurantInventory.addIngredient( test5 );
    restaurantInventory.addIngredient( test6 );

    restaurantInventory.addStock( test1, 50 );
    restaurantInventory.addStock( test2, 50 );
    restaurantInventory.addStock( test3, 50 );
    restaurantInventory.addStock( test4, 50 );
    restaurantInventory.addStock( test5, 50 );
    restaurantInventory.addStock( test6, 50 );

    ///Foods////////////////////////////////////////////////////////////////
    std::vector<Ingredient> food1Ing; food1Ing.push_back( test1 ); food1Ing.push_back( test2 ); food1Ing.push_back( test3 );
    std::vector<Ingredient> food2Ing; food2Ing.push_back( test2 ); food2Ing.push_back( test3 ); food2Ing.push_back( test4 );
    std::vector<Ingredient> food3Ing; food3Ing.push_back( test3 ); food3Ing.push_back( test4 ); food3Ing.push_back( test5 );
    std::vector<Ingredient> food4Ing; food4Ing.push_back( test4 ); food4Ing.push_back( test5 ); food4Ing.push_back( test6 );
    std::vector<Ingredient> food5Ing; food5Ing.push_back( test5 ); food5Ing.push_back( test6 ); food5Ing.push_back( test1 );
    std::vector<Ingredient> food6Ing; food6Ing.push_back( test6 ); food6Ing.push_back( test1 ); food6Ing.push_back( test2 );

    Food food1( "Food1", 0, 1.10, food1Ing );
    Food food2( "Food2", 0, 1.20, food2Ing );
    Food food3( "Food3", 0, 1.30, food3Ing );
    Food food4( "Food4", 0, 1.40, food4Ing );
    Food food5( "Food5", 0, 1.50, food5Ing );
    Food food6( "Food6", 0, 1.60, food6Ing );

    ///Combos///////////////////////////////////////////////////////////////
    std::vector<Food> combo1Food; combo1Food.push_back( food1 ); combo1Food.push_back( food2 ); combo1Food.push_back( food3 );
    std::vector<Food> combo2Food; combo2Food.push_back( food2 ); combo2Food.push_back( food3 ); combo2Food.push_back( food4 );
    std::vector<Food> combo3Food; combo3Food.push_back( food3 ); combo3Food.push_back( food4 ); combo3Food.push_back( food5 );
    std::vector<Food> combo4Food; combo4Food.push_back( food4 ); combo4Food.push_back( food5 ); combo4Food.push_back( food6 );
    std::vector<Food> combo5Food; combo5Food.push_back( food5 ); combo5Food.push_back( food6 ); combo5Food.push_back( food1 );
    std::vector<Food> combo6Food; combo6Food.push_back( food6 ); combo6Food.push_back( food1 ); combo6Food.push_back( food2 );

    Combo combo1( "Combo1", 4.10, 0, combo1Food );
    Combo combo2( "Combo2", 4.20, 0, combo2Food );
    Combo combo3( "Combo3", 4.30, 0, combo3Food );
    Combo combo4( "Combo4", 4.40, 0, combo4Food );
    Combo combo5( "Combo5", 4.50, 0, combo5Food );
    Combo combo6( "Combo6", 4.60, 0, combo6Food );

    ///Menu///////////////////////////////////////////////////////////////////
    restaurantMenu.addFood( food1 );
    restaurantMenu.addFood( food2 );
    restaurantMenu.addFood( food3 );
    restaurantMenu.addFood( food4 );
    restaurantMenu.addFood( food5 );
    restaurantMenu.addFood( food6 );

    restaurantMenu.addCombo( combo1 );
    restaurantMenu.addCombo( combo2 );
    restaurantMenu.addCombo( combo3 );
    restaurantMenu.addCombo( combo4 );
    restaurantMenu.addCombo( combo5 );
    restaurantMenu.addCombo( combo6 );

    ///Schedule for every employee///////////////////////////////////////////////////////////////
    MyDate currentDate;
    MyTime currentTime;
    WorkDay currentWorkDay;
    MyTime clockInTime(9,0,0);
    MyTime clockOutTime(16,0,0);

    currentDate.setDate( currentDate.getCurrentDate().getYear(),
                         currentDate.getCurrentDate().getMonth(),
                         currentDate.getCurrentDate().getDay() );
    currentTime.setTime( currentTime.getCurrentTime() );
    currentWorkDay.setDate( currentDate );
    currentWorkDay.setScheduledStartTime(8,0,0);
    currentWorkDay.setScheduledEndTime(17,0,0);
    currentWorkDay.setClockInTime( clockInTime );
    currentWorkDay.setClockOutTime( clockOutTime );

    Schedule currentSchedule;
    for(int week = 0; week < 2; week++)
    {
        for(int day = 0; day < 7; day++)
        {
            currentSchedule.setWorkDay( currentWorkDay, week, day);
            currentWorkDay.getDate().nextDay();
        }
    }

    ///Employees and Staff/////////////////////////////////////////////////////////
    Employee employee1( "Employee1", 1, "Grunt", 7.25, currentSchedule );
    Employee employee2( "Employee2", 2, "UpperGrunt", 9.25, currentSchedule );
    Employee employee3( "Employee3", 3, "TopGrunt", 13.25, currentSchedule );
    Employee employee4( "Employee4", 1, "Grunt", 7.25, currentSchedule );
    Employee employee5( "Employee5", 2, "UpperGrunt", 9.25, currentSchedule );
    Employee employee6( "Employee6", 3, "TopGrunt", 13.25, currentSchedule );

    restaurantStaff.hireEmployee( employee1 );
    restaurantStaff.hireEmployee( employee2 );
    restaurantStaff.hireEmployee( employee3 );
    restaurantStaff.hireEmployee( employee4 );
    restaurantStaff.hireEmployee( employee5 );
    restaurantStaff.hireEmployee( employee6 );

    ///Pay Roll
    restaurantPayRoll.setBudget(100000.0);
}

///Main Menu
void Terminal::mainMenu()
{
    bool closeTerminal = false;

    while( !closeTerminal )
    {
        wclear( displayWindow );
        makeWindowBorders();

        mvwprintw( displayWindow, 2, 55, "Main Menu" );

        mvwprintw( displayWindow, 5, 50, "Enter Your Selection:" );
        mvwprintw( displayWindow, 8, 45, "1 - Point Of Sale " );
        mvwprintw( displayWindow, 9, 45, "2 - Inventory " );
        mvwprintw( displayWindow, 10, 45, "3 - Menu and Foods " );
        mvwprintw( displayWindow, 11, 45, "4 - Staffing ");
        mvwprintw( displayWindow, 12, 45, "5 - Pay Roll " );
        mvwprintw( displayWindow, 13, 45, "9 - Shut Down Terminal " );
        wrefresh( displayWindow );

        bool goodInput = false;
        int userInput;

        //Get input for menu choice
        while( !goodInput )
        {
            userInput = getUserIntInput();
            if( ( userInput > 0 && userInput < 6 ) || userInput == 9 )
            {
                goodInput = true;
            }
        }

        //Logic to select correct menu
        if( userInput == 1 )
        {
            pointOfSaleMenu();
        }

        else if( userInput == 2 )
        {
            inventoryMenu();
        }

        else if( userInput == 3 )
        {
            foodsMenu();
        }

        else if( userInput == 4 )
        {
            staffingMenu();
        }

        else if( userInput == 5 )
        {
            payRollMenu();
        }

        else if ( userInput == 9 )
        {
            closeTerminal = true;
        }
    }//Close terminal loop
}

///Point Of Sale
void Terminal::pointOfSaleMenu()
{
    bool closeMenu = false;

    while( !closeMenu )
    {
        wclear( displayWindow );
        makeWindowBorders();

        mvwprintw( displayWindow, 2, 55, "Foods and Combos Menu" );

        mvwprintw( displayWindow, 5, 50, "Enter Your Selection:" );
        mvwprintw( displayWindow, 8, 45, "1 - View Menu ");
        mvwprintw( displayWindow, 9, 45, "2 - Take Order (NOT IMPLIMENTED) " );
        mvwprintw( displayWindow, 10, 45, "3 - View Active Orders (NOT IMPLIMENTED) ");
        mvwprintw( displayWindow, 11, 45, "4 - Complete Order (NOT IMPLIMENTED) " );
        mvwprintw( displayWindow, 12, 45, "9 - Return to Main Menu " );
        wrefresh( displayWindow );

        bool goodInput = false;
        int userInput;

        //Get input for menu choice
        while( !goodInput )
        {
            userInput = getUserIntInput();
            if( ( userInput > 0 && userInput < 5 ) || userInput == 9 )
            {
                goodInput = true;
            }
        }

        //Logic to select correct menu
        if( userInput == 1 )
        {
            viewMenu();
        }

        else if( userInput == 2 )
        {
            takeOrder();
        }

        else if( userInput == 3 )
        {
            viewActiveOrders();
        }

        else if( userInput == 4 )
        {
            completeOrder();
        }

        else if ( userInput == 9 )
        {
            closeMenu = true;
        }
    }//Close menu loop
}

void Terminal::viewMenu()
{
    wclear( displayWindow );
    makeWindowBorders();

    displayFoods();
    displayCombos();

    getch();
}

void Terminal::displayFoods()
{
    ///Writing the Foods
    mvwprintw( displayWindow, 2, 35, "Food Name     |      Price " );
    for( int i = 0; i < restaurantMenu.getFoods().size(); i++ )
    {
        for( int j = 0; j < restaurantMenu.getFoods().at(i).getName().size(); j++ )
        {
            mvwaddch( displayWindow, i+3, j+35, restaurantMenu.getFoods().at(i).getName().at(j) );
        }

        std::stringstream priceSS;
        priceSS << '$' << restaurantMenu.getFoods().at(i).getPrice();
        std::string price = priceSS.str();
        if( price.at( price.size() - 2 ) == '.' )
        {
            price = price +  "0";
        }

        for( int j = 0; j < price.size(); j++ )
        {
            mvwaddch( displayWindow, i+3, j+56, price[j] );
        }
    }

    wrefresh( displayWindow );
}

void Terminal::displayCombos()
{
    ///Writing the Combos
    mvwprintw( displayWindow, 2, 70, "Combo Name     |      Price " );
    for( int i = 0; i < restaurantMenu.getCombos().size(); i++ )
    {
        for( int j = 0; j < restaurantMenu.getCombos().at(i).getName().size(); j++ )
        {
            mvwaddch( displayWindow, i+3, j+70, restaurantMenu.getCombos().at(i).getName().at(j) );
        }

        std::stringstream priceSS;
        priceSS << '$' << restaurantMenu.getCombos().at(i).getPrice();
        std::string price = priceSS.str();
        if( price.at( price.size() - 2 ) == '.' )
        {
            price = price +  "0";
        }

        for( int j = 0; j < price.size(); j++ )
        {
            mvwaddch( displayWindow, i+3, j+92, price[j] );
        }
    }

    wrefresh( displayWindow );
}

void Terminal::takeOrder()
{
    wclear( displayWindow );
    makeWindowBorders();

    Order newOrder;

    bool orderFinished = false;
    bool goodInput = false;

    while( !orderFinished )
    {
        while( !goodInput )
        {
            mvwprintw( displayWindow, 4, 25, "Would you like to add a (F)ood or (C)ombo?");
            mvwprintw( displayWindow, 5, 25, "Or press enter to submit order." );
            wrefresh( displayWindow );
            char foodOrCombo = getch();

            if( foodOrCombo == 'F' || foodOrCombo == 'f' )
            {
                goodInput = true;
                addFoodToOrder( newOrder );
            }

            else if( foodOrCombo == 'C' || foodOrCombo == 'c' )
            {
                goodInput = true;
                addComboToOrder( newOrder );
            }

            else if( foodOrCombo == '\n' )
            {
                goodInput = true;
                orderFinished = true;
            }

            else
            {
                goodInput = false;
            }
        }
    }

    activeOrders.push_back( newOrder );
}

void Terminal::addFoodToOrder( Order orderToAddTo )
{
    wclear( displayWindow );
    makeWindowBorders();

    Food foodToAdd;
    bool correctFood = false;

    while( !correctFood )
    {
        mvwprintw( displayWindow, 20, 45, "Enter the number of the food you want to add: " );

    }

    orderToAddTo.addFood( foodToAdd );
}

void Terminal::addComboToOrder( Order orderToAddTo )
{

}

void Terminal::displayOrder( Order orderToDisplay )
{

}

void Terminal::viewActiveOrders()
{

}

void Terminal::completeOrder()
{

}

///Menu and Foods
void Terminal::foodsMenu()
{
    bool closeMenu = false;

    while( !closeMenu )
    {
        wclear( displayWindow );
        makeWindowBorders();

        mvwprintw( displayWindow, 2, 55, "Foods and Combos Menu" );

        mvwprintw( displayWindow, 5, 50, "Enter Your Selection:" );
        mvwprintw( displayWindow, 8, 45, "1 - View Menu " );
        mvwprintw( displayWindow, 9, 45, "2 - Add Food To Menu ");
        mvwprintw( displayWindow, 10, 45, "3 - Remove Food From Menu " );
        mvwprintw( displayWindow, 11, 45, "4 - Add Combo To Menu ");
        mvwprintw( displayWindow, 12, 45, "5 - Remove Combo From Menu " );
        mvwprintw( displayWindow, 13, 45, "9 - Return to Main Menu " );
        wrefresh( displayWindow );

        bool goodInput = false;
        int userInput;

        //Get input for menu choice
        while( !goodInput )
        {
            userInput = getUserIntInput();
            if( ( userInput > 0 && userInput < 6 ) || userInput == 9 )
            {
                goodInput = true;
            }
        }

        //Logic to select correct menu
        if( userInput == 1 )
        {
            viewMenu();
        }

        else if( userInput == 2 )
        {
            addFoodToMenu();
        }

        else if( userInput == 3 )
        {
            removeFoodFromMenu();
        }

        else if( userInput == 4 )
        {
            addComboToMenu();
        }

        else if( userInput == 5 )
        {
            removeComboFromMenu();
        }

        else if ( userInput == 9 )
        {
            closeMenu = true;
        }
    }//Close menu loop
}

void Terminal::addFoodToMenu()
{
    wclear( displayWindow );
    makeWindowBorders();

    bool correctFood = false;

    Food foodToAdd;
    std::string foodName;
    int foodSize;
    float foodPrice;
    std::vector<Ingredient> foodIngredients;
    std::string ingredientNameToAdd;
    Ingredient ingredientToAdd;

    while( !correctFood )
    {
        mvwprintw( displayWindow, 8, 45, "Enter the name of the food being added" );
        wrefresh( displayWindow );
        foodName = getUserStringInput();

        wclear( displayWindow );
        makeWindowBorders();

        mvwprintw( displayWindow, 8, 45, "Enter the size(1-3) of the food being added" );
        wrefresh( displayWindow );
        foodSize = getUserIntInput();

        wclear( displayWindow );
        makeWindowBorders();

        mvwprintw( displayWindow, 8, 45, "Enter the price(x.xx) of the food being added" );
        wrefresh( displayWindow );
        foodPrice = getUserFloatInput();

        wclear( displayWindow );
        makeWindowBorders();

        bool doneWithIngredients = false;

        while( !doneWithIngredients )
        {
            mvwprintw( displayWindow, 25, 20, "Enter the name of the ingredient to add to your food or hit enter if all ingredients are added" );
            displayIngredients();
            wrefresh( displayWindow );

            ingredientNameToAdd = getUserStringInput();

            if( ingredientNameToAdd == "" )
            {
                doneWithIngredients = true;
            }

            else
            {
                ingredientToAdd.setName( ingredientNameToAdd );

                if( restaurantInventory.ifInStock( ingredientToAdd ) )
                {
                    ingredientToAdd = restaurantInventory.getInventory().at( restaurantInventory.searchForIngredient( ingredientToAdd ) );
                    ingredientToAdd.setQuantity(1);
                    foodIngredients.push_back( ingredientToAdd );
                }

                else
                {
                    wclear( displayWindow );
                    makeWindowBorders();
                    mvwprintw( displayWindow, 8, 45, "That ingredient is not in the inventory " );
                    wrefresh( displayWindow );
                    getch();
                }
            }//added another ingredient or not in inventory

            wclear( displayWindow );
            makeWindowBorders();
        }//Done with ingredients

        mvwprintw( displayWindow, 8, 45, "Press enter if that is correct or any other key to try again" );
        wrefresh( displayWindow );
        char goodOrNot = getch();

        if( goodOrNot == '\n' )
        {
            correctFood = true;
        }
    }

    foodToAdd.setName( foodName );
    foodToAdd.setPrice( foodPrice );
    foodToAdd.setSize( foodSize );
    for( int i = 0; i < foodIngredients.size(); i++ )
    {
        foodToAdd.addIngredient( foodIngredients.at(i) );
    }
    foodToAdd.setCost();

    restaurantMenu.addFood( foodToAdd );
}

void Terminal::removeFoodFromMenu()
{
    wclear( displayWindow );
    makeWindowBorders();

    std::string foodNameToRemove;
    Food foodToRemove;
    mvwprintw( displayWindow, 8, 45, "Enter the name of the food to remove from the menu " );
    wrefresh( displayWindow );

    foodNameToRemove = getUserStringInput();
    foodToRemove.setName( foodNameToRemove );

    wclear( displayWindow );
    makeWindowBorders();

    if( restaurantMenu.ifFoodExists( foodToRemove ) )
    {
        restaurantMenu.removeFood( foodToRemove );
        mvwprintw( displayWindow, 8, 45, "That food was removed from the menu" );
    }

    else
    {
        mvwprintw( displayWindow, 8, 45, "That food is not on the menu" );
    }

    wrefresh( displayWindow );
    getch();
}

void Terminal::addComboToMenu()
{
    wclear( displayWindow );
    makeWindowBorders();

    bool correctCombo = false;

    Combo comboToAdd;
    std::string comboName;
    int comboSize;
    float comboPrice;
    std::vector<Food> comboFoods;
    std::string foodNameToAdd;
    Food foodToAdd;

    while( !correctCombo )
    {
        mvwprintw( displayWindow, 8, 45, "Enter the name of the combo being added" );
        wrefresh( displayWindow );
        comboName = getUserStringInput();

        wclear( displayWindow );
        makeWindowBorders();

        mvwprintw( displayWindow, 8, 45, "Enter the size(1-3) of the combo being added" );
        wrefresh( displayWindow );
        comboSize = getUserIntInput();

        wclear( displayWindow );
        makeWindowBorders();

        mvwprintw( displayWindow, 8, 45, "Enter the price(x.xx) of the combo being added" );
        wrefresh( displayWindow );
        comboPrice = getUserFloatInput();

        wclear( displayWindow );
        makeWindowBorders();

        bool doneWithFoods = false;

        while( !doneWithFoods )
        {
            mvwprintw( displayWindow, 25, 20, "Enter the name of the food to add to your combo or hit enter if all foods are added" );
            displayFoods();
            wrefresh( displayWindow );

            foodNameToAdd = getUserStringInput();

            if( foodNameToAdd == "" )
            {
                doneWithFoods = true;
            }

            else
            {
                foodToAdd.setName( foodNameToAdd );

                if( restaurantMenu.ifFoodExists( foodToAdd ) )
                {
                    foodToAdd = restaurantMenu.getFoods().at( restaurantMenu.searchForFood( foodToAdd ) );
                    comboFoods.push_back( foodToAdd );
                }

                else
                {
                    wclear( displayWindow );
                    makeWindowBorders();
                    mvwprintw( displayWindow, 8, 45, "That food is not on the menu " );
                    wrefresh( displayWindow );
                    getch();
                }
            }//added another ingredient or not in inventory

            wclear( displayWindow );
            makeWindowBorders();
        }//Done with ingredients

        mvwprintw( displayWindow, 8, 45, "Press enter if that is correct or any other key to try again" );
        wrefresh( displayWindow );
        char goodOrNot = getch();

        if( goodOrNot == '\n' )
        {
            correctCombo = true;
        }
    }

    comboToAdd.setName( comboName );
    comboToAdd.setPrice( comboPrice );
    comboToAdd.setComboSize( comboSize );
    for( int i = 0; i < comboFoods.size(); i++ )
    {
        comboToAdd.addFood( comboFoods.at(i) );
    }
    comboToAdd.setCost();

    restaurantMenu.addCombo( comboToAdd );
}

void Terminal::removeComboFromMenu()
{
    wclear( displayWindow );
    makeWindowBorders();

    std::string comboNameToRemove;
    Combo comboToRemove;
    mvwprintw( displayWindow, 8, 45, "Enter the name of the combo to remove from the menu " );
    wrefresh( displayWindow );

    comboNameToRemove = getUserStringInput();
    comboToRemove.setName( comboNameToRemove );

    wclear( displayWindow );
    makeWindowBorders();

    if( restaurantMenu.ifComboExists( comboToRemove ) )
    {
        restaurantMenu.removeCombo( comboToRemove );
        mvwprintw( displayWindow, 8, 45, "That combo was removed from the menu" );
    }

    else
    {
        mvwprintw( displayWindow, 8, 45, "That combo is not on the menu" );
    }

    wrefresh( displayWindow );
    getch();
}

///Inventory
void Terminal::inventoryMenu()
{
    bool closeMenu = false;

    while( !closeMenu )
    {
        wclear( displayWindow );
        makeWindowBorders();

        mvwprintw( displayWindow, 2, 55, "Inventory Menu" );

        mvwprintw( displayWindow, 5, 50, "Enter Your Selection:" );
        mvwprintw( displayWindow, 8, 45, "1 - Display Inventory ");
        mvwprintw( displayWindow, 9, 45, "2 - Add New Ingredient " );
        mvwprintw( displayWindow, 10, 45, "3 - Remove Ingredient ");
        mvwprintw( displayWindow, 11, 45, "4 - Add Stock to Ingredient " );
        mvwprintw( displayWindow, 12, 45, "5 - Remove Stock from Ingredient " );
        mvwprintw( displayWindow, 13, 45, "9 - Return to Main Menu " );
        wrefresh( displayWindow );

        bool goodInput = false;
        int userInput;

        //Get input for menu choice
        while( !goodInput )
        {
            userInput = getUserIntInput();
            if( ( userInput > 0 && userInput < 6 ) || userInput == 9 )
            {
                goodInput = true;
            }
        }

        //Logic to select correct menu
        if( userInput == 1 )
        {
            displayInventory();
        }

        else if( userInput == 2 )
        {
            addNewIngredient();
        }

        else if( userInput == 3 )
        {
            removeIngredient();
        }

        else if( userInput == 4 )
        {
            addIngredientStock();
        }

        else if( userInput == 5 )
        {
            removeIngredientStock();
        }

        else if ( userInput == 9 )
        {
            closeMenu = true;
        }
    }//Close menu loop
}

void Terminal::displayInventory()
{
    wclear( displayWindow );
    makeWindowBorders();

    displayIngredients();

    wrefresh( displayWindow );
    getch();
}

void Terminal::displayIngredients()
{
    mvwprintw( displayWindow, 2, 35, "Name           |  Cost Per | Quantity | Total Stock Value" );

    for( int i = 0; i < restaurantInventory.getInventory().size(); i++ )
    {
        ///Name
        for( int j = 0; j < restaurantInventory.getInventory().at(i).getName().size(); j++ )
        {
            mvwaddch( displayWindow, i+3, j+35, restaurantInventory.getInventory().at(i).getName().at(j) );
        }

        ///Cost per Unit
        std::stringstream costSS;
        costSS << '$' << restaurantInventory.getInventory().at(i).getCostPerUnit();
        std::string cost = costSS.str();
        if( cost.at( cost.size() - 2 ) == '.' )
        {
            cost = cost +  "0";
        }

        for( int j = 0; j < cost.size(); j++ )
        {
            mvwaddch( displayWindow, i+3, j+54, cost.at(j) );
        }

        ///Quantity
        std::stringstream quantitySS;
        quantitySS << restaurantInventory.getInventory().at(i).getQuantity();
        std::string quantity = quantitySS.str();
        for( int j = 0; j < quantity.size(); j++ )
        {
            mvwaddch( displayWindow, i+3, j+67, quantity.at(j) );
        }

        ///Total Stock
        std::stringstream stockSS;
        stockSS << '$' << restaurantInventory.getInventory().at(i).getCostOfStock();
        std::string stock = stockSS.str();
        if( stock.at( stock.size() - 2 ) == '.' )
        {
            stock = stock +  "0";
        }
        if( stock.at( stock.size() - 2 ) != '.' && stock.at( stock.size() - 3 ) != '.' )
        {
            stock = stock + ".00";
        }
        for( int j = 0; j < stock.size(); j++ )
        {
            mvwaddch( displayWindow, i+3, j+75, stock.at(j) );
        }
    }

    wrefresh( displayWindow );
}

void Terminal::addNewIngredient()
{
    wclear( displayWindow );
    makeWindowBorders();

    bool correctIngredient = false;

    std::string ingredientName;
    float ingredientCost;
    int ingredientQuantity;
    std::string ingredientUnit;

    while( !correctIngredient )
    {
        mvwprintw( displayWindow, 8, 45, "Enter the name of the ingredient" );
        ingredientName = getUserStringInput();

        wclear( displayWindow );
        makeWindowBorders();

        mvwprintw( displayWindow, 8, 45, "Enter the cost of the ingredient in x.xx form" );
        ingredientCost = getUserFloatInput();

        wclear( displayWindow );
        makeWindowBorders();

        mvwprintw( displayWindow, 8, 45, "Enter the quantity of the ingredient" );
        ingredientQuantity = getUserLongIntInput();

        wclear( displayWindow );
        makeWindowBorders();

        mvwprintw( displayWindow, 8, 45, "Enter the units used for that quantity" );
        ingredientUnit = getUserStringInput();

        wclear( displayWindow );
        makeWindowBorders();

        mvwprintw( displayWindow, 15, 45, " Press enter if Correct or any other key to start over. ");
        wrefresh( displayWindow );
        char goodOrNot = getch();
        if( goodOrNot == '\n' )
        {
            correctIngredient = true;
        }
    }

    Ingredient ingredientToAdd( ingredientName, ingredientQuantity, ingredientCost, ingredientUnit );
    restaurantPayRoll.setBudget( restaurantPayRoll.getBudget() - ingredientToAdd.getCostOfStock() );

    restaurantInventory.addIngredient( ingredientToAdd );
}

void Terminal::removeIngredient()
{
    bool correctIngredient = false;

    std::string ingredientName;
    Ingredient ingredientToRemove;

    while( !correctIngredient )
    {
        wclear( displayWindow );
        makeWindowBorders();
        mvwprintw( displayWindow, 8, 45, "Enter the name of the ingredient to remove" );
        wrefresh( displayWindow );
        ingredientName = getUserStringInput();

        ingredientToRemove.setName( ingredientName );

        if( restaurantInventory.ifInStock( ingredientToRemove ) )
        {
            restaurantInventory.removeIngredient( ingredientToRemove );
            correctIngredient = true;
        }

        else
        {
            wclear( displayWindow );
            makeWindowBorders();
            mvwprintw( displayWindow, 8, 45, "That ingredient is not in the inventory." );
            wrefresh( displayWindow );
            getch();
            correctIngredient = true;
        }

    }
}

void Terminal::addIngredientStock()
{
    bool correctIngredient = false;

    std::string ingredientName;
    Ingredient ingredientToAddTo;
    int quantityToAdd;

    while( !correctIngredient )
    {
        wclear( displayWindow );
        makeWindowBorders();
        mvwprintw( displayWindow, 8, 45, "Enter the name of the ingredient to add stock to" );
        wrefresh( displayWindow );
        ingredientName = getUserStringInput();

        ingredientToAddTo.setName( ingredientName );

        if( restaurantInventory.ifInStock( ingredientToAddTo ) )
        {
            correctIngredient = true;

            wclear( displayWindow );
            makeWindowBorders();
            mvwprintw( displayWindow, 8, 45, "Enter the quantity to add to the stock" );
            wrefresh( displayWindow );
            quantityToAdd = getUserLongIntInput();

            restaurantInventory.addStock( ingredientToAddTo, quantityToAdd );
        }

        else
        {
            wclear( displayWindow );
            makeWindowBorders();
            mvwprintw( displayWindow, 8, 45, "That ingredient is not in the inventory." );
            wrefresh( displayWindow );
            getch();
            correctIngredient = true;
        }

    }
}

void Terminal::removeIngredientStock()
{
    bool correctIngredient = false;

    std::string ingredientName;
    Ingredient ingredientToRemoveFrom;
    int quantityToRemove;

    while( !correctIngredient )
    {
        wclear( displayWindow );
        makeWindowBorders();
        mvwprintw( displayWindow, 8, 45, "Enter the name of the ingredient to remove stock from" );
        wrefresh( displayWindow );
        ingredientName = getUserStringInput();

        ingredientToRemoveFrom.setName( ingredientName );

        if( restaurantInventory.ifInStock( ingredientToRemoveFrom ) )
        {
            correctIngredient = true;

            wclear( displayWindow );
            makeWindowBorders();
            mvwprintw( displayWindow, 8, 45, "Enter the quantity to remove from the stock" );
            wrefresh( displayWindow );
            quantityToRemove = getUserLongIntInput();

            restaurantInventory.removeStock( ingredientToRemoveFrom, quantityToRemove );
        }

        else
        {
            wclear( displayWindow );
            makeWindowBorders();
            mvwprintw( displayWindow, 8, 45, "That ingredient is not in the inventory." );
            wrefresh( displayWindow );
            getch();
            correctIngredient = true;
        }

    }
}

///Staffing
void Terminal::staffingMenu()
{
    bool closeMenu = false;

    while( !closeMenu )
    {
        wclear( displayWindow );
        makeWindowBorders();

        mvwprintw( displayWindow, 2, 55, "Staffing Menu" );

        mvwprintw( displayWindow, 5, 50, "Enter Your Selection: " );
        mvwprintw( displayWindow, 8, 45, "1 - View Staff ");
        mvwprintw( displayWindow, 9, 45, "2 - Fire Employee (NOT IMPLIMENTED) " );
        mvwprintw( displayWindow, 10, 45, "3 - Hire Employee ");
        mvwprintw( displayWindow, 11, 45, "4 - View Employee Schedule (NOT IMPLIMENTED) " );
        mvwprintw( displayWindow, 12, 45, "5 - Change Employee Schedule (NOT IMPLIMENTED) " );
        mvwprintw( displayWindow, 13, 45, "9 - Return to Main Menu " );
        wrefresh( displayWindow );

        bool goodInput = false;
        int userInput;

        //Get input for menu choice
        while( !goodInput )
        {
            userInput = getUserIntInput();
            if( ( userInput > 0 && userInput < 6 ) || userInput == 9 )
            {
                goodInput = true;
            }
        }

        //Logic to select correct menu
        if( userInput == 1 )
        {
            displayStaff();
        }

        else if( userInput == 2 )
        {
            ///fireEmployee();  Not Currently Working
        }

        else if( userInput == 3 )
        {
            hireEmployee();
        }

        else if( userInput == 4 )
        {
            ///viewEmployeeSchedule(); Not Currently Working
        }

        else if( userInput == 5 )
        {
            changeEmployeeSchedule();
        }

        else if ( userInput == 9 )
        {
            closeMenu = true;
        }
    }//close menu loop
}

void Terminal::displayStaff()
{
    wclear( displayWindow );
    makeWindowBorders();
    mvwprintw( displayWindow, 2, 35, "Employee Name      |    ID#    |   Position    |   Pay Rate");

    for( int i = 0; i < restaurantStaff.getStaff().size(); i++ )
    {
        ///Name
        for( int j = 0; j < restaurantStaff.getStaff().at(i).getName().size(); j++ )
        {
            mvwaddch( displayWindow, i+3, j+35, restaurantStaff.getStaff().at(i).getName().at(j) );
        }

        ///ID#
        std::stringstream idSS;
        idSS << restaurantStaff.getStaff().at(i).getID();
        std::string id = idSS.str();
        for( int j = 0; j < id.size(); j++ )
        {
            mvwaddch( displayWindow, i+3, j+57, id.at(j) );
        }

        ///Position
        std::stringstream positionSS;
        positionSS << restaurantStaff.getStaff().at(i).getPosition() << " - " << restaurantStaff.getStaff().at(i).getPositionTitle();
        std::string position = positionSS.str();
        for( int j = 0; j < position.size(); j++ )
        {
            mvwaddch( displayWindow, i+3, j+68, position.at(j) );
        }

        ///Pay Rate
        std::stringstream payRateSS;
        payRateSS << '$' << restaurantStaff.getStaff().at(i).getHourlyPayRate();
        std::string payRate = payRateSS.str();
        if( payRate.at( payRate.size() - 2 ) == '.' )
        {
            payRate = payRate + ' ';
        }
        for( int j = 0; j < payRate.size(); j++ )
        {
            mvwaddch( displayWindow, i+3, j+87, payRate.at(j) );
        }
    }

    wrefresh( displayWindow );
    getch();
}

void Terminal::fireEmployee()
{
    wclear( displayWindow );
    makeWindowBorders();

    mvwprintw( displayWindow, 8, 45, "Enter the name of the employee to fire" );
    wrefresh( displayWindow );

    std::string employeeName = getUserStringInput();
    Employee employeeToFire;
    employeeToFire.setName( employeeName );

    wclear( displayWindow );
    makeWindowBorders();

    if( restaurantStaff.ifEmployed( employeeToFire ) )
    {
        mvwprintw( displayWindow, 8, 45, "That employee has been fired. " );
        restaurantStaff.fireEmployee( employeeToFire );
    }

    else
    {
        mvwprintw( displayWindow, 8, 45, "That employee is not employed here. " );
    }

    wrefresh( displayWindow );
    getch();
}

void Terminal::hireEmployee()
{
    wclear( displayWindow );
    makeWindowBorders();

    bool correctEmployee = false;

    Employee employeeToHire;
    std::string employeeName;
    int employeePosition;
    std::string employeePositionTitle;
    float employeePayRate;

    while( !correctEmployee )
    {
        mvwprintw( displayWindow, 8, 45, "Enter the name of the employee being hired" );
        wrefresh( displayWindow );
        employeeName = getUserStringInput();

        wclear( displayWindow );
        makeWindowBorders();

        mvwprintw( displayWindow, 8, 45, "Enter the position(1-3) of the employee being hired" );
        wrefresh( displayWindow );
        employeePosition = getUserIntInput();

        wclear( displayWindow );
        makeWindowBorders();

        mvwprintw( displayWindow, 8, 45, "Enter the title of the position of the employee being hired" );
        wrefresh( displayWindow );
        employeePositionTitle = getUserStringInput();

        wclear( displayWindow );
        makeWindowBorders();

        mvwprintw( displayWindow, 8, 45, "Enter the hourly pay rate(xx.xx) of the employee being hired" );
        wrefresh( displayWindow );
        employeePayRate = getUserFloatInput();

        wclear( displayWindow );
        makeWindowBorders();

        mvwprintw( displayWindow, 8, 45, "Press enter if that is correct or any other key to try again" );
        wrefresh( displayWindow );
        char goodOrNot = getch();

        if( goodOrNot == '\n' )
        {
            correctEmployee = true;
        }
    }

    employeeToHire.setName( employeeName );
    employeeToHire.setPosition( employeePosition );
    employeeToHire.setPositionTitle( employeePositionTitle );
    employeeToHire.setHourlyPayRate( employeePayRate );

    restaurantStaff.hireEmployee( employeeToHire );
}

void Terminal::viewEmployeeSchedule()
{
    wclear( displayWindow );
    makeWindowBorders();

    mvwprintw( displayWindow, 8, 45, "Enter the name of the employee to examine" );
    wrefresh( displayWindow );

    std::string employeeName = getUserStringInput();
    Employee employeeToExamine;
    employeeToExamine.setName( employeeName );

    wclear( displayWindow );
    makeWindowBorders();

    if( restaurantStaff.ifEmployed( employeeToExamine ) )
    {
        employeeToExamine = restaurantStaff.getStaff().at( restaurantStaff.searchForEmployee( employeeToExamine ) );

        for( int i = 0; i < employeeToExamine.getEmployeeSchedule().getWorkWeekOne().size(); i++ )
        {
            std::string week1WorkDayToPrint = employeeToExamine.getEmployeeSchedule().getWorkWeekOne().at(i).getScheduledStartTime().toString() + " - "
                                            + employeeToExamine.getEmployeeSchedule().getWorkWeekOne().at(i).getScheduledEndTime().toString();
            outputString( displayWindow, 4+i, 25, week1WorkDayToPrint );

            std::string week2WorkDayToPrint = employeeToExamine.getEmployeeSchedule().getWorkWeekTwo().at(i).getScheduledStartTime().toString() + " - "
                                            + employeeToExamine.getEmployeeSchedule().getWorkWeekTwo().at(i).getScheduledEndTime().toString();
            outputString( displayWindow, 4+i, 55, week2WorkDayToPrint );
        }
    }

    else
    {
        mvwprintw( displayWindow, 8, 45, "That employee is not employed here" );
    }

    wrefresh( displayWindow );
    getch();
}

void Terminal::changeEmployeeSchedule()
{

}

///Pay Roll
void Terminal::payRollMenu()
{
    bool closeMenu = false;

    while( !closeMenu )
    {
        wclear( displayWindow );
        makeWindowBorders();

        mvwprintw( displayWindow, 2, 55, "Pay Roll Menu" );

        mvwprintw( displayWindow, 5, 50, "Enter Your Selection: " );
        mvwprintw( displayWindow, 8, 45, "1 - View Budget ");
        mvwprintw( displayWindow, 9, 45, "2 - Increase Budget (NOT IMPLIMENTED) " );
        mvwprintw( displayWindow, 10, 45, "3 - Decrease Budget (NOT IMPLIMENTED) " );
        mvwprintw( displayWindow, 11, 45, "4 - Generate Employee Pay Check (NOT IMPLIMENTED) " );
        mvwprintw( displayWindow, 12, 45, "9 - Return to Main Menu " );
        wrefresh( displayWindow );

        bool goodInput = false;
        int userInput;

        //Get input for menu choice
        while( !goodInput )
        {
            userInput = getUserIntInput();
            if( ( userInput > 0 && userInput < 6 ) || userInput == 9 )
            {
                goodInput = true;
            }
        }

        //Logic to select correct menu
        if( userInput == 1 )
        {
            viewBudget();
        }

        else if( userInput == 2 )
        {
            createCheck();
        }

        else if( userInput == 3 )
        {
            //Something else
        }

        else if ( userInput == 9 )
        {
            closeMenu = true;
        }
    }//close menu loop
}

void Terminal::viewBudget()
{
    wclear( displayWindow );
    makeWindowBorders();
    mvwprintw( displayWindow, 2, 45, "BUDGET");

    std::stringstream budgetSS;
    budgetSS << "Current Budget:  " << '$' << restaurantPayRoll.getBudget();
    std::string budget = budgetSS.str();

    if( budget.at( budget.size() - 2 ) == '.' )
    {
        budget = budget + '0';
    }

    if( budget.at( budget.size() - 2 ) != '.' && budget.at( budget.size() - 3 ) != '.' )
    {
        budget = budget + ".00";
    }

    outputString( displayWindow, 3, 35, budget );

    wrefresh( displayWindow );
    getch();
}

void Terminal::increaseBudget()
{

}

void Terminal::decreaseBudget()
{

}

void Terminal::createCheck()
{

}

///Random Functions used to get input
int Terminal::getUserIntInput()
{
    char userInput =  getch();
    int userIntInput = int ( userInput ) - 48; //subtracted the ascii value for an easy conversion.

    if( userIntInput < 1 && userIntInput > 9 )
    {
        userInput = 0;
    }

    return userIntInput;
}

int Terminal::getUserLongIntInput()
{
    std::string userInput = getUserStringInput();
    int userIntInput;

    std::stringstream ( userInput ) >> userIntInput;

    return userIntInput;
}

float Terminal::getUserFloatInput()
{
    std::string userInput = getUserStringInput();
    float userFloatInput;

    std::stringstream ( userInput ) >> userFloatInput;

    return userFloatInput;
}

std::string Terminal::getUserStringInput()//Modified function from Randy Hash's CS202 Final Project
{
    std::string userInput;

    echo();
    bool goodInput = false;

    while( !goodInput )
    {
        wclear( userInputWindow );
        makeWindowBorders();
        wmove( userInputWindow, 8, 55 );

        int letterCounter = 0;
        char ch;

        while( letterCounter < 30 && ch != '\n' )
        {
            ch = wgetch( userInputWindow );

            if( ch == '\n' )
            {
                break;
            }

            else
            {
                userInput.push_back(ch);
            }

            letterCounter++;
        }//End of user input loop

        mvwprintw( userInputWindow, 12, 45, "Press enter if that is correct." );
        wrefresh( userInputWindow );

        ch = getch();
        if( ch == '\n' )
        {
            goodInput = true;
        }

    }//End of good input while loop


    noecho();

    wclear( userInputWindow );
    makeWindowBorders();
    wrefresh( userInputWindow );

    return userInput;
}

///Functions for Output
void Terminal::outputString( WINDOW* window, int startY, int startX, std::string stringToOutput )
{
    for( int i = 0; i < stringToOutput.size(); i++ )
    {
        mvwaddch( window, startY, startX+i, stringToOutput.at(i) );
    }
}
