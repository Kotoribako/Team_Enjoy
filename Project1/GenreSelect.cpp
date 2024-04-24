#include "GenreSelect.h"
#include<stdlib.h>
#include<time.h>
#include <DxLib.h>
#include"PadInput.h"
#include"Stage1.h"
#include "GameMain.h"
GenreSelect::GenreSelect()
{
	r = 0;
	max = 6;
	min = 1;
	result = 0;

	Genre1 = 1;

	Enter = FALSE;

	AnimeGame[0] = LoadGraph("image/Quiz/Anime&Game/AnimeGame1.png", TRUE);
	AnimeGame[1] = LoadGraph("image/Quiz/Anime&Game/AnimeGame2.png", TRUE);
	AnimeGame[2] = LoadGraph("image/Quiz/Anime&Game/AnimeGame3.png", TRUE);

	WordExchange[0] = LoadGraph("image/Quiz/WordExchange/WordExchange1.png", TRUE);
	WordExchange[1] = LoadGraph("image/Quiz/WordExchange/WordExchange2.png", TRUE);
	WordExchange[2] = LoadGraph("image/Quiz/WordExchange/WordExchange3.png", TRUE);

	ijin[0] = LoadGraph("image/Quiz/Greatman/ijin1.png", TRUE);
	ijin[1] = LoadGraph("image/Quiz/Greatman/ijin2.png", TRUE);
	ijin[2] = LoadGraph("image/Quiz/Greatman/ijin3.png", TRUE);

	Causer = LoadGraph("image/Causer.png", TRUE);
	CauserX = 200;
	CauserY = 200;
	
	for (int i = 0; i < 2; i++) 
	{
		Quiz1[i] = AnimeGame[i];
		Quiz2[i] = WordExchange[i];
		Quiz3[i] = ijin[i];
		Quiz4[i] = 0;
		Quiz5[i] = 0;
		Quiz6[i] = 0;
	}

	for (int i = 0; i < 6; i++)
	{
		Select[i] = 0;
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
		if (Genre1 > 1)
		{
			Genre1 -= 1;
			CauserY = 200 + Genre1 * 50;
		}
	}

	// 下キー押すか、左スティックを下に倒す
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_DOWN))
	{
		if(Genre1 <= 5)
		{
			Genre1 += 1;
			CauserY = 200 + Genre1 * 50;
		}
	}
	

	// Aボタンを押すと決定
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_A))
	{
		Enter = TRUE;
	}

	// クイズ配列の最後番がTRUEなら、ステージに移行する
	if (Quiz1[2] == 1 || Quiz2[2] == 1 || Quiz3[2] == 1 ||
		Quiz4[2] == 1 || Quiz5[2] == 1 || Quiz6[2] == 1) 
	{
		// ステージへ遷移
	}

	/* カーソルが６より下に言ったら */
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
	SetFontSize(30);
	DrawFormatString(500, 250, GetColor(255, 255, 255), "アニメ・ゲーム\n", Select[0]);
	DrawFormatString(500, 300, GetColor(255, 255, 255), "アニメ・ゲーム\n", Select[1]);
	DrawFormatString(500, 350, GetColor(255, 255, 255), "アニメ・ゲーム\n", Select[2]);
	DrawFormatString(500, 400, GetColor(255, 255, 255), "アニメ・ゲーム\n", Select[3]);
	DrawFormatString(500, 450, GetColor(255, 255, 255), "アニメ・ゲーム\n", Select[4]);
	DrawFormatString(500, 500, GetColor(255, 255, 255), "アニメ・ゲーム\n", Select[5]);


	// ランダムで出した値に応じて、いくつかのパターンに派生する
	if (result == 1) 
	{
		DrawFormatString(200, 200, GetColor(255, 255, 255), "1", result);
	}
	else if (result == 2) 
	{
		DrawFormatString(200, 200, GetColor(255, 255, 255), "2", result);
	}
	else if (result == 3) 
	{
		DrawFormatString(200, 200, GetColor(255, 255, 255), "3", result);
	}
	else if (result == 4)
	{
		DrawFormatString(200, 200, GetColor(255, 255, 255), "4", result);
	}
	else if (result == 5)
	{
		DrawFormatString(200, 200, GetColor(255, 255, 255), "5", result);
	}
	else if (result == 6) 
	{
		DrawFormatString(200, 200, GetColor(255, 255, 255), "6", result);
	}

	if (Quiz1[0] == 1) 
	{
		DrawGraph(500, 500, Quiz1[0], TRUE);
	}
	if (Quiz1[1] == 1) 
	{
		DrawGraph(500, 0, Quiz1[1], TRUE);
	}
	if (Quiz1[2] == 1) 
	{
		DrawGraph(0, 500, Quiz1[2], TRUE);
	}

	//DrawGraph(500, 0, ijin[0], TRUE);
	//DrawGraph(0, 500, ijin[1], TRUE);
	//DrawGraph(500, 500, ijin[2], TRUE);
}


void GenreSelect::greflection()
{

	// gSelectで変数に入れた値を持ちいて、いくつかあるパターンにを派生させる処理
	if (Genre1 == 1&&Enter == TRUE)
	{
		for (int i = 0; i < 2; i++) 
		{
			// この結果をGameMainに受け継がせる
			Quiz1[i] = 1;
		}
	}
	else if (Genre1 == 2&&Enter == TRUE)
	{
		for (int i = 0; i < 2; i++)
		{
			Quiz2[i] = 1;
		}
	}
	else if (Genre1 == 3&&Enter == TRUE)
	{
		for (int i = 0; i < 2; i++) 
		{
			Quiz3[i] = 1;
		}
	}
	else if (Genre1 == 4&&Enter == TRUE)
	{
		for (int i = 0; i < 2; i++) 
		{
			Quiz4[i] = 1;
		}
	}
	else if (Genre1 == 5&&Enter == TRUE) 
	{
		for (int i = 0; i < 2; i++) 
		{
			Quiz5[i] = 1;
		}
	}
	else if (Genre1 == 6&&Enter == TRUE)
	{
		for (int i = 0; i < 2; i++) 
		{

		}
	}

	
}
