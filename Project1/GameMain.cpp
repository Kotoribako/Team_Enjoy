#include "GameMain.h"

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
