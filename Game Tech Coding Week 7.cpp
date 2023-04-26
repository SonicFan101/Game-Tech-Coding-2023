#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

void welcome() { cout << "Hello world!\n"; }

void welcome(string message) { cout << message << "\n"; }

int doubleThe(int x) { return x * 2; }
float doubleThe(float x) { return x * 2; }

int addTwoNums(int a, int b) { return a + b; }

int rollDie() {
  return rand() % (6) + 1; // Gives a random number between 1 and 6
}

int rollDie(int sides) {
  return rand() % (sides) + 1; // Gives a random number between 1 and 6
}

bool askYN(string question) {
  while (true) {
    cout << question << " (y/n)\n";
    char input;
    cin >> input;

    if (input == 'y' || input == 'Y')
      return true;
    else if (input == 'n' || input == 'N')
      return false;
  }
}

int index = 0;
void add(string array[]) {
  cout << "What whould you like to add?\n";
  string input;
  // cin >> input;
  getline(cin, input);
  array[index] = input;
  index++;
}

void show(string array[]) {
  cout << "\nHere's what we got so far...\n";
  for (int i = 0; i < index; i++)
    cout << i + 1 << ". " << array[i] << "\n";
}

void bulkadd(string array[]) {
  cout << "\nEnter items one after another (Type 'quit' to stop):\n";
  string temp;
  while (true) {
    cin >> temp;
    if (temp == "quit") {
      break;
    } else {
      array[index] = temp;
      index++;
    }
  }
}

void edit(string array[]) {
  cout << "\nWhat is the number of the item you wish to edit?\n";
  int newIndex;
  cin >> newIndex;
  cout << "What would you like to change " << array[newIndex - 1] << " to?\n";
  string temp;
  // cin >> temp;
  getline(cin, temp);
  array[newIndex - 1] = temp;
}

void find(string array[]) {
  string find;
  string found;
  cout << "What is the item you want to find and replace?\n";
  cin >> find;
  for (int i = 0; i < index; i++) {
    if (array[i] == find) {
      cout << "\nFound it!\n";
      cout << "What would you like to change it to?\n";
      cin >> found;
      array[i] = found;
      break;
    }
    if (i + 1 == index)
      cout << "'" << find << "' not found!\n";
  }
}

void help() {
  cout << "Type 'quit' to quit!\n";
  cout << "Type 'add' to add an item!\n";
  cout << "Type 'bulkadd' to add multiple items at once!\n";
  cout << "Type 'show' to show what you've added!\n";
  cout << "Type 'edit' to edit an item on the list!\n";
  cout << "Type 'help' to repeat these instructions!\n";
  cout << "Type 'find' to search for and edit an item!\n";
}

int main() {
  index = 0;
  srand(time(0));
  welcome();
  welcome("Let's get started");
  // string input;
  // cin >> input;
  // welcome(input);

  cout << doubleThe(16) << "\n";
  cout << doubleThe(1.5f) << "\n";
  cout << addTwoNums(16, 89) << "\n\n";
  cout << rollDie() << "\n";
  cout << rollDie(100) << "\n";

  // if (askYN("Would you like to play?") == true) {
  //   cout << "Let's get started!\n";
  // } else {
  //   cout << "Maybe next time.\n";
  // }

  cout << "\nLet's make a list!\n";
  cout << "Type 'quite' to quit!\n";
  cout << "Type 'add' to add an item!\n";
  cout << "Type 'bulkadd' to add multiple items at once!\n";
  cout << "Type 'show' to show what you've added!\n";
  cout << "Type 'edit' to edit an item on the list!\n";
  cout << "Type 'help' to repeat these instructions!\n";
  cout << "Type 'find' to search for and edit an item!\n";
  string list[] = {"Eggs", "Cheese", "Bacon"};
  index = 3;

  do {
    string input;
    cin >> input;

    if (input == "quit") {
      cout << "\nQuitting...\n";
      break;
    }

    else if (input == "add") {
      add(list);
    } else if (input == "bulkadd") {
      bulkadd(list);
    } else if (input == "show") {
      show(list);
    } else if (input == "edit") {
      edit(list);
    } else if (input == "help") {
      help();
    } else if (input == "find") {
      find(list);
    } else {
      cout << "Command not found\nType 'help' to see the list of commands\n";
    }
    cout << "What would you like to do?\n";

  } while (true);
  return 0;
}