#include "AStar.h"
#include <queue>
#include <algorithm>

AStar::AStar()
{
}

AStar::~AStar()
{
}

bool AStar::CropToVisit(vector<vector<char>>Cropped, vector<char>Input)
{
	for (auto i: Cropped)
	{
		if (i == Input)
		{
			return false;
		}
	}
	return true;
}

int AStar::HN(vector<char>Input)
{
	//int WhiteTile = 0;
	//int BlackTile = 0;
	//int Total = 0;
	//for (auto i: Input)
	//{
	//	if (i == 'B')
	//		BlackTile++;
	//	else if (i == 'W')
	//		WhiteTile++;
	//	
	//	if (BlackTile == 3)
	//		return 3 - WhiteTile;
	//}
	//return Total;
	int WhiteTile = 0;
	int BlackTile = 0;
	int Total = 0;
	for (auto i : Input)
	{
		if (i == 'B')
		{
			BlackTile++;
			Total += (3 - WhiteTile);
		}
		else if (i == 'W')
			WhiteTile++;

	}
	return Total;
}

vector<int> AStar::ValidMoves(vector<char>Input)
{
	// Set empty location
	int Empty = -1;
	for (int i = 0; i < Input.size(); i++)
		if (Input[i] == ' ')
			Empty = i;
	// Return indexes within 3 squares of empty
	vector<int>RetVec;
	for (int i = 0; i < Input.size(); i++)
		if (Input[i] != ' ' && abs(Empty - i) < 4)
			RetVec.push_back(i);
	return RetVec;
}

vector<int> AStar::AStarCalc(Board board)
{
	State Current; // Current state of the game
	vector<State>ToVisit; // Saved States intending to visit
	vector<State>Visited; // Saved visited states
	vector<vector<char>>CropVisited; // Save all boards visited
	
	Current.SavedBoard = board.Squares; // Initialisisng the state
	ToVisit.push_back(Current);

	while (!ToVisit.empty())
	{
		sort(ToVisit.begin(), ToVisit.end());

		Current = ToVisit[0];
		CropVisited.push_back(Current.SavedBoard);
		ToVisit.erase(ToVisit.begin());
		Current.Index = Visited.size();
		Visited.push_back(Current);

		if (board.WinCondition(Current.SavedBoard))
		{
			cout << "\n\nDONE\n\n";
			vector<int> Path;
			while (Current.ParentIndex != -1)
			{
				// Fill path with coordinates for moves that lead to completed board
				Path.push_back(Current.Move);
				Current = Visited[Current.ParentIndex];
			}
			return Path;
		}
		vector<int>Moves = ValidMoves(Current.SavedBoard);
		for (auto i: Moves)
		{
			State Child;
			Child.ParentIndex = Current.Index;

			int Blank = board.GetEmpty(Current.SavedBoard);
			int GN = abs(Blank - i) - 1;
			if (GN == 0)
				GN = 1;
			Child.gn = Current.gn + GN; 
			//Child.gn = Current.gn + 1;

			Child.Move = i;
			Child.SavedBoard = Current.SavedBoard;
			Child.SavedBoard = board.MoveTile(Child.SavedBoard, Child.Move);
			Child.hn = HN(Child.SavedBoard);

			Child.f = Child.hn + Child.gn;
			if (CropToVisit(CropVisited, Child.SavedBoard))
				ToVisit.push_back(Child);
		}
	}
}


