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
	ClearImg = LoadGraph("image/Clear_Img.png");
	BackImg = LoadGraph("image/BackGround02.png");

	S_FPS = 0;
	S_Seconas = FALSE;

}

Clear::~Clear()
{

}

AbstractScene* Clear::Update()
{
	S_FPS++;

	//FPS
	if (S_FPS > 30) {
		S_FPS = 0;
		S_Seconas++;
	}// P_FPS_INC
	else if (S_Seconas > 3) {
		S_Seconas = TRUE;
	}


	return this;
}

void Clear::Draw() const
{

	//タイトル画像表示
	DrawGraph(0, 0, BackImg, TRUE);

	//タイトル画像表示
	if (S_Seconas == TRUE) {
	DrawGraph(0, 0, ClearImg, TRUE);
	}
}
