#include "donki.h"
#include"function.h"

CDonki::CDonki() {
	d_img = LoadGraph("image\\donki.png");

	//マップ初期位置
	m_pos.x = 64;//128
	m_pos.y = 830;//832
	//描画位置
	pos = m_pos;

	ImgWidth = 48;
	ImgHeight = 32;


	framecount2 = 0;
	pri = 2;
}

int CDonki::Action(std::vector<std::unique_ptr<BaseVector>>& base, CMap& map) {
	//キャラ画像
	framecount2++;
	if (framecount2 < 8)
		CutX = 48;
	else if (framecount2 < 16)
		CutX = 96;
	else if (framecount2 < 24)
		CutX = 48;
	else if (framecount2 < 32)
		CutX = 96;
	else if (framecount2 <= 40)
		CutX = 0;
		framecount2 = 0;
	return 0;
}
void CDonki::Draw() {
	DrawRectGraph(
		pos.x, pos.y,
		CutX, CutY,
		ImgWidth, ImgHeight,
		d_img,
		true
	);
}