#include "Yahtzee.h"

#include <iostream>
#include <fstream>
#include <iomanip>

// Save file dir
const char FILE_DIR[] = "yahtzee.txt";

using namespace std;

Yahtzee::Yahtzee() {
    this->round = 0;
    this->done = false;
    this->round = 1;
    print_rules();
}

Yahtzee::~Yahtzee() {
  // Deletes each instance 
  // of player in Players
  for(Player* player : players) {
    delete player;
  }
  last_player = NULL; // Last player points to 
                      // a player in players
                      // so it does not need to be deleted
}

// Prints out the rules of Yahtzee
void Yahtzee::print_rules() {
    cout << "Game Summary:\nOn each turn, roll the dice to get the highest "
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
}

void Yahtzee::play() {
    string user_input = "";
    cout<<"Press 'e' to exit, or any other key to start the game!"<<endl;
    cin>>user_input;

    if (toupper(user_input.c_str()[0]) == 'E') {
        return;
    }

    bool game_load = load();

    if(!game_load || round > MAX_ROUNDS) {
        setup_players();
    }

    readyup();

    do {  //For multiple rounds, start over here.
        //Loop through each player.
        for( int pl_indx = 0; pl_indx < players.size(); pl_indx++ ) {
            //TODO
            last_player = players[pl_indx];
            scores[pl_indx] += player_turn( pl_indx );
        } //End of loop through players


      //Ask if player wants to continue
      if( round < MAX_ROUNDS ) {
        cout << "Do you want to play another round? (Y or N): " << endl;

        //Remember to validate user choice.
        char choice;
        cin >> choice;
        choice = toupper( choice );
        if( choice == 'N' ) {
           //Save game.
           cout << "Saving game for next time!" << endl;
           save_game();

           done = true;
           break;
        }
        else {
          cout << "Save the game anyways? (Y or N): " << endl;

          char choice;
          cin >> choice;
          choice = toupper( choice );
          if( choice == 'Y' ) {
             //Save game.
             cout << "Saving game for next time!" << endl;
             save_game();
          }  
        }
      }
      else {  //We've reached Round NM_RDS
          //End of game. Total scores, etc.
          //cout<<"ending dialogue";
          //Indicate in the file that the last game was completed.
          save_game();

          done = true;
      }

     round++;
    
    } while( done );  //For multiple round game

    print_scores();
}

// Loads all players and current round in the yahtzee.txt
bool Yahtzee::load() {
    ifstream In( FILE_DIR, ios::binary  );

    //NOTE: Probably should check for file-open errors here.
    if( ! In.is_open() ) return false;  //Can't open file
    int pc = 0;
    In >> round >> pc;  // loads the current round and player count

    //Read game data in as vectors.
    vector<string> N;
    for( int i = 0; i < pc; i++ ) {
        string name;
        int    score;
        In >> name >> score;  // loads player information such as Name and Score
        players.push_back(new Player(name));  // pushes a player into Players
        scores[i] = score;  // loads score into score
    }
    In.close(); // closes the file

    return true;
}

// Ready up function serves as a stall function
// It allows the player to wait before moving to the next turn
void Yahtzee::readyup() {
    char beg;
    do{
          cout << "Ready to begin? (y/n)" << endl;
          cin  >> beg;
    } while (!(beg=='y'||beg=='Y'));
}

// If the load functions returns false or a player count of zero then function is called
// Creates atleast 1 - 4 players
void Yahtzee::setup_players() {
    int pc = 0;
    do {
        cout << "How many players are there? (1-4)" << endl;
        cin >> pc;
        if( pc < 1 || pc > 4 )
            cout << "You must enter a number from 1 to 4" << endl;
    } while( pc < 1 || pc > 4 );

    for( int i = 0; i < pc; i++ ) {
        cout << "Enter player " << (i+1) << " name "<<endl;
        string name;
        cin  >> name;
        players.push_back( new Player(name));
        cout << endl;
        scores[i] = 0;
    }
    round = 1;  //Default to Round #1
}

int Yahtzee::player_turn(int index) {
    //The roll of dices for turn 1 of up to 3
    int  rolCts[6];
            for( int i = 0; i < 7; i++ ) {
            rolCts[i] = 0;
        }
    bool keep[5];
    //Dice to keep for 1st,2nd, and 3rd rolls.
    bool r2ndT, r3rdT;                      //Rolled 2nd Time? Rolled 3rd time?
    //Will player roll a 2nd or 3rd time?
    char ans;
    string s;
    int scr3k;              //Score with 3 of a Kind

    cout << "\n===================================================\n"
         << "It's " << players[index]->getName() << "'s turn:" << endl;

    //Turn begins //First roll
    cout << "roll 1:\n(Dice are labeled a-e)\n";
    for( int i = 0; i < 5; i++ )
      players[index]->setRoll(i, rand() % 6 + 1);

    //Show dice
    cout << *players[index] << endl;
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
              if( keep[i] )  cout << msg << players[index]->getRoll(i) << endl;
              else {
                players[index]->setRoll(i, rand() % 6 + 1);
                 cout << msg << players[index]->getRoll(i) << endl;
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
                  if( keep[i] )  cout << msg << players[index]->getRoll(i) << endl;
                  else {
                    players[index]->setRoll(i, rand() % 6 + 1);
                    cout << msg << players[index]->getRoll(i) << endl;
                  }
                }

            } //End of if for 3rd roll
        } //end of if for 2nd roll

        //Scoring sequence beings
        //Score UPPER section.
        //Clear out count 
        cout << "Scoring..." << endl;
        //Look at each die in a roll.
        //Add the number to the appropriate entry in Counts
        for( int r = 0; r < 5; r++ ) {  //Loop through rolls
            int _index = players[index]->getRoll(r) - 1;
            rolCts[ _index ]++;
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
        cout << "Congratulations " << players[index]->getName() << "!\nYour Score: " << score << endl;
        return score;
}

// Searches through an array
// to find if there are 2 unique values
bool Yahtzee::two_of_a_kind(int rolCts[], int Size, int &index) {
  bool found = false;
  for( index = 0; index < Size && ! found; index++ ) {
    if( rolCts[index] == 2 ) {
      return true;
    }
  }
  return false;
}

// Prints a detailed list of the scores
// and congratulates the winner
void Yahtzee::print_scores() {

    cout << "Congratulations, " << last_player->getName() << "!" << endl;
    cout << "You are the winner!!!" << endl;
    cout << "\n\n";
    cout << setw(20) << "NAME" << setw(10) << "SCORE" << "\n"
         << "--------------------------------------------------" << endl;
    for( int i = players.size() - 1; i >= 0; i-- ) {
        cout << "|" << setw( 20 ) << players[i]->getName() << setw(10) << scores[i]
             << " | " << endl;
    }

}


// Saves each player and their current score
// to the Yahtzee.txt file
// it also saves the current round
void Yahtzee::save_game() {

  cout << "The game has been saved " << sve_cnt << " times" << endl;

  ofstream Out( FILE_DIR,ios::binary );

  //NOTE: Probably should check for file-open errors here.

  Out << round << " " << players.size() << endl;  // Saves the current round and amount of players
  for( int i = 0; i < players.size(); i++ ) {
    Out << players[i]->getName() << " " << scores[i] << endl; // Saves the player's name and score
  }
  Out.close();  // Closes the file
  
  sve_cnt++;  // Increments how many times the game has been saved in this instance
              // of yahtzee
}
