#include <iostream>
#include <string>
#include <termios.h>
#include <unistd.h>

using namespace std;

string prompt(const string& text = "Enter password: ") {
  string pass;
  cout << text;

  termios oldt;
  tcgetattr(STDIN_FILENO, &oldt);
  termios newt = oldt;
  newt.c_lflag &= ~ECHO;
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);

  string hide;
  getline(cin, pass);

  hide.append(pass.size(), '*');
  cout << hide << endl;
  
  return pass;
}

int main() {
  string real = "AaBbCcDdEe";
  string typed = prompt();

  if (real==typed) cout << "Correct password." << endl;
  else cout << "You got it wrong man!" << endl;
}//main 
