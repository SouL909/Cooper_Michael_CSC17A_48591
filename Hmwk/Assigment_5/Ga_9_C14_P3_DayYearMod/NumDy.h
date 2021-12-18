/* 
 * File:   NumDy.h
 * Author: michaelcooper
 *
 * Created on November 20, 2021, 10:23 PM
 */

#ifndef NUMDY_H
#define NUMDY_H
#include <iostream> 
#include <math.h>

using namespace std;  //STD Name-space where Library is compiled

class NumDays
{
private:
    double hours, days;
    void calcDays();
public:
    // Constructors
    NumDays();
    NumDays(double);
    // Mutator Functions
    void setHours(double);

    // Accessor Functions
    double getHours();
    double getDays();

    // Overloaded operator functions
    NumDays operator + (const NumDays &);   // Overloaded +
    NumDays operator - (const NumDays &);   // Overloaded -
    NumDays operator ++ ();                 // Overloaded Prefix ++
    NumDays operator ++ (int);              // Overloaded Postfix ++
    NumDays operator -- ();                 // Overloaded Prefix --
    NumDays operator -- (int);              // Overloaded Postfix --
};

#endif /* NUMDY_H */

