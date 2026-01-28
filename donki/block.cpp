#pragma once
#include"block.h"
#include "player.h"
#include"function.h"
#include "map.h"
#include "enemy.h"

extern bool onGround;
extern bool ladder;
extern bool yellow;
extern bool underladder;

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
	CEnemy* e = (CEnemy*)Get_obj(base, ENEMY);
	

	int pchipX = (p->pos.x + p->ImgWidth / 2) / CHIP_SIZE;
	int pchipY = (p->pos.y + p->ImgHeight) / CHIP_SIZE;

	//int echipX = (e->pos.x + e->ImgWidth / 2) / CHIP_SIZE;
	//int echipY = (e->pos.y + e->ImgHeight) / CHIP_SIZE;

	int ladderChip = map.GetChip(pchipX, pchipY + 2);
	
	//int chipX = p->pos.x / 32;
	//int chipY = p->pos.y / 32;
	// 
	//床判定
	if (HitCheck_box(this, p) && this->ID == BLOCK) {
		onGround = true;
		p->pos.y = this->pos.y - ImgWidth;
		p->vec.y = 0.0f;
		ladderChip = map.GetChip(pchipX, pchipY + 2);
		DrawFormatString(0, 64, GetColor(255, 255, 255), "床です");
		DrawFormatString(500, 96, GetColor(255, 255, 255), "ladderChip:%d  LADDER:%d", ladderChip, LADDER);
		if (ladderChip == 2 || ladderChip == LADDER)
		{
			underladder = true;
			DrawFormatString(200, 400, GetColor(255, 255, 255), "下はしごです");
		}
		else
		{
			underladder = false;
		}
	}	

	//if (HitCheck_box(this, e) && this->ID == BLOCK) {
	//	onGround = true;
	//	e->pos.y = this->pos.y - ImgWidth;
	//	e->vec.y = 0.0f;
	//	ladderChip = map.GetChip(pchipX, pchipY + 2);
	//	DrawFormatString(0, 64, GetColor(255, 255, 255), "床です");
	//	DrawFormatString(500, 96, GetColor(255, 255, 255), "ladderChip:%d  LADDER:%d", ladderChip, LADDER);
	//}

	if (ladderChip == 2 || ladderChip == LADDER)
	{
		underladder = true;
		DrawFormatString(200, 400, GetColor(255, 255, 255), "下はしごです");
	}
	else
	{
		underladder = false;
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

