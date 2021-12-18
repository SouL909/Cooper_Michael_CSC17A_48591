// Implementation file for the NumDays class

#include "NumDy.h"

// Recalculation function
void NumDays::calcDays()
{
    days = hours / 8;
}

// Default Constructor
NumDays::NumDays()
{
    hours = 0;
    days = 0;
}

// Constructor 1
NumDays::NumDays(double h)
{
    hours = h;         
    days = hours * 1 / 8;   
}

// Mutatory Functions
void NumDays::setHours(double h)
{
    hours = h;
}

// Accessor Functions
double NumDays::getHours()
{
    return hours;
}

double NumDays::getDays()
{
    NumDays::calcDays();
    return days;
}

// Overloaded operator functions
NumDays NumDays::operator + (const NumDays &a)
{
    NumDays temp;
    temp.hours = this->hours + a.hours;
return temp;
}

NumDays NumDays::operator - (const NumDays &a)
{
    NumDays temp;
    temp.hours = this->hours + a.hours;
    return temp;
}

NumDays NumDays::operator ++ ()
{
    ++hours;
    calcDays();
    return *this;
}

NumDays NumDays::operator -- ()
{
    --hours;
    calcDays();
    return *this;
}

NumDays NumDays::operator ++ (int)
{
    NumDays temp(*this);
    ++hours;
    return temp;
}

NumDays NumDays::operator -- (int)
{
    hours--;
    calcDays();
    return *this;
}
