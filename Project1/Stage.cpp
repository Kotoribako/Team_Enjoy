#include"Stage.h"
#include<DxLib.h>

Stage::Stage()
{
	
}

Stage::~Stage()
{

}

void Stage::Update()
{
	switch (NowStageNumber) // ステージ数によって遷移する
	{
	case 1: // １ステージ目の時
		break;
	case 2: // ２ステージ目の時
		break;
	case 3: // ３ステージ目の時
		break;
	}
}

void Stage::Draw()
{

}

void Stage::MoveXStage()
{

}