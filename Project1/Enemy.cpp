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

Enemy::Enemy()
{
	img = 0; //仮
	count = 0;
	block = new Block();
	player = new Player();
	countup = 0;
	switch (GameMain::NowStage)
	{
	case 1:
		enemyX = 580;
		enemyY = 400;
		break;
	case 2:
		enemyX = Stage2::Stage2X + 580;
		enemyY = 400;
		break;
	case 3:
		enemyX = Stage3::Stage3X + 580;
		enemyY = 400;
	}
	
	moveX = 0;
	direction = 0;
	speed = 30;
	Hitflg = FALSE;
}

void Enemy::Update()
{
	

	ex = enemyX - 20;
	ex2 = enemyX + 20;
	ey = enemyY - 20;
	ey2 = enemyY + 20;



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

	// 当たり判定の可視化
	DrawBox(ex + moveX + Stage1::Stage1X, ey - 15, ex2 + moveX + Stage1::Stage1X, ey2 - 15, GetColor(255, 0, 0), ex);
	DrawBox(ex - 15 + moveX + Stage1::Stage1X, ey, ex2 - 15 + moveX + Stage1::Stage1X, ey2, GetColor(255, 255, 0), ex);
	DrawBox(ex + moveX + Stage1::Stage1X, ey + 15, ex2 + moveX + Stage1::Stage1X, ey2 + 15, GetColor(0, 0, 255), ex);
	DrawBox(ex + moveX + Stage1::Stage1X, ey, ex2 +15 + moveX + Stage1::Stage1X, ey2 , GetColor(255, 0, 255), ex);
	
	// ステージに応じて、場所を変更する
	switch (GameMain::NowStage)
	{
	case 1:
		DrawBox(ex + moveX + Stage1::Stage1X, ey, ex2 + moveX + Stage1::Stage1X, ey2, GetColor(0, 0, 0), TRUE);
		break;
	case 2:
		DrawBox(ex + moveX + Stage2::Stage2X, ey, ex2 + moveX + Stage1::Stage1X, ey2, GetColor(0, 0, 0), TRUE);
		break;
	case 3:
		DrawBox(ex + moveX + Stage3::Stage3X, ey, ex2 + moveX + Stage1::Stage1X, ey2, GetColor(0, 0, 0), TRUE);
		break;
	}
	
	// 敵にプレイヤーが当たったあとの処理
	if (Hitflg == TRUE )
	{
		DrawFormatString(200, 250, GetColor(0, 0, 255), "Hit!!");

		Player::Life -= 1;

		if (Player::Life <= 0)
		{
			// タイトルかゲームオーバーに戻す
		}
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
	 
	

	// 当たり判定	
	/*if (int(player->GetLocationX1()) >= ex2 && ex >= int(player->GetLocationX2()) && int(player->GetLocationY1()) >= ey2 && ey >= int(player->GetLocationY2()))
	{
		Hitflg = TRUE;
	}
	else {
		Hitflg = FALSE;
	}*/

	if ((player->GetLocationX1() > ex && player->GetLocationX1() < ex + ex2) ||
		(ex > player->GetLocationX1() && ex < player->GetLocationX1() + player->GetLocationX2()) &&
		((player->GetLocationY1() > ey && player->GetLocationY1() < ey + ey2) ||
			(ey > player->GetLocationY1() && ey < player->GetLocationY1() + player->GetLocationY2())))
	{
		Hitflg = TRUE;
	}
}

	

	

	
