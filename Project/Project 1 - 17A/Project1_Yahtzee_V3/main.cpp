/*
    Author: Michael Cooper
    Date:   Nov 9, 2021
    Purpose: 17A Project 1 - Yahtzee
    Version: 3 - Took out everything from main and began the long process of 
    reworking them into the functions. This build does not run yet.
 */

/*
Official Rules for Yahtzee can be found here:
https://www.hasbro.com/common/instruct/Yahtzee.pdf
*/

//System Libraries
#include <iostream>    //Input/Output Library
#include <iomanip>     //I/O manipulation Library
#include <ctime>       //For rand
#include <cmath>       //find max
#include <cstdlib>     
#include <string>      //Can use for tutorial and dialogue options
#include <fstream>     //For input output files
#include <vector>

using namespace std;            //Library Name-space
//Global/Universal Constants -- No Global Variables
const int MAX_PLAYERS = 4;
const int MAX_NUMBER_ROUNDS = 13;
const char FILE_DIR[] = "yahtzee.txt";
//User Libraries
struct Player {
    int* rolls = new int[5];
    string name;
};

enum DiceFace { ONE = 1, TWO, THREE, FOUR, FIVE, SIX, };

struct Yahtzee {
    int current_round = 0;
    int scores[MAX_NUMBER_ROUNDS];
    bool done = false;
    int player_count;
    int round;
    Player* players;
    Yahtzee();
};

//Science, Math, Conversions, Higher Dimensioned constants only

//Function Prototypes
void print_rules(Yahtzee* Yahtzee);
void print_intro(Yahtzee* Yahtzee);
void play(Yahtzee* Yahtzee);
bool load(Yahtzee* Yahtzee);
void setup_players(Yahtzee* Yahtzee);
void readyup(Yahtzee* Yahtzee);
int player_turn(Yahtzee* Yahtzee, Player* player);
void print_scores(Yahtzee* Yahtzee);
void save_game(Yahtzee* Yahtzee);

bool two_of_a_kind(int rolCts[], int Size, int &index);
void SortScr( Player* players, int Scores[], int player_count );
float CalcAvg( int Scores[], int NumPlrs );

//Execution Begins Here
int main(int argc, char** argv) {
    //Set the Random number seed
    srand( time(0) );
    
    //Declare variables
    Yahtzee game = Yahtzee();
    play(&game);
    return 0; 
}
    void play(Yahtzee* Yahtzee) {
    print_rules(Yahtzee);

    string user_input = "";
    cout<<"Press 'e' to exit, or any other key to start the game!"<<endl;
    cin>>user_input;

    if (toupper(user_input.c_str()[0]) == 'E') {
        return;
    }

    bool game_load = load(Yahtzee);

    if(!game_load || Yahtzee->round > MAX_NUMBER_ROUNDS) {
        setup_players(Yahtzee);
    }

    readyup(Yahtzee);

    do {  //For multiple rounds, start over here.
        //Loop through each player.
        for( int pl_indx = 0; pl_indx < Yahtzee->player_count; pl_indx++ ) {
            //TODO
            Yahtzee->scores[pl_indx] += player_turn( Yahtzee, &(Yahtzee->players[pl_indx]) );
        } //End of loop through players


      //Ask if player wants to continue
      if( Yahtzee->round < MAX_NUMBER_ROUNDS ) {
        cout << "Do you want to play another round? (Y or N): " << endl;

        //Remember to validate user choice.
        char choice;
        cin >> choice;
        choice = toupper( choice );
        if( choice == 'N' ) {
           //Save game.
           cout << "Saving game for next time!" << endl;
           save_game(Yahtzee);

           Yahtzee->done = true;
        }
        else {
          cout << "Save the game anyways? (Y or N): " << endl;

          char choice;
          cin >> choice;
          choice = toupper( choice );
          if( choice == 'Y' ) {
             //Save game.
             cout << "Saving game for next time!" << endl;
             save_game(Yahtzee);
          }  
        }
      }
      else {  //We've reached Round NM_RDS
          //End of game. Total scores, etc.
          //cout<<"ending dialogue";
          //Indicate in the file that the last game was completed.
          save_game(Yahtzee);

          Yahtzee->done = true;
      }

      Yahtzee->round++;
    
    } while( ! Yahtzee->done );  //For multiple round game

    print_scores(Yahtzee);
}

bool load(Yahtzee* Yahtzee) {
    ifstream In( FILE_DIR );

    //NOTE: Probably should check for file-open errors here.
    if( ! In ) return false;  //Can't open file

    In >> Yahtzee->round >> Yahtzee->player_count;

    //Read game data in as vectors.
    vector<string> N;
    vector<int> S;
    for( int i = 0; i < Yahtzee->player_count; i++ ) {
    string name;
    int    score;
    In >> name >> score;
    N.push_back( name );
    S.push_back( score );
    }
    In.close();

    Yahtzee->players = new Player[Yahtzee->player_count];
    for( int i = 0; i < N.size(); i++ ) {
        Yahtzee->players[i]=Player();
    }
    //Copy vectors to arrays.
    for( int i = 0; i < N.size(); i++ ) {
        Yahtzee->players[i].name = N[i];
        Yahtzee->scores[i] = S[i];
    }

    return true;
}
    