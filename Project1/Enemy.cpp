#include "Enemy.h"
#include"DxLib.h"
#include"Stage1.h"
#include"Stage2.h"
#include"Stage3.h"
#include"GameMain.h"
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
	EnemyControl();
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
	switch (GameMain::NowStage)
	{
	case 1:
		DrawBox(ex + moveX + Stage1::Stage1X, ey, ex2 + moveX + Stage1::Stage1X, ey2, GetColor(0, 255, 0), TRUE);
		break;
	case 2:
		DrawBox(ex + moveX + Stage2::Stage2X, ey, ex2 + moveX + Stage1::Stage1X, ey2, GetColor(0, 255, 0), TRUE);
		break;
	case 3:
		DrawBox(ex + moveX + Stage3::Stage3X, ey, ex2 + moveX + Stage1::Stage1X, ey2, GetColor(0, 255, 0), TRUE);
		break;
	}
	
	
	if (Hitflg == TRUE)
	{
		DrawFormatString(200, 250, GetColor(0, 0, 255), "Hit!!", Hitflg);
	}
}

void Enemy::EnemyControl()
{
	if (Enemyhit() == TRUE)
	{
		Hitflg = TRUE;
	}
}

int Enemy::Enemyhit()
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

	//// プレイヤー右と敵左を比べる　&&　プレイヤーの下と敵の上を比べる  ||  プレイヤーの左と敵の右を比べる　&&　プレイヤーの上と敵の下を比べる
	//if (player->GetLocationX2() >= GetLocationX() && player->GetLocationY2() >= GetLocationY() || 
	//	player->GetLocationX1() <= GetLocationX2() && player->GetLocationY1() <= GetLocationY2())
	//{
	//	Hitflg = TRUE;
	//}
	//else
	//{
	//	Hitflg = FALSE;
	//}



	/*if (((player->GetLocationX1() >= ex && player->GetLocationX1() <= ex + ex2) ||
		(ex > player->GetLocationX1() && ex < player->GetLocationX1() + player->GetLocationX2()) &&
		((player->GetLocationY1() > ey && player->GetLocationY1() < ey + ey2) ||
			(ey > player->GetLocationY1() && ey < player->GetLocationY1() + player->GetLocationY2()))))
	{
		Hitflg = TRUE;
	}
	else
	{
		Hitflg = FALSE;
	}*/





	if (player->GetLocationX2() >= GetLocationX() + 15 && player->GetLocationX1() >= GetLocationX2()) {
		Hitflg = TRUE;
		if (player->GetLocationY1() <= GetLocationY() + 10 && GetLocationY() <= player->GetLocationY1()) {
			//当たった処理
			Hitflg = TRUE;
		}
	}
	else
	{
		Hitflg = FALSE;
	}
	

	

	//if (player->GetLocationX1() >= ex2 + 15 || player->GetLocationX2() >= ex - 15)
	//{
	//	Hitflg = TRUE;
	//}
	//if (player->GetLocationY1() >= ey/*&&player->GetLocationX1()>=ex -15*/)
	//{
	//	Hitflg = TRUE;
	//}

	return 0;

} 
