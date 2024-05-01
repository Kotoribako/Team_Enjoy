#include "Player.h"
#include "Stage1.h"
#include<iostream>
#include"DxLib.h"
float Player::playerX;  //左
float Player::playerX2; //右
float Player::playerY;  //下
float Player::playerY2; //上
int   Player::standflg; //立ってるかのフラグ
float Player::velocity;
int   Player::MoveFlg;

#define PLAYERSTARTX 220
#define PLAYERSTARTY 630

Player::Player():/*is_active(false),*/ image(NULL),location(0.0f),box_size(0.0f),speed(0.0f)
{
	playerX = 235;
	playerY = 615;
	
	/*px = playerX - 15;
	px2 = playerX + 15;
	py = playerY - 15;
	py2 = playerY + 15;*/

	location = Vector2D(235.0f, 615.0f);
	box_size = Vector2D(31.0f, 60.0f);
	speed = 3.0f;

	P_FPS = 0;
	velocity = 0.0f;
	MoveFlg = FALSE;
	standflg = 1;
}

Player::~Player()
{
}

void Player::Update()
{
	
	P_FPS++;
	Move();
	
	if (P_FPS > 59) {
		P_FPS = 0;
		P_Seconas1++;

	}// P_FPS_INC 
	else if (P_Seconas1 > 3) {
		P_Seconas1 = 0;
	}
	playerX = location.x;
	playerY = location.y;
	playerX2 = location.x + 30;
	playerY2 = location.y - 30;
}

void Player::Draw()
{
	DrawBox(playerX, playerY, playerX2, playerY2, GetColor(0, 0, 255), TRUE);
	DrawFormatString(0, 50, GetColor(0, 0, 0), "count:%d",count);
	DrawFormatString(0, 50, GetColor(0, 0, 0), "standflg:%d", standflg);
	DrawFormatString(0, 30, GetColor(0, 0, 0), "jumoflg:%d", Jumpflg);
	DrawFormatString(100, 0, GetColor(0, 0, 0), "playerX:%f  playerY:%f", playerX, playerY);
	DrawFormatString(100, 20, GetColor(0, 0, 0), "playerX2:%f  playerY2:%f", playerX2, playerY2);
}

void Player::Move()
{
	float Jump;
	float y;
	float y_temp;
	float y_prev = 20.0f;
	float sy = 0.0f;
	// ����Ԋu����
	const int max_input_margin = 10;
	// �X�e�B�b�N�̊��x
	const int stick_sensitivity = 20000;

	int stick_y1 = PAD_INPUT::GetLStick().ThumbY;
	int stick_x1 = PAD_INPUT::GetLStick().ThumbX;

	Vector2D move = Vector2D(0.0f);
	//if (std::abs(stick_y1) > stick_sensitivity) {
	//	// スティック上
	//	if (stick_y1 > 0) {
	//		playerY -= 3;
	//	}
	//	//ステック下
	//	else if (stick_y1 < 0) {
	//		playerY += 3;
	//	}
	//	input_margin = 0;
	//}
	if (std::abs(stick_x1) > stick_sensitivity) {
		//スティック左
		if (stick_x1 < 0) {
			move += Vector2D(-1.0f, 0.0f);
		}
		//スティック右
		else if (stick_x1 > 0) {
			move += Vector2D(1.0f, 0.0f);
		}
		input_margin = 0;
	}

	if (PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_LEFT))
	{
		move += Vector2D(-3.0f, 0.0f);
	}
	if (PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_RIGHT))
	{
		move += Vector2D(3.0f, 0.0f);
	}
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_A) && Jumpflg == FALSE)
	{
		Jumpflg = TRUE;
		standflg = 0;
		count += 1;
	}

	if (Jumpflg == TRUE && Downflg == FALSE)
	{
		move += Vector2D(0.0f,-12.0f);
		move += Vector2D(0.0f, 3.0f);
		if (location.y <= 200) {
			location.y = 200;
			Jumpflg = FALSE;
			Downflg = TRUE;
		}
	}
	 if (Downflg == TRUE && count >= 1)
	{
		move += Vector2D(0.0f, 12.0f);
		move += Vector2D(0.0f, 3.0f);
	 }
	if (location.y >= 630) {//地面に付いたとき
		location.y = 630;
		standflg = 1;
		Jumpflg = FALSE;
		Downflg = FALSE;
	
		count = 0;

	}
	if (location.x >= 640 && MoveFlg == FALSE) {
		location.x = 640;
	}
	if (location.x <= 0) {
		location.x = 0;
	}
	location += move;
	
}
Vector2D Player::Getlocation()const 
{
	return this->location;
}
Vector2D Player::GetBoxsize()const
{
	return this->box_size;
}
float Player::GetSpeed()const
{
	return this->speed;
}
void Player::PlayerHit()
{
	/*if (playerX >= Block::block[1].X && playerX >= Block::block[0].X2 && playerY <= Block::block[0].Y) {
		py2 = Block::block[0].Y;
	}*/
}

