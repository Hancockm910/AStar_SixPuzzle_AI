#pragma once
#include "Board.h"
class AStar
{
public:
	AStar();
	~AStar();

private:
	struct State
	{
		int Index = -1;
		int ParentIndex = -1;
		vector<char>SavedBoard;
		int Move = -1; // Move coordinate

		int gn = 0; //Number of moves taken
		int hn = 0; //Sum of distance of the tiles from end location
		int f = 0; // f = gn + hn;
		bool operator < (const State& state) const
		{
			return f < state.f;
		}
	};

	bool CropToVisit(vector<vector<char>>Cropped, vector<char>Input);
	int HN(vector<char>Input); //Sum of distance of the tiles from end location
	vector<int>ValidMoves(vector<char>Input);

public:

	vector<int> AStarCalc(Board board);

};

