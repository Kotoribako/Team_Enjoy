#include"Stage2.h"
#include"Player.h"
#include"PadInput.h"
#include<DxLib.h>
#include"GenreSelect.h"
#include"GameMain.h"

int Stage2::StopStage2Xflg;
float Stage2::Stage2X;
int Stage2::S2DecisionToAnswerFlg;

#define Stage2MaxX 2560 // 画像の最大Xの値
#define Stage2MinX 0 // 画像の最小のXの値

Stage2::Stage2()
{
	//タイトルBGM読み込み
	((Stage2BGM = LoadSoundMem("sound/BGM/Stage2_BGM.wav")) == -1);

	//SE読み込み
	((SeikaiSE = LoadSoundMem("sound/SE/Seikai_SE.wav")) == -1);
	//SE読み込み
	((HazureSE = LoadSoundMem("sound/SE/Hazure_SE.wav")) == -1);
	//BGM音量
	ChangeVolumeSoundMem(300, SeikaiSE);
	ChangeVolumeSoundMem(300, HazureSE);

	quiz->X = 770;
	quiz->Y = 0;
	//アニメゲームのクイズ情報
	quiz[0].Img = LoadGraph("image/Quiz/Anime&Game/AnimeGame2.png");
	quiz[0].answer[0] = 0; //選択肢１
	quiz[0].answer[1] = 1; //選択肢２
	quiz[0].answer[2] = 0; //選択肢３
	quiz[0].answer[3] = 0; //選択肢４
	//偉人のクイズ情報
	quiz[1].Img = LoadGraph("image/Quiz/Greatman/Ijin2.png");
	quiz[1].answer[0] = 0; //選択肢１
	quiz[1].answer[1] = 1; //選択肢２
	quiz[1].answer[2] = 0; //選択肢３
	quiz[1].answer[3] = 0; //選択肢４
	//並び替えのクイズ情報
	quiz[2].Img = LoadGraph("image/Quiz/WordExchange/WordExchange2.png");
	quiz[2].answer[0] = 0; //選択肢１
	quiz[2].answer[1] = 0; //選択肢２
	quiz[2].answer[2] = 0; //選択肢３
	quiz[2].answer[3] = 1; //選択肢４

	for (int i = 0; i < 4; i++)
	{
		door[i].Img = LoadGraph("image/Dummy/DummyDoor.png");
		door[i].Y = 460;
		door[i].answer = quiz[GenreSelect::Selectgenre].answer[i];
	}

	block = new Block();
	Stage2Img = LoadGraph("image/Dummy/Stage2.png");
	Stage2X = 0.0; // 最初の画像のX座標を0にする
	StopStage2Xflg = FALSE;
	GameMain::NowStage = 2;

	S2DecisionToAnswerFlg = FALSE; // 回答を決定していない状態にする
}

Stage2::~Stage2()
{
	//BGM削除
	DeleteSoundMem(Stage2BGM);
	StopSoundMem(Stage2BGM);
}

void Stage2::Update()
{
	//BGM再生（ループ）
	if (CheckSoundMem(Stage2BGM) == 0)
	{
		PlaySoundMem(Stage2BGM, DX_PLAYTYPE_BACK, TRUE);
	}

	if (GameMain::NowStage == 5) // 間違った選択肢入った時、
	{
		Initialize(); // ステージを初期化する（死んでもループ出来る）
	}

	for (int i = 0; i < 4; i++)

	{
		door[i].X = 2000 + Stage2X + i * 150;
	}
	MoveXStage(); // X軸の画像を動かす処理を入れる
	ChangeStage();
	//block->Update();
}

void Stage2::Draw()
{

	DrawGraph(Stage2X, 0, Stage2Img, TRUE);
	DrawFormatString(0, 30, GetColor(255, 0, 0), "Genre:%d", GenreSelect::Selectgenre);
	////DrawLine(0, 400, 1280, 400, GetColor(255, 0, 0), TRUE);
	////DrawLine(0, 200, 1280, 200, GetColor(255, 0, 0), TRUE);
	DrawFormatString(0, 600, GetColor(255, 0, 0), "stage2X:%f\n", Stage2X);
	DrawLine(640, 0, 640, 720, GetColor(0, 0, 255), TRUE);

	////DrawLine(0, 630, 1280, 630, GetColor(0, 255, 0), TRUE);

	//DrawGraph(700, 0, TestImg, TRUE);
	for (int i = 0; i < 4; i++)
	{
		DrawGraph(door[i].X, door[i].Y, door[i].Img, TRUE);
	}

	DrawBox(door[0].X - 10, door[0].Y, door[0].X + 70, door[0].Y + 60, 0x00ff00, FALSE);
	DrawBox(door[1].X - 10, door[1].Y, door[1].X + 70, door[1].Y + 60, 0xff0000, FALSE);
	DrawBox(door[2].X - 10, door[2].Y, door[2].X + 70, door[2].Y + 60, 0x0000ff, FALSE);
	DrawBox(door[3].X - 10, door[3].Y, door[3].X + 70, door[3].Y + 60, 0xffff00, FALSE);


	if (Player::quizflg == 1) // プレイヤーのX座標が1050を超えると、
	{
		// ジャンルによって問題変え
		switch (GenreSelect::Selectgenre)
		{
		case 0:
			DrawGraph(700, 0, quiz[0].Img, TRUE);
			break;
		case 1:
			DrawGraph(700, 0, quiz[1].Img, TRUE);
			break;
		case 2:
			DrawGraph(700, 0, quiz[2].Img, TRUE);
			break;
		}
	}
	block->Draw();

	DrawFormatString(1500, 0, GetColor(255, 255, 255), "Genre:%d", GenreSelect::Selectgenre);

}

