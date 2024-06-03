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

	switch (GameMain::NowStage)
	{
	case 1:
	case 4:
		//左、右、上、下
		block->S1bloc[0] = { 0,270,630,720 };
		block->S1bloc[1] = { 340,440,565,615 };
		block->S1bloc[2] = { 475,555,510,555 };
		block->S1bloc[3] = { 510,555,470,510 };
		block->S1bloc[4] = { 580,735,420,455 };
		block->S1bloc[5] = { 780,845,365,415 };
		block->S1bloc[6] = { 875,940,310,360 };
		block->S1bloc[7] = { 950,1010,425,480 };
		block->S1bloc[8] = { 980,1035,235,290 };
		block->S1bloc[9] = { 1055,1120,350,410 };
		block->S1bloc[10] = { 1125,1700,610,720 };
		break;
	case 2:
	case 5:
		//左、右、上、下
		block->S2bloc[0] = { 0,455,565,720 };
		block->S2bloc[1] = { 500,565,450,493 };
		block->S2bloc[2] = { 613,676,345,390 };
		block->S2bloc[3] = { 769,795,338,380 };
		block->S2bloc[4] = { 840,865,400,440 };
		block->S2bloc[5] = { 911,937,459,500 };
		block->S2bloc[6] = { 987,1038,359,400 };
		block->S2bloc[7] = { 1008,1353,600,640 };
		block->S2bloc[8] = { 1193,1245,360,400 };
		block->S2bloc[9] = { 1295,1332,460,486 };
		block->S2bloc[10] = { 1312,1746,236,268 };
		block->S2bloc[11] = { 1376,1396,520,541 };
		block->S2bloc[12] = { 1443,1564,463,484 };
		block->S2bloc[13] = { 1528,1550,567, 588 };
		block->S2bloc[14] = { 1570,1590,513,534 };
		block->S2bloc[15] = { 1621,1638,444,461 };
		block->S2bloc[16] = { 1702,1718,399,415 };
		block->S2bloc[17] = { 1773,1791,515,532 };
		block->S2bloc[18] = { 1881,2560,523,720 };
		break;
	case 3:
	case 6:
		//左、右、上、下
		block->S3bloc[0] = { 0,276,560,720 };
		block->S3bloc[1] = { 304,335,477,508 };
		block->S3bloc[2] = { 374,396,418,448 };
		block->S3bloc[3] = { 428,848,381,480 };
		block->S3bloc[4] = { 533,556,292,315 };
		block->S3bloc[5] = { 627,651,292,315 };
		block->S3bloc[6] = { 719,742,292,315 };
		block->S3bloc[7] = { 909,930,296,329 };
		block->S3bloc[8] = { 943,982,511,541 };
		block->S3bloc[9] = { 970,990,222,253 };
		block->S3bloc[10] = { 1035,1055,175,195 };
		block->S3bloc[11] = { 1040,1063,550,508 };
		block->S3bloc[12] = { 1121,1660,140,214 };
		block->S3bloc[13] = { 1121,1722,563,660 };
		block->S3bloc[14] = { 1176,1215,471,560 };
		block->S3bloc[15] = { 1589,1629,471,560 };
		block->S3bloc[16] = { 1732,1797,203,224 };
		block->S3bloc[17] = { 1759,1781,500,518 };
		block->S3bloc[18] = { 1830,1864,625,645 };
		block->S3bloc[19] = { 1878,1894,0,188 };
		block->S3bloc[20] = { 1873,1898,279,298 };
		block->S3bloc[21] = { 1900,1911,587,604 };
		block->S3bloc[22] = { 1946,1957,532,551 };
		block->S3bloc[23] = { 1945,1957,656,676 };
		block->S3bloc[24] = { 1993,2005,621,639 };
		block->S3bloc[25] = { 2047,2062,587,596 };
		block->S3bloc[26] = { 2062,2560,561,720 };

		break;

	};

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
		Stage2::Stage2X = 0;
		Stage3::Stage3X = 0;
		Life--;
		if (Life == -1) {
			/* ここにゲームオーバー処理を入れる */
			GameMain::NowStage = 0;
		}

		block = new Block();
		//switch (GameMain::NowStage)
		//{
		//case 1:
		//case 4:
		//	//左、右、上、下
		//	block->S1bloc[0] = { 0,270,630,720 };
		//	block->S1bloc[1] = { 340,440,565,615 };
		//	block->S1bloc[2] = { 475,555,510,555 };
		//	block->S1bloc[3] = { 510,555,470,510 };
		//	block->S1bloc[4] = { 580,735,420,455 };
		//	block->S1bloc[5] = { 780,845,365,415 };
		//	block->S1bloc[6] = { 875,940,310,360 };
		//	block->S1bloc[7] = { 950,1010,425,480 };
		//	block->S1bloc[8] = { 980,1035,235,290 };
		//	block->S1bloc[9] = { 1055,1120,350,410 };
		//	block->S1bloc[10] = { 1125,1700,610,720 };
		//	break;
		//case 2:
		//case 5:
		//	//左、右、上、下
		//	block->S2bloc[0] = { 0,455,565,720 };
		//	block->S2bloc[1] = { 500,565,450,493 };
		//	block->S2bloc[2] = { 613,676,345,390 };
		//	block->S2bloc[3] = { 769,795,338,380 };
		//	block->S2bloc[4] = { 840,865,400,440 };
		//	block->S2bloc[5] = { 911,937,459,500 };
		//	block->S2bloc[6] = { 987,1038,359,400 };
		//	block->S2bloc[7] = { 1008,1353,600,640 };
		//	block->S2bloc[8] = { 1193,1245,360,400 };
		//	block->S2bloc[9] = { 1295,1332,460,486 };
		//	block->S2bloc[10] = { 1312,1746,236,268 };
		//	block->S2bloc[11] = { 1376,1396,520,541 };
		//	block->S2bloc[12] = { 1443,1564,463,484 };
		//	block->S2bloc[13] = { 1528,1550,567, 588 };
		//	block->S2bloc[14] = { 1570,1590,513,534 };
		//	block->S2bloc[15] = { 1621,1638,444,461 };
		//	block->S2bloc[16] = { 1702,1718,399,415 };
		//	block->S2bloc[17] = { 1773,1791,515,532 };
		//	block->S2bloc[18] = { 1881,2560,523,720 };
		//	break;
		//case 3:
		//case 6:
		//	//左、右、上、下
		//	block->S3bloc[0] = { 0,276,560,720 };
		//	block->S3bloc[1] = { 304,335,477,508 };
		//	block->S3bloc[2] = { 374,396,418,448 };
		//	block->S3bloc[3] = { 428,848,381,480 };
		//	block->S3bloc[4] = { 533,556,292,315 };
		//	block->S3bloc[5] = { 627,651,292,315 };
		//	block->S3bloc[6] = { 719,742,292,315 };
		//	block->S3bloc[7] = { 909,930,296,329 };
		//	block->S3bloc[8] = { 943,982,511,541 };
		//	block->S3bloc[9] = { 970,990,222,253 };
		//	block->S3bloc[10] = { 1035,1055,175,195 };
		//	block->S3bloc[11] = { 1040,1063,550,508 };
		//	block->S3bloc[12] = { 1121,1660,140,214 };
		//	block->S3bloc[13] = { 1121,1722,563,660 };
		//	block->S3bloc[14] = { 1176,1215,471,560 };
		//	block->S3bloc[15] = { 1589,1629,471,560 };
		//	block->S3bloc[16] = { 1732,1797,203,224 };
		//	block->S3bloc[17] = { 1759,1781,500,518 };
		//	block->S3bloc[18] = { 1830,1864,625,645 };
		//	block->S3bloc[19] = { 1878,1894,0,188 };
		//	block->S3bloc[20] = { 1873,1898,279,298 };
		//	block->S3bloc[21] = { 1900,1911,587,604 };
		//	block->S3bloc[22] = { 1946,1957,532,551 };
		//	block->S3bloc[23] = { 1945,1957,656,676 };
		//	block->S3bloc[24] = { 1993,2005,621,639 };
		//	block->S3bloc[25] = { 2047,2062,587,596 };
		//	block->S3bloc[26] = { 2062,2560,561,720 };

		//	break;

		//};
		////block->bloc[0] = { 0,270,630,720 };
		////block->bloc[1] = { 340,440,565,615 };
		////block->bloc[2] = { 475,555,510,555 };
		////block->bloc[3] = { 510,555,470,510 };
		////block->bloc[4] = { 580,735,420,455 };
		////block->bloc[5] = { 780,845,365,415 };
		////block->bloc[6] = { 875,940,310,360 };
		////block->bloc[7] = { 950,1010,425,480 };
		////block->bloc[8] = { 980,1035,235,290 };
		////block->bloc[9] = { 1055,1120,350,410 };
		////block->bloc[10] = { 1125,1700,610,720 };

	}
	//if (BlockNum == 8) {
	//	eightflg = TRUE;
	//	threeflg = FALSE;
	//}
	//else if(BlockNum == 3){
	//	threeflg = TRUE;
	//	eightflg = FALSE;
	//}
	//else {
	//	threeflg = FALSE;
	//	eightflg = FALSE;
	//}

	if (Stage1::S1DecisionToAnswerFlg == TRUE && GameMain::NowStage == 4) {
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
	DrawFormatString(100, 0, GetColor(0, 255, 0), "playerX:%f  playerY:%f", playerX, playerY);
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

	if (PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_LEFT) /*&& NoHitBlockFlg == TRUE*/)
	{
		P_moveX = -3;
		playerX += P_moveX;
	}
	if (PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_RIGHT) /*&& NoHitBlockFlg == TRUE*/)
	{
		P_moveX = 3;
		playerX += P_moveX;
	}
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_A) && Jumpflg == FALSE /*&& NoHitBlockFlg == TRUE*/)
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
	//if (playerY >= 640) {
	//	playerY = 640;
	//}
}

