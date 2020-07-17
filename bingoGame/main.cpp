#include<iostream>
#include<time.h>
using namespace std;

enum AI_MODE {
	AM_EASY = 1,
	AM_HARD
};

int main() {
	int num[25] = {};
	int aiNum[25] = {};

	for (int i = 0; i < 25; i++)
	{
		num[i] = i + 1;
		aiNum[i] = i + 1;
	}
	srand((unsigned)time(0));
	int temp, idx1, idx2;
	for (int i = 0; i < 100; i++)
	{
		idx1 = rand() % 25;
		idx2 = rand() % 25;

		temp = num[idx1];
		num[idx1] = num[idx2];
		num[idx2] = temp;

		//ai 숫자 섞기
		idx1 = rand() % 25;
		idx2 = rand() % 25;

		temp = aiNum[idx1];
		aiNum[idx1] = aiNum[idx2];
		aiNum[idx2] = temp;
	}
	int bingo = 0;
	int aiBingo = 0;
	int aiMode;

	//AI 난이도를 선택한다.
	while (true) {
		cout << "1. Easy" << endl;
		cout << "2. Hard" << endl;
		cout << "AI 모드를 선책하세요: ";
		cin >> aiMode;

		if (aiMode >= AM_EASY && aiMode <= AM_HARD)
			break;
	}

	/*
	AI Easy 모드는 현재 ai의 숫자 목록 중 *로 바뀌지 않은 숫자목록을 만들어서
	그 목록중 하나를 선택하게 한다 랜덤하게
	*/

	//선택이 안 된 목록 배열을 만들어준다.
	int noneSelect[25];
	int noneSelectCount = 0;


	while (true)
	{
		system("cls");

		//숫자를 5x5로 출력한다
		cout << "========= Player =============" << endl;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (num[i * 5 + j] == INT_MAX)
				{
					cout << "*" << "\t";
				}
				else
				{
					cout << num[i * 5 + j] << "\t";
				}
			}
			cout << endl;
		}

		cout << "bingo Line: " << bingo << endl << endl;

		//AI 빙고 판을 출력
		cout << "=========== AI ============" << endl;

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (aiNum[i * 5 + j] == INT_MAX)
					cout << "*" << "\t";
				else
					cout << aiNum[i * 5 + j] << "\t";
			}
			cout << endl;

		}
		//AI 빙고 줄 수를 출력
		cout << "AI bingo Line: " << aiBingo << endl;

		//줄 수가 5 이상이면 게임종료
		if (bingo >= 5) {
			cout << "Player 승리" << endl;
			break;
		}

		else if (aiBingo >= 5) {
			cout << "AI 승리" << endl;
			break;
		}

		cout << "숫자를 입력하세요: (0: 종료): ";
		int input;
		cin >> input;

		if (input == 0)
			break;
		else if (input < 1 || input >> 25)
			continue;

		//중복입력을 체크하기 위한 변수
		bool bAcc = true;

		//모든 숫자를 차례대로 검사해서 입력한 숫자와 같은 숫자가 있는 지 찾는다
		for (int i = 0; i < 25; i++)
		{
			//같은 숫자가 있을 경우
			if (input == num[i])
			{
				bAcc = false; //중복이 아니다
				num[i] = INT_MAX;
				break;
			}
		}

		if (bAcc) //중복되면 다시 숫자를 입력
			continue;

		//중복이 아니라면 AI의 숫자도 찾아서 *로 바꿔준다
		for (int i = 0; i < 25; i++)
		{
			if (aiNum[i] == input) {
				aiNum[i] = INT_MAX;
			}
		}

		//AI가 선택을 한다. 선택은 AI모드에 따라 달라진다
		switch (aiMode)
		{
		case AM_EASY:
			cout << "AIMode: Easy" << endl;
			//선택안 된 숫자 목록을 만들어준다 
			noneSelectCount = 0;
			for (int i = 0; i < 25; i++) 
			{
				if (aiNum[i] != INT_MAX) 
				{
					noneSelect[noneSelectCount] = aiNum[i];
					noneSelectCount++;
				}
			}
			input = noneSelect[rand() % noneSelectCount];
			break;

		case AM_HARD:
			break;
		}

		//AI가 숫자를 선택했으므로 플레이어와 AI의 숫자를 *로 바꿔준다

		for (int i = 0; i < 25; i++) 
		{
			if (aiNum[i] == input)
			{
				aiNum[i] = INT_MAX;
				break;
			}
		}

		for (int i = 0; i < 25; i++)
		{
			if (num[i] == input)
			{
				num[i] = INT_MAX;
				break;
			}
		}

		bingo = 0;
		aiBingo = 0;
		//가로,세로 줄 수를 구해준다

		int star1 = 0, star2 = 0;
		int aiStar1 = 0, aiStar2 = 0;

		for (int i = 0; i < 5; i++)
		{
			star1 = star2 = 0;
			aiStar1 = aiStar2 = 0;
			for (int j = 0; j < 5; j++)
			{
				//가로 별 개수를 구해준다.
				if (num[i * 5 + j] == INT_MAX)
					star1++;

				if (num[i + j * 5] == INT_MAX)
					star2++;

				if (aiNum[i * 5 + j] == INT_MAX)
					aiStar1++;

				if (aiNum[i + j * 5] == INT_MAX)
					aiStar2++;
			}

			if (star1 == 5)
				bingo++;
			if (star2 == 5)
				bingo++;
			if (aiStar1 == 5)
				aiBingo++;
			if (aiStar2 == 5)
				aiBingo++;
		}


		//왼쪽 상단 -> 오른쪽 하단 대각선 체크
		star1 = 0;
		aiStar1 = 0;
		for (int i = 0; i < 25; i += 6)
		{
			if (num[i] == INT_MAX)
				star1++;
			if (aiNum[i] == INT_MAX)
				aiStar1++;
		}

		if (star1 == 5)
			bingo++;
		if (aiStar1 == 5)
			aiBingo++;


		//오른쪽 상단->왼쪽 하단 대각선 체크
		star1 = 0;
		aiStar1 = 0;
		for (int i = 4; i <= 20; i += 4)
		{
			if (num[i] == INT_MAX)
				star1++;
			if (aiNum[i] == INT_MAX)
				aiStar1++;
		}

		if (star1 == 5)
			bingo++;
		if (aiStar1 == 5)
			aiBingo++;
	}
}