#include"Stage1.h"
#include"Player.h"
#include"PadInput.h"
#include<DxLib.h>
#include"GenreSelect.h"

int Stage1::StopStage1Xflg;
float Stage1::Stage1X;

#define Stage1MaxX 1700 // 画像の最大Xの値
#define Stage1MinX 0 // 画像の最小のXの値

int Stage1::NowStageNumber;
Stage1::Stage1()
{
	Stage1Img = LoadGraph("image/Dummy/FirstStage(temporary).png");
	DoorImg = LoadGraph("image/Dummy/DummyDoor.png");
	NowStageNumber = 0; // 現在のステージを管理する
	Stage1X = 0.0; // 最初の画像のX座標を0にする
	StopStage1Xflg = FALSE;
	block = new Block();
	TestImg = LoadGraph("image/Quiz/Anime&Game/AnimeGame1.png");
}

Stage1::~Stage1()
{

}

void Stage1::Update()
{
	MoveXStage(); // X軸の画像を動かす処理を入れる	
	//block->Update();
}

void Stage1::Draw()
{
	
	DrawGraph(Stage1X, 0, Stage1Img, TRUE);
	////DrawLine(0, 400, 1280, 400, GetColor(255, 0, 0), TRUE);
	////DrawLine(0, 200, 1280, 200, GetColor(255, 0, 0), TRUE);
	//DrawFormatString(0, 600, GetColor(255, 0, 0), "stage1X:%f\n", Stage1X);
	DrawLine(640, 0, 640, 720, GetColor(0, 0, 255), TRUE);

	for (int i = 0; i < 4; i++) {
		DrawGraph(1300 + Stage1X + i * 80, 550, DoorImg, TRUE);

	}
	////DrawLine(0, 630, 1280, 630, GetColor(0, 255, 0), TRUE);

	DrawGraph(700, 0, TestImg, TRUE);

	block->Draw();
	DrawFormatString(1500, 0, GetColor(255, 255, 255), "Genre:%d", GenreSelect::Selectgenre);

}

void Stage1::MoveXStage()
{
	// プレイヤーのX座標が640以上かつ、右ボタンを押していて、
	if (Player::playerX >= 640.0 && PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_RIGHT))
	{
		if ((Stage1X * (-1)) + 640.0 <= Stage1MaxX - 640.0) // 画像の端に到達していないとき、
		{
			Stage1X -= 3; // 画像を左に動かす。
			Player::MoveFlg = FALSE; // 真ん中よりも右に進めないようにする

			//for (int i = 0; i < 11; i++)
			//{
			//	//block->bloc[i].X += -2.9; // 左側の当たり判定ずらす
			//	//block->bloc[i].X2 += -2.9; // 右側の当たり判定ずらす
			//}
		}
		else // 画像の端に到達したとき、
		{
			StopStage1Xflg = TRUE; // ステージ１の画像移動をストップする
			Player::MoveFlg = TRUE; // 真ん中よりも右に進めるようにする
		}
		
	}
	//プレイヤーのX座標が640未満かつ、左ボタンを押している時、
	if (Player::playerX < 640.0 && PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_LEFT))
	{
		Stage1X += 3; // 画像を右に動かす。
		//if (Player::playerX + -(Stage1X) >= 640.0) {
		//	for (int i = 0; i < 11; i++)
		//	{
		//		//block->bloc[i].X += 3.0; // 左側の当たり判定ずらす
		//		//block->bloc[i].X2 += 3.0; // 右側の当たり判定ずらす
		//	}

		//}
	}

	if (Stage1X >= 0) // ステージ画像のX座標が0以下の時、
	{
		Stage1X = 0; // ステージ画像のX座標を0に固定する
	}
}