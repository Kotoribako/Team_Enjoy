#pragma once
#include"Block.h"
class Enemy
{
private:

	struct enemy
	{
		int X, Y;
		int X2,Y2;
		bool flg;
		int No[3];
	};

	struct enemy gEnemy;

	int img;
	int count;
	int Hitflg;
	int speed;

	Block* block;

public:
	Enemy();
	void Update();
	void Draw();
	void Enemyhit();
};

