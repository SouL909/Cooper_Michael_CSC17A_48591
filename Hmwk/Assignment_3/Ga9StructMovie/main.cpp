//System Libraries
#include <iostream>    //Input/Output Library
#include <string>      //String Library
#include <iomanip>     //Input/Output Manipulation Library
using namespace std;   //Library Name-space

//User Libraries
struct MovieInfo{
    string movName;          //Movie title / name
    char *dirName;            //Director name 
    unsigned short runTime, //Run time - minutes
                   yrRlsd;   //Year release
};
struct Movies{
    int nMovies;
    MovieInfo *mveinfo;
};
//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only

//Function Prototypes
Movies *fillDat();     //Fill structure movieData with data
void display(Movies *); //Display info of structure array
void destroy(Movies *); //Deallocate memory

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    Movies *movies;

    //Initialize
    movies = fillDat();

    //Process, map inputs to outputs
    //Display your initial conditions as well as outputs.
    display(movies);
    
    //Dynamic clean up
    destroy(movies);

    //Exit stage right
    return 0;
}
void destroy(Movies *movies){
    for(int mvees = 0; mvees < movies-> nMovies; mvees++){
        delete[]movies->mveinfo[mvees].dirName; //char arrays in structure
    }
    delete [] movies->mveinfo; //array of structures
    delete movies;
}

void display(Movies *movies){
    for(int mvees = 0; mvees < movies->nMovies; mvees++){
        
        cout << left<<endl;
        cout << setw(11) << "Title:" << movies->mveinfo[mvees].movName << endl;
        cout << setw(11) << "Director:" << movies->mveinfo[mvees].dirName << endl;
        cout << setw(11) << "Year:" << movies->mveinfo[mvees].yrRlsd << endl;
        cout << setw(11) << "Length:" << movies->mveinfo[mvees].runTime << endl;
        
    }
    
}
Movies *fillDat(){
    Movies *movies=new Movies;
        cout << "This program reviews structures"<<endl;
        cout << "Input how many movies, the Title of the Movie, Director, Year "
             << "Released, and the Running Time in (minutes)."<<endl;
        cin >>movies->nMovies;
        //Initialize variables

        //Allocate array dynamically
        movies->mveinfo=new MovieInfo[movies->nMovies];

        for(int mvees = 0; mvees<movies->nMovies;mvees++){
            cin.ignore();                     //clean buffer
            getline(cin, movies->mveinfo[mvees].movName);   //Movie name/title in array structure 
            char size = 81;                   //Dynamic
            movies->mveinfo[mvees].dirName=new char [size];
            cin.getline(movies->mveinfo[mvees].dirName,size-1); //Array structure element
            cin >> movies-> mveinfo[mvees].yrRlsd;
            cin >> movies-> mveinfo[mvees].runTime;
        }
        return movies;
}