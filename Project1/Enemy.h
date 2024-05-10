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
	int ex,ex2;
	int ey, ey2;
	Block* block;

public:
	static float enemyX;
	static float enemyX2;
	static float enemyY;
	static float enemyY2;

	float GetLocationX() { return ex;}
	float GetLocationX2() { return ex2;}
	float GetLocationY() { return ey;}
	float GetLocationY2() { return ey2;}


	Enemy();
	void Update();
	void Draw();
	void Enemyhit();
};

