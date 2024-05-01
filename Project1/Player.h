#pragma once
#include"PadInput.h"
#include"Block.h"
#include"Vector2D.h"
class Player
{
private:
	//C++の範囲↓
	//bool is_active; //有効状態か
	int image;      //画像データ
	Vector2D location; //位置座標
	Vector2D box_size; //当たり判定の大きさ
	float speed;
	//C++の範囲↑




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

	//C++の範囲↓
	Vector2D Getlocation()const;   //位置座標取得
	Vector2D GetBoxsize()const;	   //当たり判定の大きさ所得
	float GetSpeed() const;        //速さの取得
private:
	/*void Movement();*/
	//C++の範囲↑
};
