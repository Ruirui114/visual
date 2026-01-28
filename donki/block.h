#pragma once
#include "objBase.h"

class CBlock :public BaseVector {
public:
	//位置、チップNo、イメージハンドル
	CBlock(Point, int, int);
	~CBlock() {};

	int Action(std::vector<std::unique_ptr<BaseVector>>& base, CMap& map);
	void Draw();

	float x, y;

	
};