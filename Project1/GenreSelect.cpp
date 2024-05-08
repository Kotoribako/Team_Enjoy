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

int GenreSelect::Selectgenre;

GenreSelect::GenreSelect()
{
	now_menu = static_cast<int>(SELECT::ANIMEGAME);
	input_margin = 0;
	GetRand(2);
	MenuFont = CreateFontToHandle("HG創英角POP体", 64, 1, DX_FONTTYPE_ANTIALIASING_EDGE_8X8, -1, 3);
}


AbstractScene* GenreSelect::Update()
{
	const int max_input_margin = 15;
	const int stick_sensitivity = 20000;

	if (input_margin < max_input_margin) 
	{
		input_margin++;
	}
	else 
	{
		int stick_y = PAD_INPUT::GetLStick().ThumbY;

		if (std::abs(stick_y) > stick_sensitivity || PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_UP))
		{
			//	PlaySoundMem(CursorImg, DX_PLAYTYPE_BACK, TRUE);
				//playsoundmem
			if (stick_y > 0) 
			{
				now_menu = (now_menu - 1 + static_cast<int>(SELECT::SELECT_SIZE)) % static_cast<int>(SELECT::SELECT_SIZE);
				Genre1 -= 1;
			}
			else if (stick_y < 0 || PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_DOWN)) 
			{
				now_menu = (now_menu + 1) % static_cast<int>(SELECT::SELECT_SIZE);
				Genre1 += 1;
			}
			input_margin = 0;
		}
	}
	if (PAD_INPUT::GetNowKey(XINPUT_BUTTON_A) && (PAD_INPUT::OnButton(XINPUT_BUTTON_A) == true))
	{
		input_margin = 0;
		SELECT current_select = static_cast<SELECT>(now_menu);
		switch (current_select)
		{
		case SELECT::ANIMEGAME:
			Selectgenre = 0;
			return new GameMain();
			break;
		case SELECT::WORDEXCHANGE:
			Selectgenre = 1;
			return new GameMain();
			break;
		case SELECT::GREATMAN:
			Selectgenre = 2;
			return new GameMain();
			break;
		case SELECT::RANDOMSELECT:
			Selectgenre = GetRand(2);
			return new GameMain();
			break;
		default:
			//printfDx("�������ȋ@�\�ł��B\n"); 
			break;
		}
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
	

	//DrawGraph(500, 0, ijin[0], TRUE);
	//DrawGraph(0, 500, ijin[1], TRUE);
	//DrawGraph(500, 500, ijin[2], TRUE);



	SetFontSize(60);
	////タイトル表示
	//DrawFormatString(300, 200, 0xffffff, "Title");
	//DrawFormatString(300, 500, 0xffffff, "GameMain");

	for (int i = 0; i < static_cast<int>(SELECT::SELECT_SIZE); i++)
	{
		const int base_y = 200;

		const int margin_y = 100;

		
		int color = 0xFFFFFF;		
		int border_color = 0x000000;

		if (now_menu == i) 
		{
			color = ~color;
			border_color = ~border_color;
		}
		DrawStringToHandle(SCREEN_WIDTH / 2 - 100, i * margin_y + base_y, select_items[i], color, MenuFont, border_color);
	}
	DrawStringToHandle(150, 100, "Select", 0xffffff, MenuFont);

}
