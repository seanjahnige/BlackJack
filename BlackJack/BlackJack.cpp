#include "BlackJack.h"
#include <iostream>
#include <string>
#include <cstdlib>  // Library has rand() in it
#include <ctime>    // Library for srand() and importing time

using namespace std;

// Constructor for the player of the game
BlackJack::BlackJack() {}

// Fills the deckValues array, cardNames array, and deck array
void BlackJack::fillDecks() {
	int count = 1;

	// Fills the bool deck with true for all indexes
	for (int i = 0; i < 52; i++) {
		deck[i] = true;
	}
	// Fills the string deck with the name of the cards
	cardNames[0] = "AceSpades ";
	cardNames[1] = "AceSuits ";
	cardNames[2] = "AceHearts ";
	cardNames[3] = "AceDiamonds ";
	cardNames[4] = "2Spades ";
	cardNames[5] = "2Suits ";
	cardNames[6] = "2Hearts ";
	cardNames[7] = "2Diamonds ";
	cardNames[8] = "3Spades ";
	cardNames[9] = "3Suits ";
	cardNames[10] = "3Hearts ";
	cardNames[11] = "3Diamonds ";
	cardNames[12] = "4Spades ";
	cardNames[13] = "4Suits ";
	cardNames[14] = "4Hearts ";
	cardNames[15] = "4Diamonds ";
	cardNames[16] = "5Spades ";
	cardNames[17] = "5Suits ";
	cardNames[18] = "5Hearts ";
	cardNames[19] = "5Diamonds ";
	cardNames[20] = "6Spades ";
	cardNames[21] = "6Suits ";
	cardNames[22] = "6Hearts ";
	cardNames[23] = "6Diamonds ";
	cardNames[24] = "7Spades ";
	cardNames[25] = "7Suits ";
	cardNames[26] = "7Hearts ";
	cardNames[27] = "7Diamonds ";
	cardNames[28] = "8Spades ";
	cardNames[29] = "8Suits ";
	cardNames[30] = "8Hearts ";
	cardNames[31] = "8Diamonds ";
	cardNames[32] = "9Spades ";
	cardNames[33] = "9Suits ";
	cardNames[34] = "9Hearts ";
	cardNames[35] = "9Diamonds ";
	cardNames[36] = "10Spades ";
	cardNames[37] = "10Suits ";
	cardNames[38] = "10Hearts ";
	cardNames[39] = "10Diamonds ";
	cardNames[40] = "JackSpades ";
	cardNames[41] = "JackSuits ";
	cardNames[42] = "JackHearts ";
	cardNames[43] = "JackDiamonds ";
	cardNames[44] = "QueenSpades ";
	cardNames[45] = "QueenSuits ";
	cardNames[46] = "QueenHearts ";
	cardNames[47] = "QueenDiamonds ";
	cardNames[48] = "KingSpades ";
	cardNames[49] = "KingSuits ";
	cardNames[50] = "KingHearts ";
	cardNames[51] = "KingDiamonds ";
	// Fills the int deck with the values of the cards
	for (int i = 0; i < 52; i += 4) {
		for (int j = i; j < (i + 4); j++) {
			deckValues[j] = count;
		}
		if (i < 36) {
			count++;
		}
	}
}

// Gives the user two cards
// Gives the user string of the cards and stores the value of the cards
void BlackJack::dealHand() {
	int firstDigit = 0, secondDigit = 0, total = 0;
	int firstCard = 0, secondCard = 0;
	bool value = true;

	cout << "Your Hand:" << endl;
	for (int i = 0; i < 2; i++) {
		do {
			firstDigit = rand() % 10;
			secondDigit = rand() % 10;
			while (firstDigit > 5) {
				firstDigit = rand() % 10;
			}
			if (firstDigit == 5) {
				while (secondDigit > 1) {
					secondDigit = rand() % 10;
				}
			}
			total = firstDigit * 10 + secondDigit;
			if (deck[total] == true) {
				value = false;
				deck[total] = false;
			} 
		} while (value);
		if (i == 0) {
			firstCard = total;
		}
		else if (i == 1) {
			secondCard = total;
		}
	}
	userHand = cardNames[firstCard] + cardNames[secondCard];
	cout << userHand << endl << endl;
	userSum1 = deckValues[firstCard] + deckValues[secondCard];
	if (firstCard < 4) {
		if (secondCard < 4) {
			userSum2 = 12;
		}
		else {
			userSum2 = 11 + deckValues[secondCard];
		}
	}
	else if (secondCard < 4) {
		userSum2 = deckValues[firstCard] + 11;
	}
	else {
		userSum2 = userSum1;
	}
	cout << userSum1 << " " << userSum2 << endl;  // TODO delete  when not needed
}

