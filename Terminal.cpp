#include "Terminal.h"

Terminal::Terminal():
    displayWindow(NULL), userInputWindow(NULL), sidePanelWindow(NULL)
{
    setupCurses();
    makeWindowBorders();
    createTestStuff();
    titleScreen();
    //restaurantInventory.loadInventory();
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
    init_pair(1, COLOR_GREEN, COLOR_BLACK);//color for Good Stuff
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);//color for Borders
    init_pair(3, COLOR_RED, COLOR_BLACK);//color for Bad Stuff

    displayWindow = newwin( DISPLAY_WINDOW_HEIGHT, DISPLAY_WINDOW_WIDTH, 0, 0 );
    userInputWindow = newwin( USER_INPUT_WINDOW_HEIGHT, USER_INPUT_WINDOW_WIDTH, DISPLAY_WINDOW_HEIGHT, 0 );
    sidePanelWindow = newwin( SIDE_PANEL_WINDOW_HEIGHT, SIDE_PANEL_WINDOW_WIDTH, 0, DISPLAY_WINDOW_WIDTH );

    wrefresh( stdscr );

    wattron( displayWindow, COLOR_PAIR(2) );
    wattron( sidePanelWindow, COLOR_PAIR(1) );
    wattron( userInputWindow, COLOR_PAIR(2) );
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

    wattron( displayWindow, COLOR_PAIR(2) );
    wattron( sidePanelWindow, COLOR_PAIR(1) );
    wattron( userInputWindow, COLOR_PAIR(3) );
}

void Terminal::createTestStuff()
{
    ///Inventory ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    Ingredient test1( "Hamburger", 1, 0.75, "patties" );
    Ingredient test2( "Hamburger Buns", 1, 0.23, "buns" );
    Ingredient test3( "Cheese", 1, 0.1, "slices" );
    Ingredient test4( "French Fries", 1, 0.60, "servings" );
    Ingredient test5( "Tater Tots", 1, 0.5, "servings" );
    Ingredient test6( "Bacon", 1, 0.6, "slivers" );
    Ingredient test7( "Coke", 1, 0.25, "servings" );

    restaurantInventory.addIngredient( test1 );
    restaurantInventory.addIngredient( test2 );
    restaurantInventory.addIngredient( test3 );
    restaurantInventory.addIngredient( test4 );
    restaurantInventory.addIngredient( test5 );
    restaurantInventory.addIngredient( test6 );
    restaurantInventory.addIngredient( test7 );

    restaurantInventory.addStock( test1, 50 );
    restaurantInventory.addStock( test2, 50 );
    restaurantInventory.addStock( test3, 50 );
    restaurantInventory.addStock( test4, 50 );
    restaurantInventory.addStock( test5, 50 );
    restaurantInventory.addStock( test6, 50 );
    restaurantInventory.addStock( test7, 50 );


    ///Foods////////////////////////////////////////////////////////////////
    std::vector<Ingredient> food1Ing; food1Ing.push_back( test1 ); food1Ing.push_back( test2 );
    std::vector<Ingredient> food2Ing; food2Ing.push_back( test1 ); food2Ing.push_back( test2 ); food2Ing.push_back( test3 );
    std::vector<Ingredient> food3Ing; food3Ing.push_back( test1 ); food3Ing.push_back( test2 ); food3Ing.push_back( test6 );
    std::vector<Ingredient> food4Ing; food4Ing.push_back( test1 ); food4Ing.push_back( test2 ); food4Ing.push_back( test3 );  food3Ing.push_back( test6 );
    std::vector<Ingredient> food5Ing; food5Ing.push_back( test4 );
    std::vector<Ingredient> food6Ing; food6Ing.push_back( test5 );
    std::vector<Ingredient> food7Ing; food7Ing.push_back( test7 );

    Food food1( "Hamburger", 0, 1.10, food1Ing );
    Food food2( "Cheeseburger", 0, 1.40, food2Ing );
    Food food3( "Bacon Burger", 0, 1.60, food3Ing );
    Food food4( "Bacon Cheeseburger", 0, 1.80, food4Ing );
    Food food5( "French Fries", 0, 1.00, food5Ing );
    Food food6( "Tater Tots", 0, 1.10, food6Ing );
    Food food7( "Large Coke", 0, 1.00, food7Ing );

    ///Combos///////////////////////////////////////////////////////////////
    std::vector<Food> combo1Food; combo1Food.push_back( food1 ); combo1Food.push_back( food5 ); combo1Food.push_back( food7 );
    std::vector<Food> combo2Food; combo2Food.push_back( food1 ); combo2Food.push_back( food6 ); combo2Food.push_back( food7 );
    std::vector<Food> combo3Food; combo3Food.push_back( food2 ); combo3Food.push_back( food5 ); combo3Food.push_back( food7 );
    std::vector<Food> combo4Food; combo4Food.push_back( food2 ); combo4Food.push_back( food6 ); combo4Food.push_back( food7 );
    std::vector<Food> combo5Food; combo5Food.push_back( food3 ); combo5Food.push_back( food5 ); combo5Food.push_back( food7 );
    std::vector<Food> combo6Food; combo6Food.push_back( food3 ); combo6Food.push_back( food6 ); combo6Food.push_back( food7 );
    std::vector<Food> combo7Food; combo7Food.push_back( food4 ); combo7Food.push_back( food5 ); combo7Food.push_back( food7 );
    std::vector<Food> combo8Food; combo8Food.push_back( food4 ); combo8Food.push_back( food6 ); combo8Food.push_back( food7 );

    Combo combo1( "Hamburger with Fries", 4.10, 0, combo1Food );
    Combo combo2( "Hamburger with Tots", 4.20, 0, combo2Food );
    Combo combo3( "Cheeseburger with Fries", 4.30, 0, combo3Food );
    Combo combo4( "Cheeseburger with Tots", 4.40, 0, combo4Food );
    Combo combo5( "Bacon Burger with Fries", 4.50, 0, combo5Food );
    Combo combo6( "Bacon Burger with Tots", 4.60, 0, combo6Food );
    Combo combo7( "Bacon Cheeseburger with Fries", 4.70, 0, combo7Food );
    Combo combo8( "Bacon Cheeseburger with Tots", 4.80, 0, combo8Food );

    ///Menu///////////////////////////////////////////////////////////////////
    restaurantMenu.addFood( food1 );
    restaurantMenu.addFood( food2 );
    restaurantMenu.addFood( food3 );
    restaurantMenu.addFood( food4 );
    restaurantMenu.addFood( food5 );
    restaurantMenu.addFood( food6 );
    restaurantMenu.addFood( food7 );

    restaurantMenu.addCombo( combo1 );
    restaurantMenu.addCombo( combo2 );
    restaurantMenu.addCombo( combo3 );
    restaurantMenu.addCombo( combo4 );
    restaurantMenu.addCombo( combo5 );
    restaurantMenu.addCombo( combo6 );
    restaurantMenu.addCombo( combo7 );
    restaurantMenu.addCombo( combo8 );

    ///Schedule for every employee///////////////////////////////////////////////////////////////
    MyDate currentDate;
    MyTime currentTime;
    WorkDay currentWorkDay;
    MyTime clockInTime(8,0,0);
    MyTime clockOutTime(14,0,0);

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
            currentWorkDay.nextDay();
        }
    }

    ///Employees and Staff/////////////////////////////////////////////////////////
    Employee employee1( "Bill", 1, "Grunt", 7.25, currentSchedule );
    Employee employee2( "Ted", 1, "UpperGrunt", 7.25, currentSchedule );
    Employee employee3( "Matt", 2, "TopGrunt", 11.25, currentSchedule );
    Employee employee4( "Leandra", 2, "Grunt", 11.25, currentSchedule );
    Employee employee5( "Randy", 3, "UpperGrunt", 19.99, currentSchedule );
    Employee employee6( "Mr. Bowe", 3, "TopGrunt", 9000.01, currentSchedule );

    restaurantStaff.hireEmployee( employee1 );
    restaurantStaff.hireEmployee( employee2 );
    restaurantStaff.hireEmployee( employee3 );
    restaurantStaff.hireEmployee( employee4 );
    restaurantStaff.hireEmployee( employee5 );
    restaurantStaff.hireEmployee( employee6 );

    ///Pay Roll
    //restaurantPayRoll.setBudget(100000.0);
}

