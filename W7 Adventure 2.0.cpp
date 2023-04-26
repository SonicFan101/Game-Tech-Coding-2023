#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

// Global Variables
int health = 50;
int totalTreasure = 0;

// Function Declarations
void Story();
bool AskYesNo(string question);
int RollDie(int sides = 6);
void Ending();
void Adventure();

// Function Definitions
void Story() {
  cout << "Once upon a time, in a faraway land, there was a great treasure "
          "that everyone wanted to get their hands on.\n";
  cout << "You have heard the tales and decided to seek out the treasure.\n";
  cout << "You embark on an adventure and encounter an enemy that you must "
          "defeat to gain the treasure.\n\n";
}

bool AskYesNo(string question) {
  char response;
  cout << question << " (y/n): ";
  cin >> response;
  return (response == 'y' || response == 'Y');
}

int RollDie(int sides) { return (rand() % sides) + 1; }

void Ending() {
  cout << "You are dead. Better luck next time.\n";
  cout << "You had " << totalTreasure << " treasure.\n";
}

void Adventure() {
  int attack = RollDie();
  int block = RollDie();
  int treasure = RollDie() * 10;
  bool continueAdventure = true;

  cout << "You encounter an enemy!\n";
  cout << "Attack: " << attack << endl;
  cout << "Block: " << block << endl;

  if (block >= attack) {
    cout << "You successfully block the attack and gain " << treasure
         << " treasure.\n";
    totalTreasure += treasure;
  } else {
    int damage = attack - block;
    health -= damage;
    cout << "You failed to block the attack and lose " << damage
         << " health.\n";
    if (health <= 0) {
      continueAdventure = false;
    }
  }

  cout << "Your health is now " << health << ".\n";
  cout << "Your total treasure is " << totalTreasure << ".\n";

  if (!continueAdventure) {
    Ending();
  }
}

// Main Function
int main() {
  srand(time(NULL));
  Story();
  while (health > 0) {
    if (AskYesNo("Do you want to go adventuring?")) {
      Adventure();
    } else {
      break;
    }
  }

  if (health > 0) {
    cout << "Congratulations! You have survived.\n";
    cout << "You ended with " << health << " health and " << totalTreasure
         << " treasure.\n";
  }

  return 0;
}
