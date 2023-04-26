#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
using namespace std;

void showList(string list[], int &index) {
  cout << "\nHere's what we got so far...\n";
  for (int i = 0; i < index; i++)
    cout << i + 1 << ". " << list[i] << "\n";
}

void addItem(string list[], int &index) {
  cout << "\nEnter item:\n";
  string temp;
  cin >> temp;
  list[index] = temp;
  index++;
}

void bulkAdd(string list[], int &index) {
  cout << "\nEnter items one after another (Type 'quit' to stop):\n";
  string temp;
  while (true) {
    cin >> temp;
    if (temp == "quit") {
      break;
    } else {
      list[index] = temp;
      index++;
    }
  }
}

void editItem(string list[], int &index) {
  cout << "\nWhat is the number of the item you wish to edit?\n";
  int newIndex;
  cin >> newIndex;
  cout << "What would you like to change " << list[newIndex - 1] << " to?\n";
  string temp;
  cin >> temp;
  list[newIndex - 1] = temp;
}

void removeItem(string list[], int &index) {
  cout << "\nWhat is the number of the item you wish to remove?\n";
  int newIndex;
  cin >> newIndex;
  for (int i = newIndex - 1; i < index; i++) {
    list[i] = list[i + 1];
  }
  index--;
}

void loadList(string list[], int &index) {
  ifstream file("list.txt");
  if (file.is_open()) {
    string line;
    while (getline(file, line)) {
      list[index] = line;
      index++;
    }
    file.close();
  } else {
    cout << "Unable to open file\n";
  }
}

void saveList(string list[], int &index) {
  ofstream file("list.txt");
  if (file.is_open()) {
    for (int i = 0; i < index; i++) {
      file << list[i] << "\n";
    }
    file.close();
  } else {
    cout << "Unable to open file\n";
  }
}

void help() {
  cout << "Type 'quit' to quite!\n";
  cout << "Type 'add' to add an item!\n";
  cout << "Type 'bulkadd' to add multiple items at once!\n";
  cout << "Type 'show' to show what you've added!\n";
  cout << "Type 'edit' to edit an item on the list!\n";
  cout << "Type 'remove' to remove an item from the list!\n";
  cout << "Type 'help' to repeat these instructions!\n";
  cout << "Type 'find' to search for and edit an item!\n";
}

int main() {
  cout << "\nLet's make a list!\n";
  cout << "Type 'quit' to quit!\n";
  cout << "Type 'add' to add an item!\n";
  cout << "Type 'bulkadd' to add multiple items at once!\n";
  cout << "Type 'show' to show what you've added!\n";
  cout << "Type 'edit' to edit an item on the list!\n";
  cout << "Type 'help' to repeat these instructions!\n";
  cout << "Type 'find' to search for and edit an item!\n";

  string list[100];
  int index = 0;
  loadList(list, index);

  do {
    string input;
    cin >> input;

    if (input == "quit") {
      cout << "\nQuitting...\n";
      saveList(list, index);
      break;
    }

    else if (input == "add") {
      addItem(list, index);
    }

    else if (input == "bulkadd") {
      cout << "\nEnter items one after another (Type 'quit' to stop):\n";
      string temp;
      while (true) {
        cin >> temp;
        if (temp == "quit") {
          break;
        } else {
          list[index] = temp;
          index++;
        }
      }
    }

    else if (input == "show") {
      showList(list, index);
    }

    else if (input == "edit") {
      editItem(list, index);
    }

    else if (input == "help") {
      help();
    }

    else if (input == "find") {
      string find;
      string found;
      cout << "What is the item you want to find and replace?\n";
      cin >> find;
      for (int i = 0; i < index; i++) {
        if (list[i] == find) {
          cout << "\nFound it!\n";
          cout << "What would you like to change it to?\n";
          cin >> found;
          list[i] = found;
          break;
        }
        if (i + 1 == index)
          cout << "'" << find << "' not found!\n";
      }
    } else {
      cout << "Command not found\nType 'help' to see the list of commands\n";
    }
    cout << "What would you like to do?\n";
  } while (true);
  saveList(list, index);
  return 0;
}