///Main Menu
void Terminal::titleScreen()
{
    //The formating of this ascii art has been altered in code to compensate for "\" being a viewable character in c++
    mvwprintw( displayWindow, 2,  10, " ______     ______     ______     ______   ______     __  __     ______     ______     __   __     ______  " );
    mvwprintw( displayWindow, 3,  10, "/\\  == \\   /\\  ___\\   /\\  ___\\   /\\__  _\\ /\\  __ \\   /\\ \\/\\ \\   /\\  == \\   /\\  __ \\   /\\ '-.\\ \\   /\\__  _\\ " );
    mvwprintw( displayWindow, 4,  10, "\\ \\  __<   \\ \\  __\\   \\ \\___  \\  \\/_/\\ \\/ \\ \\  __ \\  \\ \\ \\_\\ \\  \\ \\  __<   \\ \\  __ \\  \\ \\ \\-.  \\  \\/_/\\ \\/ " );
    mvwprintw( displayWindow, 5,  10, " \\ \\_\\ \\_\\  \\ \\_____\\  \\/\\_____\\    \\ \\_\\  \\ \\_\\ \\_\\  \\ \\_____\\  \\ \\_\\ \\_\\  \\ \\_\\ \\_\\  \\ \\_\\\\'\\_\\    \\ \\_\\ " );
    mvwprintw( displayWindow, 6,  10, "  \\/_/ /_/   \\/_____/   \\/_____/     \\/_/   \\/_/\\/_/   \\/_____/   \\/_/ /_/   \\/_/\\/_/   \\/_/ \\/_/     \\/_/ " );
    mvwprintw( displayWindow, 7,  10, "                                                                                                           " );
    mvwprintw( displayWindow, 8,  10, "             ______   ______     ______     __    __     __     __   __     ______     __                  " );
    mvwprintw( displayWindow, 9,  10, "            /\\__  _\\ /\\  ___\\   /\\  == \\   /\\ '-./  \\   /\\ \\   /\\ '-.\\ \\   /\\  __ \\   /\\ \\                 " );
    mvwprintw( displayWindow, 10, 10, "            \\/_/\\ \\/ \\ \\  __\\   \\ \\  __<   \\ \\ \\-./\\ \\  \\ \\ \\  \\ \\ \\-.  \\  \\ \\  __ \\  \\ \\ \\____            " );
    mvwprintw( displayWindow, 11, 10, "               \\ \\_\\  \\ \\_____\\  \\ \\_\\ \\_\\  \\ \\_\\ \\ \\_\\  \\ \\_\\  \\ \\_\\\\'\\_\\  \\ \\_\\ \\_\\  \\ \\_____\\           " );
    mvwprintw( displayWindow, 12, 10, "                \\/_/   \\/_____/   \\/_/ /_/   \\/_/  \\/_/   \\/_/   \\/_/ \\/_/   \\/_/\\/_/   \\/_____/           " );
    mvwprintw( displayWindow, 13, 10, "                                                                                                           " );

    mvwprintw( displayWindow, 20, 55, "Press Enter to Continue" );
    wrefresh( displayWindow );

    getch();
}

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
        mvwprintw( displayWindow, 9, 45, "2 - Time Clock " );
        mvwprintw( displayWindow, 10, 45, "3 - Inventory      (MANAGER ACCESS ONLY) " );
        mvwprintw( displayWindow, 11, 45, "4 - Menu and Foods (MANAGER ACCESS ONLY) " );
        mvwprintw( displayWindow, 12, 45, "5 - Staffing       (MANAGER ACCESS ONLY) ");
        mvwprintw( displayWindow, 13, 45, "6 - Pay Roll       (MANAGER ACCESS ONLY) " );
        mvwprintw( displayWindow, 14, 45, "9 - Shut Down Terminal " );
        wrefresh( displayWindow );

        bool goodInput = false;
        int userInput;

        //Get input for menu choice
        while( !goodInput )
        {
            userInput = getUserIntInput();
            if( ( userInput > 0 && userInput < 7 ) || userInput == 9 )
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
            timeClockMenu();
        }

        else if( userInput == 3 )
        {
            if( verifyManager() )
            {
                inventoryMenu();
            }
        }

        else if( userInput == 4 )
        {
            if( verifyManager() )
            {
                foodsMenu();
            }
        }

        else if( userInput == 5 )
        {
            if( verifyManager() )
            {
                staffingMenu();
            }
        }

        else if( userInput == 6 )
        {
            if( verifyManager() )
            {
                payRollMenu();
            }
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

        mvwprintw( displayWindow, 2, 55, "Point of Sale Menu" );

        mvwprintw( displayWindow, 5, 50, "Enter Your Selection:" );
        mvwprintw( displayWindow, 8, 45, "1 - View Menu ");
        mvwprintw( displayWindow, 9, 45, "2 - Take Order " );
        mvwprintw( displayWindow, 10, 45, "3 - View Active Orders ");
        mvwprintw( displayWindow, 11, 45, "4 - Complete Order " );
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
    mvwprintw( displayWindow, 2, 25, "Food Name       |        Price " );
    for( int i = 0; i < restaurantMenu.getFoods().size(); i++ )
    {
        outputString( displayWindow, i+3, 25, restaurantMenu.getFoods().at(i).getName() );
        outputPrice( displayWindow, i+3, 50, restaurantMenu.getFoods().at(i).getPrice() );
    }

    wrefresh( displayWindow );
}

