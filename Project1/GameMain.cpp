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
	player->Update();
	stage1->Update();
	return this;
}

void GameMain::Draw() const
{
	player->Draw();
	stage1->Draw();
}
