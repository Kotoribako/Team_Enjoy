#pragma once
#include"Block.h"
#include"Player.h"
class Enemy
{
private:

	struct BlockX
	{
		float X;
		float X2;
	};
	struct BlockX blockx[4];


	struct S_Enemy
	{
		float enemyX;
		float enemyX2;
		float enemyY;
		float enemyY2;
		int Turnflg;
		float speed;

	};
	struct S_Enemy s_enemy[3];
	int slimeImg[3];

	//img[2];
	int E_Img;
	int count;
	bool Hitflg;
	
	int countup;
	int moveX;
	int direction; // エネミーの方向
	Block* block;
	Player* player;
	int flg;

	int OverFlg;
	int E_FPS;     //FPScnt
	int E_Seconas1;  //秒数
	int Returnflg;
public:
	
	static float ex, ex2; // 敵の左座標(ex)と右座標を取る(ex2) 
	static float  ey, ey2;// 敵の上座標(ey)と下座標を取る(ey2 b)
	static 	int Range;


	float GetLocationX() { return ex;}  // 左側
	float GetLocationX2() { return ex2;}// 右側
	float GetLocationY() { return ey;}  // 上側
	float GetLocationY2() { return ey2;}// 下側


	Enemy();
	void Update();
	void Draw();
	void Enemyhit();
	void EnemyAnim();
};

