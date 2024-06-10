#include "GameOver.h"
#include <DxLib.h>
#include "Title.h"
#include "PadInput.h"
#include<iostream>
#include"GameMain.h"
#include"GenreSelect.h"

GameOver::GameOver()
{
	//タイトル画像読み込み
	BackImg = LoadGraph("image/BackGround02.png");
	GameOverImg = LoadGraph("image/GameOver.png");
	ModoruImg = LoadGraph("image/GameOver_Modoru.png");

	S_FPS = 0;
	S_FPS1 = 0;
	S_Seconas = 0;
	S_Seconas1 = 0;
}

GameOver::~GameOver()
{

}

AbstractScene* GameOver::Update()
{
	S_FPS++;
	S_FPS1++;

	//FPS
	if (S_FPS > 30) {
		S_FPS = 0;
		S_Seconas++;
	}
	//FPS1
	if (S_FPS1 > 30) {
		S_FPS1 = 0;
		S_Seconas1++;
	}
	else if (S_Seconas1 >= 5) {
		S_Seconas1 = 0;
	}

	if (PAD_INPUT::OnButton(XINPUT_BUTTON_A))
	{
		return new Title();
	}
	else if (PAD_INPUT::OnButton(XINPUT_BUTTON_B)) {
		return new GenreSelect();
	}

	return this;
}

void GameOver::Draw() const
{
	//タイトル画像表示
	DrawGraph(0, 0, BackImg, TRUE);

	/*SetFontSize(20);
	DrawFormatString(0, 30, 0x000000, "S_FPS1 : %d", Clear::S_FPS);
	DrawFormatString(0, 50, 0x000000, "S_Seconas1 : %d", Clear::S_Seconas1);*/

	//画像表示
	if (S_Seconas >= 3) {
		DrawGraph(0, 0, GameOverImg, TRUE);
	}
	//画像表示
	if (S_Seconas1 >= 3) {
		DrawGraph(0, 230, ModoruImg, TRUE);
	}
}
