//include libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

//include header function
#include "objects.h"

//void function displays starting menu
void Cards::display()
{
  cout << "---------------- BLACK JACK ---------------\n";
  cout << "1. View Rules\n";
  cout << "2. Play\n";
  cout << "3. Quit\n";
}

//void function prints the rules for the user
void Cards::rules()
{
  cout << "You start with one card and play against the dealer and flip cards over.\n";
  cout << "The goal is to get a sum of cards as close as ";
  cout << "you can to 21 without going over.\n";
  cout << "You can choose to 'Stand' or 'Hit'\n";
  cout << "which means to not flip and flip a card respectively.\n";
  cout << "There will be no money involved because gambling is bad :(\n";
}

//function returns card number/ letter
char Cards::convert(int x){
  //switch case determines what letter to return
  switch (x){
    case 1:
    {
      return 'A';
      break;
    }
    case 2:
    {
      return '2';
      break;
    }
    case 3:
    {
      return '3';
      break;
    }
    case 4:
    {
      return '4';
      break;
    }
    case 5:
    {
      return '5';
      break;
    }
    case 6:
    {
      return '6';
      break;
    }
    case 7:
    {
      return '7';
      break;
    }
    case 8:
    {
      return '8';
      break;
    }
    case 9:
    {
      return '9';
      break;
    }
    case 10:
    {
      return 'X';
      break;
    }
    case 11: 
    {
      return 'J';
      break;
    }
    case 12: 
    {
      return 'Q';
      break;
    }
    case 13: 
    {
      return 'K';
      break;
    }
    default:
    {
      return 'A';
      break;
    }
  }
}

//int function returns sum of vector array
int Cards:: total()
{
  //variable declarations and init.
  int total = 0;
  
  //loop to add all values of hand to total
  for (int i = 0; i < hand.size(); i++)
  {
    total += hand[i];
  }

  //returns value
  return total;
}

//void function runs the main code (play)
void play(Player a, Dealer b, Cards c)
{
  //variable declarations
  int action = 0, bj = 21;
  bool loop = true;

  //while player hasn't lost/ won
  while (loop)
  {
    //starter display
    cout << "Your Hand: ";
    a.displayHand();
    cout << "Total Sum: " << a.total();
    cout << endl << endl;
  
    cout << "Dealer's Hand: ";
    b.displayHand();
    cout << "Total Sum: " << b.total();
    cout << endl << endl;

    //input validation
    while (action != 1 && action !=2)
    {
      cout << "1. Stand\n";
      cout << "2. Hit\n";
      cin >> action;
    }

    //action based on user input
    if (action == 1)
    {
      //only dealer checks to hit
      b.run(a.total());
    }
    else 
    {
      //you and dealer hit
      b.run(a.total());
      a.hit();
    }

    //if-else to check if anyone wins + output after the action
    //also displays hands if anyone has won/ lost
    if (a.total() > bj && b.total() <= bj)
    {
      cout << "You lose!\n";
      cout << "Your Hand: ";
      a.displayHand();
      cout << "Total Sum: " << a.total();
      cout << endl;
    
      cout << "Dealer's Hand: ";
      b.displayHand();
      cout << "Total Sum: " << b.total();
      cout << endl << endl;

      loop = false;
      break;
    }
    if (a.total() <= bj && b.total() > bj)
    {
      cout << "You win!\n";
      cout << "Your Hand: ";
      a.displayHand();
      cout << "Total Sum: " << a.total();
      cout << endl << endl;
    
      cout << "Dealer's Hand: ";
      b.displayHand();
      cout << "Total Sum: " << b.total();
      cout << endl << endl;

      loop = false;
      
      break;
    }
    if (a.total() == bj && b.total() != bj)
    {
      cout << "You win!\n";
      cout << "Your Hand: ";
      a.displayHand();
      cout << "Total Sum: " << a.total();
      cout << endl << endl;
    
      cout << "Dealer's Hand: ";
      b.displayHand();
      cout << "Total Sum: " << b.total();
      cout << endl << endl;

      loop = false;
      
      break;
    }
    if(a.total() == bj && b.total() == bj)
    {
      cout << "You tied!\n";
      cout << "Your Hand: ";
      a.displayHand();
      cout << "Total Sum: " << a.total();
      cout << endl << endl;
    
      cout << "Dealer's Hand: ";
      b.displayHand();
      cout << "Total Sum: " << b.total();
      cout << endl << endl;
      
      loop = false;
      break;
    }
    if(a.total() > bj && b.total() > bj)
    {
      cout << "You both lost!\n";
      cout << "Your Hand: ";
      a.displayHand();
      cout << "Total Sum: " << a.total();
      cout << endl << endl;
    
      cout << "Dealer's Hand: ";
      b.displayHand();
      cout << "Total Sum: " << b.total();
      cout << endl << endl;
      
      loop = false;
      break;
    }
    action = 0;
  }
}

//displays all elements in vector array converted into 'cards'
void Player:: displayHand(){
  for (int i = 0; i < hand.size(); i++){
    cout << convert(hand[i]) << " ";
  }
  cout << endl;
}

//adds a random 'card' to vector array
void Player:: hit(){
  int num = rand()%13 + 1;
  hand.push_back(num);
}

//returns vector array
vector <int> Player:: getHand(){
  return hand;
}

//void function determines wether or not dealer should hit
void Dealer:: run(int pTotal){
  //if player has a higher score and 
  //dealer has yet to reach 21, dealer will hit
  if (pTotal > total() && total() < 21){
    hit();
  }
}

//void function prints out hand
void Dealer:: displayHand(){
  for (int i = 0; i < hand.size(); i++){
    cout << convert(hand[i]) << " ";
  }
  cout << endl;
}

//function adds a 'card' to vector array
void Dealer:: hit(){
  int num = rand()%13 + 1;
  hand.push_back(num);
}

//returns vector array (getter function)
vector <int> Dealer:: getHand(){
  return hand;
}