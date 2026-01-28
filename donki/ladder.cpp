#pragma once
#include "ladder.h"
#include "player.h"
#include"function.h"
//Žg‚Á‚Ä‚¢‚È‚¢
extern bool ladder;
CLadder::CLadder(Point p, int _i, int _img) {
	img = _img;

	ImgWidth = 32;
	ImgHeight = 32;

	pos = p;

	CutX = (_i % 16) * ImgWidth;
	CutY = (_i / 16) * ImgHeight;

	pri = 0;

	//if (_i == 2)
	//	ID = LADDER;

}

int CLadder::Action(vector<unique_ptr<BaseVector>>& base) {
	CPlayer* p = (CPlayer*)Get_obj(base, PLAYER);
	


	//if (HitCheck_box(this, p) && this->ID == LADDER) {

		//ladder = true;

	//}
	//else
	//{
	//	ladder = false;
	//}

	return 0;
}


void CLadder::Draw() {
	DrawRectGraph(
		pos.x, pos.y,
		CutX, CutY,
		ImgWidth, ImgHeight,
		img,
		true
	);
	//DrawBox(pos.x, pos.y, pos.x + 32, pos.y + 32, GetColor(255, 0, 0), false);
}