void Stage2::MoveXStage()
{
	// プレイヤーのX座標が640以上かつ、右ボタンを押していて、
	if (Player::playerX >= 640.0 && PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_RIGHT))
	{
		if ((Stage2X * (-1)) + 640.0 <= Stage2MaxX - 640.0) // 画像の端に到達していないとき、
		{
			Stage2X -= 3; // 画像を左に動かす。
			Player::MoveFlg = FALSE; // 真ん中よりも右に進めないようにする

			//for (int i = 0; i < 11; i++)
			//{
			//	//block->bloc[i].X += -2.9; // 左側の当たり判定ずらす
			//	//block->bloc[i].X2 += -2.9; // 右側の当たり判定ずらす
			//}
		}
		else // 画像の端に到達したとき、
		{
			StopStage2Xflg = TRUE; // ステージ１の画像移動をストップする
			Player::MoveFlg = TRUE; // 真ん中よりも右に進めるようにする
		}

	}
	//プレイヤーのX座標が640未満かつ、左ボタンを押している時、
	if (Player::playerX < 640.0 && PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_LEFT))
	{
		//GameMain::NowStage = 3;
		Stage2X += 3; // 画像を右に動かす。
		//if (Player::playerX + -(Stage1X) >= 640.0) {
		//	for (int i = 0; i < 11; i++)
		//	{
		//		//block->bloc[i].X += 3.0; // 左側の当たり判定ずらす
		//		//block->bloc[i].X2 += 3.0; // 右側の当たり判定ずらす
		//	}

		//}
	}

	if (Stage2X >= 0) // ステージ画像のX座標が0以下の時、
	{
		Stage2X = 0; // ステージ画像のX座標を0に固定する
	}

	//if (Player::playerX + ( - 1 * Stage1X ) >= 1500)
	//{
	//	GameMain::NowStage = 2;
	//}
}

void Stage2::ChangeStage()
{
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_UP)) {
		for (int i = 0; i < 4; i++)
		{
			if (Player::playerX >= door[i].X - 10 && Player::playerX <= door[i].X + 70 && Player::playerY >= door[i].Y && Player::playerY <= door[i].Y + 60)
			{
				if (door[i].answer == 1) // 正解のドアを選んだら、
				{
					//ボタンが押された時SE再生
					PlaySoundMem(SeikaiSE, DX_PLAYTYPE_BACK, TRUE);
					
					//BGM削除
					DeleteSoundMem(Stage2BGM);
					StopSoundMem(Stage2BGM);

					GameMain::NowStage = 3; // 次のステージへ進む。
				}
				else
				{
					//ボタンが押された時SE再生
					PlaySoundMem(HazureSE, DX_PLAYTYPE_BACK, TRUE);
					//BGM削除
					DeleteSoundMem(Stage2BGM);
					StopSoundMem(Stage2BGM);

					GameMain::NowStage = 5;
				}
				S2DecisionToAnswerFlg = TRUE; // 回答を決定した状態にする
			}
		}
		//Stage::NowStage = 2; 
	}
}

void Stage2::Initialize()
{
	quiz->X = 770;
	quiz->Y = 0;
	//アニメゲームのクイズ情報
	quiz[0].Img = LoadGraph("image/Quiz/Anime&Game/AnimeGame2.png");
	quiz[0].answer[0] = 0; //選択肢１
	quiz[0].answer[1] = 1; //選択肢２
	quiz[0].answer[2] = 0; //選択肢３
	quiz[0].answer[3] = 0; //選択肢４
	//偉人のクイズ情報
	quiz[1].Img = LoadGraph("image/Quiz/Greatman/Ijin2.png");
	quiz[1].answer[0] = 0; //選択肢１
	quiz[1].answer[1] = 1; //選択肢２
	quiz[1].answer[2] = 0; //選択肢３
	quiz[1].answer[3] = 0; //選択肢４
	//並び替えのクイズ情報
	quiz[2].Img = LoadGraph("image/Quiz/WordExchange/WordExchange2.png");
	quiz[2].answer[0] = 0; //選択肢１
	quiz[2].answer[1] = 0; //選択肢２
	quiz[2].answer[2] = 0; //選択肢３
	quiz[2].answer[3] = 1; //選択肢４

	for (int i = 0; i < 4; i++)
	{
		door[i].Img = LoadGraph("image/Dummy/DummyDoor.png");
		door[i].Y = 550;
		door[i].answer = quiz[GenreSelect::Selectgenre].answer[i];
	}

	block = new Block();		
	Stage2Img = LoadGraph("image/Dummy/Stage2.png");
	Stage2X = 0.0; // 最初の画像のX座標を0にする
	StopStage2Xflg = FALSE;
	TestImg = LoadGraph("image/Quiz/Anime&Game/AnimeGame1.png");
	GameMain::NowStage = 1;

	S2DecisionToAnswerFlg = FALSE; // 回答を決定していない状態にする
}