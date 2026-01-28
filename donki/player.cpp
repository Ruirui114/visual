//player.cpp
#pragma once
#include "player.h"
#include "block.h"
#include"function.h"
#include "ladder.h"
#include "map.h"
bool ladder = false;
bool onGround = false;
bool yellow = false;
//extern CMap mapObj;
CPlayer::CPlayer() {
	img = LoadGraph("image\\chara.png");
	
	//マップ初期位置
	m_pos.x = 736;//128 ,250 320
	m_pos.y = 192;//832, 100
	//描画位置
	pos = m_pos;

	ChipX = pos.x / 32;
	ChipY = pos.y / 32;

	ImgWidth = 32;
	ImgHeight = 32;
	
	
	framecount = 0;
	pri = 1;
	ID = PLAYER;
}


int CPlayer::Action(vector<unique_ptr<BaseVector>>& base, CMap& map)
{

	const float jumpPower = -8.0f;
	const float moveSpeed = 2.0f;
	const float gravity = 2.0f;
	int move = false;
	int up_move = false;

	int px = (pos.x + ImgWidth / 2) / CHIP_SIZE;
	int py = (pos.y + ImgHeight + 1) / CHIP_SIZE;
	int underChip = map.GetChip(px, py);

	ChipX = pos.x / 32;
	ChipY = pos.y / 32;

	//重力
	if (onGround == true)
	{
		vy = 0.0f;
		up_move = false;
	}
	else
	{
		vy = gravity;
	}
	
	vec.x = 0.0f; vec.y = 0.0f;
	pos.y += vy;
	//プレイヤー操作
	if (CheckHitKey(KEY_INPUT_A)) {
		vec.x = -moveSpeed;
		CutY = 33;
		move = true;
	}
	if (CheckHitKey(KEY_INPUT_D)) {
		vec.x = moveSpeed;
		CutY = 0;
		move= true;
	}
	if (CheckHitKey(KEY_INPUT_SPACE)) {
		onGround = false;
		move = true;
		up_move = false;
		vec.y += -5.0f;
	}
	//はしご
	if (ladder == true)
	{
		DrawFormatString(0, 48, GetColor(255, 255, 255), "登れます");
		if (CheckHitKey(KEY_INPUT_W)) {
			vec.y += -1.5;
			onGround = true;
			move = false;
			up_move = true;
		}
		if (CheckHitKey(KEY_INPUT_S)) {
			vec.y += 1.5;
			onGround = true;
			move = false;
			up_move = true;
		}
	}
	else 
	{
		onGround = false;
		up_move = false;
	}

	if (underChip == 2)
	{
		onGround = true;
		DrawFormatString(30, 48, GetColor(255, 255, 255), "降りれます");
		if (CheckHitKey(KEY_INPUT_S)) {
			DrawFormatString(30, 48, GetColor(255, 255, 255), "降りてます");
		}
	}
	else
	{
		DrawFormatString(30, 48, GetColor(255, 255, 255), "aaaaaaaa");
	}

	//キャラ画像
	if (move == true)
	{
		DrawFormatString(300, 48, GetColor(255, 255, 255), "count = %d",framecount);
		img = LoadGraph("image\\chara.png");
		framecount++;
		if (framecount < 4)
			CutX = 32;
		else if (framecount < 8)
			CutX = 64;
		else if (framecount <= 12)
		{
			CutX = 0;
			framecount = 0;
		}
	}

	if (up_move == true)
	{
		CutY = 0;
		DrawFormatString(300, 32, GetColor(255, 255, 255), "upmove");
		img = LoadGraph("image\\upchara2.png");
		framecount++;
		if (framecount < 4)
			CutX = 32;
		else if (framecount < 8)
		{
			CutX = 0;
			framecount = 0;
		}
	}
	if (framecount >= 13)
	{
		framecount = 0;
	}
	pos.x += vec.x;
	pos.y += vec.y;

	if (pos.y == 162 && pos.x >= 300 && pos.x <= 380)
	{
		DrawFormatString(200, 48, GetColor(255, 255, 255), "おめでとう");
	}

	DrawFormatString(100, 48, GetColor(255, 255, 255), "y = %.1f", pos.y);
	DrawFormatString(100, 65, GetColor(255, 255, 255), "x = %.1f", pos.x);

	DrawFormatString(350, 64, GetColor(255, 255, 255),
		"px:%d py:%d chip:%d", px, py, underChip);
	return 0;
}

void CPlayer::Draw() {
	DrawBox(pos.x, pos.y, pos.x + 32, pos.y + 32, (255, 255, 255), false);
	DrawRectGraph(
		pos.x, pos.y,
		CutX, CutY,
		ImgWidth, ImgHeight,
		img,
		true
	);

}


///のぼりが出来たら降りるのをやりたいあとほかのキャラクター配置したい
//プレイヤーの当たり判定だけを小さくしたいもしくは丸の当たり判定にする