/*
 * File:   main.cpp
 * Author: michaelcooper
 * Created on December 13, 2021, 6:00 PM
 * Project 2: Yahtzee V4
 * finished implementing the player and yahtzee header and source files
 * still need to incorporate missing requirements
 */

#include <cstdlib>
#include "Yahtzee.h"
using namespace std;

int main(int, char**) {
    Yahtzee yhtz;   //Creating an instance of yahtzee class from the .h file
    yhtz.play();    //yhtz calls the method play
    return 0;
}


