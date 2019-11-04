#pragma once
#include <iostream>
#include<string>
#include "Ranks.h"
using std::string;


class Player {
	private:
		unsigned short value = 0;
		int topValue = 0;
		int money = 100;
		string hands[7];

	public:
		void setHands(unsigned short& i, string card);
		string getHands(unsigned short& i);
		void setMoney(int n);
		int getMoney();
		void setValue();
		unsigned short getValue() const;
		int getTopValue() const;
		bool operator<(const Player& player) const;
		string combination(string res, int index, int n, int r, int pick);
		~Player();
};