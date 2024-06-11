#include "Enemy.h"
#include"DxLib.h"
#include"Stage1.h"
#include"Stage2.h"
#include"Stage3.h"
#include"GameMain.h"
#include"GameOver.h"
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
	enemyX = 580;
	enemyY = 406;
	moveX = 0;
	direction = 0;
	speed = 30;
	Hitflg = FALSE;
	Range = 15;
	OverFlg = 0; // ゲームオーバー用フラグ
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

	if (OverFlg == 1)
	{
		
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
	
	
	if (Hitflg == TRUE)
	{
		DrawFormatString(200, 250, GetColor(0, 0, 255), "Hit!!");
	}
}



void Enemy::Enemyhit()
{
	//if (player->GetLocationX2() >= GetLocationX() + 15 && player->GetLocationX1() >= GetLocationX2()) {
	//	Hitflg = TRUE;
	//	if (player->GetLocationY1() <= GetLocationY() + 10 && GetLocationY() <= player->GetLocationY1()) {
	//		//当たった処理
	//		Hitflg = TRUE;
	//	}
	//}
	//else
	//{
	//	Hitflg = FALSE;
	//}

	//// プレイヤー画像と敵画像で当たり判定
	//if (player->GetLocationX1() + player->GetLocationX2() >= ex && player->GetLocationX1() <= player->GetLocationX1() + player->GetLocationX2())
	//{
	//	if (player->GetLocationY1() + player->GetLocationY2() >= ey && player->GetLocationY1() <= ey + ey2)
	//	{
	//		Hitflg = TRUE; 
	//	
	//	}
	//}

	

	int x = player->playerX - enemyX;
	int y = player->playerY - enemyY;
	int Hitrange = player->Range + Range;

	if(x * x + y * y < Hitrange * Hitrange)
	{

		/*if ((player->GetLocationY1() <= ey  && ey2 <= player->GetLocationY2())) {*/
			Hitflg = TRUE;
			Player::Life -= 1;
			Player::playerX = 220;
			Player::playerY = 430;
			//}
	}
	else {
		Hitflg = FALSE;

	
	}
	if (Player::Life <= 0)
	{
		// ゲームオーバーに遷移する
		OverFlg = 1;
	}
}

	

	

	
