#include "GameMain.h"
#include"GenreSelect.h"
#include"Title.h"
#include "Clear.h"
#include "GameOver.h"
int GameMain::NowStage;

GameMain::GameMain()
{
	NowStage = 1;
	player = new Player();
	stage1 = new Stage1();
	stage2 = new Stage2();
	stage3 = new Stage3();
	enemy = new Enemy();
}

GameMain::~GameMain()
{

}

void GameMain::Initialize()
{
	switch (NowStage) {
	case 1:
	case 4:
		stage1 = new Stage1();
		//player = new Player();
		break;
	case 2:
	case 5:
		stage2 = new Stage2();
		//player = new Player();
		break;
	case 3:
	case 6:
		stage3 = new Stage3();
		//player = new Player();
		break;
	}
	enemy = new Enemy();
	player = new Player();
}

AbstractScene* GameMain::Update()
{
	GetMousePoint(&mouseX, &mouseY);
	//player->Update();
	//enemy->Update();
	switch (NowStage) {
	case 1:
	case 4:
		NowStage = 1;
		stage1->Update();
		if (Stage1::S1DecisionToAnswerFlg == TRUE)
		{
			Initialize();
		}
		break;
	case 2:
	case 5:
		/* Stage2の処理 */
		NowStage = 2;
		stage2->Update();
		if (Stage2::S2DecisionToAnswerFlg == TRUE)
		{
			Initialize();
		}
		break;
	case 3:
	case 6:
		/* Stage3の処理 */
		NowStage = 3;
		stage3->Update();
		if (Stage3::S3DecisionToAnswerFlg == TRUE)
		{
			Initialize();
		}
		break;
	case 7:
		return new Clear();
		break;
	case 8:
		/* BGM消す用の処理↓ */
		delete stage1;
		delete stage2;
		delete stage3;
		/* BGM消す用の処理↑ */
		return new GameOver();
		break;

	default:
		return 0;
	}
	player->Update();
	enemy->Update();

	return this;
}

void GameMain::Draw() const
{
	switch (NowStage) {
	case 1:
	case 4:
		stage1->Draw();
		break;
	case 2:
	case 5:
		/* Stage2の処理 */
		stage2->Draw();
		break;
	case 3:
	case 6:
		/* Stage3の処理 */
		stage3->Draw();
		break;
	}
	player->Draw();
	enemy->Draw();
	////DrawFormatString(500, 0, GetColor(0, 0, 0), "mouseX:%d  mouseY:%d", mouseX, mouseY);
	SetFontSize(32);
	DrawFormatString(1150, 0, GetColor(0, 255, 255), "Stage%d", NowStage);

}

