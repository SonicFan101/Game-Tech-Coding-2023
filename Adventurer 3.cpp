#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Adventurer {
private:
    string name;
    int level;
    int health;
    int staminaLevel;
    int x;
    int y;
    
public:
    Adventurer() {
        srand(time(NULL));
        string names[] = {"Alice", "Bob", "Charlie", "Dave", "Eve"};
        name = names[rand() % 5];
        level = rand() % 10 + 1;
        health = rand() % 100 + 1;
        staminaLevel = rand() % 100 + 1;
        x = rand() % 2;
        y = rand() % 2;
    }
    
    Adventurer(string newName, int newLevel) {
        srand(time(NULL));
        name = newName;
        level = newLevel;
        health = rand() % 100 + 1;
        staminaLevel = rand() % 100 + 1;
        x = rand() % 2;
        y = rand() % 2;
    }
    
    void setName(string newName) {
        name = newName;
    }
    
    void setLevel(int newLevel) {
        level = newLevel;
    }
    
    void move() {
        int dx = rand() % 3 - 1;
        int dy = rand() % 3 - 1;
        
        while (x + dx < 0 || x + dx > 1 || y + dy < 0 || y + dy > 1) {
            cout << "Can't go there. Try again." << endl;
            dx = rand() % 3 - 1;
            dy = rand() % 3 - 1;
        }
        
        x += dx;
        y += dy;
        
        string direction;
        if (dx == -1 && dy == -1) {
            direction = "up-left";
        }
        else if (dx == -1 && dy == 0) {
            direction = "up";
        }
        else if (dx == -1 && dy == 1) {
            direction = "up-right";
        }
        else if (dx == 0 && dy == -1) {
            direction = "left";
        }
        else if (dx == 0 && dy == 0) {
            direction = "nowhere";
        }
        else if (dx == 0 && dy == 1) {
            direction = "right";
        }
        else if (dx == 1 && dy == -1) {
            direction = "down-left";
        }
        else if (dx == 1 && dy == 0) {
            direction = "down";
        }
        else if (dx == 1 && dy == 1) {
            direction = "down-right";
        }
        
        cout << "Moved " << direction << ". ";
        staminaLevel--;
        cout << "Stamina level decreased to " << staminaLevel << "." << endl;
    }
    
    void rest() {
        staminaLevel = 100;
        cout << "Restored stamina to full (100)." << endl;
    }
    
    void status() {
        cout << "Name: " << name << endl;
        cout << "Level: " << level << endl;
        cout << "Health: " << health << endl;
        cout << "Stamina level: " << staminaLevel << endl;
        cout << "Position: (" << x << ", " << y << ")" << endl;
    }
    
    void interactiveMode()
    {
        string input;
        cout << "Welcome to the adventurer simulator!" << endl;
        cout << "Type 'help' to see available commands." << endl;
        while (input != "quit") {
            cout << "> ";
            cin >> input;
            if (input == "help") {
                cout << "Commands: " << endl;
                cout << "  name <new name> : Change the adventurer's name." << endl;
                cout << "  level <new level> : Change the adventurer's level." << endl;
                cout << "  move : Move the adventurer to a new location." << endl;
                cout << "  rest : Rest to restore stamina." << endl;
                cout << "  status : Check the adventurer's status." << endl;
                cout << "  quit : Quit the game." << endl;
            }
            else if (input == "name") {
                string newName;
                cin >> newName;
                setName(newName);
                cout << "Changed name to " << newName << "." << endl;
            }
            else if (input == "level") {
                int newLevel;
                cin >> newLevel;
                setLevel(newLevel);
                cout << "Changed level to " << newLevel << "." << endl;
            }
            else if (input == "move") {
                move();
            }
            else if (input == "rest") {
                rest();
            }
            else if (input == "status") {
                status();
            }
            else if (input == "quit") {
                cout << "Goodbye!" << endl;
            }
            else {
                cout << "Invalid command. Type 'help' to see available commands." << endl;
            }
        }
    }
};
int main() {
    Adventurer adventurer("John", 1);
    adventurer.interactiveMode();
    return 0;
}
