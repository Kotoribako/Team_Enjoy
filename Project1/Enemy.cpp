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
	//if (LoadDivGraph("image/Dummy/enemy.png", 2, 2, 1, 64, 64, img)) {};
	//enemyX = 580;
	if (LoadDivGraph("image/Dummy/slime.png", 3, 3, 1, 64, 64, slimeImg)) {};
	E_Img = slimeImg[0];
	count = 0;
	block = new Block();
	player = new Player();
	countup = 0;
	moveX = 0;
	direction = 0;
	Hitflg = FALSE;
	Range = 15;
	s_enemy->Turnflg = 0;
	Returnflg = 0;
	switch (GameMain::NowStage)
	{
	case 1:
	case 4:
		blockx[0].X = block->S1bloc[4].X;
		blockx[0].X2 = block->S1bloc[4].X2;
		s_enemy[0].enemyX = block->S1bloc[4].X;
		s_enemy[0].enemyY = block->S1bloc[4].Y - 15;
		break;
	case 2:
	case 5:
		blockx[0].X = block->S2bloc[8].X;
		blockx[0].X2 = block->S2bloc[8].X2;
		s_enemy[0].enemyX = block->S2bloc[8].X;
		s_enemy[0].enemyY = block->S2bloc[8].Y - 30;

		blockx[1].X = block->S2bloc[10].X;
		blockx[1].X2 = block->S2bloc[10].X2;
		s_enemy[1].enemyX = block->S2bloc[10].X;
		s_enemy[1].enemyY = block->S2bloc[10].Y - 30;
		break;
	case 3:
	case 6:
		blockx[0].X = block->S3bloc[6].X;
		blockx[0].X2 = block->S3bloc[6].X2;
		s_enemy[0].enemyX = block->S3bloc[6].X;
		s_enemy[0].enemyY = block->S3bloc[6].Y - 30;

		blockx[1].X = block->S3bloc[12].X;
		blockx[1].X2 = block->S3bloc[12].X2;
		s_enemy[1].enemyX = block->S3bloc[12].X;
		s_enemy[1].enemyY = block->S3bloc[12].Y - 30;

		blockx[2].X = block->S3bloc[14].X2;
		blockx[2].X2 = block->S3bloc[15].X;
		s_enemy[2].enemyX = block->S3bloc[14].X + 30;
		s_enemy[2].enemyY = block->S3bloc[13].Y - 30;
		break;
	}

}

