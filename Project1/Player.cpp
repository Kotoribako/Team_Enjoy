#include "Player.h"
#include "Stage1.h"
#include<iostream>
#include"DxLib.h"
#include"GenreSelect.h"
#include"GameMain.h"
float Player::playerX;  //左
float Player::playerY;  //下
int   Player::standflg; //立ってるかのフラグ
float Player::velocity;
int   Player::MoveFlg;
int   Player::quizflg;
int   Player::Life;
#define PLAYERSTARTX 220
#define PLAYERSTARTY 430

Player::Player()
{
	block = new Block();

	playerX = PLAYERSTARTX;
	playerY = PLAYERSTARTY;
	
	px = playerX - 15;
	px2 = playerX + 15;
	py = playerY - 15;
	py2 = playerY + 15;

	P_FPS = 0;
	velocity = 0.0f;
	MoveFlg = FALSE;
	standflg = 1;

	HitFlg = FALSE;

	NoHitBlockFlg = TRUE;

	Life = 3;
}

Player::~Player()
{
}

void Player::Update()
{
	
	P_FPS++;

	PlayerHit(); // 当たり判定

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


	if (playerY >= 800) // リスポーン処理（後で消す）
	{
		playerX = 235;
		playerY = 615;
		Stage1::Stage1X = 0;
		Life--;
		if (Life == -1) {
			GameMain::NowStage = 0;
		}

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
	if (BlockNum == 8) {
		eightflg = TRUE;
		threeflg = FALSE;
	}
	else if(BlockNum == 3){
		threeflg = TRUE;
		eightflg = FALSE;
	}
	else {
		threeflg = FALSE;
		eightflg = FALSE;
	}

	if (Stage1::S1DecisionToAnswerFlg == TRUE) {
		// プレイヤーをスタート地点に戻す
		playerX = PLAYERSTARTX;
		playerY = PLAYERSTARTY;
	}
}

void Player::Draw()
{
	DrawBox(px, py, px2, py2, GetColor(0, 0,255 ), TRUE);
	DrawFormatString(0, 50, GetColor(0, 0, 0), "count:%d",count);
	DrawFormatString(0, 80, GetColor(0, 0, 0), "Life:%d", Life);
	DrawFormatString(100, 0, GetColor(0, 0, 0), "playerX:%f  playerY:%f", playerX, playerY);
	//DrawFormatString(100, 20, GetColor(0, 0, 0), "playerX2:%f  playerY2:%f", playerX2, playerY2);
	DrawFormatString(0, 120, GetColor(0, 0, 0), "BlockNum:%d", BlockNum);
	for (int i = 0; i < Life; i++)
	{
		DrawBox(100 + 50 * i, 100, 130 + 50 * i, 130, GetColor(255, 0, 0), TRUE);
	}
}

void Player::Move()
{
	float Jump;
	float y;
	int MaxY = 0; // ジャンプする高さの上限
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

	if (PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_LEFT) && NoHitBlockFlg == TRUE)
	{
		P_moveX = -3;
		playerX += P_moveX;
	}
	if (PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_RIGHT) && NoHitBlockFlg == TRUE)
	{
		P_moveX = 3;
		playerX += P_moveX;
	}
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_A) && Jumpflg == FALSE && NoHitBlockFlg == TRUE)
	{
		MaxY = playerY - 50;
		Jumpflg = TRUE;
		standflg = 0;
		count += 1;
	}

	if (Jumpflg == TRUE && Downflg == FALSE)
	{
		sy = 12.0f;
		playerY -= sy;
		sy += 0.3f;
		P_moveY += sy;
		if (P_moveY > 300.0) {
			//playerY = MaxY;
			Jumpflg = FALSE;
			Downflg = TRUE;
		}
	}
	if (Downflg == TRUE && count >= 1 || NoHitBlockFlg == FALSE)
	{
		P_moveY = 0; // 動かした値をリセットする
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
	if (playerX >= 1280) {
		playerX = 1280;
	}
}