// After the user is dealt their cards this function lets the user either stay with the amount they have or get more cards
// The user is in this function until they hold or they have busted
void BlackJack::hitHold() {
	string answer = "";
	bool value = false;

	if (userSum1 == 21 || userSum2 == 21) {
		cout << "WINNER WINNER CHICKEN DINNER!!" << endl;
		cout << "You got Blackjack!" << endl;
		cout << endl;
	}
	else {
		answer = promptHitHold();
		if (answer[0] == '1') {
			cout << endl << "Now to see what you dealers hand is!?!?!" << endl << endl;
		}
		else {
			do {
				hit();
				if (userSum1 < 21) {
					answer = promptHitHold();
					if (answer[0] == '2') {
						value = true;
					}
					else {
						value = false;
					}
				}
				else {
					value = false;
				}
			} while (value);
			if (userSum1 == 21) {
				cout <<  "Congradulations you win!" << endl << endl;
			}
			else if (userSum2 == 21) {
				cout << "Congradulations you win!" << endl << endl;
			}
			else if (userSum1 > 21){
				cout << "BUST!! You Lose!" << endl << endl;
			}
			else {
				cout << endl << "Now to see what you dealers hand is!?!?!" << endl << endl;
			}
		}
	}
}

// After given the next cards index
// Calculates the userSum1, userSum2 and edits the userHand string
void BlackJack::hit() {
	int card = 0;

	card = getCard();
	userHand += cardNames[card];
	cout << "Your Hand:" << endl;
	cout << userHand << endl << endl;
	userSum1 += deckValues[card];
	if (card < 4) {
		userSum2 += 11;
		if (userSum2 > 21) {
			userSum2 -= 10;
		}
	}
	else {
		userSum2 = userSum1;
	}
	cout << userSum1 << " " << userSum2 << endl;  // TODO delete when not needed anymore
}

// Gives the user either the option to hit again or hold
// Returns the number they typed as a string
string BlackJack::promptHitHold() {
	string answer;
	bool value = true;

	cout << "Press the number next to what you would like to do:" << endl;
	cout << "1. Hold" << endl;
	cout << "2. Hit" << endl;
	cout << "Response: ";
	getline(cin, answer);
	do {
		if (answer[0] == '1' && answer.length() == 1) {
			value = false;
		}
		else if (answer[0] == '2' && answer.length() == 1) {
			value = false;
		}
		else {
			cout << "Please enter either one of the listed number." << endl;
			cout << "Response: ";
			getline(cin, answer);
		}
	} while (value);
	return answer;
}

// Returns the index of the new card
int BlackJack::getCard() {
	int firstDigit = 0, secondDigit = 0, total = 0;
	bool value = true;

	do {
		firstDigit = rand() % 10;
		secondDigit = rand() % 10;
		while (firstDigit > 5) {
			firstDigit = rand() % 10;
		}
		if (firstDigit == 5) {
			while (secondDigit > 1) {
				secondDigit = rand() % 10;
			}
		}
		total = firstDigit * 10 + secondDigit;
		if (deck[total] == true) {
			value = false;
			deck[total] = false;
		}
	} while (value);
	return total;
}

// Function deals the dealers hand and goes until it beats the users hand or busts
/*
void BlackJack::dealersHand() {
	
}
*/

void BlackJack::reset() {

}

/* Pseudocode
- Reset the deck to have all of the cards available to be used
	fillDecks();
	only does this once at the begining of the game
- Deal the initial hand to the user
	dealHand();
	give the user two cards randomly from the deck and tell them what they are and their total
- Prompt user to to either take a hit or stay
	hitHold();
	if (userSum equals 21)
		congradulate the user for winning
	else if (holds)
		then tell them what the next card is
		if (puts userSum over 21)
			congradulate the user for winning
		else
			tell the user they are wrong
	else (hit)
		hit();
		give the user another card
- Resets the needed objects
	reset();
	resets the bool deck back to all true
	resets the userSum1, userSum2
	resets userHand
*/
void BlackJack::playBlackJack() {
	fillDecks();
	dealHand();
	hitHold();
	if (userSum1 != 21) {
		//dealersHand();
	}
	reset();
}