#pragma once
#include<string>

using namespace std;

class BlackJack {
private:
	bool deck[52];  // The array holds the cards, 0-3 are Aces|4-7 are 2s|ect., holds true if card is still available and false if not
	string cardNames[52];  // Has the names of all of the cards in the same order as as the deck array used to add onto the userHand string, card names example "AceSpades " (space at end is supposed to be there)
	string userHand = "", dealersHand = "";  // The user's cards by name example "AceSpades KingHearts", is edited when user is hit
	int deckValues[52];  // Has the number values of the cards, 2 of spades = 2, jack of spades = 10 
	int userSum1 = 0, userSum2 = 0;  // Holds the sum of the cards dealt to the user, their are two to deal with aces
	//int dealerSum1 = 0, userSum2 = 0; // Holds the sums of the cards dealt to the dealer, their are two to deal with aces
public:
	BlackJack();

	void fillDecks();
	void dealHand();
	void hitHold();
	void hit();
	string promptHitHold();
	int getCard();
	//void dealersHand();
	void reset();
	void playBlackJack();
};