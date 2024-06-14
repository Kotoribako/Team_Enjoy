#include "Enemy.h"
#include"DxLib.h"
#include"Stage1.h"
#include"Stage2.h"
#include"Stage3.h"
#include"GameMain.h"
#include"math.h"
float Enemy::ex;
float Enemy::ex2;
float Enemy::ey;
float Enemy::ey2;
int   Enemy::Range;

Enemy::Enemy()
{
	if (LoadDivGraph("image/Dummy/enemy.png", 2, 2, 1, 64, 64, img)) {};
	//enemyX = 580;
	if (LoadDivGraph("image/Dummy/slime.png", 3, 3, 1, 64, 64, slimeImg)) {};
	E_Img = slimeImg[0];
	count = 0;
	block = new Block();
	player = new Player();
	countup = 0;
	moveX = 0;
	direction = 0;
	speed = 30;
	Hitflg = FALSE;
	Range = 15;
	Turnflg = 0;
	switch (GameMain::NowStage)
	{
	case 1:
	case 4:
		blockx[1].X = block->S1bloc[4].X;
		blockx[1].X2 = block->S1bloc[4].X2;
		enemyX = block->S1bloc[4].X;
		enemyY = block->S1bloc[4].Y - 15;
		break;
	case 2:
	case 5:
		blockx[2].X = block->S2bloc[8].X;
		blockx[2].X2 = block->S2bloc[8].X2;
		enemyX = block->S2bloc[8].X - 30;
		enemyY = block->S2bloc[8].Y - 30;
		break;
	case 3:
	case 6:
		blockx[3].X = block->S3bloc[6].X;
		blockx[3].X2 = block->S3bloc[6].X2;
		enemyX = block->S3bloc[6].X - 30;
		enemyY = block->S3bloc[6].Y - 30;
		break;
	}

}

void Enemy::Update()
{
	E_FPS++;

	enemyX2 = enemyX + 30;
	enemyY2 = enemyY + 30;

	ex = enemyX - 15;
	ex2 = enemyX + 15;
	ey = enemyY - 15;
	ey2 = enemyY + 15;



	speed = (blockx[GameMain::NowStage].X2 - blockx[GameMain::NowStage].X) / 6.0f;
	Enemyhit();
	count++;
	//switch (GameMain::NowStage)
	//{
	//case 1:
	//case 4:

	//}
	if (count == 60)
	{
		countup += 1;
		
		if (direction == 0)
		{
			enemyX += speed;
			Turnflg = 1;
		}
		else if (direction == 1)
		{
			enemyX -= speed;
			Turnflg = 0;
		}
		
		count = 0;
	}

	if (countup == 5)
	{
		if (direction == 0)
		{
			direction = 1;
		}
		else if (direction == 1)
		{
			direction = 0;
		}
		countup = 0;
	}
	EnemyAnim();
	if (E_FPS > 59) {
		E_FPS = 0;
		E_Seconas1++;

	}// P_FPS_INC 
	else if (E_Seconas1 > 3) {
		E_Seconas1 = 0;
	}

}

