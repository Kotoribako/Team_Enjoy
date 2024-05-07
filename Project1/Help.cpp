#include "DxLib.h"
#include "PadInput.h"
#include "Title.h"
#include "Help.h"
#include "GameMain.h"

Help::Help()
{
	//タイトル画像読み込み
	HelpImg = LoadGraph("image/help_image.png");
}

Help::~Help()
{

}

AbstractScene* Help::Update()
{
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_A))
	{
		return new GameMain();
	}
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_B))
	{
		return new Title();
	}

	return this;
}

void Help::Draw() const
{
	//タイトル画像表示
	DrawGraph(0, 0, HelpImg, TRUE);

	/*SetFontSize(100);
	DrawFormatString(500, 300, 0xffffff, "Help");

	SetFontSize(30);
	DrawFormatString(400, 500, 0xffffff, "--- A  →  GAME STARAT ---");
	DrawFormatString(450, 550, 0xffffff, "--- B  →  TITLE ---");*/
}
