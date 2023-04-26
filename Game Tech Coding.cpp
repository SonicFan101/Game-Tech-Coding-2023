#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main() {
  srand(time(0));
  cout << "You flip the light switch!\n\n";

  string playerName = "player";
  int score = 4500;
  bool lightIsOn = false;
  int randOn = rand() % 2 + 1;
  if (randOn == 1)
    lightIsOn = true;
  
  if (lightIsOn) {
    lightIsOn = false;
    cout << "The light is now off.\n";
  } else {
    lightIsOn = true;
    cout << "The light is now on.\n\n";
  }
  srand(time(0));
  int min = 10;
  int max = 100;
  cout << "\nGuess the number!\n\nGive me a number between " << min << " and "
       << max << "\n";
  int input = rand() % ((max - min) + 1) + min;
  //cin >> input;
  int random = rand() % ((max - min) + 1) + min;
  if (input == random)
    cout << "My number was... " << random << "\nYou got it!\n" << input << " = " << random;
  else
    cout << "My number was... " << random << "\nYou got it wrong!\n" << input << " /= " << random;;
  if (input < random)
    cout << "\nToo low!\n";
  else if (input > random)
    cout << "\nToo high!\n";

  srand(time(0));
  int randNum = rand() % 100 + 1;
  int num = rand() % ((max - min) + 1) + min;
  int count = 0;
  if (randNum > num){
    cout << "\n\nThe random number " << randNum << " is greater than the random number " << num << "\n";
  }
  else
    cout << "\n\nThe random number " << randNum << " is not greater than the random number " << num << "\n";

  int loop = rand() % 50 + 1;
  cout << "\nLet's do this " << loop << " more times.\n";
  int loopCount = 0;
  while (loopCount < loop) {
    loopCount++;
    randNum = rand() % 100 + 1;
    num = rand() % ((max - min) + 1) + min;
    if (randNum > num)
      count++;
  }
    
  cout << "The random number was greater than the other random number: " << count << " out of " << loop << " times\n";

  string inpuut;
  do {
    cout << "\nDo you want to me to keep talking?\n";
    cin >> inpuut;
  } while (inpuut != "no" && inpuut != "No" && inpuut != "NO");
  // cout << "1+1=" << 1+1 << "\n";
  // cout << "1+1=" << '1' << '1' << "\n";
  // cout << "a+a=" << 'a' << 'a' << "\n";
  return 0;
}