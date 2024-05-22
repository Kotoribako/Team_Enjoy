#include "Enemy.h"
#include"DxLib.h"
#include"Stage1.h"
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
	player = new Player();
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

	enemyX2 = enemyX + 30;
	enemyY2 = enemyY + 30;

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
	//// プレイヤー画像と敵画像で当たり判定
	//if (Player::playerX >= GetLocationX() && Player::playerX >= GetLocationX() + GetLocationX2())
	//{
	//	if (Player::playerY >= GetLocationY() && Player::playerY >= GetLocationY()+ GetLocationY2())
	//	{
	//		Hitflg = TRUE;
	//	}
	//}
	//// プレイヤーの左 <= 敵の右 && 敵の左 <= プレイヤーの右&&
	//if (player->GetLocationX1() <= ex2 && ex <= player->GetLocationX2() 
	//	&&
	//	// プレイヤーの上 <= 敵の下 && 敵の上 <= プレイヤーの下
	//	player->GetLocationY1() <= ey2 && ey <= player->GetLocationY2())
	//{
	//	Hitflg = TRUE;
	//}
	//else
	//{
	//	Hitflg = FALSE;
	//}

	// プレイヤーの右 ＋ プレイヤーの下(右下)　&&　敵の左　＋　敵の上(左上)
	if (player->GetLocationX2() + player->GetLocationY2() && ex + ey ||
		// プレイヤーの左　＋　プレイヤーの上(左上)　&&　敵の右　＋　敵の下(右下)
		player->GetLocationX1() + player->GetLocationY1() && ex2 + ey2)
	{
		Hitflg = TRUE;
	}
	else
	{
		Hitflg = FALSE;
	}


	//if (Player::playerX  <= GetLocationX() + 100 && GetLocationX() <= Player::playerX + 20) {
	//	if (Player::playerY <= GetLocationY() + 10 && GetLocationY() <= Player::playerY + 20) {
	//		//当たった処理
	//		Hitflg = TRUE;
	//	}
	//}
	//else
	//{
	//	Hitflg = FALSE;
	//}



} 
