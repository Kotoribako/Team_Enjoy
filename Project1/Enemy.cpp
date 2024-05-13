#include "Enemy.h"
#include"DxLib.h"
#include"Stage1.h"
#include"Player.h"
float Enemy::enemyX;
float Enemy::enemyX2;
float Enemy::enemyY;
float Enemy::enemyY2;

Enemy::Enemy()
{
	img = 0; //仮
	count = 0;
	block = new Block();
	countup = 0;
	enemyX = 600;
	enemyY = 350;
	moveX = 0;
	direction = 0;
	speed = 20;
	Hitflg = FALSE;
}

void Enemy::Update()
{

	ex = enemyX - 165;
	ex2 = enemyY + 15;
	ey = enemyX - 165;
	ey2 = enemyY + 15;

	

	count++;
	if (count == 60) 
	{	
		countup += 1;
		if (direction == 0) 
		{
			moveX += speed;

		}
		else if (direction == 1) 
		{
			moveX -= speed;
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
	DrawFormatString(200, 200, GetColor(0, 0, 255),"countup:%d",countup);
	DrawBox(ex + moveX, ey, ex2 + moveX, ey2, GetColor(0, 255, 0), TRUE);
	if (Hitflg == TRUE) 
	{
		DrawFormatString(200, 250, GetColor(0, 0, 255), "Hit!!", Hitflg);

	}
}

void Enemy::Enemyhit()
{
	if (ex >= Player::playerX || ex2 >= Player::playerX2 || ey >= Player::playerY || ey2 >= Player::playerY2)
	{
		Hitflg = TRUE;
    }
} 