void Enemy::Draw()
{
	DrawFormatString(200, 200, GetColor(0, 0, 255), "Turnflg:%d",Turnflg);
	//DrawFormatString(200, 200, GetColor(0, 0, 255), "countup:%d", countup);
	switch (GameMain::NowStage)
	{
	case 1:
		if (Turnflg == 1)
		{
			DrawTurnGraph(enemyX + Stage1::Stage1X - 30, enemyY - 50, E_Img, TRUE);
		}
		else if (Turnflg == 0)
		{
			DrawGraph(enemyX + Stage1::Stage1X - 30, enemyY - 50, E_Img, TRUE);

		}
		DrawBox(ex + /*moveX +*/ Stage1::Stage1X, ey, ex2 + /*moveX +*/ Stage1::Stage1X, ey2, GetColor(0, 255, 0), FALSE);
		DrawCircle(enemyX + Stage1::Stage1X, enemyY, Range, GetColor(0, 255, 0), FALSE);
		break;
	case 2:
		if (Turnflg == 1)
		{
	
			DrawTurnGraph(enemyX + Stage2::Stage2X - 30, enemyY - 30, E_Img, TRUE);
		}
		else if (Turnflg == 0)
		{
			DrawGraph(enemyX + Stage2::Stage2X - 30, enemyY - 30, E_Img, TRUE);
		}
		DrawBox(ex + /*moveX +*/ Stage2::Stage2X, ey, ex2 +/* moveX +*/ Stage2::Stage2X, ey2, GetColor(0, 255, 0), FALSE);
		DrawCircle(enemyX + Stage2::Stage2X, enemyY, Range, GetColor(0, 255, 0), FALSE);
		break;
	case 3:
		if (Turnflg == 1)
		{
			DrawTurnGraph(enemyX + Stage3::Stage3X - 30, enemyY - 30, E_Img, TRUE);
		}
		else if (Turnflg == 0)
		{
			DrawGraph(enemyX + Stage3::Stage3X - 30, enemyY - 30, E_Img, TRUE);
		}

		DrawBox(ex + /*moveX +*/ Stage3::Stage3X, ey, ex2 + /*moveX +*/ Stage3::Stage3X, ey2, GetColor(0, 255, 0), FALSE);
		DrawCircle(enemyX + Stage3::Stage3X, enemyY, Range, GetColor(0, 255, 0), FALSE);
		break;
	}
	if (Hitflg == TRUE)
	{
		DrawFormatString(enemyX, enemyY - 30, GetColor(0, 0, 255), "Hit!!");
	}
}



void Enemy::Enemyhit()
{
	float a, b;
	switch (GameMain::NowStage)
	{
	case 1:
	case 4:
		 a = player->GetLocationCenterX() - enemyX - Stage1::Stage1X;
		 b = player->GetLocationCenterY() - enemyY;
		break;
	case 2:
	case 5:
		 a = player->GetLocationCenterX() - enemyX - Stage2::Stage2X;
		 b = player->GetLocationCenterY() - enemyY;
		break;
	case 3:
	case 6:
		 a = player->GetLocationCenterX() - enemyX - Stage3::Stage3X;
		 b = player->GetLocationCenterY() - enemyY;
		break;
	/* ゲームオーバーかゲームクリアに入った時 */
	case 7:
	case 8:
		a = 0; // 例外スロー対策
		b = 0; // 例外スロー対策
		break;
	}
	if (Player::Life >= 0)
	{
		float c = a * a + b * b;
		float Hitrange = (player->Range + Range) * (player->Range * Range) / 4;
		if (c <= Hitrange)
		{

			Hitflg = TRUE;
			Player::Life -= 1;
			Player::playerX = 220;
			Player::playerY = 430;
			Stage1::Stage1X = 0;
			Stage2::Stage2X = 0;
			Stage3::Stage3X = 0;

			Hitflg = FALSE;
		}
		else
		{
			Hitflg = FALSE;
		}
	}
}