void Enemy::Update()
{
	E_FPS++;

	//s_enemy[0].enemyX2 = enemyX + 30;
	//enemyY2 = enemyY + 30;

	//ex = enemyX - 15;
	//ex2 = enemyX + 15;
	//ey = enemyY - 15;
	//ey2 = enemyY + 15;



	Enemyhit();
	count++;
	switch (GameMain::NowStage)
	{
	case 1:
	case 4:
		if (s_enemy[0].enemyX == blockx[0].X2)
		{
			Returnflg = 1;
		}
		if (s_enemy[0].enemyX == blockx[0].X)
		{
			Returnflg = 0;
		}
		if (Returnflg == 0)
		{
			s_enemy[0].enemyX += 0.5f;
			s_enemy[0].Turnflg = 1;
		}
		if (Returnflg == 1)
		{
			s_enemy[0].enemyX -= 0.5f;
			s_enemy[0].Turnflg = 0;
		}
		break;
	case 2:
	case 5:
		for (int i = 0; i < 2; i++)
		{
			if (s_enemy[i].enemyX == blockx[i].X2)
			{
				Returnflg = 1;
			}
			if (s_enemy[i].enemyX == blockx[i].X)
			{
				Returnflg = 0;
			}
			if (Returnflg == 0)
			{
				s_enemy[i].enemyX += 0.5f;
				s_enemy[i].Turnflg = 1;
			}
			if (Returnflg == 1)
			{
				s_enemy[i].enemyX -= 0.5f;
				s_enemy[i].Turnflg = 0;
			}
		}
		break;

	case 3:
	case 6:
		for (int i = 0; i < 3; i++)
		{
			if (s_enemy[i].enemyX == blockx[i].X2)
			{
				Returnflg = 1;
			}
			if (s_enemy[i].enemyX == blockx[i].X)
			{
				Returnflg = 0;
			}
			if (Returnflg == 0)
			{
				s_enemy[i].enemyX += 0.5f;
				s_enemy[i].Turnflg = 1;
			}
			if (Returnflg == 1)
			{
				s_enemy[i].enemyX -= 0.5f;
				s_enemy[i].Turnflg = 0;
			}
		}
		break;
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
	DrawFormatString(200, 200, GetColor(0, 0, 255), "ReTurnflg:%d",Returnflg);
	//DrawFormatString(200, 200, GetColor(0, 0, 255), "countup:%d", countup);
	switch (GameMain::NowStage)
	{
	case 1:
		if (s_enemy[0].Turnflg == 1)
		{
			DrawTurnGraph(s_enemy[0].enemyX + Stage1::Stage1X - 30, s_enemy[0].enemyY - 50, E_Img, TRUE);
		}
		else if (s_enemy[0].Turnflg == 0)
		{
			DrawGraph(s_enemy[0].enemyX + Stage1::Stage1X - 30, s_enemy[0].enemyY - 50, E_Img, TRUE);

		}
		DrawBox(ex + /*moveX +*/ Stage1::Stage1X, ey, ex2 + /*moveX +*/ Stage1::Stage1X, ey2, GetColor(0, 255, 0), FALSE);
		DrawCircle(s_enemy[0].enemyX + Stage1::Stage1X, s_enemy[0].enemyY, Range, GetColor(0, 255, 0), FALSE);
		break;
	case 2:
		for (int i = 0; i < 2; i++)
		{
			if (s_enemy[i].Turnflg == 1)
			{

				DrawTurnGraph(s_enemy[i].enemyX + Stage2::Stage2X - 30, s_enemy[i].enemyY - 30, E_Img, TRUE);
			}
			else if (s_enemy[i].Turnflg == 0)
			{
				DrawGraph(s_enemy[i].enemyX + Stage2::Stage2X - 30, s_enemy[i].enemyY - 30, E_Img, TRUE);
			}
			DrawBox(ex + /*moveX +*/ Stage2::Stage2X, ey, ex2 +/* moveX +*/ Stage2::Stage2X, ey2, GetColor(0, 255, 0), FALSE);
			DrawCircle(s_enemy[i].enemyX + Stage2::Stage2X, s_enemy[i].enemyY, Range, GetColor(0, 255, 0), FALSE);

		}
		break;
	case 3:
		for (int i = 0; i < 3; i++)
		{
			if (s_enemy[i].Turnflg == 1)
			{

				DrawTurnGraph(s_enemy[i].enemyX + Stage3::Stage3X - 30, s_enemy[i].enemyY - 30, E_Img, TRUE);
			}
			else if (s_enemy[i].Turnflg == 0)
			{

				DrawGraph(s_enemy[i].enemyX + Stage3::Stage3X - 30, s_enemy[i].enemyY - 30, E_Img, TRUE);
			}
			DrawBox(ex + /*moveX +*/ Stage3::Stage3X, ey, ex2 +/* moveX +*/ Stage3::Stage3X, ey2, GetColor(0, 255, 0), FALSE);
			DrawCircle(s_enemy[i].enemyX + Stage3::Stage3X, s_enemy[i].enemyY, Range, GetColor(0, 255, 0), FALSE);

		}

		//if (s_enemy[0].Turnflg == 1)
		//{
		//	DrawTurnGraph(s_enemy[0].enemyX + Stage3::Stage3X - 30, s_enemy[0].enemyY - 30, E_Img, TRUE);
		//}
		//else if (s_enemy[0].Turnflg == 0)
		//{
		//	DrawGraph(s_enemy[0].enemyX + Stage3::Stage3X - 30, s_enemy[0].enemyY - 30, E_Img, TRUE);
		//}

		//DrawBox(ex + /*moveX +*/ Stage3::Stage3X, ey, ex2 + /*moveX +*/ Stage3::Stage3X, ey2, GetColor(0, 255, 0), FALSE);
		//DrawCircle(s_enemy[0].enemyX + Stage3::Stage3X, s_enemy[0].enemyY, Range, GetColor(0, 255, 0), FALSE);

		//if (s_enemy[1].Turnflg == 1)
		//{
		//	DrawTurnGraph(s_enemy[1].enemyX + Stage3::Stage3X - 30, s_enemy[1].enemyY - 30, E_Img, TRUE);
		//}
		//else if (s_enemy[1].Turnflg == 0)
		//{
		//	DrawGraph(s_enemy[1].enemyX + Stage3::Stage3X - 30, s_enemy[1].enemyY - 30, E_Img, TRUE);
		//}

		//DrawBox(ex + /*moveX +*/ Stage3::Stage3X, ey, ex2 + /*moveX +*/ Stage3::Stage3X, ey2, GetColor(0, 255, 0), FALSE);
		//DrawCircle(s_enemy[1].enemyX + Stage3::Stage3X, s_enemy[1].enemyY, Range, GetColor(0, 255, 0), FALSE);

		//if (s_enemy[2].Turnflg == 1)
		//{
		//	DrawTurnGraph(s_enemy[2].enemyX + Stage3::Stage3X - 30, s_enemy[2].enemyY - 30, E_Img, TRUE);
		//}
		//else if (s_enemy[2].Turnflg == 0)
		//{
		//	DrawGraph(s_enemy[2].enemyX + Stage3::Stage3X - 30, s_enemy[0].enemyY - 30, E_Img, TRUE);
		//}

		//DrawBox(ex + /*moveX +*/ Stage3::Stage3X, ey, ex2 + /*moveX +*/ Stage3::Stage3X, ey2, GetColor(0, 255, 0), FALSE);
		//DrawCircle(s_enemy[2].enemyX + Stage3::Stage3X, s_enemy[2].enemyY, Range, GetColor(0, 255, 0), FALSE);

		break;
	}
}



void Enemy::Enemyhit()
{
	float a[3], b[3], c[3];
	switch (GameMain::NowStage)
	{
	case 1:
	case 4:
		 a[0] = player->GetLocationCenterX() - s_enemy[0].enemyX - Stage1::Stage1X;
		 b[0] = player->GetLocationCenterY() - s_enemy[0].enemyY;
		 if (Player::Life >= 0)
		 {

			 c[0] = a[0] * a[0] + b[0] * b[0];
			 float Hitrange = (player->Range + Range) * (player->Range * Range) / 4;
			 if (c[0] <= Hitrange)
			 {

				 Hitflg = TRUE;
				 Player::Life -= 1;
				 Player::Death += 1;
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
		break;
	case 2:
	case 5:
		for (int i = 0; i < 2; i++)
		{
			a[i] = player->GetLocationCenterX() - s_enemy[i].enemyX - Stage2::Stage2X;
			b[i] = player->GetLocationCenterY() - s_enemy[i].enemyY;
		}

		if (Player::Life >= 0)
		{
			for (int i = 0; i < 2; i++)
			{
				c[i] = a[i] * a[i] + b[i] * b[i];
				float Hitrange = (player->Range + Range) * (player->Range * Range) / 4;
				if (c[i] <= Hitrange)
				{

					Hitflg = TRUE;
					Player::Life -= 1;
					Player::Death += 1;
					Player::playerX = 220;
					Player::playerY = 430;
					Stage1::Stage1X = 0;
					Stage2::Stage2X = 0;
					Stage3::Stage3X = 0;
					Hitflg = FALSE;
					break;
				}
				else
				{
					Hitflg = FALSE;
				}
			}
		}

		 break;
	case 3:
	case 6:
		for (int i = 0; i < 3; i++)
		{
			a[i] = player->GetLocationCenterX() - s_enemy[i].enemyX - Stage3::Stage3X;
			b[i] = player->GetLocationCenterY() - s_enemy[i].enemyY;
		}
		for (int i = 0; i < 3; i++)
		{
			c[i] = a[i] * a[i] + b[i] * b[i];
			float Hitrange = (player->Range + Range) * (player->Range * Range) / 4;
			if (c[i] <= Hitrange)
			{

				Hitflg = TRUE;
				Player::Life -= 1;
				Player::Death += 1;
				Player::playerX = 220;
				Player::playerY = 430;
				Stage1::Stage1X = 0;
				Stage2::Stage2X = 0;
				Stage3::Stage3X = 0;
				Hitflg = FALSE;
				break;
			}
			else
			{
				Hitflg = FALSE;
			}
		}
		 break;
	/* ゲームオーバーかゲームクリアに入った時 */
	case 7:
	case 8:
		for (int i = 0; i < 3; i++)
		{
			a[i] = 0; // 例外スロー対策
			b[i] = 0; // 例外スロー対策
		}
		break;
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
	

	

	
