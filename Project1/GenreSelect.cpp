#include "GenreSelect.h"
#include<stdlib.h>
#include<time.h>
#include <DxLib.h>
#include"DxLib.h"
#include"PadInput.h"
#include"Stage1.h"
#include "GameMain.h"
#include<iostream>
#define SCREEN_WIDTH 1280
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
	CauserX = 300;
	CauserY = 250;
	
	for (int i = 0; i < 2; i++) 
	{
		Quiz1[i] = AnimeGame[i];
		Quiz2[i] = WordExchange[i];
		Quiz3[i] = ijin[i];
		Quiz4[i] = 0;
		Quiz5[i] = 0;
		Quiz6[i] = 0;
	}

	now_menu = static_cast<int>(SELECT::ANIMEGAME);
	input_margin = 0;
	MenuFont = CreateFontToHandle("HG創英角POP体", 64, 1, DX_FONTTYPE_ANTIALIASING_EDGE_8X8, -1, 3);
}


AbstractScene* GenreSelect::Update()
{

	
	
	int x = 0;
	// 上キー押すか、左スティックを上に倒す
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_UP))
	{
		/*if (Genre1 > 1)
		{
			Genre1 -= 1;
			CauserY = 200 + Genre1 * 50;
		}*/
	}

	// 下キー押すか、左スティックを下に倒す
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_DOWN))
	{
		/*if(Genre1 <= 5)
		{
			Genre1 += 1;
			CauserY = 200 + Genre1 * 50;
		}*/
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


	const int max_input_margin = 15;
	const int stick_sensitivity = 20000;

	if (input_margin < max_input_margin) {
		input_margin++;
	}
	else {
		int stick_y = PAD_INPUT::GetLStick().ThumbY;

		if (std::abs(stick_y) > stick_sensitivity || PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_UP)) {
			//	PlaySoundMem(CursorImg, DX_PLAYTYPE_BACK, TRUE);
				//playsoundmem
			if (stick_y > 0) {
				now_menu = (now_menu - 1 + static_cast<int>(SELECT::SELECT_SIZE)) % static_cast<int>(SELECT::SELECT_SIZE);
			}
			else if (stick_y < 0 || PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_DOWN)) {
				now_menu = (now_menu + 1) % static_cast<int>(SELECT::SELECT_SIZE);
			}
			input_margin = 0;
		}
	}
	if (CheckHitKey(KEY_INPUT_1) || PAD_INPUT::OnButton(XINPUT_BUTTON_A)) {
		return new GameMain();

	}
	if (CheckHitKey(KEY_INPUT_2)) {
		return new GenreSelect;
	}


	return this;
}

void GenreSelect::Draw() const
{
	DrawBox(0, 0, 1280, 750, GetColor(255, 255, 255), TRUE);
	// カーソル画像
	//DrawGraph(CauserX, CauserY, Causer, TRUE);

	DrawFormatString(100, 100, GetColor(0, 0, 0), "CauserX:%d\n",CauserX);
	DrawFormatString(200, 100, GetColor(0, 0, 0), "CauserY:%d\n",CauserY);
	SetFontSize(30);
	

	// ランダムで出した値に応じて、いくつかのパターンに派生する
	if (result == 1) 
	{
		DrawFormatString(200, 200, GetColor(0, 0, 0), "1", result);
	}
	else if (result == 2) 
	{
		DrawFormatString(200, 200, GetColor(0, 0, 0), "2", result);
	}
	else if (result == 3) 
	{
		DrawFormatString(200, 200, GetColor(0, 0, 0), "3", result);
	}
	else if (result == 4)
	{
		DrawFormatString(200, 200, GetColor(0, 0, 0), "4", result);
	}
	else if (result == 5)
	{
		DrawFormatString(200, 200, GetColor(0, 0, 0), "5", result);
	}
	else if (result == 6) 
	{
		DrawFormatString(200, 200, GetColor(0, 0, 0), "6", result);
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



	SetFontSize(60);
	////タイトル表示
	//DrawFormatString(300, 200, 0xffffff, "Title");
	//DrawFormatString(300, 500, 0xffffff, "GameMain");

	for (int i = 0; i < static_cast<int>(SELECT::SELECT_SIZE); i++)
	{
		// ������̍ŏ�Y���W
		const int base_y = 200;

		// �������Y���W�Ԋu
		const int margin_y = 100;

		// �����F
		int color = 0xFFFFFF;
		// �����O�g�F
		int border_color = 0x000000;

		// �J�[�\���������Ă���ꍇ�A�����F�ƕ����O�g�F�𔽓]������
		if (now_menu == i) {
			color = ~color;
			border_color = ~border_color;
		}
		DrawStringToHandle(SCREEN_WIDTH / 2 - 100, i * margin_y + base_y, select_items[i], color, MenuFont, border_color);
	}
	DrawStringToHandle(150, 100, "Select", 0xffffff, MenuFont);

}


void GenreSelect::greflection()
{
	greflection();
	srand((unsigned)time(NULL)); // 乱数の仕組みの初期化

	r = (rand() % (max - min + 1)) + min; // 1～６までの数字をランダムで変数に格納する
	result = r;

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
