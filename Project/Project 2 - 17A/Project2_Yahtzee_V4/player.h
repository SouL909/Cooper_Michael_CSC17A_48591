/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <array>
#include <string>
#include <ostream>

class Player {
    std::array<int, 5> rolls;
    std::string name;
public:
    Player();                   // Default Constructor
    Player(std::string name);
    Player(Player& player);     // Copy Constructor

    void setName(std::string name);     // Setters
    void setRoll(int nth, int roll);    // -------

    std::string getName() const;        // Getters
    int getRoll(int nth) const;         // -------

    friend std::ostream& operator<<(std::ostream& os, const Player& player);
};


/*
    strmlst - takes in a list that is supposed to be an
    STL sequence container of some type that supports
    the operator <<
*/
template<class T>
inline std::ostream& strmlst(std::ostream& os, const T& list) {
    for(auto el : list) {   // For each loop
        os << el << " ";    // outputs its contents to the ostream
    }
    return os;    
}

// Will print out the Player's name and rolls
inline std::ostream& operator<<(std::ostream& os, const Player& player) {
    os << player.getName() << "'s rolls: ";
    strmlst(os, player.rolls);
    return os;
}

#endif
