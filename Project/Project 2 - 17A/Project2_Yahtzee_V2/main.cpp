/*
 * File:   main.cpp
 * Author: michaelcooper
 * Created on December 7, 2021, 12:30 PM
 * Project 2: Yahtzee V2
 * Making basic outline for project and identifying new changes
 * Included Class outline with public and private functions. 
 * Still need to reconstruct player header file for player info. until then build does not run.
 */

#include <cstdlib>
#include "Yahtzee.h"
using namespace std;

//I want to make the main as short as possible to fully utilize the other sections 
//and apply as many requirements. Included the main turn functions of the game to start with
//still need to tweak and include other files, so this version does not run.

int main(int, char**) {
    Yahtzee yhtz;
    yhtz.play();
    return 0;
}