void Enemy::EnemyAnim()
{
	if (E_FPS % 15 == 0 || E_FPS % 50 == 1 || E_FPS % 50 == 2 || E_FPS % 50 == 3 || E_FPS % 50 == 4)
	{
		E_Img = slimeImg[0];
	}
	else if (E_FPS % 15 == 5 || E_FPS % 15 == 6 || E_FPS % 15 == 7 || E_FPS % 15 == 8 || E_FPS % 15 == 9) {
		E_Img = slimeImg[1];
	}
	else if (E_FPS % 15 == 10 || E_FPS % 15 == 11 || E_FPS % 15 == 12 || E_FPS % 15 == 13 || E_FPS % 15 == 14) {
		E_Img = slimeImg[2];
	}
	//else if (E_FPS % 70 == 15 || E_FPS % 70 == 16 || E_FPS % 70 == 17 || E_FPS % 70 == 18 || E_FPS % 70 == 19) {
	//	E_Img = slimeImg[0];
	//}
	//else if (E_FPS % 70 == 20 || E_FPS % 70 == 21 || E_FPS % 70 == 22 || E_FPS % 70 == 23 || E_FPS % 70 == 24) {
	//	E_Img = slimeImg[1];
	//}
	//else if (E_FPS % 70 == 25 || E_FPS % 70 == 26 || E_FPS % 70 == 27 || E_FPS % 70 == 28 || E_FPS % 70 == 29) {
	//	E_Img = slimeImg[2];
	//}
	//else if (E_FPS % 70 == 30 || E_FPS % 70 == 31 || E_FPS % 70 == 32 || E_FPS % 70 == 33 || E_FPS % 70 == 34) {
	//	E_Img = slimeImg[0];
	//}
	//else if (E_FPS % 70 == 35 || E_FPS % 70 == 36 || E_FPS % 70 == 37 || E_FPS % 70 == 38 || E_FPS % 70 == 39) {
	//	E_Img = slimeImg[1];
	//}
	//else if (E_FPS % 70 == 40 || E_FPS % 70 == 41 || E_FPS % 70 == 42 || E_FPS % 70 == 43 || E_FPS % 70 == 44) {
	//	E_Img = slimeImg[2];
	//}
	//else if (E_FPS % 70 == 45 || E_FPS % 70 == 46 || E_FPS % 70 == 47 || E_FPS % 70 == 48 || E_FPS % 70 == 49) {
	//	E_Img = slimeImg[0];
	//}
	//else if (E_FPS % 70 == 50 || E_FPS % 70 == 51 || E_FPS % 70 == 52 || E_FPS % 70 == 53 || E_FPS % 70 == 54) {
	//	E_Img = slimeImg[1];
	//}
	//else if (E_FPS % 70 == 55 || E_FPS % 70 == 56 || E_FPS % 70 == 57 || E_FPS % 70 == 58 || E_FPS % 70 == 59) {
	//	E_Img = slimeImg[2];
	//}
	//else if (E_FPS % 70 == 60 || E_FPS % 70 == 61 || E_FPS % 70 == 62 || E_FPS % 70 == 63 || E_FPS % 70 == 64) {
	//	E_Img = slimeImg[0];
	//}
	//else if (E_FPS % 70 == 65 || E_FPS % 70 == 66 || E_FPS % 70 == 67 || E_FPS % 70 == 68 || E_FPS % 70 == 69) {
	//	E_Img = slimeImg[1];
	//}

	//else if (E_FPS % 50 == 10 || E_FPS % 50 == 11 || E_FPS % 50 == 12 || E_FPS % 50 == 13 || E_FPS % 50 == 14) {
	//	E_Img = slimeImg[2];
	//}
	//else if (E_FPS % 50 == 5 || E_FPS % 50 == 6 || E_FPS % 50 == 7 || E_FPS % 50 == 8 || E_FPS % 50 == 9) {
	//	E_Img = slimeImg[1];
	//}
	//else if (E_FPS % 50 == 10 || E_FPS % 50 == 11 || E_FPS % 50 == 12 || E_FPS % 50 == 13 || E_FPS % 50 == 14) {
	//	E_Img = slimeImg[2];
	//}


	else {
		// 5�t���[��
		if (E_FPS % 15 == 0 || E_FPS % 15 == 1 || E_FPS % 15 == 2 || E_FPS % 15 == 3 || E_FPS % 15 == 4)
		{
			E_Img = slimeImg[0];
		}
		else if (E_FPS % 15 == 5 || E_FPS % 15 == 6 || E_FPS % 15 == 7 || E_FPS % 15 == 8 || E_FPS % 15 == 9) {
			E_Img = slimeImg[1];
		}
		else if (E_FPS % 15 == 10 || E_FPS % 15 == 11 || E_FPS % 15 == 12 || E_FPS % 15 == 13 || E_FPS % 15 == 14) {
			E_Img = slimeImg[2];
		}
	}
}
	

	

	
