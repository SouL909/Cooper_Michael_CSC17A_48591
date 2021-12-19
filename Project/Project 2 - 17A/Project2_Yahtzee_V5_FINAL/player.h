#ifndef PLAYER_H
#define PLAYER_H

#include <array>
#include <string>
#include <ostream>

// Abstract player 
// class responsible
// for keeping track 
// of the player data
// in relation to the 
// yahtzee game
class Player 
{
protected:
    std::array<int, 5> rolls;
    std::string name;
public:
    Player();       
                // Default Constructor
    Player(std::string name);

    Player(Player& player);     // Copy Constructor

    void setName(std::string name);     // Setters

    void setRoll(int nth, int roll);    // -------

    std::string getName() const;        // Getters

    int getRoll(int nth) const;         // -------

    virtual char get_input() = 0;

    friend std::ostream& operator<<(std::ostream& os, const Player& player);
    int operator[](int index);
    void operator=( const Player& player);
};

// The ComputerPlayer
// is made when
// a user inputs
// a name with the
// '_' at the start
// of their name
class ComputerPlayer : public Player 
{
public:
    ComputerPlayer();

    ComputerPlayer(std::string name);

    ComputerPlayer(ComputerPlayer& player);

    char get_input();  
};

// HumanPlayers are the default
// Player when creating a player
class HumanPlayer : public Player 
{
public:
    HumanPlayer();

    HumanPlayer(std::string name);

    HumanPlayer(ComputerPlayer& player);

    char get_input();  
};


/*
    strmlst - takes in a list 
    that is supposed to be an
    STL sequence container of 
    some type that supports
    the operator <<
*/
template<class T>
inline std::ostream& strmlst(std::ostream& os, const T& list) 
{
    for(auto el : list) 
    {   
        // For each loop
        os << el << " ";    
        // outputs its contents to the ostream
    }
    return os;    
}

// Will print out the Player's name and rolls
inline std::ostream& operator<<(std::ostream& os, const Player& player) 
{
    os << player.getName() << "'s rolls: ";
    
    strmlst(os, player.rolls);
    return os;
}

inline int Player::operator[](int index) {
    return getRoll(index);
}

inline void Player::operator=( const Player& player) {
    this->name = player.name;
    this->rolls = player.rolls;
}
#endif