void Terminal::displayCombos()
{
    ///Writing the Combos
    mvwprintw( displayWindow, 2, 70, "Combo Name          |           Price " );
    for( int i = 0; i < restaurantMenu.getCombos().size(); i++ )
    {
        outputString( displayWindow, i+3, 70, restaurantMenu.getCombos().at(i).getName() );
        outputPrice( displayWindow, i+3, 102, restaurantMenu.getCombos().at(i).getPrice() );
    }

    wrefresh( displayWindow );
}

void Terminal::takeOrder()
{
    wclear( displayWindow );
    makeWindowBorders();

    Order newOrder;

    bool orderFinished = false;

    while( !orderFinished )
    {
        wclear( displayWindow );
        displayOrder( newOrder );

        mvwprintw( displayWindow, 4, 25, "Would you like to (A)dd or (R)emove and item" );
        mvwprintw( displayWindow, 5, 25, "Or press enter to submit order." );
        wrefresh( displayWindow );
        char addOrRemove = getch();

        if( addOrRemove == '\n' )
        {
            orderFinished = true;
        }

    ///Adding items to order
        else if( addOrRemove == 'A' || addOrRemove == 'a' )
        {
            wclear( displayWindow );
            makeWindowBorders();
            mvwprintw( displayWindow, 4, 25, "Would you like to add a (F)ood or (C)ombo?");
            wrefresh( displayWindow );

            char foodOrCombo = getch();

            if( foodOrCombo == 'F' || foodOrCombo == 'f' )
            {
                addFoodToOrder( newOrder );
            }

            else if( foodOrCombo == 'C' || foodOrCombo == 'c' )
            {
                addComboToOrder( newOrder );
            }
        }

    ///Removing items from order
        else if( addOrRemove == 'R' || addOrRemove == 'r' )
        {
            wclear( displayWindow );
            makeWindowBorders();
            mvwprintw( displayWindow, 4, 25, "Would you like to remove a (F)ood or (C)ombo?" );
            wrefresh( displayWindow );

            char foodOrCombo = getch();

            if( foodOrCombo == 'F' || foodOrCombo == 'f' )
            {
                removeFoodFromOrder( newOrder );
            }

            else if( foodOrCombo == 'C' || foodOrCombo == 'c' )
            {
                removeComboFromOrder( newOrder );
            }
        }
    }

    wclear( sidePanelWindow );
    activeOrders.push_back( newOrder );
}

