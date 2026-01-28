#pragma once
#include "objBase.h"

class CPeech :public BaseVector {
public:
	CPeech();

	int Action(std::vector<std::unique_ptr<BaseVector>>& base, CMap& map);
	void Draw();

	//マップ上の位置;
	Point m_pos{ 0,0 };
	int framecount;
	float x, y;
	int mame;

};