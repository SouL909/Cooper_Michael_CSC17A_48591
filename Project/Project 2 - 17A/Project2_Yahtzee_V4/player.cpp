/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "player.h"
#include <exception>
#include <string>

using namespace std;

Player::Player() {}

Player::Player(string name) : name(name) {}

Player::Player(Player& player) {
    this->name = player.name;
    this->rolls = player.rolls;
}

// sets the name to the given name
void Player::setName(string name) { this->name = name; }
// sets the corresponding index to the given value
void Player::setRoll(int nth, int roll) { 
    // if nth is greater than the size of rolls then throw an out of range excepetion
    if (nth >= 5) {
        throw out_of_range("Domain of Roll is 1-5: received " + to_string(nth) + ".");
    } else {
        this->rolls[nth] = roll;
    }
}

// returns a copy of the name
string Player::getName() const { return this->name; }
// returns a value from the given index if possible
int Player::getRoll(int nth) const {
    // if nth is greater than the size of rolls then throw an out of range exception
    if (nth >= 5) {
        throw out_of_range("Domain of Roll is 1-5: received " + to_string(nth) + ".");
        return -1;
    } else {
        return this->rolls[nth];
    }
}