void Terminal::addFoodToOrder( Order& orderToAddTo )
{
    wclear( displayWindow );
    makeWindowBorders();

    std::string foodNameToAdd;
    Food foodToAdd;

    wclear( displayWindow );
    mvwprintw( displayWindow, 20, 45, "Enter the name of the food you want to add " );
    displayFoods();
    wrefresh( displayWindow );
    foodNameToAdd = getUserStringInput();

    foodToAdd.setName( foodNameToAdd );

    wclear( displayWindow );
    makeWindowBorders();

    if( restaurantMenu.ifFoodExists( foodToAdd ) )
    {
        foodToAdd = restaurantMenu.getFoods().at( restaurantMenu.searchForFood( foodToAdd ) );
        mvwprintw( displayWindow, 8, 45, "That food has been added to the order" );
        orderToAddTo.addFood( foodToAdd );
    }

    else
    {
        mvwprintw( displayWindow, 8, 45, "That food is not on the menu" );
    }

    wrefresh( displayWindow );
    getch();

}

void Terminal::addComboToOrder( Order& orderToAddTo )
{
    wclear( displayWindow );
    makeWindowBorders();

    std::string comboNameToAdd;
    Combo comboToAdd;

    wclear( displayWindow );
    mvwprintw( displayWindow, 20, 45, "Enter the name of the combo you want to add " );
    displayCombos();
    wrefresh( displayWindow );
    comboNameToAdd = getUserStringInput();

    comboToAdd.setName( comboNameToAdd );

    wclear( displayWindow );
    makeWindowBorders();

    if( restaurantMenu.ifComboExists( comboToAdd ) )
    {
        comboToAdd = restaurantMenu.getCombos().at( restaurantMenu.searchForCombo( comboToAdd ) );
        mvwprintw( displayWindow, 8, 45, "That combo has been added to the order" );
        orderToAddTo.addCombo( comboToAdd );
    }

    else
    {
        mvwprintw( displayWindow, 8, 45, "That combo is not on the menu" );
    }

    wrefresh( displayWindow );
    getch();
}

void Terminal::removeFoodFromOrder( Order& orderToRemoveFrom )
{
    wclear( displayWindow );
    makeWindowBorders();

    std::string foodNameToRemove;
    Food foodToRemove;

    wclear( displayWindow );
    mvwprintw( displayWindow, 20, 45, "Enter the name of the food you want to remove " );
    displayFoods();
    wrefresh( displayWindow );
    foodNameToRemove = getUserStringInput();

    foodToRemove.setName( foodNameToRemove );

    wclear( displayWindow );
    makeWindowBorders();

    if( orderToRemoveFrom.ifFoodExists( foodToRemove ) )
    {
        foodToRemove = orderToRemoveFrom.getFoods().at( orderToRemoveFrom.searchForFood( foodToRemove ) );
        mvwprintw( displayWindow, 8, 45, "That food has been removed from the order" );
        orderToRemoveFrom.removeFood( foodToRemove );
    }

    else
    {
        mvwprintw( displayWindow, 8, 45, "That food is not in the order " );
    }

    wrefresh( displayWindow );
    getch();
}

void Terminal::removeComboFromOrder( Order& orderToRemoveFrom )
{
    wclear( displayWindow );
    makeWindowBorders();

    std::string comboNameToRemove;
    Combo comboToRemove;

    wclear( displayWindow );
    mvwprintw( displayWindow, 20, 45, "Enter the name of the combo you want to remove " );
    displayFoods();
    wrefresh( displayWindow );
    comboNameToRemove = getUserStringInput();

    comboToRemove.setName( comboNameToRemove );

    wclear( displayWindow );
    makeWindowBorders();

    if( orderToRemoveFrom.ifComboExists( comboToRemove ) )
    {
        comboToRemove = orderToRemoveFrom.getCombos().at( orderToRemoveFrom.searchForCombo( comboToRemove ) );
        mvwprintw( displayWindow, 8, 45, "That combo has been removed from the order" );
        orderToRemoveFrom.removeCombo( comboToRemove );
    }

    else
    {
        mvwprintw( displayWindow, 8, 45, "That combo is not in the order " );
    }

    wrefresh( displayWindow );
    getch();
}

