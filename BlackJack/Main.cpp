#include"BlackJack.h"
#include <iostream>
#include <string>
#include <cstdlib>  // Library has rand() in it
#include <ctime>    // Library for srand() and importing time

using namespace std;

bool playAgain(bool);
void playGame();
void printEndGame();
void printIntro();

int main() {
	srand(time(NULL));  // Randomizing the rand() function calls later in the function

	printIntro();
	playGame();
	printEndGame();

	system("pause");
	return 1;
}
void printIntro() {
	cout << "Welcome to the card game BlackJack!" << endl;
	cout << endl;
	
}
void playGame() {
	BlackJack user;
	bool play = false;

	do {
		user.playBlackJack();
		play = playAgain(play);
	} while (play);
}
void printEndGame() {
	cout << "Thank you for playing BlackJack!" << endl;
	cout << "Enjoy the rest of you day and continue to win money!" << endl;
}
bool playAgain(bool play) {
	string answer = "word";
	bool value = true;
	bool playAgain = play;

	cout << "Would you like to play again(Y/N)?" << endl;
	cout << "Response: ";
	getline(cin, answer);
	do {
		if ((answer[0] == 'Y' || answer[0] == 'y') && answer.length() == 1) {
			value = false;
			playAgain = true;
		}
		else if ((answer[0] == 'N' || answer[0] == 'n') && answer.length() == 1) {
			value = false;
			playAgain = false;
		}
		else {
			cout << "Please enter either 'Y' or 'N'." << endl;
			getline(cin, answer);
		}
	} while (value);
	cout << endl;
	return playAgain;
}