/*
 * Class outline, still need player header file
 */

/* 
 * File:   Yahtzee.h
 * Author: michaelcooper
 *
 * Created on December 13, 2021, 11:07 PM
 */

#ifndef YAHTZEE_H
#define YAHTZEE_H

#include "player.h"
#include <vector>

class Yahtzee {
    const static int MAX_ROUNDS = 13;
    int sve_cnt = 0;
    int round;
    std::vector<Player*> players;
    Player * last_player;
    std::array<int, MAX_ROUNDS> scores;
    bool done;
public:
    Yahtzee();  // Default Constructor
    ~Yahtzee(); // Deconstructor
    void play();
private:
    void print_rules();
    bool load();
    void setup_players();
    int player_turn(int index);
    void readyup();
    void save_game();
    void print_scores();
    bool two_of_a_kind(int rolCts[], int Size, int &index);

};

#endif
