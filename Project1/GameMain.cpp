#include "GameMain.h"
#include"GenreSelect.h"
#include"Title.h"
int GameMain::NowStage;

GameMain::GameMain()
{
	player = new Player();
	stage1 = new Stage1();
}

GameMain::~GameMain()
{
}

void GameMain::Initialize()
{
	player = new Player();
	stage1 = new Stage1();

}

AbstractScene* GameMain::Update()
{
	GetMousePoint(&mouseX, &mouseY);
	player->Update();
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
	default:
		return 0;
	}

			}
		}
	}
	return this;
}

void GameMain::Draw() const
{

	stage1->Draw();
	player->Draw();
	DrawFormatString(500, 0, GetColor(0, 0, 0), "mouseX:%d  mouseY:%d", mouseX, mouseY);
}

