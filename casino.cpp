#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <unistd.h>
using namespace std;

int bet;
int bal;
int guess;
int realNum;
int winAmt;
bool done = false;
bool validBet = false;

void rules() {
  system("clear");
  cout << "\t\t======CASINO NUMBER GUESSING RULES!======\n";
  cout << "\t1. Choose a number between 1 to 10\n";
  cout << "\t2. Winner gets 10 times of the money bet\n";
  cout << "\t3. Wrong bet, and you lose the amount you bet\n";
  cout << "\t4. You win when you have 100x the amount you started with\n";
  cout << "\t5. Enter 0 as a bet to quit\n\n";
}

int getBal() {
  cout << "Enter starting balance: ";
  cin >> bal;
  cout << "You need " << bal * 100 << " to win!" << endl;
  winAmt = bal * 100;
  return bal;
}

int getBet() {
  while (!validBet) {
    cout << "Enter bet: ";
    cin >> bet;
    if (bet > bal) {
      cout << "Bet was greater than your balance, please enter an amount less "
              "than or equal to your balance"
           << endl;
    } else if (bet == 0) {
      system("quit");
    } else {
      break;
    }
  }
  bal = bal - bet;
  return bet;
}

bool guessNum() {
  realNum = rand() % 10 + 1;
  cout << realNum << endl;
  cout << "Guess the number between 1 and 10: ";
  cin >> guess;
  if (guess == realNum) {
    return true;
  }
  return false;
}

int main() {
  srand(time(NULL));
  rules();
  getBal();
  while (bal < winAmt || bal <= 0) {
    sleep(5);
    system("clear");
    getBet();
    if (guessNum()) {
      cout << "Correct!" << endl;
      cout << bet * 10 << endl;
      bal = bet * 10 + bal;
      cout << "New balance: " << bal << endl;
    } else {
      cout << "Incorrect, the real number was: " << realNum << endl;
      cout << "New balance: " << bal << endl;
    }
  }
  if (bal <= 0) {
    cout << "You went bankrupt" << endl;
  } else {
    cout << "You cleaned house!" << endl;
  }
  return 0;
}