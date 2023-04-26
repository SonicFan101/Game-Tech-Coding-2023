#include <cstdlib>
#include <iostream>
#include <time.h>
using namespace std;

// start of main function
int main() {
  srand(time(0));
  // declare and set values to variables
  int health = 10;
  int attack = 0;
  int block = 0;
  int turns = 0;
  // continue the loop untill health is above 10 and number of turns below 4
  while (health > 0 && turns < 4) { // start the encounter
    turns++;
    // generate random number for attack
    attack = rand() % 4;
    block = rand() % 4;
    // subtract health by 1 if block is less than attack
    if (block < attack)
      health--;
  }
  // check if health > 0 then print the message, Congratulations
  if (health > 0)
    cout << "Congratulations! " << endl;
  else
    // otherwise, print the defeated message

    cout << "Sorry! You are defeated" << endl;
}