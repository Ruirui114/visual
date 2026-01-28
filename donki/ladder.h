#pragma once
#include "objBase.h"

class CLadder :public BaseVector {
public:
	//位置、チップNo、イメージハンドル
	CLadder(Point, int, int);
	~CLadder() {};

	int Action(vector<unique_ptr<BaseVector>>&);
	void Draw();

	float x, y;
	//int tipNo{ -1 };


};