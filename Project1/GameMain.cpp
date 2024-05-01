#include "GameMain.h"
#include<math.h>

GameMain::GameMain()
{
	player = new Player();
	stage1 = new Stage1();
}

GameMain::~GameMain()
{
}

AbstractScene* GameMain::Update()
{
	GetMousePoint(&mouseX, &mouseY);
	player->Update();
	stage1->Update();
	
	return this;
}

void GameMain::Draw() const
{

	stage1->Draw();
	player->Draw();
	DrawFormatString(500, 0, GetColor(0, 0, 0), "mouseX:%d  mouseY:%d", mouseX, mouseY);
}

bool GameMain::IsHitCheck(Player* p, Block* b)
{
	if (b == nullptr) {
		return false;
	}

	//位置情報の差分を取得
	Vector2D diff_location = p->Getlocation() - b->GetLocation();

	//当たり判定サイズの大きさを取得
	Vector2D box_ex = p->GetBoxsize();
	return((fabsf(diff_location.x) < box_ex.x) && (fabsf(diff_location.y) < box_ex.y));
}
