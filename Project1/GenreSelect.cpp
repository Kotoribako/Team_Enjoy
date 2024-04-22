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

	Genre1 = 1;

	AnimeGame1 = LoadGraph("image/Anime&Game/AnimeGame1.png", TRUE);
	AnimeGame2 = LoadGraph("image/Anime&Game/AnimeGame2.png", TRUE);
	AnimeGame3 = LoadGraph("image/Anime&Game/AnimeGame3.png", TRUE);

	Causer = LoadGraph("image/Causer.png", TRUE);
	CauserX = 200;
	CauserY = 200;
	for (int i = 0; i < 3; i++) {
		Quiz1[i] = 0;
		Quiz2[i] = 0;
		Quiz3[i] = 0;
		Quiz4[i] = 0;
		Quiz5[i] = 0;
		Quiz6[i] = 0;
	}
}


AbstractScene* GenreSelect::Update()
{
	greflection();
	srand((unsigned)time(NULL)); // 乱数の仕組みの初期化

	r = (rand() % (max - min + 1)) + min; // 1～６までの数字をランダムで変数に格納する
	result = r; 

	

	
	int x = 0;
	// 上キー押すか、左スティックを上に倒す
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_UP))
	{
		if (Genre1 > 1) {
			Genre1 -= 1;
			CauserY = 200 + Genre1 * 50;
		}

	}
	// 下キー押すか、左スティックを下に倒す
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_DOWN))
	{
		if(Genre1 <= 5){
			Genre1 += 1;
			CauserY = 200 + Genre1 * 50;
		}
		
	}
	

	///* カーソルが６より下に言ったら */
	//if (Genre1 == 6 && PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_DOWN)) {
	//	// カーソルを動かないようにする（6番を代入させる）
	//	Genre1 = 6;
	//}
	

	return this;
}

void GenreSelect::Draw() const
{

	DrawGraph(CauserX, CauserY, Causer, TRUE);

	DrawFormatString(100, 100, GetColor(255, 255, 255), "CauserX:%d\n",CauserX);
	DrawFormatString(200, 100, GetColor(255, 255, 255), "CauserY:%d\n",CauserY);


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


void GenreSelect::greflection()
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
