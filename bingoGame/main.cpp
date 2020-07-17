#include<iostream>
#include<time.h>
using namespace std;

int main() {
	int num[25] = {};
	for (int i = 0; i < 25; i++)
	{
		num[i] = i + 1;
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
	}
	int bingo = 0;

	while (true)
	{
		system("cls");

		//숫자를 5x5로 출력한다
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

		cout << "bingo Line: " << bingo << endl;
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

		bingo = 0;
		//가로,세로 줄 수를 구해준다

		int star1 = 0, star2 = 0;

		for (int i = 0; i < 5; i++)
		{
			star1 = star2 = 0;
			for (int j = 0; j < 5; j++)
			{
				//가로 별 개수를 구해준다.
				if (num[i * 5 + j] == INT_MAX)
					star1++;

				if (num[i + j * 5] == INT_MAX)
					star2++;

			}

			if (star1 == 5)
				bingo++;
			if (star2 == 5)
				bingo++;
		}


		//왼쪽 상단 -> 오른쪽 하단 대각선 체크
		star1 = 0;
		for (int i = 0; i < 25; i += 6)
		{
			if (num[i] == INT_MAX)
				star1++;
		}

		if (star1 == 5)
			bingo++;

		//오른쪽 상단->왼쪽 하단 대각선 체크
		star1 = 0;
		for (int i = 4; i <= 20; i += 4)
		{
			if (num[i] == INT_MAX)
				star1++;
		}

		if (star1 == 5)
			bingo++;
	}


}