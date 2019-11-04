#include "Ranks.h"

int* check(string* cards)
{
	short cardVals[5][2] = { 0 };
	int val[2] = { 0 };
	// {랭크 밸류, top밸류 }

	///카드 벨류 분류
	for (int i = 0; i < 5; i++) {
		if(cards[i].substr(0, 2) == "♠")
			cardVals[i][0] = 1;
		else if (cards[i].substr(0, 2) == "♣")
			cardVals[i][0] = 2;
		else if (cards[i].substr(0, 2) == "◆")
			cardVals[i][0] = 3;
		else if (cards[i].substr(0, 2) == "♥")
			cardVals[i][0] = 4;
		switch (cards[i][2]) {
		case 'A':
			cardVals[i][0] += 140;
			break;
		case '2':
			cardVals[i][0] += 20;
			break;
		case '3':
			cardVals[i][0] += 30;
			break;
		case '4':
			cardVals[i][0] += 40;
			break;
		case '5':
			cardVals[i][0] += 50;
			break;
		case '6':
			cardVals[i][0] += 60;
			break;
		case '7':
			cardVals[i][0] += 70;
			break;
		case '8':
			cardVals[i][0] += 80;
			break;
		case '9':
			cardVals[i][0] += 90;
			break;
		case '0':
			cardVals[i][0] += 100;
			break;
		case 'J':
			cardVals[i][0] += 110;
			break;
		case 'Q':
			cardVals[i][0] += 120;
			break;
		case 'K':
			cardVals[i][0] += 130;
			break;
		}
	}
	//----------------------------정렬
	{
		short arr[5];
		for (int i = 0; i < 5; i++)
			arr[i] = cardVals[i][0];
		sort(arr, arr + 5);
		for (int i = 0; i < 5; i++)
			cardVals[i][0] = arr[i];
	}
	//----------------------------

	///같은 카드 체크
	short same = 1;
	cardVals[0][1] = same;
	for (int i = 1; i < 5; i++) {
		if (cardVals[i - 1][0] / 10 == cardVals[i][0] / 10)
			cardVals[i][1] = same;
		else
			cardVals[i][1] = ++same;
	}

	if (cardVals[4][1] == 5) {
		bool isFlush = flushCheck(cardVals);
		bool isStright = strightCheck(cardVals);
		if (!isFlush && !isStright)
			val[0] = 1;//탑
		else if (!isFlush && isStright)
			val[0] = 5;//스트레이트
		else if (isFlush && !isStright)
			val[0] = 6;//플러쉬
		else if (isFlush && isStright)
			val[0] = 9;//스트레이트 플러쉬
		
		///////////////topCheck////////////////// 
		if (cardVals[0][0] / 10 == 1) {
			val[1] = 14;
			for(int i = 4; i > 0; i--)
				val[1] = val[1] * 100 + cardVals[i][0] / 10;
		}
		else  {
			for (int i = 4; i >= 0; i--)
				val[1] = val[1] * 100 + cardVals[i][0] / 10;
		}
		/////////////////////////////////////////
	}
	else if (cardVals[4][1] == 4) {
		val[0] = 2;//원페어
		short priorityNum = -1;
		///////////////topCheck////////////////// 
		for (int i = 0; i < 4; i++)
			if (cardVals[i][0] / 10 == cardVals[i + 1][0] / 10) {
				priorityNum = i;
				break;
			}

		val[1] = cardVals[priorityNum][0] / 10;

		for (int i = 4; i >= 0; i--) {
			if (i == priorityNum || i == priorityNum + 1) continue;
			val[1] = val[1] * 100 + cardVals[i][0] / 10;
		}
		/////////////////////////////////////////
	}
	else if (cardVals[4][1] == 3) {
		int count = 1;
		for (int i = 1; i < 5; i++) {
			if (cardVals[i - 1][1] == cardVals[i][1]) count++;
			else count = 1;

			if (count == 3) {
				val[0] = 4;// 트리플
				short priorityNum = -1;
				///////////////topCheck//////////////////
				for (int j = 0; j < 4; j++)
					if (cardVals[j][0] / 10 == cardVals[j + 1][0] / 10) {
						priorityNum = j;
						break;//jbreak
					}

				val[1] = cardVals[priorityNum][0] / 10;

				for (int j = 4; j >= 0; j--) {
					if (j == priorityNum || j == priorityNum + 1 || j == priorityNum + 2) 
						continue;
					val[1] = val[1] * 100 + cardVals[j][0] / 10;
				}
				//////////////////////////////////////
				break;//ibreak
			}
		}
		if (count != 3) {
			val[0] = 3; // 투페어
		///////////////topCheck////////////////// 
			short priorityNum1 = -1;
			short priorityNum2 = -1;
			for (int i = 0; i < 4; i++)
				if (cardVals[i][0] / 10 == cardVals[i + 1][0] / 10) {
					if (priorityNum1 == -1)
						priorityNum1 = i;
					else
						priorityNum2 = i;
				}
			val[1] = cardVals[priorityNum2][0] / 10;
			val[1] = val[1] * 100 + cardVals[priorityNum1][0] / 10;
			switch (priorityNum1 + priorityNum2) {
				case 2:
					val[1] = val[1] * 100 + cardVals[4][0] / 10;
					break;
				case 3:
					val[1] = val[1] * 100 + cardVals[2][0] / 10;
					break;
				case 4:
					val[1] = val[1] * 100 + cardVals[0][0] / 10;
					break;
			}
		//////////////////////////////////////
		}
	}
	else {
		int count = 1;
		for (int i = 1; i < 5; i++) {
			if (cardVals[i - 1][1] == cardVals[i][1]) count++;
			else count = 1;
		}
		if (count == 1 || count == 4) {
			val[0] = 8; // 포카드
			///////////////topCheck////////////////// 
			if (cardVals[0][0] != cardVals[1][0]) {
				val[1] = cardVals[1][0] / 10;
				val[1] = val[1] * 100 + cardVals[0][0] / 10;
			}
			else {
				val[1] = cardVals[0][0] / 10;
				val[1] = val[1] * 100 + cardVals[4][0] / 10;
			}
			//////////////////////////////////////
		}
		else {
			val[0] = 7; // 풀하우스
			///////////////topCheck//////////////////
			if (cardVals[1][0] != cardVals[2][0]) {
				val[1] = cardVals[2][0] / 10;
				val[1] = val[1] * 100 + cardVals[0][0] / 10;
			}
			else {
				val[1] = cardVals[0][0] / 10;
				val[1] = val[1] * 100 + cardVals[3][0] / 10;
			}
			/////////////////////////////////////////
		}
	}
	
	return val;// * 1 +val[1] * 0;
}
//00,00,00,00,00
//숫자점수  


