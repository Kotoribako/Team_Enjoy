#include "GameMain.h"
#include"GenreSelect.h"

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
	stage1->Update();
	for (int i = 0; i < 4; i++) {
		if (Player::playerX >= stage1->door[i].X - 30 && Player::playerX <= stage1->door[i].X + 30 && Player::playerY >= 550 && Player::playerY <= 605)
		{
			if (PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_UP))
			{
				switch (stage1->door[i].answer)
				{
				case 0:
					return new GameMain();
					break;
				case 1:
					return new GenreSelect();
					break;
				default:
					break;
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

