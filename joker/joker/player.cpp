#include "Player.h"

void Player::setValue() {
	int* returnVal;
	int max[2];
	string rankHands[5];
	string str = combination("", 0, 7, 5, 0);

	for (int i = 0; i < 5; i++) {
		int start = 0 + (i * 3);
		rankHands[i] = str.substr(start, 3);
	}
	returnVal = check(rankHands);
	max[0] = returnVal[0];
	max[1] = returnVal[1];
	for (int i = 1; i < 21; i++) {
		for (int j = 0; j < 5; j++) {
			int start = (i * 15) + (j * 3);
			rankHands[j] = str.substr(start, 3);
		}
		returnVal = check(rankHands);

		if (max[0] < returnVal[0]) {
			max[0] = returnVal[0];
			max[1] = returnVal[1];
		}
		else if (max[0] == returnVal[0] && max[1] < returnVal[1]) {
			max[0] = returnVal[0];
			max[1] = returnVal[1];
		}
	}
	value = max[0];
	topValue = max[1];
	
	string rankStr;
	switch (max[0]) {
	case 1:
		rankStr = "top";
		break;
	case 2:
		rankStr = "one pair";
		break;
	case 3:
		rankStr = "two pair";
		break;
	case 4:
		rankStr = "triple";
		break;
	case 5:
		rankStr = "stright";
		break;
	case 6:
		rankStr = "flush";
		break;
	case 7:
		rankStr = "full house";
		break;
	case 8:
		rankStr = "four card";
		break;
	case 9:
		rankStr = "stright flush";
		break;
	}

	std::cout << rankStr.c_str() << " " << max[1] << std::endl;
}

unsigned short Player::getValue() const
{
	return value;
}

int Player::getTopValue() const
{
	return topValue;
}

void Player::setHands(unsigned short& i, string card)
{
	hands[i] = card;
}

string Player::getHands(unsigned short& i)
{
	return hands[i];
}

void Player::setMoney(int n)
{
	money += n;
}

int Player::getMoney()
{
	return money;
}

bool Player::operator<(const Player& player) const
{
	if (getValue() < player.getValue()) return true;
	else if (getValue() == player.getValue()) return getTopValue() < player.getTopValue();
	else return false;
}

string Player::combination(string res, int index, int n, int r, int pick)
{ 
	if (pick == r) return res;
	else if (index == n) return "";
	
	return combination(res, index + 1, 7, 5, pick) +
	combination(res + hands[index], index + 1, 7, 5, pick + 1);
}

Player::~Player() { }