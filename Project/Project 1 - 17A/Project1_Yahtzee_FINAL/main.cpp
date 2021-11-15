/*
    Author: Michael Cooper
    Date:   Nov 14, 2021
    Purpose: 17A Project 1 - Yahtzee
    Version: Final Build
    Finished putting the turn mechanics into new functions.
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

struct Yahtzee {            //Keeps track of the state of the game
    int crnt_rnd = 0;       //Current Round
    int scores[MAX_NUMBER_ROUNDS];
    bool done = false;
    int plyr_cnt;           //Player count
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

Yahtzee* makeGame() {       //ties to struct to start game (creating the round)
  Yahtzee* yahtzee = new Yahtzee;   //implemented for function return requirement
  yahtzee->crnt_rnd = 0;
  yahtzee->done = false;
  yahtzee->plyr_cnt = 0;
  yahtzee->round = 1;
  return yahtzee;
}

//Execution Begins Here
int main(int argc, char** argv) {
    //Set the Random number seed
    srand( time(0) );
    
    //Declare variables
    Yahtzee* game = makeGame();     //make game is default state, passing into play starts the game process
    play(game);
    return 0; 
}

Yahtzee::Yahtzee() {

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
        for( int pl_indx = 0; pl_indx < Yahtzee->plyr_cnt; pl_indx++ ) {
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
    ifstream In( FILE_DIR, ios::binary  );

    //NOTE: Probably should check for file-open errors here.
    if( ! In.is_open() ) return false;  //Can't open file

    In >> Yahtzee->round >> Yahtzee->plyr_cnt;

    //Read game data in as vectors.
    vector<string> N;
    vector<int> S;
    for( int i = 0; i < Yahtzee->plyr_cnt; i++ ) {
    string name;
    int    score;
    In >> name >> score;
    N.push_back( name );
    S.push_back( score );
    }
    In.close();

    Yahtzee->players = new Player[Yahtzee->plyr_cnt];
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

void readyup(Yahtzee* Yahtzee) {
    char beg;
    do{
          cout << "Ready to begin? (y/n)" << endl;
          cin  >> beg;
    } while (!(beg=='y'||beg=='Y'));
}

void setup_players(Yahtzee* Yahtzee) {
    do {
        cout << "How many players are there? (1-4)" << endl;
        cin >> Yahtzee->plyr_cnt;
        if( Yahtzee->plyr_cnt < 1 || Yahtzee->plyr_cnt > 4 )
            cout << "You must enter a number from 1 to 4" << endl;
    } while( Yahtzee->plyr_cnt < 1 || Yahtzee->plyr_cnt > 4 );

    Yahtzee->players = new Player[Yahtzee->plyr_cnt];
    for( int i = 0; i < Yahtzee->plyr_cnt; i++ ) {
        Yahtzee->players[i]=Player();
    }

    for( int i = 0; i < Yahtzee->plyr_cnt; i++ ) {
        cout << "Enter player " << (i+1) << " name "<<endl;
        cin  >> Yahtzee->players[i].name;
        cout << endl;
        Yahtzee->scores[i] = 0;
    }
    Yahtzee->round = 1;  //Default to Round #1
}

void print_intro(Yahtzee* Yahtzee) {
    cout << "Welcome to Yahtzee!\nWould you like to read the rules?"<< endl;
    cout << "Enter Y for yes or N for no" << endl;
    char tut;
    cin >> tut;
    if (tut == 'y' || tut == 'Y') {
        print_rules(Yahtzee);
    }
}

void print_rules(Yahtzee* Yahtzee) {
    string tutor = "Game Summary:\nOn each turn, roll the dice to get the highest "
    "scoring combination for one of the 13 categories.\nKeep any dice you do not not wish to reroll. You can roll up to 3 times,\n"
    "but once you fill a category with a score it cannot be replaced.\nAfter you finish rolling, "
    "your score (or zero) will be logged.\nThe game ends when all 13 boxes are filled by all players, "
    "scores are then totaled,\nincluding any bonus points and the player with the highest total wins.\n\n"
            
    "The Thirteen Categories:\n"
    "There are two sections in which to place scores:\nan upper area and a lower area.\n\n"
    "The upper section is aces-sixes (63+ scores a 35 bonus)\n"
    "For example: Total of aces(ones) only, total of twos only, and so on...\n\n"
    "The lower section consists of the following:\n"        
    "3 of a kind = total of all 5 dice\n4 of a kind = total of all 5 dice\n"
    "Full house (3 of a kind and a pair) = 25 points\nSmall straight (any sequence of 4 numbers) = 30 points\n"
    "Large straight (any sequence of 5 numbers) = 40 points\nYahtzee (five of a kind) = 50 points\n"
    "Chance: score the total of any 5 dice, this comes in handy when you\ncan't or don't want to score"
    " in another category and dont want to enter a zero.\n\n";

    cout << tutor <<endl;
}

int player_turn(Yahtzee* Yahtzee, Player* player) {
    //The roll of dices for turn 1 of up to 3
    int  rolCts[6];
    bool keep[5];
    //Dice to keep for 1st,2nd, and 3rd rolls.
    bool r2ndT, r3rdT;                      //Rolled 2nd Time? Rolled 3rd time?
    //Will player roll a 2nd or 3rd time?
    char ans;
    string s;
    int scr3k;              //Score with 3 of a Kind

    cout << "\n===================================================\n"
         << "It's " << player->name << "'s turn:" << endl;

    //Turn begins //First roll
    cout << "roll 1:\n(Dice are labeled a-e)\n";
    for( int i = 0; i < 5; i++ )
      player->rolls[i] = rand() % 6 + 1;

    //Show dice
    for( int i = 0; i < 5; i++ ) 
       cout << (char)('a' + i) << ") Roll: " << player->rolls[i] << endl;
       cout << endl;    
        r2ndT = r3rdT = false; 
        //setting to false so user can decide if they want to set to true.
        //after first roll dialogue

        cout << "Do you want to (S)top, or choose dice to hold and (R)oll again? [S or R]:";
        cin >> ans;
        ans = toupper( ans ); //will make sure entry is uppercase

        if( ans == 'R' ) {  //User wants to reroll
            r2ndT = true;

            cin.clear();
            cin.ignore();
            cout << "\nType letters of dice (a - e) you would like to keep:"<<endl;
            cout << "(please type a space between letters)"<<endl;
            std::getline( cin, s );  //Get whatever user types ('a' - 'e)

            //Go through string character by character
            for( int i = 0; i < 5; i++ )
                keep[i] = false;

            for( int i = 0; i < s.length(); i++ ) {      
              char choice = s[i];  //String property -- treating as array
              choice = tolower( choice );  //Make sure it's lowercase
              //If a, b, c, d, or e was typed, treat as a choice
              if( choice >= 'a' && choice <= 'e' )
                keep[ choice - 'a' ] = true;

              //Should validate choice is 'a' through 'e'.
            }

            //Second roll
            cout << "roll 2:\n";

            for( int i = 0; i < 5; i++ ) {
              cout << (char)(i + 'a') << ") ";
              string msg = keep[i] ? "KEPT: ":"Roll: ";
              if( keep[i] )  cout << msg << player->rolls[i] << endl;
              else {
                player->rolls[i] = rand() % 6 + 1;
                 cout << msg << player->rolls[i] << endl;
              }
            }

            cout << "Do you want to (S)top, or choose dice to hold and (R)oll again? [S or R]:\n";
            cin >> ans;
            ans = toupper( ans ); //will make sure entry is uppercase

            if( ans == 'R' ) {  //User wants to reroll
                r3rdT = true;   //this was rolled 2nd time. was it a mistake to change this to 3rd?
                //GetKeepersFromUser( Keepers1 );

                cin.clear();
                cin.ignore();
                cout << "Type letters of dice (a - e) you would like to keep:"<<endl;
                cout << "(You must reselect any dice you wish to keep)"<<endl;
                std::getline( cin, s );  //Get whatever user types ('a' - 'e' hopefully)

                //Go through string character by character
                for( int i = 0; i < 5; i++ )
                  keep[i] = false;
                for( int i = 0; i < s.length(); i++ ) {      
                  char choice = s[i];  //This is a property strings have -- treat as array
                  choice = tolower( choice );  //Make sure it's lowercase

                  //If a, b, c, d, or e was typed, treat as a choice
                  if( choice >= 'a' && choice <= 'e' )
                    keep[ choice - 'a' ] = true;

                  //Should validate choice is 'a' through 'e'.
                }

                //Third roll
                cout << "roll 3:\n";
                for( int i = 0; i < 5; i++ ) {
                  cout << (char)(i + 'a') << ") ";
                  string msg = keep[i] ? "KEPT: ":"Roll: ";
                  if( keep[i] )  cout << msg << player->rolls[i] << endl;
                  else {
                    player->rolls[i] = rand() % 6 + 1;
                    cout << msg << player->rolls[i] << endl;
                  }
                }

            } //End of if for 3rd roll
        } //end of if for 2nd roll

        //Scoring sequence beings
        //Score UPPER section.
        //Clear out count 
        cout << "Scoring..." << endl;
        for( int i = 0; i < 6; i++ )
          rolCts[i] = 0;

        //Look at each die in a roll.
        //Add the number to the appropriate entry in Counts
        for( int r = 0; r < 5; r++ ) {  //Loop through rolls
            int index = player->rolls[r] - 1;
            rolCts[ index ]++;
        }

        //Debugging: printing out roll counts.
        cout << "Roll counts:" << endl;
        for( int i = 0; i < 6; i++ ) //Loop through rolls
            cout << "# of " << (i+1) << "'s: " << rolCts[i] << endl;
        cout << endl;
        
        int score = 0;

        bool gt_yhtz = false;
        for( int i = 0; i < 6; i++ ) {
            if( rolCts[i] == 5 ) {
              cout << "Yahtzee!" << endl;
              score += 50;
              gt_yhtz = true;
            }
        }

        if( ! gt_yhtz ) {
          for( int i = 0; i < 6; i++ ) {  //Go through roll counts
            if( rolCts[i] == 3 ) {
              int scr3k = 0;
              for( int j = 0; j < 6; j++ )
                  scr3k += rolCts[j] * (j+1);
              //cout << "HAVE A 3-OF-A-KIND (at least): " << (i+1) << " scr3k=" << scr3k << endl; //debugging
              if( scr3k > 25 ) {
                  //Situation where 3-of-a-kind is worth more pts than full house
                  //(sum of dice just get added together here)
                  cout << "Three of a kind with " << (i+1)
                       << "'s, which scores more than a full house!" << endl;
                  score += scr3k;
              }
              else {
                  int index;
                  bool ful_hse = two_of_a_kind( rolCts, 6, index );

                  if( ful_hse ) {
                      cout << "Full House with three " << (i+1)
                           << "'s and two " << (index+1) << "'s." << endl;
                      score += 25;
                  }
                  else {
                    cout << "Three of a kind with " << (i+1) << "'s." << endl;
                    //Total of all 5 dice
                    score += scr3k;
                  }
              }
            }
          }

          for( int i = 0; i < 6; i++ ) {
            //cout << "i=" << i << " rolCts[" << i << "]=" << rolCts[i] << endl; //Debugging
            if( rolCts[i] == 4 ) {
              cout << "Four of a kind with " << (i+1) << "'s." << endl;
              //Total of all 5 dice
              for( int j = 0; j < 6; j++ )
                score += rolCts[j] * (j+1);
            }
          }

          //Check for straights
          if( (rolCts[0] == 0 && rolCts[1] == 1 && rolCts[2] == 1 &&
               rolCts[3] == 1 && rolCts[4] == 1 && rolCts[5] == 1) ||
              (rolCts[0] == 1 && rolCts[1] == 1 && rolCts[2] == 1 &&
               rolCts[3] == 1 && rolCts[4] == 1 && rolCts[5] == 0) ) {
            cout << "Large straight." << endl;
            score += 40;
          }
          else {
            if( (rolCts[0] == 1 && rolCts[1] == 1 && rolCts[2] == 1 &&
                 rolCts[3] == 1) ||                                                 //1,2,3,4
                (rolCts[1] == 1 && rolCts[2] == 1 && rolCts[3] == 1 &&
                 rolCts[4] == 1) ||                                                 //2,3,4,5
                (rolCts[2] == 1 && rolCts[3] == 1 && rolCts[4] == 1 &&
                 rolCts[5] == 1) ) {                                                //3,4,5,6
              cout << "Small straight." << endl;
              score += 30;
            }
          }      
        }  //end of else
 
        if( score == 0 ) {  //Chance
            for( int j = 0; j < 6; j++ )
              score += rolCts[j] * (j+1);
        }

        //Scores[RoundNum-1] = score;
        cout << "Congratulations " << player->name << "!\nYour Score: " << score << endl;
        return score;
}

bool two_of_a_kind(int rolCts[], int Size, int &index) {
    bool found = false;
  for( index = 0; index < Size && ! found; index++ ) {
    if( rolCts[index] == 2 ) {
      return true;
    }
  }
  return false;
}

void print_scores(Yahtzee* Yahtzee) {
    SortScr( Yahtzee->players, Yahtzee->scores, Yahtzee->plyr_cnt );
    cout << "Congratulations, " << Yahtzee->players[Yahtzee->plyr_cnt-1].name << "!" << endl;
    cout << "You are the winner!!!" << endl;
    cout << "\n\n";
    cout << setw(20) << "NAME" << setw(10) << "SCORE" << "\n"
         << "--------------------------------------------------" << endl;
    for( int i = Yahtzee->plyr_cnt - 1; i >= 0; i-- ) {
        cout << "|" << setw( 20 ) << Yahtzee->players[i].name << setw(10) << Yahtzee->scores[i]
             << " | " << endl;
    }
    
    //Print average.
    if( true ) {
        float avg = CalcAvg( Yahtzee->scores, Yahtzee->plyr_cnt );
        cout << "\n"
             << "Average score: " << avg << endl;
    }
}

float  CalcAvg( int Scores[], int NumPlrs ) {
   int sum = 0;
   for( int i = 0; i < NumPlrs; i++ )
      sum += Scores[i];
        
   float avg = (float)(sum) / NumPlrs;    
   
   return avg;
}

void SortScr( Player* players, int Scores[], int NumPlrs ) {
    for( int i = 0; i < NumPlrs - 1; i++ ) {
        for( int j = i + 1; j < NumPlrs; j++ ) {
            if( Scores[i] > Scores[j] ) {
                //Swap scores & player's names
                int temp_score = Scores[i];
                Scores[i] = Scores[j];
                Scores[j] = temp_score;
                Player temp_name = players[i];
                players[i] = players[j];
                players[j] = temp_name;
            }
        }
    }
}

void save_game(Yahtzee* Yahtzee) {
  static int sve_cnt = 0;

  cout << "The game has been saved " << sve_cnt << " times" << endl;

  ofstream Out( FILE_DIR,ios::binary );

  //NOTE: Probably should check for file-open errors here.

  Out << Yahtzee->round << " " << Yahtzee->plyr_cnt << endl;
  for( int i = 0; i < Yahtzee->plyr_cnt; i++ ) {
    Out << Yahtzee->players[i].name << " " << Yahtzee->scores[i] << endl;
  }
  Out.close();
  
  sve_cnt++;
}
