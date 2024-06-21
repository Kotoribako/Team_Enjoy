#include "Player.h"
#include "Stage1.h"
#include<iostream>
#include"DxLib.h"
#include"GenreSelect.h"
#include"GameMain.h"
float Player::playerX;  //プレイヤー座標X プレイヤーX軸の中心座標
float Player::playerY;  //プレイヤー座標X プレイヤーY軸の中心座標
int   Player::standflg; //立ってるかのフラグ
float Player::velocity;
int   Player::MoveFlg;
int   Player::quizflg;
int   Player::Life;
int   Player::Range;
int   Player::Death;
#define PLAYERSTARTX 220
#define PLAYERSTARTY 430

Player::Player()
{
	block = new Block();

	playerX = PLAYERSTARTX;
	playerY = PLAYERSTARTY;

	if (LoadDivGraph("image/Dummy/player.png", 3, 3, 1, 64, 64, image)) {};

	DeathSE = LoadSoundMem("sound/SE/deth2_SE.wav");
	JumpSE = LoadSoundMem("sound/SE/Jump.mp3");

	P_img = image[0];
	px = playerX - 15;
	px2 = playerX + 15;
	py = playerY - 15;
	py2 = playerY + 15;

	Range = 15;
	P_FPS = 0;
	velocity = 0.0f;
	MoveFlg = FALSE;
	standflg = 1;

	HitFlg = FALSE;
	Animflg = 0;
	Rightflg = 0;
	Leftflg = 0;

	Life = 3;
	if (GameMain::NowStage >= 2)
	{
		Life -= Death;
	}
	else
	{
		Death = 0;
	}

	Downflg = FALSE;
}

Player::~Player()
{
	DeleteSoundMem(DeathSE);
	DeleteSoundMem(JumpSE);
}

void Player::Update()
{
	
	P_FPS++;

	block = new Block();

	if (BlockHitY() == 1)
	{
		/* 下に落ちない処理を書く */
		Jumpflg = FALSE;
		Downflg = FALSE;
		count = 0;
		switch (GameMain::NowStage) {
		case 1:
		case 4:
			if (px + -1 * (Stage1::Stage1X) < block->S1bloc[9].X2 && block->S1bloc[9].X < px2 + -1 * (Stage1::Stage1X) && block->S1bloc[9].Y < py2 ||
				px + -1 * (Stage1::Stage1X) < block->S1bloc[10].X2 && block->S1bloc[10].X < px2 + -1 * (Stage1::Stage1X) && block->S1bloc[10].Y < py2)
			{
				quizflg = 1;
			}
			else
			{
				quizflg = 0;
			}
			break;
		case 2:
		case 5:
			if (px + -1 * (Stage2::Stage2X) < block->S2bloc[18].X2 && block->S2bloc[18].X < px2 + -1 * (Stage2::Stage2X) && block->S2bloc[18].Y < py2)
			{
				quizflg = 1;
			}
			else
			{
				quizflg = 0;
			}
			break;
		case 3:
		case 6:
			if (px + -1 * (Stage3::Stage3X) < block->S3bloc[26].X2 && block->S3bloc[26].X < px2 + -1 * (Stage3::Stage3X) && block->S3bloc[26].Y < py2)
			{
				quizflg = 1;
			}
			else
			{
				quizflg = 0;
			}
		}
	}
	else if(BlockHitY() == 3)
	{
		Jumpflg = FALSE;
		// 落下処理させる
		count += 1;
		Downflg = TRUE;
		HitFlg = FALSE;
	}
	else if (BlockHitY() == 0 && Jumpflg == FALSE)
	{
		// 落下処理させる
		count += 1;
		Downflg = TRUE;
		HitFlg = FALSE;
	}
	if (BlockHitY() == 19 && GameMain::NowStage == 2 || GameMain::NowStage == 5)
	{
		count += 1;
		Downflg = TRUE;
		HitFlg = FALSE;


	}

	Move();
	if (Animflg == 1 /*&& Moveflg == 0*/)
	{
		PlayerAnim();
	}
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
		playerY = 500;
		Stage1::Stage1X = 0;
		Stage2::Stage2X = 0;
		Stage3::Stage3X = 0;
		Life--;
		Death++;

		block = new Block();

		PlaySoundMem(DeathSE, DX_PLAYTYPE_BACK, TRUE);

	}
	if (Life < 0) {
		/* ここにゲームオーバー処理を入れる */
		GameMain::NowStage = 8;
	}


	if (BlockHitX() == 1)
	{
		// ブロックにめり込ませないようにする
		P_moveX = 3;
		playerX += P_moveX;
		BlockNum = -1; // BlockNumberをリセット
	}
	if (BlockHitX() == 2)
	{
		// ブロックにめり込ませないようにする
		P_moveX = -3;
		playerX += P_moveX;
		BlockNum = -1; // BlockNumberをリセット
	}
	
	if (P_FPS > 59) {
		P_FPS = 0;
		P_Seconas1++;

	}// P_FPS_INC 
	else if (P_Seconas1 > 3) {
		P_Seconas1 = 0;
	}

	if (Stage1::S1DecisionToAnswerFlg == TRUE && GameMain::NowStage == 4 ||
		Stage2::S2DecisionToAnswerFlg == TRUE && GameMain::NowStage == 5 ||
		Stage3::S3DecisionToAnswerFlg == TRUE && GameMain::NowStage == 6) {
		// プレイヤーをスタート地点に戻す
		playerX = PLAYERSTARTX;
		playerY = PLAYERSTARTY;
		//PlaySoundMem(DeathSE, DX_PLAYTYPE_BACK, TRUE);
	}
	if (Rightflg == 0 && Leftflg == 0 && Turnflg == 0)
	{
		P_img = image[0];
	}
}

