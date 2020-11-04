#include "Board.h"

using namespace std;

bool Board::WinCondition(vector<char>FinalBoard)
{
	int White = 0;
	for (auto i : FinalBoard)
	{
		if (i == 'B' && White != 3)
			return false;
		if (i == 'W')
			White++;
	}
	return true;
}

void Board::PrintBoard(vector<char>Input)
{
	cout << endl;
	cout << " ";
	for (int j = 0; j < Input.size(); j++)
	{
		cout << j + 1 << " ";
	}
	cout << endl;
	for (int j = 0; j < Input.size(); j++)
	{
		cout << "---";
	}
	cout << endl;
	for (int j = 0; j < Input.size(); j++)
	{
		cout << "|" << Input[j];
	}
	cout << "|" << endl;
	for (int j = 0; j < Input.size(); j++)
	{
		cout << "---";
	}
	cout << endl << endl;
}

int Board::GetEmpty(vector<char>Input)
{
	for (int i = 0; i < Input.size(); i++)
		if (Input[i] == ' ')
			return i;
}

vector<char> Board::MoveTile(vector<char>Input, int Swap)
{
	vector<char>RetVec = Input;
	int Empty = GetEmpty(RetVec);
	swap(RetVec[Swap], RetVec[Empty]);
	return RetVec;
}
