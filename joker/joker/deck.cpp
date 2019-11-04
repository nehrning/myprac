#include "Deck.h"

void Deck::shuffle()
{
	short tmp;
	int num;

	deck = {};
	srand(time(NULL));
	for (int i = 0; i < 52; i++) {
		num = rand() % (52 - i);
		tmp = numbers[num];
		numbers[num] = numbers[51 - i];
		numbers[51 - i] = tmp;
	}
	for (int i = 0; i < 52; i++) 
		deck.push(cards[numbers[i]]);
}

string Deck::deal()
{
	string res = deck.top();
	deck.pop();
	return res;
}

Deck::~Deck() { }
