/*
Name: Davina C
Course: ICS4U
Teacher: Mr. Saleem
Topic: Summative (Black Jack)
*/

//include libraries
#include <iostream>
using namespace std;

//include header files
#include "objects.h"

//main function prints to console
int main() {
  //randomize random num generator each time
  srand(time(0));

  //variable dec and init.
  int option = 0, games = 0;
  bool run = true;

  //while loop runs until user quits
  while (run)
  {
    //object creation
    Player a;
    Dealer b;
    Cards c;

    //displays menu
    c.display();

    //input validation
    while (option != 1 && option != 2 && option != 3)
    {
      cout << "Enter your choice (1-3): ";
      cin >> option;
    }

    //determines action based on input
    switch (option){
    case 1: 
      {
        //prints rules
        c.rules();
        break;
      }
    case 2:
      {
        //plays
        play(a, b, c);
        ++games;
        break;
      }
    case 3: 
      {
        //quits the loop
        run = false;
        break;
      }
    }
    option = 0;
  }
  //thank you message
  cout << "Thank you for playing!\n";
  cout << "You played " << games << " games\n";

  //returns 0 for successful run to main function
  return 0;
}