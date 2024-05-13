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
	ClearImg = LoadGraph("image/noname.png");
	BackImg = LoadGraph("image/BackGround02.png");
}

Clear::~Clear()
{

}

AbstractScene* Clear::Update()
{
	return this;
}

void Clear::Draw() const
{

	//タイトル画像表示
	DrawGraph(0, 0, BackImg, TRUE);
	//タイトル画像表示
	DrawGraph(0, 100, ClearImg, TRUE);
}
