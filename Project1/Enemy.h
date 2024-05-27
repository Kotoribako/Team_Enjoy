#pragma once
#include"Block.h"
#include"Player.h"
class Enemy
{
private:

	

	int img;
	int count;
	bool Hitflg;
	int speed;
	int ex,ex2;
	int ey, ey2;
	int countup;
	int moveX;
	int direction; // エネミーの方向
	Block* block;
	Player* player;
	int flg;
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
	void EnemyControl();
	int Enemyhit();
};

