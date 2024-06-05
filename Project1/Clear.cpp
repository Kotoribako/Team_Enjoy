#include "Clear.h"
#include <DxLib.h>
#include "Title.h"
#include "PadInput.h"
#include<iostream>
#include"GameMain.h"
#include"GenreSelect.h"

Clear::Clear()
{
	//タイトル画像読み込み
	BackImg = LoadGraph("image/BackGround02.png");
	ClearImg = LoadGraph("image/Clear_Img.png");
	ModoruImg = LoadGraph("image/modoru.png");

	S_FPS = 0;
	S_Seconas = FALSE;

}

Clear::~Clear()
{

}

AbstractScene* Clear::Update()
{
	S_FPS++;
	S_FPS1++;

	//FPS
	if (S_FPS > 30) {
		S_FPS = 0;
		S_Seconas++;
	}// P_FPS_INC
	/*else if (S_Seconas1 < 3) {
		S_Seconas1 = TRUE;
	}*/
	if (S_FPS1 > 60) {
		S_FPS1 = 0;
		S_Seconas1++;
	}// P_FPS_INC
	else if (S_Seconas1 < 3) {
		S_Seconas1 = 0;
	}


	return this;
}

void Clear::Draw() const
{

	//タイトル画像表示
	DrawGraph(0, 0, BackImg, TRUE);

	//画像表示
	if (S_Seconas >= 3) {
	DrawGraph(0, 0, ClearImg, TRUE);
	}

	if (S_Seconas1 >= 3) {
		DrawGraph(0, 230, ModoruImg, TRUE);
	}
}
