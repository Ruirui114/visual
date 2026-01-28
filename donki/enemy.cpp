#pragma once
#include "enemy.h"
#include "block.h"
#include"function.h"
#include "map.h"
#include "player.h"

#define CHIP_SIZE 32
#define BLOCK     1  

CEnemy::CEnemy() : CEnemy(128, 832)
{
}

CEnemy::CEnemy(int startX, int startY) {
	img = LoadGraph("image\\chara.png");

    pos.x = startX;
    pos.y = startY;

    vec.x = 0.0f;
    vec.y = 0.0f;

    ImgWidth = 32;
    ImgHeight = 32;

    onGround = false;
    dir = 1;
    jumpTimer = 60;   // 60フレームごとにジャンプ

    framecount = 0;
    ID = ENEMY;
}


int CEnemy::Action(vector<unique_ptr<BaseVector>>& base, CMap& map)
{
    const float GRAVITY = 0.4f;
    const float JUMP_POWER = -8.0f;
    const float AIR_MOVE = 4.0f;

    // --- 地面判定 ---
    int ChipX = (pos.x + ImgWidth / 2) / CHIP_SIZE;
    int ChipY = (pos.y + ImgHeight) / CHIP_SIZE;

    int underChip = map.GetChip(ChipX, ChipY + 1);

    if (underChip == BLOCK)
    {
        onGround = true;
        vec.y = 0.0f;

        // めり込み防止
        pos.y = ChipY * CHIP_SIZE - ImgHeight;
    }
    else
    {
 
        onGround = false;
        vec.y += GRAVITY;
    }

    // --- ジャンプ管理 ---
    if (onGround)
    {
        vec.x = 0.0f;  // 地上では横移動しない

        jumpTimer--;
        if (jumpTimer <= 0)
        {
            vec.y = JUMP_POWER;
            jumpTimer = 60;
        }
    }
    else
    {
        // ジャンプ中だけ左右移動
        vec.x = AIR_MOVE * dir;
 
    }


    // --- 移動反映 ---
    pos.x += vec.x;
    pos.y += vec.y;
    return 0;
}

void CEnemy::Draw() {
	DrawBox(pos.x, pos.y, pos.x + 32, pos.y + 32, (255, 255, 255), false);
	DrawRectGraph(
		pos.x, pos.y,
		CutX, CutY,
		ImgWidth, ImgHeight,
		img,
		true
	);

}

