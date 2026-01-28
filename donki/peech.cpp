#pragma once
#include "peech.h"
#include"function.h"
#include "player.h"
CPeech::CPeech() {
	d_img = LoadGraph("image\\donki.png");

	//マップ初期位置
	m_pos.x = 320;//128
	m_pos.y = 162;//832
	//描画位置
	pos = m_pos;

	ImgWidth = 48;
	ImgHeight = 32;

	pri = 2;
}

int CPeech::Action(std::vector<std::unique_ptr<BaseVector>>& base, CMap& map) {
	CPlayer* p = (CPlayer*)Get_obj(base, PLAYER);
	//キャラ画像
	if (p->framecount2 < 8)
		CutX = 48;
	else if (p->framecount2 < 16)
		CutX = 96;
	else if (p->framecount2 < 24)
		CutX = 48;
	else if (p->framecount2 < 32)
		CutX = 96;
	else if (p->framecount2 <= 40)
		CutX = 0;
	return 0;
}
void CPeech::Draw() {
	DrawRectGraph(
		pos.x, pos.y,
		CutX, CutY,
		ImgWidth, ImgHeight,
		d_img,
		true
	);
}