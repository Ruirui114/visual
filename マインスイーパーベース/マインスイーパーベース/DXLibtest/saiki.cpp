#include "saiki.h"

Board::Board() 
{
	for (int y = 0; y < 12; y++)
	{
		for (int x = 0; x < 15; x++)
		{
			cell[x][y].turf = ID::turf;
			cell[x][y].empty = ID::empty;
			cell[x][y].IsClick = false;
			cell[x][y].IsFlag = false;
			cell[x][y].x = x * 32;
			cell[x][y].y = y * 32;
		}
	}


}
void Board::Click()
{
	GetMousePoint(&mouseX, &mouseY);

	for (int y = 0; y < 12; y++)
	{
		for (int x = 0; x < 15; x++)
		{
			if (mouseX > x * 32 && mouseX <  x * 32 + 32 && mouseY >y * 32 && mouseY < y * 32 + 32)
			{
				if (GetMouseInput() & MOUSE_INPUT_LEFT)
				{
					cell[x][y].turf = cell[x][y].empty;
					FindAround(x, y);
				}

			}
		}
	}
}
void Board::FindAround(int i,int t)
{
	for (int y = -1; y <= 1; y++)
	{
		for (int x = -1; x <= 1; x++)
		{
			if (i < 0 || i > 12)
			{
				continue;
			}
			if (t < 0 || t > 15)
			{
				continue;
			}

			if (y == 0 && x == 0)
			{
				continue;
			}
			cell[i + x][t + y].IsClick = true;

			cell[i + x][t + y].turf = cell[i + x][t + y].empty;
			if (cell[i + x][t + y].empty == ID::empty && cell[i + x][t + y].IsClick == false)
			{
				FindAround(i + x, t + y);
			}
		}
	}
}
void Board::Draw()
{
	int a;
	for (int y = 0; y < 12; y++)
	{
		for (int x = 0; x < 15; x++)
		{
			switch (cell[x][y].turf)
			{
			case ID::empty: a = empty;
					break;
			case ID::one: a = one;
				break;
			case ID::two: a = two;
				break;
			case ID::three: a = three;
				break;
			case ID::four: a = four;
				break;
			case ID::five: a = five;
				break;
			case ID::six: a = six;
				break;
			case ID::seven: a = seven;
				break;
			case ID::turf: a = turf;
				break;
			case ID::frag: a = frag;
				break;
			case ID::mine: a = mine;
				break;

			}
			DrawGraph(cell[x][y].x, cell[x][y].y, a, true);
		
		}
	}
}