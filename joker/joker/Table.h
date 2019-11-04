#pragma once

#include <iostream>
#include "Player.h"

using std::string;
using std::cout;
using std::endl;

class Table {
	private:
		int money = 0;
		string hands[4][7] = { 
			{"брбр", "брбр", "брбр", "брбр", "брбр", "брбр", "брбр"},
			{ "брбр", "брбр", "брбр", "брбр", "брбр", "брбр", "брбр" },
			{ "брбр", "брбр", "брбр", "брбр", "брбр", "брбр", "брбр" },
			{ "брбр", "брбр", "брбр", "брбр", "брбр", "брбр", "брбр" }
		};

	public:
		void open(unsigned short index, Player* player, int n);
		void view();
		void bettingMoney(int& n);
		int ForWinner();
		~Table();
};