void Player::PlayerHit()
{
	float sy = 0.0f;

	switch (GameMain::NowStage) {
	case 1:
		for (int i = 0; i < 11; i++)
		{
			if (i > 8)
			{
				if (int((px + -1 * (Stage1::Stage1X)) == block->S1bloc[9].X2 && int(py2) > block->S1bloc[9].Y))
				{
					P_moveX = 3;
					playerX += P_moveX;
					NoHitBlockFlg = FALSE;
					// 落下処理させる
					count += 1;
					Downflg = TRUE;
					HitFlg = FALSE;

					if (int(py2) > block->S1bloc[10].Y)
					{
						py2 = block->S1bloc[10].Y;
					}
				}
			}
			else
			{
				/* 処理ここから */
				if (/*PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_LEFT) &&*/ int(px + -1 * (Stage1::Stage1X)) == block->S1bloc[i].X2 && int(py2) > block->S1bloc[i].Y)
				{
					P_moveX = 3;
					playerX += P_moveX;
					NoHitBlockFlg = FALSE;
					// 落下処理させる
					count += 1;
					Downflg = TRUE;
					HitFlg = FALSE;

				}
				else if (/*PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_RIGHT) &&*/ int(px2 + -1 * (Stage1::Stage1X)) == block->S1bloc[i].X && int(py2) > block->S1bloc[i].Y)
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

			if (int(px + -1 * (Stage1::Stage1X)) <= block->S1bloc[i].X2 && int(px2 + -1 * (Stage1::Stage1X)) >= block->S1bloc[i].X)
			{
				// フラグを立てる
				HitFlg = TRUE;
				BlockNum = i;
				// 上にプレイヤーがいる処理
				if (int(py2) <= block->S1bloc[BlockNum].Y && HitFlg == TRUE && NoHitBlockFlg == TRUE)
				{
					HitFlg = FALSE;
					BlockNum = -1;
				}
				else
				{
					// プレイヤーの頭上よりも下のブロックが座標が高いか？
					if (int(py) < block->S1bloc[BlockNum].Y2)
					{
						/* 下に落ちない処理を書く */
						Jumpflg = FALSE;
						Downflg = FALSE;
						count = 0;
					}
					// プレイヤーの頭上と下のブロックがぶつかった時
					else if (int(py) == block->S1bloc[BlockNum].Y2)
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
			if (int(px + -1 * (Stage1::Stage1X)) <= block->S1bloc[i].X2 && int(px2 + -1 * (Stage1::Stage1X)) <= block->S1bloc[i].X && int(py) == block->S1bloc[i].Y2)
			{
				HitFlg = TRUE;
				BlockNum = i;
				///* 下に落ちない処理を書く */
				//Jumpflg = FALSE;
				//Downflg = FALSE;
				//count = 0;
				break;
				// ブロックの右側にプレイヤーの左側に当たっているか確認
				if (int(px + -1 * (Stage1::Stage1X)) == block->S1bloc[BlockNum].X2 && int(py) > block->S1bloc[BlockNum].Y2)
				{
					playerX -= 0;
					// 落下処理させる
					count += 1;
					Downflg = TRUE;
				}
				// ブロックの左側にプレイヤーの右側に当たっているか確認
				else if (int(px2 + -1 * (Stage1::Stage1X)) == block->S1bloc[BlockNum].X && int(py) > block->S1bloc[BlockNum].Y2)
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
				if (int(py2) <= block->S1bloc[BlockNum].Y && HitFlg == TRUE)
				{
					HitFlg = FALSE;
					BlockNum = -1;
				}
				else
				{
					// プレイヤーの頭上よりも下のブロックが座標が高いか？
					if (int(py) < block->S1bloc[BlockNum].Y2)
					{
						/* 下に落ちない処理を書く */
						Jumpflg = FALSE;
						Downflg = FALSE;
						count = 0;
					}
					// プレイヤーの頭上と下のブロックがぶつかった時
					else if (int(py) == block->S1bloc[BlockNum].Y2)
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
		break;
	case 2:
		for (int i = 0; i < 19; i++)
		{
			////if (i > 8)
			////{
			////	if (int((px + -1 * (Stage2::Stage2X)) == block->S2bloc[9].X2 && int(py2) > block->S2bloc[9].Y))
			////	{
			////		P_moveX = 3;
			////		playerX += P_moveX;
			////		NoHitBlockFlg = FALSE;
			////		// 落下処理させる
			////		count += 1;
			////		Downflg = TRUE;
			////		HitFlg = FALSE;

			////		if (int(py2) > block->S2bloc[10].Y)
			////		{
			////			py2 = block->S2bloc[10].Y;
			////		}
			////	}
			////}
			////else
			////{
			////	/* 処理ここから */
			////	if (/*PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_LEFT) &&*/ int(px + -1 * (Stage2::Stage2X)) == block->S2bloc[i].X2 && int(py2) > block->S2bloc[i].Y)
			////	{
			////		P_moveX = 3;
			////		playerX += P_moveX;
			////		NoHitBlockFlg = FALSE;
			////		// 落下処理させる
			////		count += 1;
			////		Downflg = TRUE;
			////		HitFlg = FALSE;

			////	}
			////	else if (/*PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_RIGHT) &&*/ int(px2 + -1 * (Stage2::Stage2X)) == block->S2bloc[i].X && int(py2) > block->S2bloc[i].Y)
			////	{
			////		//playerX += 0;
			////		P_moveX = -3;
			////		playerX += P_moveX;
			////		NoHitBlockFlg = FALSE;
			////		// 落下処理させる
			////		count += 1;
			////		Downflg = TRUE;
			////		HitFlg = FALSE;
			////	}
			////	else
			////	{
			////		NoHitBlockFlg = TRUE;
			////	}
			////}
			/* 処理ここまで */

			if (int(px + -1 * (Stage2::Stage2X)) <= block->S2bloc[i].X2 && int(px2 + -1 * (Stage2::Stage2X)) >= block->S2bloc[i].X)
			{
				// フラグを立てる
				HitFlg = TRUE;
				BlockNum = i;
				// 上にプレイヤーがいる処理
				if (int(py2) <= block->S2bloc[BlockNum].Y && HitFlg == TRUE && NoHitBlockFlg == TRUE)
				{
					HitFlg = FALSE;
					BlockNum = -1;
				}
				else
				{
					// プレイヤーの頭上よりも下のブロックが座標が高いか？
					if (int(py) < block->S2bloc[BlockNum].Y2)
					{
						/* 下に落ちない処理を書く */
						Jumpflg = FALSE;
						Downflg = FALSE;
						count = 0;
					}
					// プレイヤーの頭上と下のブロックがぶつかった時
					else if (int(py) == block->S2bloc[BlockNum].Y2)
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
					if (BlockNum >= 18) {
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
			else if (i == 18) // ブロックのX軸の範囲内にいなかった時
			{
				// 落下処理させる
				count += 1;
				Downflg = TRUE;
			}
			//}
				// ブロックに当たっているか確認
			if (int(px + -1 * (Stage2::Stage2X)) <= block->S2bloc[i].X2 && int(px2 + -1 * (Stage2::Stage2X)) <= block->S2bloc[i].X && int(py) == block->S2bloc[i].Y2)
			{
				HitFlg = TRUE;
				BlockNum = i;
				///* 下に落ちない処理を書く */
				//Jumpflg = FALSE;
				//Downflg = FALSE;
				//count = 0;
				break;
				// ブロックの右側にプレイヤーの左側に当たっているか確認
				if (int(px + -1 * (Stage2::Stage2X)) == block->S2bloc[BlockNum].X2 && int(py) > block->S2bloc[BlockNum].Y2)
				{
					playerX -= 0;
					// 落下処理させる
					count += 1;
					Downflg = TRUE;
				}
				// ブロックの左側にプレイヤーの右側に当たっているか確認
				else if (int(px2 + -1 * (Stage2::Stage2X)) == block->S2bloc[BlockNum].X && int(py) > block->S2bloc[BlockNum].Y2)
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
				if (int(py2) <= block->S2bloc[BlockNum].Y && HitFlg == TRUE)
				{
					HitFlg = FALSE;
					BlockNum = -1;
				}
				else
				{
					// プレイヤーの頭上よりも下のブロックが座標が高いか？
					if (int(py) < block->S2bloc[BlockNum].Y2)
					{
						/* 下に落ちない処理を書く */
						Jumpflg = FALSE;
						Downflg = FALSE;
						count = 0;
					}
					// プレイヤーの頭上と下のブロックがぶつかった時
					else if (int(py) == block->S2bloc[BlockNum].Y2)
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
					if (BlockNum >= 17) {
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
		break;
	case 3:
		for (int i = 0; i < 27; i++)
		{
			////if (i > 8)
			////{
			////	if (int((px + -1 * (Stage3::Stage3X)) == block->S3bloc[9].X2 && int(py2) > block->S3bloc[9].Y))
			////	{
			////		P_moveX = 3;
			////		playerX += P_moveX;
			////		NoHitBlockFlg = FALSE;
			////		// 落下処理させる
			////		count += 1;
			////		Downflg = TRUE;
			////		HitFlg = FALSE;

			////		if (int(py2) > block->S3bloc[10].Y)
			////		{
			////			py2 = block->S3bloc[10].Y;
			////		}
			////	}
			////}
			////else
			////{
			////	/* 処理ここから */
			////	if (/*PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_LEFT) &&*/ int(px + -1 * (Stage3::Stage3X)) == block->S3bloc[i].X2 && int(py2) > block->S3bloc[i].Y)
			////	{
			////		P_moveX = 3;
			////		playerX += P_moveX;
			////		NoHitBlockFlg = FALSE;
			////		// 落下処理させる
			////		count += 1;
			////		Downflg = TRUE;
			////		HitFlg = FALSE;

			////	}
			////	else if (/*PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_RIGHT) &&*/ int(px2 + -1 * (Stage3::Stage3X)) == block->S3bloc[i].X && int(py2) > block->S3bloc[i].Y)
			////	{
			////		//playerX += 0;
			////		P_moveX = -3;
			////		playerX += P_moveX;
			////		NoHitBlockFlg = FALSE;
			////		// 落下処理させる
			////		count += 1;
			////		Downflg = TRUE;
			////		HitFlg = FALSE;
			////	}
			////	else
			////	{
			////		NoHitBlockFlg = TRUE;
			////	}
			////}
			/* 処理ここまで */

			if (int(px + -1 * (Stage3::Stage3X)) <= block->S3bloc[i].X2 && int(px2 + -1 * (Stage3::Stage3X)) >= block->S3bloc[i].X)
			{
				// フラグを立てる
				HitFlg = TRUE;
				BlockNum = i;
				// 上にプレイヤーがいる処理
				if (int(py2) <= block->S3bloc[BlockNum].Y && HitFlg == TRUE && NoHitBlockFlg == TRUE)
				{
					HitFlg = FALSE;
					BlockNum = -1;
				}
				else
				{
					// プレイヤーの頭上よりも下のブロックが座標が高いか？
					if (int(py) < block->S3bloc[BlockNum].Y2)
					{
						/* 下に落ちない処理を書く */
						Jumpflg = FALSE;
						Downflg = FALSE;
						count = 0;
					}
					// プレイヤーの頭上と下のブロックがぶつかった時
					else if (int(py) == block->S3bloc[BlockNum].Y2)
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
			else if (i == 28) // ブロックのX軸の範囲内にいなかった時
			{
				// 落下処理させる
				count += 1;
				Downflg = TRUE;
			}
			//}
				// ブロックに当たっているか確認
			if (int(px + -1 * (Stage3::Stage3X)) <= block->S3bloc[i].X2 && int(px2 + -1 * (Stage3::Stage3X)) <= block->S3bloc[i].X && int(py) == block->S3bloc[i].Y2)
			{
				HitFlg = TRUE;
				BlockNum = i;
				///* 下に落ちない処理を書く */
				//Jumpflg = FALSE;
				//Downflg = FALSE;
				//count = 0;
				break;
				// ブロックの右側にプレイヤーの左側に当たっているか確認
				if (int(px + -1 * (Stage3::Stage3X)) == block->S3bloc[BlockNum].X2 && int(py) > block->S3bloc[BlockNum].Y2)
				{
					playerX -= 0;
					// 落下処理させる
					count += 1;
					Downflg = TRUE;
				}
				// ブロックの左側にプレイヤーの右側に当たっているか確認
				else if (int(px2 + -1 * (Stage3::Stage3X)) == block->S3bloc[BlockNum].X && int(py) > block->S3bloc[BlockNum].Y2)
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
				if (int(py2) <= block->S3bloc[BlockNum].Y && HitFlg == TRUE)
				{
					HitFlg = FALSE;
					BlockNum = -1;
				}
				else
				{
					// プレイヤーの頭上よりも下のブロックが座標が高いか？
					if (int(py) < block->S3bloc[BlockNum].Y2)
					{
						/* 下に落ちない処理を書く */
						Jumpflg = FALSE;
						Downflg = FALSE;
						count = 0;
					}
					// プレイヤーの頭上と下のブロックがぶつかった時
					else if (int(py) == block->S3bloc[BlockNum].Y2)
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
					if (BlockNum >= 27) {
						quizflg = 1;
					}
					else
					{
						quizflg = 0;
					}


				}
			}
			else if (i == 28)
			{
				count += 1;
				Downflg = TRUE;
			}

		}
		break;
	}

}

