#pragma once
#include"block.h"
#include "player.h"
#include"function.h"
#include "map.h"
extern bool onGround;
extern bool ladder;
extern bool yellow;

CBlock::CBlock(Point p, int _i, int _img ) {
	img = _img;

	ImgWidth = 32;
	ImgHeight = 32;

	pos = p;

	CutX = (_i % 16) * ImgWidth;
	CutY = (_i / 16) * ImgHeight;

	pri = 0;

	if (_i == 0)
		ID = BLOCK;
	else if (_i == 2)
		ID = LADDER;
	else if (_i == 3)
		ID = YELLOW;
	else if (_i == 4)
		ID = GOAL;


}

int CBlock::Action(std::vector<std::unique_ptr<BaseVector>>& base, CMap& map) {
	CPlayer* p = (CPlayer*)Get_obj(base,PLAYER);
	int chipX = p->pos.x / 32;
	int chipY = p->pos.y / 32;
	//床判定
	if (HitCheck_box(this, p) && this->ID == BLOCK) {
		onGround = true;
		p->m_pos.y = this->pos.y - ImgWidth;
		p->vec.y = 0.0f;
		p->pos.y = p->m_pos.y;
		DrawFormatString(0, 64, GetColor(255, 255, 255), "床です");
	}
	//はしご判定
	if (HitCheck_box(this, p) && this->ID == LADDER)
	{
		ladder = true;
		DrawFormatString(0, 32, GetColor(255, 255, 255), "はしごです");
	}
	//ブロック判定
	if (HitCheck_box(this, p) && this->ID == YELLOW)
	{
		yellow = true;
		FLAG = false;
		DrawFormatString(0, 80, GetColor(255, 255, 255), "ブロックです");
		
	}
	//ゴール判定
	if (HitCheck_box(this, p) && this->ID == GOAL)
	{
		DrawFormatString(30, 100, GetColor(255, 255, 255), "おめでとう");
	}
	return 0;
}


void CBlock::Draw() {
	DrawRectGraph(
		pos.x, pos.y,
		CutX, CutY,
		ImgWidth, ImgHeight,
		img,
		true
	);
}

