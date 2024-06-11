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
	count = 0;
	block = new Block();
	player = new Player();
	countup = 0;
	enemyX = 580;
	enemyY = 406;
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
		DrawGraph(enemyX + Stage1::Stage1X -30, enemyY - 30,img[0], TRUE);
		DrawBox(ex + /*moveX +*/ Stage1::Stage1X, ey, ex2 + /*moveX +*/ Stage1::Stage1X, ey2, GetColor(0, 255, 0), FALSE);
		DrawCircle(enemyX + Stage1::Stage1X, enemyY, Range, GetColor(0, 255, 0), FALSE);
		break;
	case 2:
		DrawBox(ex + /*moveX +*/ Stage2::Stage2X, ey, ex2 +/* moveX +*/ Stage2::Stage2X, ey2, GetColor(0, 255, 0), FALSE);
		DrawCircle(enemyX + Stage2::Stage2X, enemyY, Range, GetColor(0, 255, 0), FALSE);
		break;
	case 3:
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
	float a = player->GetLocationCenterX() - enemyX - Stage1::Stage1X;
	float b = player->GetLocationCenterY() - enemyY;
	float c = a*a + b*b;
	float Hitrange = (player->Range + Range) * (player->Range * Range)/4;
	if( c <= Hitrange)
	{

			Hitflg = TRUE;
			Player::Life -= 1;
			Player::playerX = 220;
			Player::playerY = 430;
	}
	else
	{
		Hitflg = FALSE;
	}
}

	

	

	
