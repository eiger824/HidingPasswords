#include <iostream>
#include <string>
#include <termios.h>
#include <unistd.h>

using namespace std;

int main()
{
    termios oldt;
    tcgetattr(STDIN_FILENO, &oldt);
    termios newt = oldt;
    newt.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    string s;
    string hide;
    getline(cin, s);

    hide.append(s.size(), '*');
    cout << hide << endl;
    return 0;
}//main 
