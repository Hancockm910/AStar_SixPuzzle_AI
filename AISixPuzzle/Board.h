#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

class Board
{
public:
	Board() 
	{
	}
	~Board() 
	{

	}

private:

public:
	vector<char>Squares;
	bool WinCondition(vector<char>FinalBoard);
	void PrintBoard(vector<char>Input);
	int GetEmpty(vector<char>Input);
	vector<char>MoveTile(vector<char>Input, int Swap);

};

