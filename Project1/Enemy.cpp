#include "Enemy.h"
#include"DxLib.h"
#include"Stage1.h"
#include"Stage2.h"
#include"Stage3.h"
#include"GameMain.h"
float Enemy::ex;
float Enemy::ex2;
float Enemy::ey;
float Enemy::ey2;
int   Enemy::Range;

Enemy::Enemy()
{
	img = 0; //仮
	count = 0;
	block = new Block();
	player = new Player();
	countup = 0;
	enemyX = block->S1bloc[4].X2 - 15;
	enemyY = block->S1bloc[4].Y - 15;
	moveX = 0;
	direction = 0;
	speed = 30;
	Hitflg = FALSE;
	Range = 15;

}

void Enemy::Update()
{
	enemyX2 = enemyX + 30;
	enemyY2 = enemyY + 30;

	ex = enemyX - 15;
	ex2 = enemyX + 15;
	ey = enemyY - 15;
	ey2 = enemyY + 15;



	Enemyhit();
	count++;
	if (count == 60)
	{
		countup += 1;
		
		if (direction == 0)
		{
			enemyX += speed;

		}
		else if (direction == 1)
		{
			enemyX -= speed;
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

}

void Enemy::Draw()
{
	DrawFormatString(200, 200, GetColor(0, 0, 255), "ex:%f ex2:%f ey:%f ey2:%f", ex,ex2,ey,ey2);
	//DrawFormatString(200, 200, GetColor(0, 0, 255), "countup:%d", countup);
	switch (GameMain::NowStage)
	{
	case 1:
		DrawBox(ex + /*moveX +*/ Stage1::Stage1X, ey, ex2 + /*moveX +*/ Stage1::Stage1X, ey2, GetColor(0, 255, 0), FALSE);
		DrawCircle(enemyX + Stage1::Stage1X, enemyY, Range, GetColor(0, 255, 0), TRUE);
		break;
	case 2:
		DrawBox(ex + /*moveX +*/ Stage2::Stage2X, ey, ex2 +/* moveX +*/ Stage2::Stage2X, ey2, GetColor(0, 255, 0), FALSE);
		DrawCircle(enemyX + Stage2::Stage2X, enemyY, Range, GetColor(0, 255, 0), TRUE);
		break;
	case 3:
		DrawBox(ex + /*moveX +*/ Stage3::Stage3X, ey, ex2 + /*moveX +*/ Stage3::Stage3X, ey2, GetColor(0, 255, 0), FALSE);
		DrawCircle(enemyX + Stage3::Stage3X, enemyY, Range, GetColor(0, 255, 0), TRUE);
		break;
	}
	
	
	//if (Hitflg == TRUE)
	//{
	//	DrawFormatString(200, 250, GetColor(0, 0, 255), "Hit!!");
	//}
}



void Enemy::Enemyhit()
{
	int x = player->playerX - enemyX;
	int y = player->playerY - enemyY;
	int Hitrange = player->Range + Range;
	if(x*x+y*y < Hitrange*Hitrange)
	{

			Hitflg = TRUE;
			Player::Life -= 1;
			Player::playerX = 220;
			Player::playerY = 430;
	}
	else {
		Hitflg = FALSE;

	
	}
}

void Enemy::Init()
{
	img = 0; //仮
	count = 0;
	block = new Block();
	player = new Player();
	countup = 0;
	switch (GameMain::NowStage)
	{
	case 1:
		enemyX = block->S1bloc[4].X2 - 15;
		enemyY = block->S1bloc[4].Y - 15;
		break;
	case 2:
		break;
	case 3:
		break;
	}
	
	moveX = 0;
	direction = 0;
	speed = 30;
	Hitflg = FALSE;
	Range = 15;
}

	

	

	
