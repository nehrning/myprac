#include "Table.h"

void Table::open(unsigned short index, Player* player, int n)
{
	hands[n][index] = player->getHands(index);
}

void Table::view()
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 7; j++)
			cout << hands[i][j].c_str() << " ";
		cout << endl;
	}
	cout << endl;
/*
14(공백)  20(2번)

\n 20(3번) 8(돈) 20(4번) \n

14(공백) 20(1번)

14 20(내 핸드 1번)
*/
}

void Table::bettingMoney(int& n)
{
	money += n;
}

int Table::ForWinner()
{
	int res = money;
	money = 0;
	return res;
}

Table::~Table() { }
