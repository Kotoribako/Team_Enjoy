#include "Enemy.h"
#include"DxLib.h"
#include"Stage1.h"
Enemy::Enemy()
{
	img = 0; //仮
	count = 0;
	
}

void Enemy::Update()
{


	count++;
	if (count == 60) 
	{
		count = 0;
	}

	block = new Block();

}

void Enemy::Draw()
{
	DrawFormatString(200, 200, GetColor(0, 0, 255),"%d",count);

}

void Enemy::Enemyhit()
{
} 
