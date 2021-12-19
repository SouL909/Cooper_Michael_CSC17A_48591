/*
 * File:   player.cpp
 * Author: michaelcooper
 * Created on December 16, 2021, 6:00 PM
 * Project 2: Yahtzee V5
 */

#include "player.h"
#include <exception>
#include <string>
#include <iostream>

using namespace std;

Player::Player() 
{

}

Player::Player(string name) : name(name) 
{
    
}

Player::Player(Player& player) {
    this->name = player.name;
    this->rolls = player.rolls;
}

// sets the name to the given name
void Player::setName(string name) 
{ 
    this->name = name; 
}
// sets the corresponding index to the given value
void Player::setRoll(int nth, int roll) 
{ 
    // if nth is greater than the size of rolls then throw an out of range excepetion
    if (nth >= 5) 
    {
        throw out_of_range("Domain of Roll is 1-5: received " + to_string(nth) + ".");
    } else 
    {
        this->rolls[nth] = roll;
    }
}

// returns a copy of the name
string Player::getName() const 
{ 
    return this->name; 
}
// returns a value from the given index if possible
int Player::getRoll(int nth) const 
{
    // if nth is greater than the size of rolls then throw an out of range excepetion
    if (nth >= 5) 
    {
        throw out_of_range("Domain of Roll is 1-5: received " + to_string(nth) + ".");
        return -1;
    } else 
    {
        return this->rolls[nth];
    }
}

ComputerPlayer::ComputerPlayer() 
{

}

ComputerPlayer::ComputerPlayer(string name) 
: Player(name) 
{

}

ComputerPlayer::ComputerPlayer(ComputerPlayer& player)
 : Player(player) 
 {

 }

// For simplicity sake computers should only
// enter 's' and not reroll 
char ComputerPlayer::get_input() 
{ 
    return 's'; 
}    
                                    
HumanPlayer::HumanPlayer() 
{

}

HumanPlayer::HumanPlayer(string name) : Player(name) 
{

}

HumanPlayer::HumanPlayer(ComputerPlayer& player) : Player(player) 
{

}

// Reads player's input and validates
// player's input 
// if the users input is not
// an 's' or an 'r'
// if the user inputs any other response
// then the function 
// will ask the user for
// input again
char HumanPlayer::get_input() 
{
    char ans;
    do 
    {
        cout << "Do you want to (S)top, or choose dice to hold and (R)oll again? [S or R]:";
        cin >> ans;
    } 
    while(ans != 's' 
    || ans != 'S'           
    && ans != 'R' 
    || ans != 'r');
    return ans;
}
