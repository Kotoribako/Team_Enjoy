#include "Enemy.h"
#include"DxLib.h"
#include"Stage1.h"
#include"Player.h"
#define IMAGE_SIZE 50 // 画像一枚の大きさ
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
	enemyX = 580;
	enemyY = 420;
	moveX = 0;
	direction = 0;
	speed = 30;
	Hitflg = FALSE;
}

void Enemy::Update()
{
	ex = enemyX - 25;
	ex2 = enemyX + 20;
	ey = enemyY ;
	ey2 = enemyY - 35;

	Enemyhit();

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
	DrawFormatString(200, 200, GetColor(0, 0, 255), "countup:%d", countup);
	
		DrawBox(ex + moveX + Stage1::Stage1X, ey, ex2 + moveX + Stage1::Stage1X, ey2, GetColor(0, 255, 0), TRUE);
	
	if (Hitflg == TRUE)
	{
		DrawFormatString(200, 250, GetColor(0, 0, 255), "Hit!!", Hitflg);
	}
}

void Enemy::Enemyhit()
{

	// プレイヤー画像と敵画像で当たり判定
	if (Player::playerX + IMAGE_SIZE >= ex && Player::playerX <= ex + IMAGE_SIZE) 
	{
		if (Player::playerY + IMAGE_SIZE >= ey && Player::playerY <= ey + IMAGE_SIZE)
		{
			Hitflg = TRUE;
		}
	}

	Hitflg = FALSE;

} 
