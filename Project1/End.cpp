#include "DxLib.h"
#include "PadInput.h"
#include "End.h"
#include "Title.h"
#include "GameMain.h"

End::End()
{
	//タイトル画像読み込み
	EndImg = LoadGraph("image/End.png");
	ThankImg = LoadGraph("image/Thank.png");

	S_FPS = 0;
	S_Seconas = 0;
}

End::~End()
{

}

AbstractScene* End::Update()
{
	S_FPS++;

	if (S_FPS > 60) {
		S_FPS = 0;
		S_Seconas++;
	}
	else if (S_Seconas >= 10) {
		S_Seconas = 0;
	}

	if (S_Seconas >= 6) {
		return 0;
	}

}

void End::Draw() const
{
	//タイトル画像表示
	DrawGraph(0, 0, EndImg, TRUE);

	if (S_Seconas >= 4) {
		DrawGraph(0, 0, ThankImg, TRUE);
	}

	SetFontSize(20);
	DrawFormatString(0, 30, 0x000000, "S_FPS : %d", End::S_FPS);
	DrawFormatString(0, 50, 0x000000, "S_Seconas : %d", End::S_Seconas);
}
