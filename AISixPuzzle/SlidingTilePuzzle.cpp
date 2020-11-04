#include "SlidingTilePuzzle.h"
#include <fstream>
#include <sstream>
#include <vector>



SlidingTilePuzzle::SlidingTilePuzzle()
{
}

SlidingTilePuzzle::~SlidingTilePuzzle()
{
}

void SlidingTilePuzzle::Play()
{
	vector<char>Input = { 'B', 'B', 'B', ' ', 'W', 'W', 'W' };
	Board b;
	b.Squares = Input;
	AStar a;
	vector<int>Moves = a.AStarCalc(b);

	reverse(begin(Moves), end(Moves));

	int TotalMoves = 0;
	for (auto i: Moves)
	{
		b.PrintBoard(Input);
		Input = b.MoveTile(Input, i);
		TotalMoves++;
	}
	b.PrintBoard(Input);

	cout << "\n=================================\n";
	cout << "TotalMoves: " << TotalMoves << endl;

}
