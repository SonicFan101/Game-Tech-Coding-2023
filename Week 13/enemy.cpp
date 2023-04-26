#include "enemy.h"

enemy::enemy(string givenName) {
  name = givenName;
  health = 10;
  cout << name << " has appeared!\n";
}

void enemy::status() {
   cout << name << " has " << health << " HP.\n";
}

void enemy::changeHealth(int by) {
  health += by;

  if (health < 0) health = 0;
  else if (health > 10) health = 10;
}

string enemy::getName() {
  return name;
}

int enemy::getHealth() {
  return health;
}

void enemy::setName(string newName) {
  if (newName == "Poop") {
    cout << "Uh oh, stinky!\n";
    return;
  }
  name = newName;
}