void Player::Draw()
{
	if (Turnflg == 0) {
		DrawGraph(playerX - 30, playerY - 50, P_img, TRUE);
	}
	DrawBox(px, py, px2, py2, GetColor(0, 0,255 ), FALSE);
	DrawCircle(playerX, playerY, Range, GetColor(255, 0, 0),FALSE);

	DrawBox(px, py-30, px2, py2-30, GetColor(0, 0, 255), FALSE);
	DrawCircle(playerX, playerY-30, Range, GetColor(255, 0, 0), FALSE);

	if (Turnflg == 1)
	{
		DrawTurnGraph(playerX - 30, playerY - 50, P_img, TRUE);
	}

	////DrawFormatString(0, 50, GetColor(0, 0, 0), "Animflg:%d", Animflg);
	////DrawFormatString(0, 80, GetColor(0, 0, 0), "Right:%d",Rightflg );
	////DrawFormatString(0, 110, GetColor(0, 0, 0), "Left:%d", Leftflg);
	////DrawFormatString(100, 0, GetColor(0, 255, 0), "playerX:%f  playerY:%f", playerX + -1 * (Stage2::Stage2X), playerY);
	////DrawFormatString(100, 20, GetColor(0, 255, 255), "px:%f py:%f px2:%f py2:%f", px + -1 * (Stage2::Stage2X), py, px2 + -1 * (Stage2::Stage2X), py2);
	////DrawFormatString(100, 40, GetColor(0, 0, 0), "HitY:%d", BlockHitY());
	////DrawFormatString(0, 120, GetColor(0, 0, 0), "Death:%d", Death);
	for (int i = 0; i < Life; i++)
	{
		DrawGraph(100 + 50 * i, 100, image[0], TRUE);
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

	if (PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_LEFT))
	{
		Animflg = 1;
		Turnflg = 1;
		Leftflg = 1;
		P_moveX = -3;
		playerX += P_moveX;
	}
	else
	{
		Leftflg = 0;
		Turnflg = 0;
		//Animflg = 0;
		//P_img = image[0];
	}
	if (PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_RIGHT))
	{
		Animflg = 1;
		Turnflg = 0;
		Rightflg = 1;
		P_moveX = 3;
		//playerX += P_moveX;
		playerX += 3;
	}
	else {
		Rightflg = 0;
	}
	if(Rightflg == 0 && Leftflg == 0)
	{
		Animflg = 0;
	}
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_A) && Jumpflg == FALSE)
	{
		PlaySoundMem(JumpSE, DX_PLAYTYPE_BACK,TRUE);
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
			Jumpflg = FALSE;
			Downflg = TRUE;
		}
	}
	if (Downflg == TRUE && count >= 1)
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

void Player::PlayerAnim()
{
	if (P_FPS % 20 == 0 || P_FPS % 20 == 1 || P_FPS % 20 == 2 || P_FPS % 20 == 3 || P_FPS % 20 == 4)
	{
		P_img = image[1];
	}
	else if (P_FPS % 20 == 5 || P_FPS % 20 == 6 || P_FPS % 20 == 7 || P_FPS % 20 == 8 || P_FPS % 20 == 9) {
		P_img = image[2];
	}
	else if (P_FPS % 20 == 10 || P_FPS % 20 == 11 || P_FPS % 20 == 12 || P_FPS % 20 == 13 || P_FPS % 20 == 14) {
		P_img = image[1];
	}
	else if (P_FPS % 20 == 15 || P_FPS % 20 == 16 || P_FPS % 20 == 17 || P_FPS % 20 == 18 || P_FPS % 20 == 19) {
		P_img = image[2];
	}
	/*else
	{
		if (P_FPS % 15 == 0 || P_FPS % 15 == 1 || P_FPS % 15 == 2 || P_FPS % 15 == 3 || P_FPS % 15 == 4) {
			P_img = image[0];
		}
		else if (P_FPS % 15 == 5 || P_FPS % 15 == 6 || P_FPS % 15 == 7 || P_FPS % 15 == 8 || P_FPS % 15 == 9) {
			P_img = image[1];
		}
		else if (P_FPS % 15 == 10 || P_FPS % 15 == 11 || P_FPS % 15 == 12 || P_FPS % 15 == 13 || P_FPS % 15 == 14) {
			P_img = image[2];
		}
	}*/
}