bool strightCheck(short (*cardVals)[2])
{
	bool res1 = true;
	bool res2 = true;
	for (int i = 0; i < 4; i++) {//A가 14일때 체크
		if ((cardVals[i][0] / 10) + 10 != cardVals[i + 1][0] / 10) {
			res1 = false;
			break;
		}
	}

	//----------------------------
	for (int i = 0; i < 4; i++)
		if (cardVals[i][0] / 10 == 14) {// A 탐색
			cardVals[i][0] = 10 + (cardVals[i][0] % 10);
			break;
		}
	{
		short arr[5];
		for (int i = 0; i < 5; i++)
			arr[i] = cardVals[i][0];
		sort(arr, arr + 5);
		for (int i = 0; i < 5; i++)
			cardVals[i][0] = arr[i];
	}//----------------------------

	for (int i = 0; i < 4; i++) {//A가 1일때 체크
		if ((cardVals[i][0] / 10) + 10 != cardVals[i + 1][0] / 10) {
			res2 = false;
			break;
		}
	}
	return res1 || res2;
}

bool flushCheck(short(*cardVals)[2])
{
	for (int i = 0; i < 4; i++)
		if (cardVals[i][0] % 10 != cardVals[i + 1][0] % 10)
			return false;
	return true;
}

int TopCheck(short(*cardVals)[2])
{
	return 0;
}

