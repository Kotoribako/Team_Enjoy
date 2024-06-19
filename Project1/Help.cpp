#include "DxLib.h"
#include "PadInput.h"
#include "Title.h"
#include "Help.h"
#include "GameMain.h"
#include"GenreSelect.h"

Help::Help()
{
	//背景画像読み込み
	BackgroundImg = LoadGraph("image/BackGround02.png");
	//画像読み込み
	HelpImg = LoadGraph("image/Help2_Img.png");
	ModoruImg = LoadGraph("image/HelpModoru.png");

	//タイトルBGM読み込み
	((TitleBGM = LoadSoundMem("sound/BGM/Title_BGM.wav")) == -1);
	//SE読み込み
	((MenuSE = LoadSoundMem("sound/SE/kettei_SE.wav")) == -1);

	S_FPS = 0;
	S_Seconas = 0;

}

Help::~Help()
{
	//BGM削除
	DeleteSoundMem(TitleBGM);
	StopSoundMem(TitleBGM);
}

AbstractScene* Help::Update()
{
	//BGM再生（ループ）
	if (CheckSoundMem(TitleBGM) == 0)
	{
		PlaySoundMem(TitleBGM, DX_PLAYTYPE_LOOP, TRUE);
	}

	S_FPS++;

	//FPS
	if (S_FPS > 20) {
		S_FPS = 0;
		S_Seconas++;
	}
	else if (S_Seconas >= 5) {
		S_Seconas = 0;
	}

	if (PAD_INPUT::OnButton(XINPUT_BUTTON_A))
	{
		PlaySoundMem(MenuSE, DX_PLAYTYPE_BACK, TRUE);
		return new GenreSelect();
	}
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_B))
	{
		PlaySoundMem(MenuSE, DX_PLAYTYPE_BACK, TRUE);
		return new Title();
	}

	return this;
}

void Help::Draw() const
{
	//画像表示
	DrawGraph(0, 0, BackgroundImg, TRUE);
	DrawGraph(0, 0, HelpImg, TRUE);
	
	if (S_Seconas >= 3) {
		DrawGraph(260, 200, ModoruImg, TRUE);
	}
}
