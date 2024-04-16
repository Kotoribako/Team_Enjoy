﻿#include "Player.h"
#include<iostream>
#include"DxLib.h"
float Player::playerY;
float Player::playerX;
float Player::velocity;
Player::Player()
{
	playerX = 300;
	playerY = 400;
	P_FPS = 0;
	velocity = 0.0f;
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

	}// P_FPS_INC �� �b�������Ă���
	else if (P_Seconas1 > 3) {
		P_Seconas1 = 0;
	}
}

void Player::Draw()
{
	DrawLine(0, 400, 1280, 400, GetColor(255, 0, 0), TRUE);
	DrawLine(0, 200, 1280, 200, GetColor(255, 0, 0), TRUE);
	DrawBox(playerX, playerY, playerX - 30, playerY - 30, GetColor(255, 255, 255), TRUE);
	DrawFormatString(0, 30, GetColor(255, 255, 255), "jumoflg:%d",Jumpflg);
	DrawFormatString(100, 0, GetColor(255, 255, 255), "playerX:%f  playerY:%f", playerX, playerY);
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
	}

	if (Jumpflg == TRUE)
	{
		count += 1;
		sy = 12.0f;
		playerY -= sy;
		sy += 0.3f;
		//y_temp = playerY;
		//playerY += (playerY - y_prev) + 200.0f;
		//y_prev = y_temp;
		if (playerY <= 200) {
			playerY = 200;
			Jumpflg = FALSE;
		}
		/* ここにインターバル入れる */
	}
	 if (Jumpflg == FALSE && playerY < 400)
	{
		sy = 12.0f;
		playerY += sy;
		sy += 0.3f;
	}

	if (playerY >= 400) {
		playerY = 400;
		Jumpflg = FALSE;
	}
	//if (count == 1 && PAD_INPUT::OnButton(XINPUT_BUTTON_A)) {
	//	sy = 12.0f;
	//	playerY += sy;
	//	sy += 0.3f;
	//}
}

//void Player::Jump()
//{
//	int flapInterval = 0;
//	int interval = 5;
//	float Y;
//	if (PAD_INPUT::OnButton(XINPUT_BUTTON_A))
//	{
//		flapInterval = 6;
//		Jumpflg = TRUE;
//	}
//	else {
//		flapInterval = 4;
//		Jumpflg = TRUE;
//	}
//	if (interval % 10 == 0 || PAD_INPUT::OnButton(XINPUT_BUTTON_A)) {
//		P_moveY += -2.0f;
//	}
//	if (PlayerLocationY > 25 && Jumpflg == TRUE) {
//		PlayerLocationY += P_moveY;
//	}
//	else
//	{
//		P_moveY = (P_moveY * 0.8f);
//	}
//	/*if (Jumpflg ==  TRUE) {
//		velocity -= 0.2f;
//		playerY += velocity;
//	}
//	if (playerY == 400) {
//		velocity = 0;
//		Jumpflg = FALSE;
//	}*/
//	//else {
//	//	if (P_FPS % 2 == 0) {
//	//		P_YSpeed = P_YSpeed + -0.6f;
//	//		playerY = playerY + P_YSpeed;
//	//		if (P_YSpeed <= -1.0f) {        //���x����
//	//			P_YSpeed = -1.0f;
//	//		}
//	//	}
//	//}
//}
//
//void Player::Gravity()
//{
//	if (playerY > 100) {
//		P_YSpeed = P_YSpeed + 0.01f;
//		playerY = playerY + P_YSpeed;
//	}
//	if (P_YSpeed >= 1.3f) {         //���x����
//		P_YSpeed = 1.3f;
//	}
//}