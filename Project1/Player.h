#pragma once
#include"PadInput.h"
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
	

public:
	static  float playerX;  //プレイヤー座標X　左
	static	float playerX2;	//プレイヤー座標Y　右
	static  float playerY;	//プレイヤー座標X　下
	static	float playerY2; //プレイヤー座標Y　上
	static  int   p_standflg;
	static float velocity;

	static int MoveFlg; // スクロール終了後移動する

	Player();
	~Player();

	void Update();
	void Draw();
	void Move();  //プレイヤー動き（ジャンプ含む）
	void StageStand(); //ステージに立つ（当たり判定の処理）
	

};
