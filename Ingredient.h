#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <string>
#include <iostream>

class Ingredient
{
public:
    ///Constructors and Destructors
    Ingredient();
    Ingredient( std::string, int, float, std::string );
    ~Ingredient();

    ///Getters and Setters
    std::string getName();
    int getQuantity();
    float getCostPerUnit();
    std::string getUnitOfMeasurement();
    float getCostOfStock();

    void setName( std::string );
    void setQuantity( int );
    void setCostPerUnit( float );
    void setUnitOfMeasurement( std::string );

    ///Member Methods
    void addUnits( int );
    void removeUnits( int );
    void printIngredient();

    Ingredient operator = ( const Ingredient& );

private:
    std::string name;
    int quantity;
    float costPerUnit;
    std::string unitOfMeasurement;
};

#endif // INGREDIENT_H
