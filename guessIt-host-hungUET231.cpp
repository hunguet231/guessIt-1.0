#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

char getHostAnswer(int X){
    char answer;
    cout << "Is " << X
         << " your number? ";
    cin >> answer;
    return answer;
}

int selectNumber(int low, int high){
    return (low+high) / 2;
}

int main(){
    int X, answer, low = 1, high = 100;
    cout << "Your think a number in mind and i\'ll guess it!" << endl;
    cout << string(50,'=') << endl;
    cout << "Enter < if my guess smaller than your number" << endl
         << "      > if my guess greater than your number" << endl
         << "      = if i was right" << endl;
    cout << string(50,'x') << endl;
    do {
        X = selectNumber(low, high);
        answer = getHostAnswer(X);
        if (answer == '>')  high = X-1;
        if (answer == '<') low  = X+1;
    } while (answer != '=');
    return 0;
}
