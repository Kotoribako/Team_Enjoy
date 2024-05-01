#pragma once
#include"PadInput.h"
#include"Block.h"
class Player
{
private:
	int image;
	int life;       //残機
	int input_margin;
	float P_YSpeed;
	int count = 0;
	int P_FPS;     //FPScnt
	int P_Seconas1;  //秒数
	int Jumpflg = FALSE;
	bool Downflg = FALSE;
	float P_moveY;
	float P_moveX;
	float PlayerLocationY;
	Block* block;
	float px,px2;
	float py, py2;

public:
	static  float playerX;  //プレイヤー座標X　左  プレイヤー中心座標
	static	float playerX2;	//プレイヤー座標Y　右
	static  float playerY;	//プレイヤー座標X　下	プレイヤー中心座標
	static	float playerY2; //プレイヤー座標Y　上
	static  int   standflg;
	static float  velocity;

	static int MoveFlg; // スクロール終了後移動する

	Player();
	~Player();

	void Update();
	void Draw();
	void Move();  //プレイヤー動き（ジャンプ含む）
	void PlayerHit(); //当たり判定のためのプレイヤー座標

	float GetLocationX1() { return px; } // プレイヤーの左端の座標を取る。
	float GetLocationY1() { return py; } // プレイヤーの頭上の座標を取る。
	float GetLocationX2() { return px2; }// プレイヤーの右端の座標を取る。
	float GetLocationY2() { return py2; }// プレイヤーの下側の座標を取る。

};
