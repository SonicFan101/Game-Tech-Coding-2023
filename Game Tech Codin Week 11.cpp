#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

string adventurerNames[] = {"Steve", "Jet",  "Alex", "Jeff", "Jacob",
                       "Ian",   "Jake", "John", "Jane", "Joe"};

class adventurer {
public:
  // data members
  string name;
  int staminaLevel;
  int x;
  int y;

  // member functions
  adventurer(string givenName = "adventurer", int givenstaminaLevel = 10) {
    cout << "A new adventurer is created!\n";
    name = givenName;
    staminaLevel = givenstaminaLevel;
    x = (rand() % 5) - 2;
    y = (rand() % 5) - 2; // randomize position on map from -2 to 2
  }

  void status() {
    cout << "[" << name << "]'s stamina level is " << staminaLevel << ".\n";
    cout << "Position: [" << x << "," << y << "]\n";
  }

  void move() {
    // north/south: positive/negative on the y-axis
    // west/east: positive/negative on the x-axis
    if (staminaLevel < 1) {
      cout << "No stamina!\n";
      return;
    }

    while (true) {
      int direction = rand() % 4;
      if (direction == 0) {
        // if not at the top
        if (y < 2) {
          // go north
          y++;
          cout << "[" << name << "]" << " moves north.\n";
          break;
        } // end if y
      }   // end if direction == 0
      else if (direction == 1 && y > -2) {
        y--;
        cout << "[" << name << "]" << " moves south.\n";
        break;
      } else if (direction == 2 && x < 2) {
        x++;
        cout << "[" << name << "]" << " moves east.\n";
        break;
      } else if (direction == 3 && x > -2) {
        x--;
        cout << "[" << name << "]" << " moves west.\n";
        break;
      }
      cout << "Can't move there, trying again\n";
    } // end while loop
    staminaLevel--;
  } // end move()
};

int main() {
  srand(time(0));

  cout << "It's Week 11!\n";

  adventurer Rang;
  Rang.name = "Rango";
  Rang.staminaLevel = 15;

  cout << "Welcome " << Rang.name << "!\n";
  cout << Rang.name << "'s stamina level is " << Rang.staminaLevel << ".\n";

  adventurer Al("Alex", 3); // constructor call
  Al.status();
  Al.move();
  Al.status();
  Al.move();
  Al.status();
  Al.move();
  Al.status();
  Al.move();
  Al.status();
  adventurer Fil("Phillup");
  Fil.status();

  // from list of names create adventurers, and stamina levels
  // and then have them move around
  adventurer adventurers[10];
  for (int i = 0; i < 10; i++) {
    adventurers[i] = adventurer(adventurerNames[rand() % 5], rand() % 6 + 5);
  }
  for (int i = 0; i < 10; i++) {
    adventurers[i].status();
    for (int k = 0; k <10; k++) {
      adventurers[i].move();
    }
    adventurers[i].status();
  }
}