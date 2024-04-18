#include"Stage1.h"
#include"Player.h"
#include<DxLib.h>

#define Stage1MaxX 1700 // 画像の最大Xの値

int Stage1::NowStageNumber;
Stage1::Stage1()
{
	Stage1Img = LoadGraph("image/FirstStage(temporary).png");
	NowStageNumber = 0;
	Stage1X = 0;
}

Stage1::~Stage1()
{

}

void Stage1::Update()
{
	if (Player::playerX >= 640 && Player::playerX <= Stage1MaxX - 640)
	{
		MoveXStage();
	}
	else if (Player::playerX < 640)
	{
		Stage1X = 0;
	}
}

void Stage1::Draw()
{
	DrawGraph(Stage1X, 0, Stage1Img, TRUE);
	DrawLine(0, 400, 1280, 400, GetColor(255, 0, 0), TRUE);
	DrawLine(0, 200, 1280, 200, GetColor(255, 0, 0), TRUE);
	DrawFormatString(0, 600, GetColor(255, 0, 0), "stage1X:%d\n", Stage1X);
}

void Stage1::MoveXStage()
{
	Stage1X = 640 - Player::playerX;
}