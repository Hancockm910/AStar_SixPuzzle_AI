#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#include "Board.h"
#include "AStar.h"
#include "SlidingTilePuzzle.h"


int main(void)
{
	SlidingTilePuzzle SL;

	SL.Play();

	return system("pause");
}