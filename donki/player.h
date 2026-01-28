//player.h
#pragma once
#include "objBase.h"

constexpr int CHIP_SIZE = 32;
class CMap;

class CPlayer :public BaseVector {
public:
	CPlayer();

	int Action(std::vector<std::unique_ptr<BaseVector>>& base,CMap& map);
	void Draw();
	int ChipY;
	int ChipX;
	//マップ上の位置;
	Point m_pos{ 0,0 };
	int up_img;
	int framecount;
	float x, y;
	float vy;
	bool onGround;

	
};