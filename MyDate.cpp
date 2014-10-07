#include "MyDate.h"

///Constructors and destructors
MyDate::MyDate()
{
    year = 1;
    month = 1;
    day = 1;
}

MyDate::MyDate( int newYear, int newMonth, int newDay )
{
    setDate( newYear, newMonth, newDay );
}

MyDate::~MyDate()
{
    //Nothing to deallocate
}

///Public Methods
bool MyDate::isLeapYear( int yearNum )
{
    bool success = false;

    if( yearNum % 4 == 0 )
    {
        success = true;
    }

    return success;
}

bool MyDate::isValidDate( int yearNum, int monthNum, int dayNum )
{
    bool success = true;

    if( yearNum < 1 || yearNum > 9999 )
    {
        success = false;
    }

    if( monthNum < 1 || monthNum > 12 )
    {
        success = false;
    }

    int daysThisMonth = daysInMonth[ monthNum ];
    if( isLeapYear( yearNum ) )
    {
        daysThisMonth++;
    }

    if( dayNum < 1 || dayNum > daysThisMonth )
    {
        success = false;
    }

    return success; std::cout << "Valid Day: " << success << std::endl;
}

int MyDate::getDayOfWeek( int yearNum, int monthNum, int dayNum )
{
    //This function is derived from the function written for the first assignment is CS202
    int dayOfWeek;

    int yearCalc = yearNum - ( 14 - monthNum ) / 12;
    int x = yearCalc + ( yearCalc / 4 ) - ( yearCalc / 100 ) + ( yearCalc / 400 );

    int monthCalc = ( monthNum + 12 * ( ( 14 - monthNum ) / 12) - 2 );
    dayOfWeek = ( ( dayNum + x + ( 31 * monthCalc ) / 12 ) % 7 ) + 1;

    return dayOfWeek;
}

MyDate MyDate::getCurrentDate()
{
    MyDate currentDate;
    int currentMonth;
    int currentDay;
    int currentYear;

    time_t rawTime;
    time( &rawTime );
    std::string timeInString = ctime( &rawTime );

    if( timeInString.substr( 4, 3 ) == "Jan" )
    {
        currentMonth = 1;
    }
    else if( timeInString.substr( 4, 3 ) == "Feb" )
    {
        currentMonth = 2;
    }
    else if( timeInString.substr( 4, 3 ) == "Mar" )
    {
        currentMonth = 3;
    }
    else if( timeInString.substr( 4, 3 ) == "Apr" )
    {
        currentMonth = 4;
    }
    else if( timeInString.substr( 4, 3 ) == "May" )
    {
        currentMonth = 5;
    }
    else if( timeInString.substr( 4, 3 ) == "Jun" )
    {
        currentMonth = 6;
    }
    else if( timeInString.substr( 4, 3 ) == "Jul" )
    {
        currentMonth = 7;
    }
    else if( timeInString.substr( 4, 3 ) == "Aug" )
    {
        currentMonth = 8;
    }
    else if( timeInString.substr( 4, 3 ) == "Sep" )
    {
        currentMonth = 9;
    }
    else if( timeInString.substr( 4, 3 ) == "Oct" )
    {
        currentMonth = 10;
    }
    else if( timeInString.substr( 4, 3 ) == "Nov" )
    {
        currentMonth = 11;
    }
    else if( timeInString.substr( 4, 3 ) == "Dec" )
    {
        currentMonth = 12;
    }


    std::istringstream( timeInString.substr( 8, 2 ) ) >> currentDay;
    std::istringstream( timeInString.substr( 20, 4 ) ) >> currentYear;

    currentDate.setMonth( currentMonth );
    currentDate.setDay( currentDay );
    currentDate.setYear( currentYear );

    return currentDate;
}

///Getters and Setters
void MyDate::setDate( int newYear, int newMonth, int newDay )
{
    setYear( newYear );
    setMonth( newMonth );
    setDay( newDay );
}

void MyDate::setYear( int newYear )
{
    if( newYear > 0 && newYear < 10000 )
    {
        year = newYear;
    }
}

void MyDate::setMonth( int newMonth )
{
    if( newMonth > 0 && newMonth < 13 )
    {
        month = newMonth;
    }
}

void MyDate::setDay( int newDay )
{
    int daysThisMonth = daysInMonth[month];

    if( isLeapYear( year ) )
    {
        daysThisMonth++;
    }

    if( newDay <= daysThisMonth && newDay > 0 )
    {
        day = newDay;
    }
}

int MyDate::getYear()
{
    return year;
}

int MyDate::getMonth()
{
    return month;
}

int MyDate::getDay()
{
    return day;
}

///Transform Methods
std::string MyDate::toString()
{
    std::string tempString;
    std::stringstream ss1;
    std::stringstream ss2;

    ss1 << " " << day << " ";
    ss2 << " " << year;

    tempString.append( strDays[ getDayOfWeek( year, month, day ) ] );
    tempString.append( ss1.str() );
    tempString.append( strMonths[ month ] );
    tempString.append( ss2.str() );

    return tempString;
}

void MyDate::nextYear()
{
    int newYear = year + 1;
    setYear( newYear );
}

void MyDate::nextMonth()
{
    int newMonth = ((month + 1) % 12);

    int daysInNextMonth = daysInMonth[ newMonth ];
    if( day > daysInNextMonth )
    {
        if( isLeapYear( year ) )
        {
            daysInNextMonth++;
        }
        setDay( daysInNextMonth );
    }

    if( newMonth == 1)
    {
        nextYear();
    }

    setMonth( newMonth );
}

void MyDate::nextDay()
{
    int daysThisMonth = daysInMonth[ month ];
    if( isLeapYear( year ) )
    {
        daysThisMonth++;
    }

    int newDay = day + 1;
    if( newDay > daysThisMonth )
    {
        newDay = 1;
        nextMonth();
    }

    setDay( newDay );
}

void MyDate::previousYear()
{
    int newYear = year - 1;
    setYear( newYear );
}

void MyDate::previousMonth()
{
    int newMonth = month - 1;
    if( newMonth == 0 )
    {
        newMonth = 12;
        previousYear();
    }

    setMonth( newMonth );
}

void MyDate::previousDay()
{
    int newDay = day - 1;
    if( newDay == 0 )
    {
        previousMonth();

        int daysThisMonth = daysInMonth[ month ];
        if( isLeapYear( year ) )
        {
            daysThisMonth++;
        }

        newDay = daysThisMonth;
    }

    setDay( newDay );
}

MyDate MyDate::operator = ( const MyDate& newDate )
{
    year = newDate.year;
    month = newDate.month;
    day = newDate.day;

    return *this;
}