void Terminal::displayOrder( Order orderToDisplay )
{
    wclear( sidePanelWindow );
    makeWindowBorders();

    int lineCounter = 0;

    if( orderToDisplay.getCombos().size() > 0 )
    {
        for( int i = 0; i < orderToDisplay.getCombos().size(); i++ )
        {
            outputString( sidePanelWindow, 2 + lineCounter, 1, orderToDisplay.getCombos().at(i).getName() );
            outputPrice( sidePanelWindow, 3 + lineCounter, 8, orderToDisplay.getCombos().at(i).getPrice() );
            lineCounter = lineCounter + 2;
        }
    }

    for( int i = 0; i < orderToDisplay.getFoods().size(); i++ )
    {
        outputString( sidePanelWindow, 2 + lineCounter, 1, orderToDisplay.getFoods().at(i).getName() );
        outputPrice( sidePanelWindow, 3 + lineCounter, 8, orderToDisplay.getFoods().at(i).getPrice() );
        lineCounter = lineCounter + 2;
    }

    mvwprintw( sidePanelWindow, 4 + lineCounter, 1, "SubTotal: " );
    outputPrice( sidePanelWindow, 4 + lineCounter, 16, orderToDisplay.getSubTotalCost() );
    mvwprintw( sidePanelWindow, 5 + lineCounter, 1, "Taxes: " );
    outputPrice( sidePanelWindow, 5 + lineCounter, 16, orderToDisplay.getTaxes() );
    mvwprintw( sidePanelWindow, 6 + lineCounter, 1, "Grand Total: " );
    outputPrice( sidePanelWindow, 6 + lineCounter, 16, orderToDisplay.getTotalCost() );

    wrefresh( sidePanelWindow );
}

bool Terminal::ifOrderActive( int orderNumberToFind )
{
    bool orderActive = false;

    for( int i = 0; i < activeOrders.size(); i++ )
    {
        if( activeOrders.at(i).getOrderNumber() == orderNumberToFind )
        {
            orderActive = true;
        }
    }

    return orderActive;
}

int Terminal::searchForActiveOrder( int orderNumberToFind )
{
    int orderIndex;

    for( int i = 0; i < activeOrders.size(); i++ )
    {
        if( activeOrders.at(i).getOrderNumber() == orderNumberToFind )
        {
            orderIndex = i;
        }
    }

    return orderIndex;
}

void Terminal::displayActiveOrders()
{
    wclear( displayWindow );
    makeWindowBorders();

    mvwprintw( displayWindow, 4, 51, "Current Active Orders " );
    mvwprintw( displayWindow, 6, 45, "Order #        |      Order Total" );
    mvwprintw( displayWindow, 7, 45, "---------------------------------" );

    for( int i = 0; i < activeOrders.size(); i++ )
    {
        outputInt( displayWindow, 8+i, 45, activeOrders.at(i).getOrderNumber() );
        outputPrice( displayWindow, 8+i, 73, activeOrders.at(i).getTotalCost() );
    }

    wrefresh( displayWindow );
}

void Terminal::viewActiveOrders()
{
    displayActiveOrders();

    mvwprintw( displayWindow, 25, 35, "Enter the number of the order you would like to view" );
    wrefresh( displayWindow );
    int orderNumberToView = getUserLongIntInput();

    if( ifOrderActive( orderNumberToView ) )
    {
        displayOrder( activeOrders.at( searchForActiveOrder( orderNumberToView) ) );
    }

    else
    {
        mvwprintw( displayWindow, 30, 45, "That Order is not active" );
    }

    wrefresh( displayWindow );
    getch();
    wclear( sidePanelWindow );
    makeWindowBorders();
}

void Terminal::completeOrder()
{
    wclear( displayWindow );
    makeWindowBorders();
    displayActiveOrders();

    mvwprintw( displayWindow, 25, 45, "Enter the order number to complete " );

    int orderNumberToComplete = getUserLongIntInput();

    wclear( displayWindow );
    makeWindowBorders();

    if( ifOrderActive( orderNumberToComplete ) )
    {
        activeOrders.erase( activeOrders.begin() + searchForActiveOrder( orderNumberToComplete ) );
        mvwprintw( displayWindow, 8, 45, "That order has been completed " );
    }

    else
    {
        mvwprintw( displayWindow, 8, 45, "That order is not an active order " );
    }

    wrefresh( displayWindow );
    getch();
}

///Time Clock
void Terminal::timeClockMenu()
{
    bool closeMenu = false;

    while( !closeMenu )
    {
        wclear( displayWindow );
        makeWindowBorders();

        mvwprintw( displayWindow, 2, 55, "Foods and Combos Menu" );

        mvwprintw( displayWindow, 5, 50, "Enter Your Selection:" );
        mvwprintw( displayWindow, 8, 45, "1 - Clock In ");
        mvwprintw( displayWindow, 9, 45, "2 - Clock Out " );
        mvwprintw( displayWindow, 10, 45, "9 - Return to Main Menu " );
        wrefresh( displayWindow );

        bool goodInput = false;
        int userInput;

        //Get input for menu choice
        while( !goodInput )
        {
            userInput = getUserIntInput();
            if( ( userInput > 0 && userInput < 3 ) || userInput == 9 )
            {
                goodInput = true;
            }
        }

        //Logic to select correct menu
        if( userInput == 1 )
        {
            clockIn();
        }

        else if( userInput == 2 )
        {
            clockOut();
        }

        else if ( userInput == 9 )
        {
            closeMenu = true;
        }
    }//Close menu loop
}

