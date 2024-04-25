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

Player::Player()
{
	block = new Block();

	playerX = 235;
	playerY = 615;
	
	px = playerX - 15;
	px2 = playerX + 15;
	py = playerY - 15;
	py2 = playerY + 15;

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
	px = playerX - 15;
	px2 = playerX + 15;
	py = playerY - 15;
	py2 = playerY + 15;
	
	if (P_FPS > 59) {
		P_FPS = 0;
		P_Seconas1++;

	}// P_FPS_INC 
	else if (P_Seconas1 > 3) {
		P_Seconas1 = 0;
	}
	playerX2 = playerX + 30;
	playerY2 = playerY - 30;

	PlayerHit(); // 当たり判定

	if (playerY >= 800) // リスポーン処理（後で消す）
	{
		playerX = 235;
		playerY = 615;
		Stage1::Stage1X = 0;

		//block = new Block();

		block->bloc[0] = { 0,270,630,720 };
		block->bloc[1] = { 340,440,565,615 };
		block->bloc[2] = { 475,555,510,555 };
		block->bloc[3] = { 510,555,470,510 };
		block->bloc[4] = { 580,735,420,455 };
		block->bloc[5] = { 780,845,365,415 };
		block->bloc[6] = { 875,940,310,360 };
		block->bloc[7] = { 950,1010,425,480 };
		block->bloc[8] = { 980,1035,235,290 };
		block->bloc[9] = { 1055,1120,350,410 };
		block->bloc[10] = { 1125,1700,610,720 };

	}
}

void Player::Draw()
{
	DrawBox(playerX, playerY, playerX2, playerY2, GetColor(0, 0,255 ), TRUE);
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
		standflg = 0;
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
	//if (playerY >= 630) {//地面に付いたとき
	//	standflg = 1;
	//	Jumpflg = FALSE;
	//	Downflg = FALSE;
	//	count = 0;

	//}
	if (playerX >= 640 && MoveFlg == FALSE) {
		playerX = 640;
	}
	if (playerX <= 0) {
		playerX = 0;
	}
	
}

void Player::PlayerHit()
{
	for (int i = 0; i < 11; i++)
	{

		if (GetLocationX1() >= block->bloc[i].X && GetLocationX2() <= block->bloc[i].X2 /*&& player->GetLocationY1() >= block->bloc[i].Y*/)
		{
			// 上にプレイヤーがいる処理
			if (GetLocationY1() >= block->bloc[i].Y)
			{
				Jumpflg = FALSE;
				Downflg = FALSE;
				count = 0;
			}
			if (GetLocationY2() <= block->bloc[i].Y2 && GetLocationX1() >= block->bloc[i].X2)
			{
				Jumpflg = FALSE;
				Downflg = TRUE;
				count = 0;

			}
		}
	}


	/*if (playerX >= Block::block[1].X && playerX >= Block::block[0].X2 && playerY <= Block::block[0].Y) {
		py2 = Block::block[0].Y;
	}*/
}

