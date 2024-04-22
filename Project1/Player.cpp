#include "Player.h"
#include "Stage1.h"
#include<iostream>
#include"DxLib.h"
float Player::playerX;
float Player::playerY;
float Player::velocity;
int Player::MoveFlg;

#define PLAYERSTARTX 220
#define PLAYERSTARTY 630

Player::Player()
{
	playerX = PLAYERSTARTX;
	playerY = PLAYERSTARTY;
	P_FPS = 0;
	velocity = 0.0f;
	MoveFlg = FALSE;
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
}

void Player::Draw()
{
	DrawBox(playerX, playerY, playerX + 30, playerY -30, GetColor(0, 0,255 ), TRUE);
	DrawFormatString(0, 50, GetColor(0, 0, 0), "count:%d",count);
	DrawFormatString(0, 30, GetColor(0, 0, 0), "jumoflg:%d", Jumpflg);
	DrawFormatString(100, 0, GetColor(0, 0, 0), "playerX:%f  playerY:%f", playerX, playerY);
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


	if (std::abs(stick_y1) > stick_sensitivity) {
		// スティック上
		if (stick_y1 > 0) {
			playerY -= 3;
		}
		//ステック下
		else if (stick_y1 < 0) {
			playerY += 3;
		}
		input_margin = 0;
	}
	if (std::abs(stick_x1) > stick_sensitivity) {
		//スティック左
		if (stick_x1 < 0) {
			playerX -= 3;
		}
		//スティック右
		else if (stick_x1 > 0) {
			playerX += 3;
		}
		input_margin = 0;
	}

	if (PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_LEFT))
	{
		playerX -= 3;
	}
	if (PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_RIGHT))
	{
		playerX += 3;
	}
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_A) && Jumpflg == FALSE)
	{
		Jumpflg = TRUE;
		count += 1;
	}

	if (Jumpflg == TRUE && Downflg == FALSE)
	{
		sy = 12.0f;
		playerY -= sy;
		sy += 0.3f;
		if (playerY <= 200) {
			playerY = 200;
			Jumpflg = FALSE;
			Downflg = TRUE;
		}
	}
	 if (Downflg == TRUE && count >= 1)
	{
		sy = 12.0f;
		playerY += sy;
		sy += 0.3f;
	}

	if (playerY >= 720) {
		playerY = 620;
		Jumpflg = FALSE;
		Downflg = FALSE;
		count = 0;
	}
	if (playerX >= 640 && MoveFlg == FALSE) {
		playerX = 640;
	}
	if (playerX <= 0) {
		playerX = 0;
	}
}