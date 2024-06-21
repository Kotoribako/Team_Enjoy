#pragma once
#include"PadInput.h"
#include"Block.h"
class Player
{
private:
	/* 画像用変数・配列 */
	int image[3]; //プレイヤー画像格納用
	int P_img;    //プレイヤー画像表示（切り替え）用

	/* BGM・SE用変数 */
	int DeathSE; // 死んだときの音
	int JumpSE; // ジャンプした時の音

	/* 処理用変数・配列 */
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
	float px = playerX - 15;
	float px2 = playerX + 15;
	float py = playerY - 15;
	float py2 = playerY + 15;
	int HitFlg;  // 地面に足がついているか
	int BlockNum;
	int NoHitBlockFlg;

	int Animflg;
	int Turnflg;
	int Rightflg;
	int Leftflg;


public:
	static  float playerX;  //プレイヤー座標X プレイヤーX軸の中心座標
	static  float playerY;	//プレイヤー座標X プレイヤーY軸の中心座標
	static  int   standflg;
	static float  velocity;
	static int quizflg;
	static int MoveFlg; // スクロール終了後移動する
	static int Life;  //残機
	static 	int Range;
	static int Death;

	Player();
	~Player();

	void Update();
	void Draw();
	void Move();  //プレイヤー動き（ジャンプ含む）
	void PlayerHit(); //当たり判定のためのプレイヤー座標
	void PlayerAnim(); //プレイヤーアニメーション

	int BlockHitY(); // Y軸の別の当たり判定をやってみる
	int BlockHitX(); // X軸の別の当たり判定をやってみる(0.X軸ヒットなし 1.ブロックの右側とプレイヤーの左側がヒットしたとき 2.ブロックの左側とプレイヤーの右側がヒットしたとき)

	float GetLocationX1() { return px; } // プレイヤーの左端の座標を取る。
	float GetLocationY1() { return py; } // プレイヤーの頭上の座標を取る。
	float GetLocationX2() { return px2; }// プレイヤーの右端の座標を取る。
	float GetLocationY2() { return py2; }// プレイヤーの下側の座標を取る。

	float GetLocationCenterX() { return playerX;}
	float GetLocationCenterY() { return playerY;}

};
