#include <iostream> // talking to the console
using namespace std;

int main() {
  // this is a comment
  cout << "State your name \n";
  string playerName = "";
  cin >> playerName;
  cout << "\n\nHello " << playerName << "\n";
  int playerAge;
  cout << "\nHow old are you?\n";
  cin >> playerAge;
  cout << "\nI see, " << playerAge << " years old...\n";
  cout << "Do you submit to lord Ainz Ool Gown?\n";
  string submit = "";
  cin >> submit;

  if (submit == "yes" || submit == "Yes" || submit == "Yeah"
      || submit == "yeah" || submit == "sure" || submit == "Sure")
      cout << "\nThen I welcome you to the Sorcerer Kingdom!\n";
  //if (submit == "Joe Momma" || submit == "joe momma" || submit == "Joe momma")
      //cout << "\nI see you have choosen death!\n";
  else
    cout << "\nThen perish!\n";
    
}