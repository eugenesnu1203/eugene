# include <iostream>

#define Bingo_Size 5
#define Bingo_Array_Size (Bingo_Size * Bingo_Size)
#define Dev_Log

// ���� ����

int MyBingo[25] = {};
int ComBingo[25] = {};
int CalledNumber = 0;
int turn = 1;
int MyBingoCount = 0;
int ComBingoCount = 0;
bool isgameplaying = true;

void MakeBoard();
void ShuffleBoard();
void PrintBoard();
void CallBingoNumber();
void MarkBingoNumber();
void GoToNextTurn();
void CheckBingoCount();


using namespace std;

void main()
{
	srand(time(NULL));
	MakeBoard();
	ShuffleBoard();
	while (isGamePlaying)
	{
		PrintBoard();
		CallBingoNumber();
		MarkBingoNumber();
		GoToNextTurn();
		CheckBingoCount();
		if (3 <= myBingoCount || 3 <= comBingoCount)
		{
			isGamePlaying = false;
		}
	}

	PrintBoard();
	if (comBingoCount == myBingoCount)
	{
		cout << "���º��Դϴ�." << endl;
	}
	else if (comBingoCount < myBingoCount)
	{
		cout << "�÷��̾ �¸��Ͽ����ϴ�." << endl;
	}
	else
	{
		cout << "��ǻ�Ͱ� �¸��Ͽ����ϴ�." << endl;
	}

}

void MakeBoard()
{
	for (int i = 0; i < BINGO_ARRAY_SIZE; i++)
	{
		myBingo[i] = i + 1;
	}

	for (int i = 0; i < BINGO_ARRAY_SIZE; i++)
	{
		comBingo[i] = i + 1;
	}
}

//2. ������ ����. (��, ��ǻ��)
void ShuffleBoard()
{
	for (int i = 0; i < 100000; i++)
	{
		int index1 = rand() % BINGO_ARRAY_SIZE;
		int index2 = rand() % BINGO_ARRAY_SIZE;

		int temp = myBingo[index1];
		myBingo[index1] = myBingo[index2];
		myBingo[index2] = temp;
	}

	for (int i = 0; i < 100000; i++)
	{
		int index1 = rand() % BINGO_ARRAY_SIZE;
		int index2 = rand() % BINGO_ARRAY_SIZE;

		int temp = comBingo[index1];
		comBingo[index1] = comBingo[index2];
		comBingo[index2] = temp;
	}
}

void PrintBoard()
{
	cout << "�� ������ " << endl;
	for (int i = 0; i < BINGO_SIZE; i++)
	{
		for (int j = 0; j < BINGO_SIZE; j++)
		{
			if (myBingo[i * BINGO_SIZE + j] == -1)
			{
				cout << "XX\t";
			}
			else
			{
				cout << myBingo[i * BINGO_SIZE + j] << "\t";
			}
		}
		cout << endl;
	}

	cout << "��� ������ " << endl;
	for (int i = 0; i < BINGO_SIZE; i++)
	{
		for (int j = 0; j < BINGO_SIZE; j++)
		{
			if (comBingo[i * BINGO_SIZE + j] == -1)
			{
				cout << "XX\t";
			}
			else
			{
				cout << comBingo[i * BINGO_SIZE + j] << "\t";
			}
		}
		cout << endl;
	}
}

// 4. ���� ���ڸ� �ϳ� �θ���.
void CallBingoNumber()
{
	cout << "[" << turn << "] ��° ��!" << endl;

	bool isValidation = false;
	while (isValidation == false)
	{
		if (turn % 2 == 1)
		{
			cout << "���� ���ڸ� �Է����ּ���." << endl;

			int input;
			cin >> input;

			calledNumber = input;
		}
		else
		{
			calledNumber = rand() % BINGO_ARRAY_SIZE + 1;
		}

		for (int i = 0; i < BINGO_ARRAY_SIZE; i++)
		{
			if (myBingo[i] == calledNumber)
			{
				isValidation = true;
			}
		}
	}

	cout << "�Ҹ� ���� : " << calledNumber << endl;
}

void MarkBingoNumber()
{
	for (int i = 0; i < BINGO_ARRAY_SIZE; i++)
	{
		if (myBingo[i] == calledNumber)
		{
			myBingo[i] = -1;
		}
	}

	for (int i = 0; i < BINGO_ARRAY_SIZE; i++)
	{
		if (comBingo[i] == calledNumber)
		{
			comBingo[i] = -1;
		}
	}
}

void GoToNextTurn()
{
	cout << "�� ����" << endl;
	turn++;
}


void CheckBingoCount()
{
	myBingoCount = 0;

	//������üũ
	for (int i = 0; i < BINGO_SIZE; i++)
	{
		bool isBingoLine = true;

		for (int j = 0; j < BINGO_SIZE; j++)
		{
			if (myBingo[i * BINGO_SIZE + j] != -1)
			{
				isBingoLine = false;
			}
		}

		if (isBingoLine)
		{
			myBingoCount++;
		}
	}

	//������üũ
	for (int i = 0; i < BINGO_SIZE; i++)
	{
		bool isBingoLine = true;

		for (int j = 0; j < BINGO_SIZE; j++)
		{
			if (myBingo[j * BINGO_SIZE + i] != -1)
			{
				isBingoLine = false;
			}
		}

		if (isBingoLine)
		{
			myBingoCount++;
		}
	}

	//�밢��üũ (\)
	{
		bool isBingoLine = true;
		for (int i = 0; i < BINGO_SIZE; i++)
		{
			if (myBingo[(BINGO_SIZE - 1) * i] != -1)
			{
				isBingoLine = false;
			}
		}
		if (isBingoLine)
		{
			myBingoCount++;
		}
	}

	//�밢��üũ (/)
	{
		bool isBingoLine = true;
		for (int i = 0; i < BINGO_SIZE; i++)
		{
			if (myBingo[i * BINGO_SIZE + i] != -1)
			{
				isBingoLine = false;
			}
		}
		if (isBingoLine)
		{
			myBingoCount++;
		}
	}

	comBingoCount = 0;

	//������üũ
	for (int i = 0; i < BINGO_SIZE; i++)
	{
		bool isBingoLine = true;

		for (int j = 0; j < BINGO_SIZE; j++)
		{
			if (comBingo[i * BINGO_SIZE + j] != -1)
			{
				isBingoLine = false;
			}
		}

		if (isBingoLine)
		{
			comBingoCount++;
		}

	}

	//������üũ
	for (int i = 0; i < BINGO_SIZE; i++)
	{
		bool isBingoLine = true;

		for (int j = 0; j < BINGO_SIZE; j++)
		{
			if (comBingo[j * BINGO_SIZE + i] != -1)
			{
				isBingoLine = false;
			}
		}

		if (isBingoLine)
		{
			comBingoCount++;
		}
	}

	//�밢��üũ (\)
	{
		bool isBingoLine = true;
		for (int i = 0; i < BINGO_SIZE; i++)
		{
			if (comBingo[(BINGO_SIZE - 1) * i] != -1)
			{
				isBingoLine = false;
			}
		}
		if (isBingoLine)
		{
			comBingoCount++;
		}
	}


	//�밢��üũ (\)
	{
		bool isBingoLine = true;
		for (int i = 0; i < BINGO_SIZE; i++)
		{
			if (comBingo[i * BINGO_SIZE + i] != -1)
			{
				isBingoLine = false;
			}
		}
		if (isBingoLine)
		{
			comBingoCount++;
		}
	}
}