int Player::BlockHitY()
{
	switch (GameMain::NowStage)
	{
	case 1:
	case 4:
		for (int i = 0; i < 11; i++)
		{
			// 上に乗っているか確認
			if (px + -1 * (Stage1::Stage1X) < block->S1bloc[i].X2 && block->S1bloc[i].X < px2 + -1 * (Stage1::Stage1X))
			{

				if (py < block->S1bloc[i].Y2 && block->S1bloc[i].Y < py2 && Jumpflg == FALSE) // 地面に着地している状態
				{
					if (py < block->S1bloc[i].Y && py2 > block->S1bloc[i].Y)
					{
						playerY = block->S1bloc[i].Y - 11;
					}
					return 1;
					break;
				}
				if (block->S1bloc[i].Y > py2 && Jumpflg == TRUE) // ジャンプ中
				{
					return 2;
					break;
				}
				if (py < block->S1bloc[i].Y2 && Jumpflg == TRUE) // プレイヤーの頭上とブロックの下がヒットしたとき、
				{
					return 3;
					break;
				}
				
				

			}
		}
		return 0;
		break;
	case 2:
	case 5:
		for (int i = 0; i < 19; i++)
		{
			// 上に乗っているか確認
			if (px + -1 * (Stage2::Stage2X) < block->S2bloc[i].X2 && block->S2bloc[i].X < px2 + -1 * (Stage2::Stage2X))
			{
				if (py < block->S2bloc[i].Y2 && block->S2bloc[i].Y < py2 && Jumpflg == FALSE) // 地面に着地している状態
				{
					//if(i==10 && )
					if (py < block->S2bloc[i].Y && py2 > block->S2bloc[i].Y)
					{
						playerY = block->S2bloc[i].Y - 11;
					}
					return 1;
					break;
				}

				if (block->S2bloc[i].Y > py2 && Jumpflg == TRUE) // ジャンプ中
				{
					return 2;
					break;
				}
				if (py < block->S2bloc[i].Y2 && Jumpflg == TRUE) // プレイヤーの頭上とブロックの下がヒットしたとき、
				{
					return 3;
					break;
				}
			}
		}
		return 0;
		break;
	case 3:
	case 6:
		for (int i = 0; i < 27; i++)
		{
			// 上に乗っているか確認
			if (px + -1 * (Stage3::Stage3X) < block->S3bloc[i].X2 && block->S3bloc[i].X < px2 + -1 * (Stage3::Stage3X))
			{
				if (py < block->S3bloc[i].Y2 && block->S3bloc[i].Y < py2) // 地面に着地している状態
				{
			
					if (py < block->S3bloc[i].Y && py2 > block->S3bloc[i].Y)
					{
						playerY = block->S3bloc[i].Y - 11;
					}
					return 1;
					break;
				}
				if (block->S3bloc[i].Y > py2 && Jumpflg == TRUE) // ジャンプ中
				{
					return 2;
					break;
				}
				if (py < block->S3bloc[i].Y2 && Jumpflg == TRUE) // プレイヤーの頭上とブロックの下がヒットしたとき、
				{
					return 3;
					break;
				}
				

			}
		}
		return 0;
		break;
	}
}

int Player::BlockHitX()
{
	switch (GameMain::NowStage)
	{
	case 1:
	case 4:
		for (int i = 0; i < 11; i++)
		{
			if (px + -1 * (Stage1::Stage1X) == block->S1bloc[i].X2 && py2 > block->S1bloc[i].Y && py < block->S1bloc[i].Y2)
			{
				BlockNum = i;
				return 1;
				break;
			}
			else if (block->S1bloc[i].X == px2 + -1 * (Stage1::Stage1X) && py2 > block->S1bloc[i].Y && py < block->S1bloc[i].Y2)
			{
				BlockNum = i;
				return 2;
			}
			else if (i == 10)
			{
				return 0;
			}
		}
		break;
	case 2:
	case 5:
		for (int i = 0; i < 19; i++)
		{
			if (px + -1 * (Stage2::Stage2X) == block->S2bloc[i].X2 && py2 > block->S2bloc[i].Y && py < block->S2bloc[i].Y2)
			{
				BlockNum = i;
				return 1;
				break;
			}
			else if (block->S2bloc[i].X == px2 + -1 * (Stage3::Stage3X) && py2 > block->S2bloc[i].Y && py < block->S2bloc[i].Y2)
			{
				BlockNum = i;
				return 2;
			}
			else if (i == 18)
			{
				return 0;
			}
		}

		break;
	case 3:
	case 6:
		for (int i = 0; i < 27; i++)
		{
			if (px + -1 * (Stage3::Stage3X) == block->S3bloc[i].X2 && py2 > block->S3bloc[i].Y && py < block->S3bloc[i].Y2)
			{
				BlockNum = i;
				return 1;
				break;
			}
			else if (block->S3bloc[i].X == px2 + -1 * (Stage3::Stage3X) && py2 > block->S3bloc[i].Y && py < block->S3bloc[i].Y2)
			{
				BlockNum = i;
				return 2;
			}
			else if (i == 26)
			{
				return 0;
			}
		}


		break;
	}
}