#pragma once
#include"PadInput.h"
class Player
{
private:
	int image;
	int life;       //残機
	int input_margin;
	float P_YSpeed;
	int P_FPS;     //FPScnt
	int P_Seconas1;  //秒数
	bool Jumpflg = FALSE;
	bool Downflg = FALSE;
	float P_moveY;
	float P_moveX;
	float PlayerLocationY;
	

public:
	static  float playerX;  //プレイヤー座標X
	static  float playerY;  //プレイヤー座標Y
	static float velocity;  
	Player();
	~Player();

	void Update();
	void Draw();
	void Move();  //プレイヤー動き（ジャンプ含む）
	

};
