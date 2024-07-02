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
		int Returnflg;
		float speed;

	};
	struct S_Enemy s_enemy[3];
	int slimeImg[3];

	int E_Img;
	//int count;
	//bool Hitflg;
	
	//int countup;

	Block* block;
	Player* player;
	int flg;

	int E_FPS;     //FPScnt
	int E_Seconas1;  //秒数

	int PlayerDeathSE; // プレイヤーが敵に当たった時に死ぬ音を入れる

public:
	
	static float ex, ex2; // 敵の左座標(ex)と右座標を取る(ex2) 
	static float  ey, ey2;// 敵の上座標(ey)と下座標を取る(ey2 b)
	static 	int Range;


	Enemy();
	~Enemy();
	void Update();
	void Draw();
	void Enemyhit();
	void EnemyAnim();
};

