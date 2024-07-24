//include libraries
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

//declare base class
class Cards 
{
//protected variables
protected:
//vector array declaration
vector <int> hand{1};

//public member functions
public:
//no-arg constructor
Cards(){
  //generates a number between 1 and 13
  int num = rand()%13 + 1;
  hand[0] = num;
};

//basic member functions
void display();
void rules();
char convert(int x);
int total();

};

//Player class definition and inheritance from Cards
class Player: public Cards {
public:
//no-arg constructor creates object using Cards constructor
Player(): Cards(){};

//member functions
void displayHand();
vector <int> getHand();
void hit();
};

//Dealer class derived from base class Cards
class Dealer: public Cards 
{
public:
//no-arg constructor creates object using base class constructor
Dealer(): Cards(){};

//member funcitons
void displayHand();
vector <int> getHand();
void hit();
void run(int pTotal);
};

//play function header
void play(Player a, Dealer b, Cards c);