void Player::PlayerHit()
{
	float sy = 0.0f;

	for (int i = 0; i < 11; i++)
	{
		if (i > 8)
		{
			if (int((px + -1 * (Stage1::Stage1X)) == block->bloc[9].X2 && int(py2) > block->bloc[9].Y))
			{
				P_moveX = 3;
				playerX += P_moveX;
				NoHitBlockFlg = FALSE;
				// 落下処理させる
				count += 1;
				Downflg = TRUE;
				HitFlg = FALSE;

				if (int(py2) > block->bloc[10].Y)
				{
					py2 = block->bloc[10].Y;
				}
			}
		}
		else
		{
			/* 処理ここから */
			if (/*PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_LEFT) &&*/ int(px + -1 * (Stage1::Stage1X)) == block->bloc[i].X2 && int(py2) > block->bloc[i].Y)
			{
				P_moveX = 3;
				playerX += P_moveX;
				NoHitBlockFlg = FALSE;
				// 落下処理させる
				count += 1;
				Downflg = TRUE;
				HitFlg = FALSE;

			}
			else if (/*PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_RIGHT) &&*/ int(px2 + -1 * (Stage1::Stage1X)) == block->bloc[i].X && int(py2) > block->bloc[i].Y)
			{
				//playerX += 0;
				P_moveX = -3;
				playerX += P_moveX;
				NoHitBlockFlg = FALSE;
				// 落下処理させる
				count += 1;
				Downflg = TRUE;
				HitFlg = FALSE;
			}
			else
			{
				NoHitBlockFlg = TRUE;
			}
		}
		/* 処理ここまで */

		if (int(GetLocationX1() + -1 * (Stage1::Stage1X)) <= block->bloc[i].X2 && int(GetLocationX2() + -1 * (Stage1::Stage1X)) >= block->bloc[i].X)
		{
			// フラグを立てる
			HitFlg = TRUE;
			BlockNum = i;
			// 上にプレイヤーがいる処理
			if (int(GetLocationY2()) <= block->bloc[BlockNum].Y && HitFlg == TRUE && NoHitBlockFlg == TRUE)
			{
				HitFlg = FALSE;
				BlockNum = -1;
			}
			else
			{
				// プレイヤーの頭上よりも下のブロックが座標が高いか？
				if (int(GetLocationY1()) < block->bloc[BlockNum].Y2) 
				{
					/* 下に落ちない処理を書く */
					Jumpflg = FALSE;
					Downflg = FALSE;
					count = 0;
				}
				// プレイヤーの頭上と下のブロックがぶつかった時
				else if(int(GetLocationY1()) == block->bloc[BlockNum].Y2)
				{
					/* 下に落ちる処理を書く */
					HitFlg = FALSE;
					BlockNum = -1;
				}
				else 
				{
					HitFlg = FALSE;
					BlockNum = -1;
				}
				// 特定の足場を踏んでいるかどうか
				if (BlockNum >= 9) {
					quizflg = 1;
				}
				else
				{
					quizflg = 0;
				}

			}
			if (BlockNum == -1 && P_moveY == 0) // ブロックないときの落下処理
			{
				count += 1;
				Downflg = TRUE;
			}
			break;

		}
		else if (i == 10) // ブロックのX軸の範囲内にいなかった時
		{
			// 落下処理させる
			count += 1;
			Downflg = TRUE;
		}
	//}
		// ブロックに当たっているか確認
		if (int(px + -1 * (Stage1::Stage1X)) <= block->bloc[i].X2 && int(px2 + -1 * (Stage1::Stage1X)) <= block->bloc[i].X && int(py) == block->bloc[i].Y2)
		{
			HitFlg = TRUE;
			BlockNum = i;
			///* 下に落ちない処理を書く */
			//Jumpflg = FALSE;
			//Downflg = FALSE;
			//count = 0;
			break;
			// ブロックの右側にプレイヤーの左側に当たっているか確認
			if (int(px + -1 * (Stage1::Stage1X)) == block->bloc[BlockNum].X2 && int(py) > block->bloc[BlockNum].Y2)
			{
				playerX -= 0;
				// 落下処理させる
				count += 1;
				Downflg = TRUE;
			}
			// ブロックの左側にプレイヤーの右側に当たっているか確認
			else if (int(px2 + -1 * (Stage1::Stage1X)) == block->bloc[BlockNum].X && int(py) > block->bloc[BlockNum].Y2)
			{
				playerX += 0;
				// 落下処理させる
				count += 1;
				Downflg = TRUE;
			}
			else
			{
				/* 下に落ちない処理を書く */
				Jumpflg = FALSE;
				Downflg = FALSE;
				count = 0;
			}

			// 上にプレイヤーがいる処理
			if (int(py2) <= block->bloc[BlockNum].Y && HitFlg == TRUE)
			{
				HitFlg = FALSE;
				BlockNum = -1;
			}
			else
			{
				// プレイヤーの頭上よりも下のブロックが座標が高いか？
				if (int(py) < block->bloc[BlockNum].Y2)
				{
					/* 下に落ちない処理を書く */
					Jumpflg = FALSE;
					Downflg = FALSE;
					count = 0;
				}
				// プレイヤーの頭上と下のブロックがぶつかった時
				else if (int(py) == block->bloc[BlockNum].Y2)
				{
					/* 下に落ちる処理を書く */
					HitFlg = FALSE;
					BlockNum = -1;
				}
				/*else
				{
					HitFlg = FALSE;
					BlockNum = -1;
				}*/
				// 特定の足場を踏んでいるかどうか
				if (BlockNum >= 9) {
					quizflg = 1;
				}
				else
				{
					quizflg = 0;
				}


			}
		}
		else if (i == 10)
		{
			count += 1;
			Downflg = TRUE;
		}

	}

}

