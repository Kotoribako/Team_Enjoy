#include "GenreSelect.h"
#include<stdlib.h>
#include<time.h>
#include <DxLib.h>
#include"PadInput.h"
GenreSelect::GenreSelect()
{
	r = 0;
	max = 6;
	min = 1;
	result = 0;
	Select = 0;

	Genre1 = 0;

	AnimeGame1 = LoadGraph("image/Anime&Game/AnimeGame1.png", TRUE);
	AnimeGame2 = LoadGraph("image/Anime&Game/AnimeGame2.png", TRUE);
	AnimeGame3 = LoadGraph("image/Anime&Game/AnimeGame3.png", TRUE);

	CauserX = 500;
	CauserY = 200;

}


AbstractScene* GenreSelect::Update()
{
	Greflection();
	srand((unsigned)time(NULL)); // 乱数の仕組みの初期化

	r = (rand() % (max - min + 1)) + min; // 1～６までの数字をランダムで変数に格納する
	result = r; 

	int x = 0;
	// 下キー押すか、左スティックを下に倒す
	if (CheckHitKey(KEY_INPUT_DOWN) || PAD_INPUT::GetLStick().ThumbY)
	{
		if (Select <= 6) {
			Select += 1;
		}
	}
	// 上キー押すか、左スティックを上に倒す
	else if (CheckHitKey(KEY_INPUT_UP) || PAD_INPUT::GetLStick().ThumbY)
	{
		if (Select >= 1) {
			Select -= 1;
		}
	}

	// 決定した時
	if (CheckHitKey(KEY_INPUT_3))
	{
		Genre1 = 1;//Select;
	}
	return this;
}

void GenreSelect::Draw() const
{

	


	// ランダムで出した値に応じて、いくつかのパターンに派生する
	if (result == 1) {
		DrawFormatString(200, 200, GetColor(255, 255, 255), "1", result);
	}
	else if (result == 2) {
		DrawFormatString(200, 200, GetColor(255, 255, 255), "2", result);

	}
	else if (result == 3) {
		DrawFormatString(200, 200, GetColor(255, 255, 255), "3", result);

	}
	else if (result == 4) {
		DrawFormatString(200, 200, GetColor(255, 255, 255), "4", result);

	}
	else if (result == 5) {
		DrawFormatString(200, 200, GetColor(255, 255, 255), "5", result);

	}
	else if (result == 6) {
		DrawFormatString(200, 200, GetColor(255, 255, 255), "6", result);

	}

	if (Quiz1[0] == 1) {
		DrawGraph(500, 500, Quiz1[0], TRUE);
	}
	if (Quiz1[1] == 1) {
		DrawGraph(500, 0, Quiz1[1], TRUE);

	}
	if (Quiz1[2] == 1) {
		DrawGraph(0, 500, Quiz1[1], TRUE);

	}
	//DrawGraph(500, 0, AnimeGame1, TRUE);
	//DrawGraph(0, 500, AnimeGame2, TRUE);
	//DrawGraph(500, 500, AnimeGame3, TRUE);
}


void GenreSelect::Greflection()
{
	// gSelectで変数に入れた値を持ちいて、いくつかあるパターンにを派生させる処理
	if (Genre1 == 1)
	{
		for (int i = 0; i < 2; i++) {
			Quiz1[i] = 1;
		}
	}
	else if (Genre1 == 2)
	{
		for (int i = 0; i < 2; i++) {
			Quiz2[i] = 1;
		}
	}
	else if (Genre1 == 3)
	{
		for (int i = 0; i < 2; i++) {
			Quiz3[i] = 1;
		}
	}
	else if (Genre1 == 4)
	{
		for (int i = 0; i < 2; i++) {
			Quiz4[i] = 1;
		}
	}
	else if (Genre1 == 5) 
	{
		for (int i = 0; i < 2; i++) {
			Quiz5[i] = 1;
		}
	}
	else if (Genre1 == 6)
	{
		for (int i = 0; i < 2; i++) {
			Quiz6[i] = 1;
		}
	}

}
