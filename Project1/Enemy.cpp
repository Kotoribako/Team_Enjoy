#include "Enemy.h"

Enemy::Enemy()
{
	img = 0; //仮
}

void Enemy::Update()
{
	count++;
	if (count == 60) 
	{
		count = 0;
	}
}

void Enemy::Draw()
{

}

void Enemy::Enemyhit()
{

}
