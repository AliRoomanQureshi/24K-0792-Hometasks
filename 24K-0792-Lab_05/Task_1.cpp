#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void takeGuess(int secret, int player) {
    int number;
    cout<<"Player "<<player<<", enter your guess (1-100): ";
    cin>>number;

    if (number == secret) {
        cout<<" Player "<<player<<" guessed it correctly! You win!\n";
        return;
    } 
    else if (number < secret) {
        cout<<"low!\n";
    } 
    else {
        cout<<"high!\n";
    }

    int next = (player == 1) ? 2 : 1;
    takeGuess(secret, next);
}

int main() {
    srand(time(0));               
    int hidden = rand() % 100 + 1;

    cout<<"==== Guessing Game ====\n";
    cout<<"Two players take turns guessing a number between 1 and 100.\n";
    cout<<"The first to guess correctly wins!\n\n";

    takeGuess(hidden, 1);

    return 0;
}
