#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

class enemy {
private:
  string name;
  int health;

public:
  enemy(string givenName = "Mr. Badguy");
  void status();
  void changeHealth(int by);
  string getName();
  int getHealth();
  void setName(string newName);
};