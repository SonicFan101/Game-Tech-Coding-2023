#include <cstdlib>
#include <ctime>
#include <iostream>
#include "enemy.h"
using namespace std;

int main() {
  enemy duke("Someone");
  cout << "What would you like to call yourself?\n";
  string input;
  cin >> input;
  duke.setName(input);

  duke.status();
  cout << "There was a storm! " << duke.getName() << " lost 2 HP\n";
  duke.changeHealth(-2);
  cout << duke.getName() << "'s Health is now " << duke.getHealth() << " HP\n";
  
}