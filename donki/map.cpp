#pragma once
#include "map.h"
#include "block.h"
#include "player.h"
#include "function.h"
#include "ladder.h"
extern bool yellow;
//ï∂éöï™äÑä÷êî
vector<string> split(string& input, char delimiter) {
	istringstream stream(input);
	string field;
	vector<string> result;
	while (getline(stream, field, delimiter)) {
		result.push_back(field);
	}
	return result;
}

CMap::CMap() {
	img = LoadGraph("image\\donki4.png");
}
void CMap::LoadMap() {
	ifstream fp("image\\donki2.txt");
	string str;

	if (!fp.fail()) {
		for (int y = 0; y < 30; y++)
		{
			getline(fp, str);
			vector<string> strv = split(str, ',');
			for (int x = 0; x < 32; x++) {
				map[y][x] = stoi(strv.at(x));
			}
		}
		fp.close();
	}
}


int CMap::GetChip(int chipX, int chipY)
{
    if (chipX < 0 || chipX >= 32 || chipY < 0 || chipY >= 30)
        return -1;

    return map[chipY][chipX];
}

void CMap::Map_Obj_Creation(vector<unique_ptr<BaseVector>>& base) {
	for (int y = 0; y < 30; y++) {
		for (int x = 0; x < 32; x++) {
			Point p{ x * 32,y * 32 };

			base.emplace_back(std::make_unique<CBlock>(p, map[y][x], img));

			if (map[y][x] == 0)
			{
				DrawBox(
				    p.x,
					p.y,
					p.x + 32,
					p.y + 32,
					GetColor(255, 0, 0),
					false
				);
			}
			if (map[y][x] == 2)
			{
				DrawBox(
					p.x + 14,
					p.y,
					p.x + 18,
					p.y + 32,
					GetColor(255, 0, 0),
					false
				);
			}
			if (map[y][x] == 3)
			{
				DrawBox(
					p.x,
					p.y,
					p.x + 32,
					p.y + 32,
					GetColor(255, 0, 0),
					false
				);
			}
			if (yellow == true)
			{
				map[y][x] = 1;
			}
		}
	}

}
