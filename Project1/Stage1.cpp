#include"Stage1.h"
#include"Player.h"
#include"PadInput.h"
#include<DxLib.h>

#define Stage1MaxX 1700 // 画像の最大Xの値
#define Stage1MinX 0 // 画像の最小のXの値

int Stage1::NowStageNumber;
Stage1::Stage1()
{
	Stage1Img = LoadGraph("image/FirstStage(temporary).png");
	NowStageNumber = 0;
	Stage1X = 0.0;
	MoveFlgX = 0;
}

Stage1::~Stage1()
{

}

void Stage1::Update()
{
	MoveXStage();
	
}

void Stage1::Draw()
{
	DrawGraph(Stage1X, 0, Stage1Img, TRUE);
	DrawLine(0, 400, 1280, 400, GetColor(255, 0, 0), TRUE);
	DrawLine(0, 200, 1280, 200, GetColor(255, 0, 0), TRUE);
	DrawFormatString(0, 600, GetColor(255, 0, 0), "stage1X:%f\n", Stage1X);
	DrawLine(640, 0, 640, 720, GetColor(0, 0, 255), TRUE);
}

void Stage1::MoveXStage()
{
	if (Player::playerX == 640.0 && PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_RIGHT) && Player::playerX <= Stage1MaxX - 640.0)
	{
		/*if (Player::playerX >= 640.0 && PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_RIGHT))*/
		//{
			Stage1X -= 3/*640.0 - Player::playerX*/;
		//}
		
	}
	if (Player::playerX < 640.0 &&/* MoveFlgX == 0 &&*/ PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_LEFT)/* && Stage1X >= 0*//* && Player::playerX - 640.0 >= Stage1MinX*/)
	{
		Stage1X += 3;
	}

	if (Stage1X >= 0)
	{
		Stage1X = 0;
	}
}