void Terminal::clockIn()
{
    wclear( displayWindow );
    makeWindowBorders();

    mvwprintw( displayWindow, 8, 45, "Enter your employee ID to clock in" );
    wrefresh( displayWindow );

    int employeeIDToLogIn = getUserLongIntInput();
    Employee* employeeToClockIn = NULL;

    wclear( displayWindow );
    makeWindowBorders();

    if( restaurantStaff.ifEmployed( employeeIDToLogIn ) )
    {
        employeeToClockIn = &restaurantStaff.getStaff().at( restaurantStaff.searchForEmployee( employeeIDToLogIn ) );
        employeeToClockIn -> clockIn();
        mvwprintw( displayWindow, 8, 45, "You have been clocked in." );
    }

    else
    {
        mvwprintw( displayWindow, 8, 45, "That employee ID does not match any current employee" );
    }

    wrefresh( displayWindow );
    getch();
}

void Terminal::clockOut()
{
    wclear( displayWindow );
    makeWindowBorders();

    mvwprintw( displayWindow, 8, 45, "Enter your employee ID to clock out" );
    wrefresh( displayWindow );

    int employeeIDToLogOut = getUserLongIntInput();
    Employee* employeeToClockOut = NULL;

    wclear( displayWindow );
    makeWindowBorders();

    if( restaurantStaff.ifEmployed( employeeIDToLogOut ) )
    {
        employeeToClockOut = &restaurantStaff.getStaff().at( restaurantStaff.searchForEmployee( employeeIDToLogOut ) );
        employeeToClockOut -> clockIn();
        mvwprintw( displayWindow, 8, 45, "You have been clocked out" );
    }

    else
    {
        mvwprintw( displayWindow, 8, 45, "That employee ID does not match any current employee" );
    }

    wrefresh( displayWindow );
    getch();
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
    foodToAdd.setFoodSize( foodSize );
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
        mvwprintw( displayWindow, 9, 45, "2 - Fire Employee " );
        mvwprintw( displayWindow, 10, 45, "3 - Hire Employee ");
        mvwprintw( displayWindow, 11, 45, "4 - View Employee Schedule " );
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
            fireEmployee();
        }

        else if( userInput == 3 )
        {
            hireEmployee();
        }

        else if( userInput == 4 )
        {
            viewEmployeeSchedule();
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
    showStaff();
    getch();
}

void Terminal::showStaff()
{
    wclear( displayWindow );
    makeWindowBorders();
    mvwprintw( displayWindow, 2, 35, "Employee Name      |    ID#    |   Position    |   Pay Rate");

    for( int i = 0; i < restaurantStaff.getStaff().size(); i++ )
    {
        ///Name
        outputString( displayWindow, i+3, 35, restaurantStaff.getStaff().at(i).getName() );

        ///ID#
        outputInt( displayWindow, i+3, 57, restaurantStaff.getStaff().at(i).getID() );

        ///Position
        std::stringstream positionSS;
        positionSS << restaurantStaff.getStaff().at(i).getPosition() << " - " << restaurantStaff.getStaff().at(i).getPositionTitle();
        std::string position = positionSS.str();
        for( int j = 0; j < position.size(); j++ )
        {
            mvwaddch( displayWindow, i+3, j+68, position.at(j) );
        }

        ///Pay Rate
        outputPrice( displayWindow, i+3, 87, restaurantStaff.getStaff().at(i).getHourlyPayRate() );
    }

    wrefresh( displayWindow );
}

