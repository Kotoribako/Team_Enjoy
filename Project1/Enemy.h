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
	
	int countup;
	int moveX;
	int direction; // エネミーの方向
	Block* block;
	Player* player;
	int flg;
public:
	float enemyX;
    float enemyX2;
    float enemyY;
	float enemyY2;
	static int ex, ex2; // 敵の左座標(ex)と右座標を取る(ex2) 
	static int ey, ey2;// 敵の上座標(ey)と下座標を取る(ey2 b)

	float GetLocationX() { return ex;}  // 左側
	float GetLocationX2() { return ex2;}// 右側
	float GetLocationY() { return ey;}  // 上側
	float GetLocationY2() { return ey2;}// 下側


	Enemy();
	void Update();
	void Draw();
	int Enemyhit();
};

