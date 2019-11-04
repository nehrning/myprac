#include<iostream>
#include<windows.h>
#include<process.h>
#include"Player.h"
#include"Deck.h"
#include"Table.h"

using std::cout;
using std::cin;
using std::endl;

void main() {

	unsigned short num = 0;
	unsigned short openCard;
	Deck mydeck;

	while (1) {
		system("cls");
		srand(time(NULL));
		do {
			cout << "플레이어 수를 입력하시오(2~4, 0은 종료) : ";
			cin >> num;
			if (num == 0) return ;
		} while (num > 4 || num == 1);
		Table mytable;
		Player* player = new Player[num];

		mydeck.shuffle(); // 덱을 섞는다.

		for (unsigned short i = 0; i < 7; i++) {

//////////////////////////카드분배/////////////////////////////////////////
			for (int n = 0; n < num; n++) 
				(player + n)->setHands(i, mydeck.deal());
///////////////////////////////////////////////////////////////////////////

			mytable.view(); // 화면 출력

			switch (i){
				case 0: case 1: 
					continue;
				case 2: 
					do {
						cout << "공개할 카드 입력하시오(1~3) : ";
						cin >> openCard;
					} while (openCard > 3 || openCard == 0);
					mytable.open(openCard - 1, player, 0);
					for (int n = 1; n < num; n++)
						mytable.open(rand() % 3, player + n, n);
					break;
				case 3: case 4: case 5:
					for (int n = 0; n < num; n++)
						mytable.open(i, player + n, n);
					break;
				case 6:
					break;
			}
			getchar();
			system("cls");
			//betting -- 나중에 만들거 만들면 앞부분 뒤엎어야함
			//mytable.view(); 배팅 미완성
		}

		short max = 0;
		player->setValue();
		for (int i = 1; i < num; i++) {
			(player + i)->setValue();
			if (player[max] < player[i]) max = i;
		}
		for (int i = 0; i < num; i++)
			for (int j = 0; j < 7; j++)
				mytable.open(j, player + i, i);
		mytable.view();
		cout << max + 1 << "번 플레이어 승리\n\n" << endl;
		//(player + max)->setMoney(mytable.ForWinner()); 배팅 미완성
		getchar();
		mytable.~Table();
		for (int i = 0; i < num; i++)
			(player + i)->~Player();
	}

}