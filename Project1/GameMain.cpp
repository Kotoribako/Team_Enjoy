#include "GameMain.h"
#include"GenreSelect.h"
#include"Title.h"
int GameMain::NowStage;

GameMain::GameMain()
{
	player = new Player();
	stage1 = new Stage1();
	enemy = new Enemy();
}

GameMain::~GameMain()
{
}

void GameMain::Initialize()
{
	player = new Player();
	stage1 = new Stage1();
	enemy = new Enemy();

}

AbstractScene* GameMain::Update()
{
	GetMousePoint(&mouseX, &mouseY);
	player->Update();
	enemy->Update();
	switch (NowStage) {
	case 1:
		stage1->Update();
		break;
	case 2:
		/* Stage2の処理 */
		return new Title();
		break;
	case 3:
		/* Stage3の処理 */
		break;
	case 4:
		stage1->Update();
		break;
	default:
		return 0;
	}

	return this;
}

void GameMain::Draw() const
{

	stage1->Draw();
	player->Draw();
	enemy->Draw();
	DrawFormatString(500, 0, GetColor(0, 0, 0), "mouseX:%d  mouseY:%d", mouseX, mouseY);
	DrawFormatString(1000, 0, GetColor(0, 0, 0), "NowStage:%d", NowStage);

}

