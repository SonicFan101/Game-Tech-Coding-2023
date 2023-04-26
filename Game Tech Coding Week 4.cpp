#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main() {
  srand(time(0));

  int min = 10;
  int max = 49;
  int ran = rand() % (max - min) +
            min; // Gives a random number between min and max (inclusive)
  cout << ran << "\n";

  for (int i = 0; i < 10; i++) {
    cout << i << "\n";
  }
  // strings are an ordered list of characters
  string name = "Mark";
  cout << "\nThe first letter in " << name << " is " << name[0] << ".\n";
  cout << "There are " << name.size() << " letters in " << name << ".\n";
  cout << "The second letter in " << name << " is " << name[1] << ".\n";

  for (int i = 0; i < name.size(); i++)
    cout << name[i] << "\n";

  cout << "\nW i t h  a e s t h e t i c : "
       << "\n";
  for (int i = 0; i < name.size(); i++)
    cout << name[i] << " ";
  cout << "\n";

  string phrase = "Cottonmouth";
  cout << "\n" << phrase << " without the vowels:\n";
  for (int i = 0; i < phrase.size(); i++) {
    if (phrase[i] == 'a' || phrase[i] == 'e' || phrase[i] == 'i' ||
        phrase[i] == 'o' || phrase[i] == 'u')
      continue;
    cout << phrase[i];
  }
  cout << "\n";
  int num = 5;
  string inv[num];
  inv[0] = "Knife";
  inv[1] = "Gun";
  inv[2] = "Ammo Magazine";
  inv[3] = "Lighter";
  inv[4] = "Phone";
  cout << "\nThe first item in your inventory is a " << inv[0];
  cout << "\nIn your inventory you have a...\n";
  for (int i = 0; i < num; i++) {
    if (inv[i] != "")
      cout << inv[i] << "\n";
  }
  string colors[] = {"Red", "Green", "Blue", "Yellow", "Black", "White"};
  bool pickedColor = false;
  cout << "The first color is " << colors[0] << "\n";

  while (!pickedColor) {
    cout << "Choose your car's color!\n";
    string input;
    cin >> input;
    for (int i = 0; i < 5; i++) {
      if (colors[i] == input) {
        cout << "\nYou have chosen a " << colors[i] << " car!\n";
        pickedColor = true;
        break;
      }
      if (i + 1 == 5) {
        cout << input << " is not a valid option\n"
             << "Try again\n";
      }
    }
  }

  return 0;
}