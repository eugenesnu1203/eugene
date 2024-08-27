# include <iostream>

#define Bingo_Size 5
#define Bingo_Array_Size (Bingo_Size * Bingo_Size)
#define Dev_Log

// 변수 정의

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
		cout << "무승부입니다." << endl;
	}
	else if (comBingoCount < myBingoCount)
	{
		cout << "플레이어가 승리하였습니다." << endl;
	}
	else
	{
		cout << "컴퓨터가 승리하였습니다." << endl;
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

//2. 빙고판 셔플. (나, 컴퓨터)
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
	cout << "내 빙고판 " << endl;
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

	cout << "상대 빙고판 " << endl;
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

// 4. 내가 숫자를 하나 부른다.
void CallBingoNumber()
{
	cout << "[" << turn << "] 번째 턴!" << endl;

	bool isValidation = false;
	while (isValidation == false)
	{
		if (turn % 2 == 1)
		{
			cout << "빙고 숫자를 입력해주세요." << endl;

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

	cout << "불린 숫자 : " << calledNumber << endl;
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
	cout << "턴 변경" << endl;
	turn++;
}


void CheckBingoCount()
{
	myBingoCount = 0;

	//가로줄체크
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

	//세로줄체크
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

	//대각선체크 (\)
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

	//대각선체크 (/)
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

	//가로줄체크
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

	//세로줄체크
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

	//대각선체크 (\)
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


	//대각선체크 (\)
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