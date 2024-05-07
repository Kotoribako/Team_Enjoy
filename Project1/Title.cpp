#include "DxLib.h"
#include <DxLib.h>
#include "Title.h"
#include "PadInput.h"
#include<iostream>
#include"GameMain.h"
#include"GenreSelect.h"
#include "Help.h"

#define SCREEN_WIDTH 1280

Title::Title()
{
	//タイトル画像読み込み
	TitleImg = LoadGraph("image/BackGround02.png");

	//タイトルBGM読み込み
	((TitleBGM = LoadSoundMem("sound/BGM/Title_BGM2.wav")) == -1);
	//BGM音量
	ChangeVolumeSoundMem(200, TitleBGM);

	//SE読み込み
	((CursorSE = LoadSoundMem("sound/SE/cursor_SE.wav")) == -1);
	//SE読み込み
	((MenuSE = LoadSoundMem("sound/SE/kettei_SE.wav")) == -1);

	//
	MenuFont = CreateFontToHandle("HG創英角POP体", 64, 1, DX_FONTTYPE_ANTIALIASING_EDGE_8X8, -1, 3);
	now_menu = static_cast<int>(TITLE_MENU::GAME_START);
	input_margin = 0;

}

Title::~Title()
{
	//BGM削除
	DeleteSoundMem(TitleBGM);
	StopSoundMem(TitleBGM);
}

AbstractScene* Title::Update()
{
	//BGM再生（ループ）
	if (CheckSoundMem(TitleBGM) == 0)
	{
		PlaySoundMem(TitleBGM, DX_PLAYTYPE_LOOP, TRUE);
	}

	//
	const int max_input_margin = 15;
	//
	const int stick_sensitivity = 20000;

	if (input_margin < max_input_margin) {
		input_margin++;
	}
	else {
		//
		int stick_y = PAD_INPUT::GetLStick().ThumbY;

		//スティックでカーソル移動
		if (std::abs(stick_y) > stick_sensitivity /*|| PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_UP)*/) {
			//ボタンが押された時SE再生
			PlaySoundMem(CursorSE, DX_PLAYTYPE_BACK, TRUE);
			//playsoundmem
			//
			if (stick_y > 0) {
				//
				now_menu = (now_menu - 1 + static_cast<int>(TITLE_MENU::TITLE_SIZE)) % static_cast<int>(TITLE_MENU::TITLE_SIZE);
			}
			
			else if (stick_y < 0 ) {
				//
				now_menu = (now_menu + 1) % static_cast<int>(TITLE_MENU::TITLE_SIZE);
			}
			input_margin = 0;
		}
		//十字キーでカーソル移動
		if (PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_UP))
		{
			PlaySoundMem(CursorSE, DX_PLAYTYPE_BACK, TRUE);
			now_menu = (now_menu - 1 + static_cast<int>(TITLE_MENU::TITLE_SIZE)) % static_cast<int>(TITLE_MENU::TITLE_SIZE);
		}
		else if (PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_DOWN))
		{
			PlaySoundMem(CursorSE, DX_PLAYTYPE_BACK, TRUE);
			now_menu = (now_menu + 1) % static_cast<int>(TITLE_MENU::TITLE_SIZE);
		}
	}

	if (CheckHitKey(KEY_INPUT_1) || PAD_INPUT::OnButton(XINPUT_BUTTON_A)) {
		return new GameMain();
		PlaySoundMem(MenuSE, DX_PLAYTYPE_BACK, TRUE);
	}

	/*if (CheckHitKey(KEY_INPUT_2)) {
		return new GenreSelect;
	}*/

	if (PAD_INPUT::GetNowKey(XINPUT_BUTTON_A) && (PAD_INPUT::OnButton(XINPUT_BUTTON_A) == true))
	{
		input_margin = 0;
		TITLE_MENU current_select = static_cast<TITLE_MENU>(now_menu);
		switch (current_select)
		{
		case TITLE_MENU::GAME_START:
			PlaySoundMem(MenuSE, DX_PLAYTYPE_BACK, TRUE);
			return new GenreSelect();
			break;
		case TITLE_MENU::HELP:
			PlaySoundMem(MenuSE, DX_PLAYTYPE_BACK, TRUE);
			return new Help;
			break;
		/*case TITLE_MENU::RANKING:
		* PlaySoundMem(MenuSE, DX_PLAYTYPE_BACK, TRUE);
			return new Ranking;
			break;*/
		case TITLE_MENU::GAME_END:
			PlaySoundMem(MenuSE, DX_PLAYTYPE_BACK, TRUE);
			return nullptr;
			break;
		default:
			//printfDx("�������ȋ@�\�ł��B\n"); 
			break;
		}
	}

	return this;
}

void Title::Draw()const
{
	//タイトル画像表示
	DrawGraph(0, 0, TitleImg, TRUE);

	SetFontSize(60);

	for (int i = 0; i < static_cast<int>(TITLE_MENU::TITLE_SIZE); i++)
	{
		//
		const int base_y = 200;

		//
		const int margin_y = 100;

		//
		int color = 0xFFFFFF;
		//
		int border_color = 0x000000;

		//
		if (now_menu == i) {
			color = ~color;
			border_color = ~border_color;
		}
		DrawStringToHandle(SCREEN_WIDTH / 2 - 100, i * margin_y + base_y, menu_items[i], color, MenuFont, border_color);
	}
	DrawStringToHandle(150, 100, "Title", 0xffffff, MenuFont);

	////�J�[�\���̕`��
	//int select_y = 230 + Select * 80;
	//DrawGraph(650, select_y, CursorImg, TRUE);
}