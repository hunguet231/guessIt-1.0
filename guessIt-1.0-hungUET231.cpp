#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <time.h>
using namespace std;

int generateRandomNumber(){
    srand(time(0));
    return rand() % 100 + 1;
}
int getPlayerGuess(){
    int num;
    cout << endl << "Enter your guess in range 1 to 100: ";
    cin >> num;
    return num;
}
void printAnswer(int guess, int secretNumber, int numberOfPlays, int scores){
    if (guess > secretNumber) {
    cout << endl << "==> Your number is too big.\t"
         << "[Number of guesses: " << numberOfPlays << " ] "
         << "[Scores: " << scores << " ] " << endl;
    } else if (guess < secretNumber) {
    cout << endl << "==> Your number is too small.\t"
         << "[Number of guesses: " << numberOfPlays << " ] "
         << "[Scores: " << scores << " ] " << endl;
    } else {
    cout << endl << "*** Congratulation! You win.\t"
         << "[Number of guesses: " << numberOfPlays << " ] "
         << "[Scores: " << scores << " ] " << endl;
    }
}
bool isContinue(){
    char opt;
    cout << endl << "Do you want to continue ? [enter y(yes)or n(no)]" << endl;
    while(cin >> opt){
        if(opt != 'y' && opt != 'n'){
            cout << "Your choice is invalid, again!" << endl;
        }else{
            if(opt == 'y') return true;
            else if (opt == 'n') return false;
        }
    }
    return false;
}
void playGuessIt(){
    int secretNumber = generateRandomNumber();
    int guess;
    int numberOfPlays = 0, scores = 0;
    do {
        guess = getPlayerGuess();
        numberOfPlays++;
        scores = 100 - numberOfPlays;
        printAnswer(guess, secretNumber, numberOfPlays, scores);
    } while (guess != secretNumber);
}

int main(){
    do {
        playGuessIt();
    } while(isContinue());
    return 0;
}

