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

		//���ڸ� 5x5�� ����Ѵ�
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

		bingo = 0;
		//����,���� �� ���� �����ش�

		int star1 = 0, star2 = 0;

		for (int i = 0; i < 5; i++)
		{
			star1 = star2 = 0;
			for (int j = 0; j < 5; j++)
			{
				//���� �� ������ �����ش�.
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


		//���� ��� -> ������ �ϴ� �밢�� üũ
		star1 = 0;
		for (int i = 0; i < 25; i += 6)
		{
			if (num[i] == INT_MAX)
				star1++;
		}

		if (star1 == 5)
			bingo++;

		//������ ���->���� �ϴ� �밢�� üũ
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