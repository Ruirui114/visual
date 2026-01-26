#pragma once
#include "DxLib.h"

enum ID
{
	empty = 0,
	one = 1,
	two = 2,
	three = 3,
	four = 4,
	five = 5,
	six = 6,
	seven = 7,
	turf = 8,
	frag = 9,
	mine = 10,
};

struct Cell
{
	int turf;
	int empty;
	int x;
	int y;
	bool IsClick = false;
	bool IsFlag = false;
};

class Board
{
public:
	Board();
	void Click();
	void Draw();
	void FindAround(int i, int t);
private:
	Cell cell[15][12]{};
	int mouseX;
	int mouseY;

	int empty = LoadGraph("image\\empty.png");
	int one = LoadGraph("image\\one.png");
	int two = LoadGraph("image\\two.png");
	int three = LoadGraph("image\\three.png");
	int four = LoadGraph("image\\four.png");
	int five = LoadGraph("image\\five.png");
	int six = LoadGraph("image\\six.png");
	int seven = LoadGraph("image\\seven.png");
	int turf = LoadGraph("image\\turf.png");
	int frag = LoadGraph("image\\frag.png");
	int mine = LoadGraph("image\\mine.png");
};