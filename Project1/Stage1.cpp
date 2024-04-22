#include"Stage1.h"
#include"Player.h"
#include"PadInput.h"
#include<DxLib.h>

#define Stage1MaxX 1700 // 画像の最大Xの値
#define Stage1MinX 0 // 画像の最小のXの値

int Stage1::NowStageNumber;
Stage1::Stage1()
{
	Stage1Img = LoadGraph("image/Dummy/FirstStage(temporary).png");
	NowStageNumber = 0; // 現在のステージを管理する
	Stage1X = 0.0; // 最初の画像のX座標を0にする
}

Stage1::~Stage1()
{

}

void Stage1::Update()
{
	MoveXStage(); // X軸の画像を動かす処理を入れる	
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
	// プレイヤーのX座標が640以上かつ、右ボタンを押していて、画像の端に到達していないとき、
	if (Player::playerX >= 640.0 && PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_RIGHT) && (Stage1X * (-1)) + 640.0 <= Stage1MaxX - 640.0) // フラグでプレイヤーを管理
	{		
		Stage1X -= 3; // 画像を左に動かす。
	}
	//プレイヤーのX座標が640未満かつ、左ボタンを押している時、
	if (Player::playerX < 640.0 &&PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_LEFT))
	{
		Stage1X += 3; // 画像を右に動かす。
	}

	if (Stage1X >= 0) // ステージ画像のX座標が0以下の時、
	{
		Stage1X = 0; // ステージ画像のX座標を0に固定する
	}
}