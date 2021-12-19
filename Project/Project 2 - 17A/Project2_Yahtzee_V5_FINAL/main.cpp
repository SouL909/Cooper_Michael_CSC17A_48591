/*
 * File:   main.cpp
 * Author: michaelcooper
 * Created on December 17, 2021, 9:00 AM
 * Project 2: Yahtzee V5 FINAL BUILD
 * Included missing requirements into the header files.
 */

#include <cstdlib>
#include "Yahtzee.h"
using namespace std;

int main(int, char**) {
    Yahtzee yhtz;   
    //Creating an instance of yahtzee class from the .h file
    yhtz.play();    
    //Starts the game
    return 0;
}

