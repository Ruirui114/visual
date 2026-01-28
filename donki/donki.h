#pragma once
#include "objBase.h"

class CDonki :public BaseVector {
public:
	CDonki();

	int Action(std::vector<std::unique_ptr<BaseVector>>& base, CMap& map);
	void Draw();

	//マップ上の位置;
	Point m_pos{ 0,0 };
	int framecount2;
	float x, y;
	int mame;

};