#include"Stage1.h"
#include<DxLib.h>

int Stage1::NowStageNumber;
Stage1::Stage1()
{
	Stage1Img = LoadGraph("image/FirstStage(temporary).png");
	NowStageNumber = 0;
}

Stage1::~Stage1()
{

}

void Stage1::Update()
{

}

void Stage1::Draw()
{
	DrawGraph(0, 0, Stage1Img, TRUE);
	DrawLine(0, 400, 1280, 400, GetColor(255, 0, 0), TRUE);
	DrawLine(0, 200, 1280, 200, GetColor(255, 0, 0), TRUE);

}

void Stage1::MoveXStage()
{

}