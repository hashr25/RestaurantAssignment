#include "Ingredient.h"

///Constructors and Destructors
Ingredient::Ingredient():
    name("Test"), quantity(0), costPerUnit(0.0), unitOfMeasurement("unit(s)")
{
    ///Variables set in init list.
}

Ingredient::Ingredient( std::string newName, int newQuantity, float newCostPerUnit, std::string newUnitOfMeasurement ):
    name(newName), quantity(newQuantity), costPerUnit(newCostPerUnit), unitOfMeasurement(newUnitOfMeasurement)
{
    ///Variables set in init list.
}

Ingredient::~Ingredient()
{
    ///Nothing to deallocate at this moment
}


///Getters and Setters
std::string Ingredient::getName()
{
    return name;
}

int Ingredient::getQuantity()
{
    return quantity;
}

float Ingredient::getCostPerUnit()
{
    return costPerUnit;
}

std::string Ingredient::getUnitOfMeasurement()
{
    return unitOfMeasurement;
}

float Ingredient::getCostOfStock()
{
    return quantity * costPerUnit;
}

void Ingredient::setName( std::string name )
{
    this -> name = name;
}

void Ingredient::setQuantity( int quantity )
{
    if( quantity < 0 )
    {
        this -> quantity = 0;
    }

    else
    {
        this -> quantity = quantity;
    }
}

void Ingredient::setCostPerUnit( float costPerUnit )
{
    this -> costPerUnit = costPerUnit;
}

void Ingredient::setUnitOfMeasurement( std::string unitOfMeasurement )
{
    this -> unitOfMeasurement = unitOfMeasurement;
}


///Member Methods
void Ingredient::addUnits( int quantityToAdd )
{
    setQuantity( getQuantity() + quantityToAdd );
}

void Ingredient::removeUnits( int quantityToRemove )
{
///     WARNING         ///
/// THIS METHOD DOES   ///
/// NOT CHECK IF IT   ///
/// IS TAKING MORE   ///
/// THAN WHAT IS IN ///
///     STOCK      ///
/// IT WILL SET   ///
/// QUANTITY TO  ///
///____ZERO_____///
///   WARNING  ///
    setQuantity( getQuantity() - quantityToRemove );
}

void Ingredient::printIngredient()
{
    std::cout << "Name:            " << name << std::endl;
    std::cout << "Quantity:        " << quantity << " " << unitOfMeasurement << std::endl;
    std::cout << "Cost per Unit:  $" << costPerUnit << std::endl;
    std::cout << "Cost of Stock:  $" << getCostOfStock() << "\n" << std::endl;
}

Ingredient Ingredient::operator = ( const Ingredient& newIngredient )
{
    name = newIngredient.name;
    quantity = newIngredient.quantity;
    costPerUnit = newIngredient.costPerUnit;
    unitOfMeasurement = newIngredient.unitOfMeasurement;

    return *this;
}