void Terminal::fireEmployee()
{
    wclear( displayWindow );
    makeWindowBorders();
    showStaff();

    mvwprintw( displayWindow, 25, 45, "Enter the name of the employee to fire" );
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

    showStaff();
    mvwprintw( displayWindow, 20, 45, "Enter the name of the employee to examine" );
    wrefresh( displayWindow );

    std::string employeeName = getUserStringInput();
    Employee employeeToExamine;
    employeeToExamine.setName( employeeName );

    wclear( displayWindow );
    makeWindowBorders();

    if( restaurantStaff.ifEmployed( employeeToExamine ) )
    {//std::cout << "Employee is employed" << std::endl;
        employeeToExamine = restaurantStaff.getStaff().at( restaurantStaff.searchForEmployee( employeeToExamine ) );
        //std::cout << "Got the employee" << std::endl;

        outputString( displayWindow, 4, 52, employeeName );
        mvwprintw( displayWindow, 4, 52+employeeName.size(), "'s Schedule" );

        ///Scheduled
        mvwprintw( displayWindow, 6, 31, "Work Week 1                    |               Work Week 2" );
        for( int i = 0; i < employeeToExamine.getEmployeeSchedule().getWorkWeekOne().size(); i++ )
        {//std::cout << "Getting into loop iteration " << i << std::endl;
            std::string week1WorkDayToPrint = employeeToExamine.getEmployeeSchedule().getWorkWeekOne().at(i).getDate().toString();
            std::string week1ScheduleToPrint = " - " + employeeToExamine.getEmployeeSchedule().getWorkWeekOne().at(i).getScheduledStartTime().toString() +
                                               " - " + employeeToExamine.getEmployeeSchedule().getWorkWeekOne().at(i).getScheduledEndTime().toString();
            outputString( displayWindow, 7+i, 18, week1WorkDayToPrint );
            outputString( displayWindow, 7+i, 39, week1ScheduleToPrint );

            std::string week2WorkDayToPrint = employeeToExamine.getEmployeeSchedule().getWorkWeekTwo().at(i).getDate().toString();
            std::string week2ScheduleToPrint = " - " + employeeToExamine.getEmployeeSchedule().getWorkWeekTwo().at(i).getScheduledStartTime().toString() +
                                               " - " + employeeToExamine.getEmployeeSchedule().getWorkWeekTwo().at(i).getScheduledEndTime().toString();
            outputString( displayWindow, 7+i, 65, week2WorkDayToPrint );
            outputString( displayWindow, 7+i, 86, week2ScheduleToPrint );
        }
        mvwprintw( displayWindow, 16, 31, "Hours Scheduled:                              Hours Scheduled: " );
        outputInt( displayWindow, 16, 51, employeeToExamine.getEmployeeSchedule().getWeekOneScheduledHours() );
        outputInt( displayWindow, 16, 97, employeeToExamine.getEmployeeSchedule().getWeekTwoScheduledHours() );

        ///Worked
        mvwprintw( displayWindow, 19, 31, "Work Week 1                    |               Work Week 2" );
        for( int i = 0; i < employeeToExamine.getEmployeeSchedule().getWorkWeekOne().size(); i++ )
        {//std::cout << "Getting into loop iteration " << i << std::endl;
            std::string week1WorkDayToPrint = employeeToExamine.getEmployeeSchedule().getWorkWeekOne().at(i).getDate().toString();
            std::string week1ScheduleToPrint = " - " + employeeToExamine.getEmployeeSchedule().getWorkWeekOne().at(i).getClockInTime().toString() +
                                               " - " + employeeToExamine.getEmployeeSchedule().getWorkWeekOne().at(i).getClockOutTime().toString();
            outputString( displayWindow, 20+i, 18, week1WorkDayToPrint );
            outputString( displayWindow, 20+i, 39, week1ScheduleToPrint );

            std::string week2WorkDayToPrint = employeeToExamine.getEmployeeSchedule().getWorkWeekTwo().at(i).getDate().toString();
            std::string week2ScheduleToPrint = " - " + employeeToExamine.getEmployeeSchedule().getWorkWeekTwo().at(i).getClockInTime().toString() +
                                               " - " + employeeToExamine.getEmployeeSchedule().getWorkWeekTwo().at(i).getClockOutTime().toString();
            outputString( displayWindow, 20+i, 65, week2WorkDayToPrint );
            outputString( displayWindow, 20+i, 86, week2ScheduleToPrint );
        }
        mvwprintw( displayWindow, 29, 31, "Hours Worked:                                  Hours Worked: " );
        outputInt( displayWindow, 29, 51, employeeToExamine.getEmployeeSchedule().getWeekOneWorkedHours() );
        outputInt( displayWindow, 29, 97, employeeToExamine.getEmployeeSchedule().getWeekTwoWorkedHours() );
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
        mvwprintw( displayWindow, 9, 45, "2 - Increase Budget " );
        mvwprintw( displayWindow, 10, 45, "3 - Decrease Budget " );
        mvwprintw( displayWindow, 11, 45, "4 - Generate Employee Pay Check " );
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
            viewBudget();
        }

        else if( userInput == 2 )
        {
            increaseBudget();
        }

        else if( userInput == 3 )
        {
            decreaseBudget();
        }

        else if( userInput == 4 )
        {
            createCheck();
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
    wclear( displayWindow );
    makeWindowBorders();

    mvwprintw( displayWindow, 8, 45, "How much is the budget increasing by? " );
    mvwprintw( displayWindow, 9, 45, "Enter in $xxx.xx form(without $ )" );
    wrefresh( displayWindow );

    float increaseInBudget = getUserFloatInput();

    mvwprintw( displayWindow, 15, 45, "The budget has been increased" );
    wrefresh( displayWindow );
    restaurantPayRoll.increaseBudget( increaseInBudget );
    getch();
}

void Terminal::decreaseBudget()
{
    wclear( displayWindow );
    makeWindowBorders();

    mvwprintw( displayWindow, 8, 45, "How much is the budget decreasing by? " );
    mvwprintw( displayWindow, 9, 45, "Enter in $xxx.xx form(without $ )" );
    wrefresh( displayWindow );

    float decreaseInBudget = getUserFloatInput();

    mvwprintw( displayWindow, 15, 45, "The budget has been decreased" );
    wrefresh( displayWindow );
    restaurantPayRoll.decreaseBudget( decreaseInBudget );
    getch();
}

void Terminal::createCheck()
{
    wclear( displayWindow );
    makeWindowBorders();

    showStaff();
    mvwprintw( displayWindow, 25, 35, "Enter the Employee ID of the employee to make the check for " );
    wrefresh( displayWindow );

    int employeeIDToPay = getUserLongIntInput();
    Employee* employeeToPay = NULL;
    Check* employeeCheck = NULL;

    wclear( displayWindow );
    makeWindowBorders();

    if( restaurantStaff.ifEmployed( employeeIDToPay ) )
    {
        employeeToPay = &restaurantStaff.getStaff().at( restaurantStaff.searchForEmployee( employeeIDToPay ) );
        employeeToPay -> setLastCheck( restaurantPayRoll.createCheck( restaurantStaff.getStaff().at( restaurantStaff.searchForEmployee( employeeIDToPay ) ) ) );
        displayCheck( employeeToPay -> getLastCheck() );
        restaurantPayRoll.deductCheckFromBudget( employeeToPay -> getLastCheck() );
    }

    else
    {
        mvwprintw( displayWindow, 8, 45, "That Employee ID does not match a current employee " );
    }

    wrefresh( displayWindow );
    getch();
}

void Terminal::displayCheck( Check checkToDisplay )
{
    wclear( displayWindow );
    makeWindowBorders();

    mvwprintw( displayWindow, 5, 45, "Check Number: ");
    mvwprintw( displayWindow, 6, 45, "Gross Pay: " );
    mvwprintw( displayWindow, 7, 45, "State Taxes Withheld: " );
    mvwprintw( displayWindow, 8, 45, "Federal Taxes Withheld: " );
    mvwprintw( displayWindow, 9, 45, "Social Security Withheld: ");
    mvwprintw( displayWindow, 10, 45, "Medicare Withheld: " );
    mvwprintw( displayWindow, 11, 45, "Net Pay: " );

    outputInt( displayWindow, 5, 72, checkToDisplay.getCheckNumber() );
    outputPrice( displayWindow, 6, 72, checkToDisplay.getGrossIncome() );
    outputPrice( displayWindow, 7, 72, checkToDisplay.getStateTaxesWitheld() );
    outputPrice( displayWindow, 8, 72, checkToDisplay.getFederalTaxesWitheld() );
    outputPrice( displayWindow, 9, 72, checkToDisplay.getSocialSecurityWitheld() );
    outputPrice( displayWindow, 10, 72, checkToDisplay.getMedicareWitheld() );
    outputPrice( displayWindow, 11, 72, checkToDisplay.getNetIncome() );

    wrefresh( displayWindow );
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

bool Terminal::verifyManager()
{
    wclear( displayWindow );
    makeWindowBorders();

    mvwprintw( displayWindow, 8, 45, "Enter your Employee ID Number" );
    wrefresh( displayWindow );

    bool managerOrNot = false;
    int managerID = getUserLongIntInput();

    wclear( displayWindow );
    makeWindowBorders();

    if( restaurantStaff.ifEmployed( managerID ) )
    {
        if( restaurantStaff.getStaff().at( restaurantStaff.searchForEmployee( managerID ) ).getPosition() >= 3 )
        {
            mvwprintw( displayWindow, 8, 45, "Access Granted" );
            managerOrNot = true;
        }

        else
        {
            mvwprintw( displayWindow, 8, 45, "Access Denied" );
            managerOrNot = false;
        }
    }

    else
    {
        mvwprintw( displayWindow, 8, 45, "That is not a valid Employee ID " );
    }

    wrefresh( displayWindow );
    getch();

    return managerOrNot;
}

///Functions for Output
void Terminal::outputString( WINDOW* window, int startY, int startX, std::string stringToOutput )
{
    for( int i = 0; i < stringToOutput.size(); i++ )
    {
        mvwaddch( window, startY, startX+i, stringToOutput.at(i) );
    }
}

void Terminal::outputPrice( WINDOW* window, int startY, int startX, float priceToOutput )
{
    std::stringstream priceSS;
    priceSS << priceToOutput;
    std::string price = priceSS.str();

    bool decimalExists = false;
    int decimalIndex;
    for( int i = 0; i < price.size(); i++ )
    {
        if( price.at(i) == '.' )
        {
            decimalExists = true;
            decimalIndex = i;
        }
    }

    if( priceToOutput == 0 )
    {
        price = "0.00";
    }

    else if( !decimalExists )
    {
        price = price + ".00";
    }

    else if( price.at( price.size() - 2 ) == '.' )
    {
        price = price + "0";
    }

    mvwaddch( window, startY, startX, '$' );
    outputString( window, startY, startX+1, price );
}

void Terminal::outputInt( WINDOW* window, int startY, int startX, int intToOutput )
{
    std::stringstream intSS;
    intSS << intToOutput;
    std::string intString = intSS.str();

    outputString( window, startY, startX, intString );
}
