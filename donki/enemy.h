#pragma once
#include "objBase.h"

class CMap;

class CEnemy :public BaseVector {
public:
    CEnemy();
    CEnemy(int startX, int startY);

    int Action(vector<unique_ptr<BaseVector>>& base, CMap& map);
    void Draw();

private:
    VECTOR pos;   // 位置（描画・判定すべてこれ）
    VECTOR vec;   // 速度

    int img;
    int ImgWidth;
    int ImgHeight;

    bool onGround;
    int dir;          // -1:左 1:右
    int jumpTimer;    // ジャンプまでのカウント

    int framecount;
};