#include <bits/stdc++.h>

using namespace std;

int turn(int roll, int pos){
  if (roll == 0){
    cout << "You Quit!" << endl;
    exit(0);
  }

  if(pos+roll > 100 || roll < 2 || roll > 12) {
    return pos;
  }

    // ladders
  if (pos + roll == 9) pos = 34;
  else if (pos + roll == 40) pos = 64;
  else if (pos + roll == 67) pos = 86;
    // snakes
  else if (pos + roll == 99) pos = 77;
  else if (pos + roll == 90) pos = 48;
  else if (pos + roll == 54) pos = 19;
  else {
    pos += roll;
  }
  return pos;
}

void print(int pos){
  if(pos == 100){
    cout << "You are now on square " << pos << endl;
    cout << "You Win!";
    exit(0);
  } else {
    cout << "You are now on square " << pos << endl;
  }
}


int main() {
  int roll;
  int pos = 1;
    while(pos != 100){
      cin >> roll;
      pos = turn(roll, pos);
      print(pos);
    }

    return 0;
}
