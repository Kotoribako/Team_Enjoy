#include "Enemy.h"
#include"DxLib.h"
#include"Stage1.h"

float Enemy::enemyX;
float Enemy::enemyX2;
float Enemy::enemyY;
float Enemy::enemyY2;

Enemy::Enemy()
{
	img = 0; //仮
	count = 0;
	block = new Block();

	enemyX = 200;
	enemyY = 200;

}

void Enemy::Update()
{

	ex = enemyX - 15;
	ex2 = enemyY + 15;
	ey = enemyX - 15;
	ey2 = enemyY + 15;

	count++;
	if (count == 60) 
	{
		count = 0;
	}


}

void Enemy::Draw()
{
	DrawFormatString(200, 200, GetColor(0, 0, 255),"count:%d",count);

}

void Enemy::Enemyhit()
{
 
} 
