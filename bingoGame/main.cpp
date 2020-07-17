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

		//ai ���� ����
		idx1 = rand() % 25;
		idx2 = rand() % 25;

		temp = aiNum[idx1];
		aiNum[idx1] = aiNum[idx2];
		aiNum[idx2] = temp;
	}
	int bingo = 0;
	int aiBingo = 0;
	int aiMode;

	//AI ���̵��� �����Ѵ�.
	while (true) {
		cout << "1. Easy" << endl;
		cout << "2. Hard" << endl;
		cout << "AI ��带 ��å�ϼ���: ";
		cin >> aiMode;

		if (aiMode >= AM_EASY && aiMode <= AM_HARD)
			break;
	}

	/*
	AI Easy ���� ���� ai�� ���� ��� �� *�� �ٲ��� ���� ���ڸ���� ����
	�� ����� �ϳ��� �����ϰ� �Ѵ� �����ϰ�
	*/

	//������ �� �� ��� �迭�� ������ش�.
	int noneSelect[25];
	int noneSelectCount = 0;


	while (true)
	{
		system("cls");

		//���ڸ� 5x5�� ����Ѵ�
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

		//AI ���� ���� ���
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
		//AI ���� �� ���� ���
		cout << "AI bingo Line: " << aiBingo << endl;

		//�� ���� 5 �̻��̸� ��������
		if (bingo >= 5) {
			cout << "Player �¸�" << endl;
			break;
		}

		else if (aiBingo >= 5) {
			cout << "AI �¸�" << endl;
			break;
		}

		cout << "���ڸ� �Է��ϼ���: (0: ����): ";
		int input;
		cin >> input;

		if (input == 0)
			break;
		else if (input < 1 || input >> 25)
			continue;

		//�ߺ��Է��� üũ�ϱ� ���� ����
		bool bAcc = true;

		//��� ���ڸ� ���ʴ�� �˻��ؼ� �Է��� ���ڿ� ���� ���ڰ� �ִ� �� ã�´�
		for (int i = 0; i < 25; i++)
		{
			//���� ���ڰ� ���� ���
			if (input == num[i])
			{
				bAcc = false; //�ߺ��� �ƴϴ�
				num[i] = INT_MAX;
				break;
			}
		}

		if (bAcc) //�ߺ��Ǹ� �ٽ� ���ڸ� �Է�
			continue;

		//�ߺ��� �ƴ϶�� AI�� ���ڵ� ã�Ƽ� *�� �ٲ��ش�
		for (int i = 0; i < 25; i++)
		{
			if (aiNum[i] == input) {
				aiNum[i] = INT_MAX;
			}
		}

		//AI�� ������ �Ѵ�. ������ AI��忡 ���� �޶�����
		switch (aiMode)
		{
		case AM_EASY:
			cout << "AIMode: Easy" << endl;
			//���þ� �� ���� ����� ������ش� 
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

		//AI�� ���ڸ� ���������Ƿ� �÷��̾�� AI�� ���ڸ� *�� �ٲ��ش�

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
		//����,���� �� ���� �����ش�

		int star1 = 0, star2 = 0;
		int aiStar1 = 0, aiStar2 = 0;

		for (int i = 0; i < 5; i++)
		{
			star1 = star2 = 0;
			aiStar1 = aiStar2 = 0;
			for (int j = 0; j < 5; j++)
			{
				//���� �� ������ �����ش�.
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


		//���� ��� -> ������ �ϴ� �밢�� üũ
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


		//������ ���->���� �ϴ� �밢�� üũ
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