#include"Stage1.h"
#include"Player.h"
#include"PadInput.h"
#include<DxLib.h>
#include"GenreSelect.h"
#include"GameMain.h"
#include"time.h"

int Stage1::StopStage1Xflg;
float Stage1::Stage1X;
int Stage1::S1DecisionToAnswerFlg;

#define Stage1MaxX 1700 // 画像の最大Xの値
#define Stage1MinX 0 // 画像の最小のXの値

Stage1::Stage1()
{
	//タイトルBGM読み込み
	((Stage1BGM = LoadSoundMem("sound/BGM/Stage1_BGM.wav")) == -1);

	//SE読み込み
	((SeikaiSE = LoadSoundMem("sound/SE/Seikai_SE.wav")) == -1);
	//SE読み込み
	((HazureSE = LoadSoundMem("sound/SE/Hazure_SE.wav")) == -1);
	//BGM音量
	ChangeVolumeSoundMem(300, SeikaiSE);
	ChangeVolumeSoundMem(300, HazureSE);

	quiz->X = 770;
	quiz->Y = 0;

	
	srand((unsigned int)time(NULL));
	i = rand() % 3;
	y = rand() % 3;
	x = rand() % 3;

	
	

	////アニメゲームのクイズ情報
	//quiz[0][i].Img = LoadGraph("image/Quiz/Anime&Game/AnimeGame1.png");
	//quiz[0][i].answer[0] = 0; //選択肢１
	//quiz[0][i].answer[1] = 0; //選択肢２
	//quiz[0][i].answer[2] = 1; //選択肢３
	//quiz[0][i].answer[3] = 0; //選択肢４
	////偉人のクイズ情報
	//quiz[1][y].Img = LoadGraph("image/Quiz/Greatman/Ijin1.png");
	//quiz[1][y].answer[0] = 0; //選択肢１
	//quiz[1][y].answer[1] = 0; //選択肢２
	//quiz[1][y].answer[2] = 1; //選択肢３
	//quiz[1][y].answer[3] = 0; //選択肢４
	////並び替えのクイズ情報
	//quiz[2][x].Img = LoadGraph("image/Quiz/WordExchange/WordExchange1.png");
	//quiz[2][x].answer[0] = 0; //選択肢１
	//quiz[2][x].answer[1] = 0; //選択肢２
	//quiz[2][x].answer[2] = 1; //選択肢３
	//quiz[2][x].answer[3] = 0; //選択肢４
	

	 switch (i)
	 {
	 case 0:
		 quiz[0].Img = LoadGraph("image/Quiz/Anime&Game/AnimeGame1.png");
		 quiz[0].answer[0] = 0; //選択肢１
		 quiz[0].answer[1] = 0; //選択肢２
		 quiz[0].answer[2] = 1; //選択肢３
		 quiz[0].answer[3] = 0; //選択肢４
		 break;
	 case 1:
		 quiz[1].Img = LoadGraph("image/Quiz/Anime&Game/AnimeGame3.png");
		 quiz[1].answer[0] = 1; //選択肢１
		 quiz[1].answer[1] = 0; //選択肢２
		 quiz[1].answer[2] = 0; //選択肢３
		 quiz[1].answer[3] = 0; //選択肢４
		 break;

	 case 2:
		 quiz[2].Img = LoadGraph("image/Quiz/Anime&Game/AnimeGame7.png");
		 quiz[2].answer[0] = 0; //選択肢１
		 quiz[2].answer[1] = 1; //選択肢２
		 quiz[2].answer[2] = 0; //選択肢３
		 quiz[2].answer[3] = 0; //選択肢４
		 break;

	 default:
		 break;
	 }

	 switch (y)
	 {
	 case 0:
		 
		 quiz2[0].Img = LoadGraph("image/Quiz/Greatman/Ijin5.png");
		 quiz2[0].answer[0] = 0; //選択肢１
		 quiz2[0].answer[1] = 0; //選択肢２
		 quiz2[0].answer[2] = 1; //選択肢３
		 quiz2[0].answer[3] = 0; //選択肢４
		 break; 
	 case 1:
		 quiz2[1].Img = LoadGraph("image/Quiz/Greatman/Ijin2.png");
		 quiz2[1].answer[0] = 0; //選択肢１
		 quiz2[1].answer[1] = 1; //選択肢２
		 quiz2[1].answer[2] = 0; //選択肢３
		 quiz2[1].answer[3] = 0; //選択肢４
		 break; 
	 case 2:
		 quiz2[2].Img = LoadGraph("image/Quiz/Greatman/Ijin3.png");
		 quiz2[2].answer[0] = 0; //選択肢１
		 quiz2[2].answer[1] = 0; //選択肢２
		 quiz2[2].answer[2] = 1; //選択肢３
		 quiz2[2].answer[3] = 0; //選択肢４
		 break; 
	 
	 default:
		 break;
	 }

	 switch (x)
	 {
	 case 0:
		 quiz3[0].Img = LoadGraph("image/Quiz/WordExchange/WordExchange1.png");
		 quiz3[0].answer[0] = 0; //選択肢１
		 quiz3[0].answer[1] = 0; //選択肢２
		 quiz3[0].answer[2] = 1; //選択肢３
		 quiz3[0].answer[3] = 0; //選択肢４
		 break;
	case 1:
		quiz3[1].Img = LoadGraph("image/Quiz/WordExchange/WordExchange2.png");
		quiz3[1].answer[0] = 0; //選択肢１
		quiz3[1].answer[1] = 0; //選択肢２
		quiz3[1].answer[2] = 0; //選択肢３
		quiz3[1].answer[3] = 1; //選択肢４
		 break;
	case 2:
		quiz3[2].Img = LoadGraph("image/Quiz/WordExchange/WordExchange3.png");
		quiz3[2].answer[0] = 0; //選択肢１
		quiz3[2].answer[1] = 0; //選択肢２
		quiz3[2].answer[2] = 1; //選択肢３
		quiz3[2].answer[3] = 0; //選択肢４
		 break;
	
	 default:
		 break;
	 }



	 int i2 = i;
	 int y2 = y;
	 int x2 = x;
	 if (GenreSelect::Selectgenre == 0)
	 {
		 for (int i = 0; i < 4; i++)
		 {
			 door[i].Img = LoadGraph("image/Dummy/DummyDoor.png");
			 door[i].Y = 550;
			 door[i].answer = quiz[i2].answer[i];
		 }
	 }
	 else if (GenreSelect::Selectgenre == 1)
	 {
		 for (int i = 0; i < 4; i++)
		 {
			 door[i].Img = LoadGraph("image/Dummy/DummyDoor.png");
			 door[i].Y = 550;
			 door[i].answer = quiz2[y2].answer[i];
		 }
	 }
	 else if (GenreSelect::Selectgenre == 2)
	 {
		 for (int i = 0; i < 4; i++)
		 {
			 door[i].Img = LoadGraph("image/Dummy/DummyDoor.png");
			 door[i].Y = 550;
			 door[i].answer = quiz3[x2].answer[i];
		 }
	 }
	

	block = new Block();
	Stage1Img = LoadGraph("image/Dummy/FirstStage(temporary).png");
	Stage1X = 0.0; // 最初の画像のX座標を0にする
	StopStage1Xflg = FALSE;
	TestImg = LoadGraph("image/Quiz/Anime&Game/AnimeGame1.png");
	//GameMain::NowStage = 1;

	S1DecisionToAnswerFlg = FALSE; // 回答を決定していない状態にする
}

Stage1::~Stage1()
{
	//BGM削除
	DeleteSoundMem(Stage1BGM);
	StopSoundMem(Stage1BGM);
}

void Stage1::Update()
{
	//BGM再生（ループ）
	if (CheckSoundMem(Stage1BGM) == 0)
	{
		PlaySoundMem(Stage1BGM, DX_PLAYTYPE_BACK, TRUE);
	}

	if (GameMain::NowStage == 4) // 間違った選択肢入った時、
	{
		Initialize(); // ステージを初期化する（死んでもループ出来る）
	}

	for (int i = 0; i < 4; i++)

	{
		door[i].X = 1150 + Stage1X + i * 150;
	}
	MoveXStage(); // X軸の画像を動かす処理を入れる
	ChangeStage();
	//block->Update();
}

void Stage1::Draw()
{
	
	DrawGraph(Stage1X, 0, Stage1Img, TRUE);
	DrawFormatString(0, 30, GetColor(255, 0, 0), "Genre:%d", GenreSelect::Selectgenre);
	////DrawLine(0, 400, 1280, 400, GetColor(255, 0, 0), TRUE);
	////DrawLine(0, 200, 1280, 200, GetColor(255, 0, 0), TRUE);
	//DrawFormatString(0, 600, GetColor(255, 0, 0), "stage1X:%f\n", Stage1X);
	DrawLine(640, 0, 640, 720, GetColor(0, 0, 255), TRUE);
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
		switch(GenreSelect::Selectgenre)
		{
			case 0:
			DrawGraph(700, 0, quiz[i].Img, TRUE);
			break;
			case 1:
			DrawGraph(700, 0, quiz2[y].Img, TRUE);
			break;
			case 2:
			DrawGraph(700, 0, quiz3[x].Img, TRUE);
			break;
		}
	}
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

	//if (Player::playerX + ( - 1 * Stage1X ) >= 1500)
	//{
	//	GameMain::NowStage = 2;
	//}
}

void Stage1::ChangeStage()
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
					DeleteSoundMem(Stage1BGM);
					StopSoundMem(Stage1BGM);

					GameMain::NowStage = 2; // 次のステージへ進む。
				}
				else
				{
					//ボタンが押された時SE再生
					PlaySoundMem(HazureSE, DX_PLAYTYPE_BACK, TRUE);
					//BGM削除
					DeleteSoundMem(Stage1BGM);
					StopSoundMem(Stage1BGM);

					GameMain::NowStage = 4;
				}
				S1DecisionToAnswerFlg = TRUE; // 回答を決定した状態にする
			}			
		}
		//Stage::NowStage = 2; 
	}
}

void Stage1::Initialize()
{
	quiz->X = 770;
	quiz->Y = 0;

	////アニメゲームのクイズ情報
	//quiz[0][i].Img = LoadGraph("image/Quiz/Anime&Game/AnimeGame1.png");
	//quiz[0][i].answer[0] = 0; //選択肢１
	//quiz[0][i].answer[1] = 0; //選択肢２
	//quiz[0][i].answer[2] = 1; //選択肢３
	//quiz[0][i].answer[3] = 0; //選択肢４
	////偉人のクイズ情報
	//quiz[1][y].Img = LoadGraph("image/Quiz/Greatman/Ijin1.png");
	//quiz[1][y].answer[0] = 0; //選択肢１
	//quiz[1][y].answer[1] = 0; //選択肢２
	//quiz[1][y].answer[2] = 1; //選択肢３
	//quiz[1][y].answer[3] = 0; //選択肢４
	////並び替えのクイズ情報
	//quiz[2][x].Img = LoadGraph("image/Quiz/WordExchange/WordExchange1.png");
	//quiz[2][x].answer[0] = 0; //選択肢１
	//quiz[2][x].answer[1] = 0; //選択肢２
	//quiz[2][x].answer[2] = 1; //選択肢３
	//quiz[2][x].answer[3] = 0; //選択肢４


	//switch (i)
	//{
	//case 0:
	//	quiz[0][0].Img = LoadGraph("image/Quiz/Anime&Game/AnimeGame1.png");
	//	quiz[0][0].answer[0] = 0; //選択肢１
	//	quiz[0][0].answer[1] = 0; //選択肢２
	//	quiz[0][0].answer[2] = 1; //選択肢３
	//	quiz[0][0].answer[3] = 0; //選択肢４
	//	break;
	//case 1:
	//	quiz[0][1].Img = LoadGraph("image/Quiz/Anime&Game/AnimeGame2.png");
	//	quiz[0][1].answer[0] = 0; //選択肢１
	//	quiz[0][1].answer[1] = 1; //選択肢２
	//	quiz[0][1].answer[2] = 0; //選択肢３
	//	quiz[0][1].answer[3] = 0; //選択肢４
	//	break;

	//case 2:
	//	quiz[0][2].Img = LoadGraph("image/Quiz/Anime&Game/AnimeGame3.png");
	//	quiz[0][2].answer[0] = 1; //選択肢１
	//	quiz[0][2].answer[1] = 0; //選択肢２
	//	quiz[0][2].answer[2] = 0; //選択肢３
	//	quiz[0][2].answer[3] = 0; //選択肢４
	//	break;

	//case 3:
	//	quiz[0][3].Img = LoadGraph("image/Quiz/Anime&Game/AnimeGame4.png");
	//	quiz[0][3].answer[0] = 0; //選択肢１
	//	quiz[0][3].answer[1] = 1; //選択肢２
	//	quiz[0][3].answer[2] = 0; //選択肢３
	//	quiz[0][3].answer[3] = 0; //選択肢４
	//	break;

	//case 4:
	//	quiz[0][4].Img = LoadGraph("image/Quiz/Anime&Game/AnimeGame5.png");
	//	quiz[0][4].answer[0] = 1; //選択肢１
	//	quiz[0][4].answer[1] = 0; //選択肢２
	//	quiz[0][4].answer[2] = 0; //選択肢３
	//	quiz[0][4].answer[3] = 0; //選択肢４
	//	break;

	//case 5:
	//	quiz[0][5].Img = LoadGraph("image/Quiz/Anime&Game/AnimeGame6.png");
	//	quiz[0][5].answer[0] = 0; //選択肢１
	//	quiz[0][5].answer[1] = 1; //選択肢２
	//	quiz[0][5].answer[2] = 0; //選択肢３
	//	quiz[0][5].answer[3] = 0; //選択肢４
	//	break;

	//case 6:
	//	quiz[0][6].Img = LoadGraph("image/Quiz/Anime&Game/AnimeGame7.png");
	//	quiz[0][6].answer[0] = 0; //選択肢１
	//	quiz[0][6].answer[1] = 1; //選択肢２
	//	quiz[0][6].answer[2] = 0; //選択肢３
	//	quiz[0][6].answer[3] = 0; //選択肢４		 
	//	break;


	//case 7:
	//	quiz[0][7].Img = LoadGraph("image/Quiz/Anime&Game/AnimeGame8.png");
	//	quiz[0][7].answer[0] = 0; //選択肢１
	//	quiz[0][7].answer[1] = 1; //選択肢２
	//	quiz[0][7].answer[2] = 0; //選択肢３
	//	quiz[0][7].answer[3] = 0; //選択肢４
	//	break;

	//case 8:
	//	quiz[0][8].Img = LoadGraph("image/Quiz/Anime&Game/AnimeGame9.png");
	//	quiz[0][8].answer[0] = 1; //選択肢１
	//	quiz[0][8].answer[1] = 0; //選択肢２
	//	quiz[0][8].answer[2] = 0; //選択肢３
	//	quiz[0][8].answer[3] = 0; //選択肢４
	//	break;

	//default:
	//	break;
	//}

	//switch (y)
	//{
	//case 0:

	//	quiz[1][0].Img = LoadGraph("image/Quiz/Greatman/Ijin1.png");
	//	quiz[1][0].answer[0] = 0; //選択肢１
	//	quiz[1][0].answer[1] = 0; //選択肢２
	//	quiz[1][0].answer[2] = 1; //選択肢３
	//	quiz[1][0].answer[3] = 0; //選択肢４
	//	break;
	//case 1:
	//	quiz[1][1].Img = LoadGraph("image/Quiz/Greatman/Ijin2.png");
	//	quiz[1][1].answer[0] = 0; //選択肢１
	//	quiz[1][1].answer[1] = 1; //選択肢２
	//	quiz[1][1].answer[2] = 0; //選択肢３
	//	quiz[1][1].answer[3] = 0; //選択肢４
	//	break;
	//case 2:
	//	quiz[1][2].Img = LoadGraph("image/Quiz/Greatman/Ijin3.png");
	//	quiz[1][2].answer[0] = 0; //選択肢１
	//	quiz[1][2].answer[1] = 0; //選択肢２
	//	quiz[1][2].answer[2] = 1; //選択肢３
	//	quiz[1][2].answer[3] = 0; //選択肢４
	//	break;
	//case 3:
	//	quiz[1][3].Img = LoadGraph("image/Quiz/Greatman/Ijin4.png");
	//	quiz[1][3].answer[0] = 0; //選択肢１
	//	quiz[1][3].answer[1] = 0; //選択肢２
	//	quiz[1][3].answer[2] = 1; //選択肢３
	//	quiz[1][3].answer[3] = 0; //選択肢４
	//	break;
	//case 4:

	//	quiz[1][4].Img = LoadGraph("image/Quiz/Greatman/Ijin5.png");
	//	quiz[1][4].answer[0] = 0; //選択肢１
	//	quiz[1][4].answer[1] = 0; //選択肢２
	//	quiz[1][4].answer[2] = 1; //選択肢３
	//	quiz[1][4].answer[3] = 0; //選択肢４
	//	break;
	//case 5:
	//	quiz[1][5].Img = LoadGraph("image/Quiz/Greatman/Ijin6.png");
	//	quiz[1][5].answer[0] = 1; //選択肢１
	//	quiz[1][5].answer[1] = 0; //選択肢２
	//	quiz[1][5].answer[2] = 0; //選択肢３
	//	quiz[1][5].answer[3] = 0; //選択肢４
	//	break;
	//case 6:
	//	quiz[1][6].Img = LoadGraph("image/Quiz/Greatman/Ijin7.png");
	//	quiz[1][6].answer[0] = 0; //選択肢１
	//	quiz[1][6].answer[1] = 1; //選択肢２
	//	quiz[1][6].answer[2] = 0; //選択肢３
	//	quiz[1][6].answer[3] = 0; //選択肢４
	//	break;
	//case 7:
	//	quiz[1][7].Img = LoadGraph("image/Quiz/Greatman/Ijin8.png");
	//	quiz[1][7].answer[0] = 0; //選択肢１
	//	quiz[1][7].answer[1] = 0; //選択肢２
	//	quiz[1][7].answer[2] = 0; //選択肢３
	//	quiz[1][7].answer[3] = 1; //選択肢４
	//	break;
	//case 8:
	//	quiz[1][8].Img = LoadGraph("image/Quiz/Greatman/Ijin9.png");
	//	quiz[1][8].answer[0] = 0; //選択肢１
	//	quiz[1][8].answer[1] = 1; //選択肢２
	//	quiz[1][8].answer[2] = 0; //選択肢３
	//	quiz[1][8].answer[3] = 0; //選択肢４
	//	break;
	//default:
	//	break;
	//}

	//switch (x)
	//{
	//case 0:
	//	quiz[2][0].Img = LoadGraph("image/Quiz/WordExchange/WordExchange1.png");
	//	quiz[2][0].answer[0] = 0; //選択肢１
	//	quiz[2][0].answer[1] = 0; //選択肢２
	//	quiz[2][0].answer[2] = 1; //選択肢３
	//	quiz[2][0].answer[3] = 0; //選択肢４
	//	break;
	//case 1:
	//	quiz[2][1].Img = LoadGraph("image/Quiz/WordExchange/WordExchange2.png");
	//	quiz[2][1].answer[0] = 0; //選択肢１
	//	quiz[2][1].answer[1] = 0; //選択肢２
	//	quiz[2][1].answer[2] = 0; //選択肢３
	//	quiz[2][1].answer[3] = 1; //選択肢４
	//	break;
	//case 2:
	//	quiz[2][2].Img = LoadGraph("image/Quiz/WordExchange/WordExchange3.png");
	//	quiz[2][2].answer[0] = 0; //選択肢１
	//	quiz[2][2].answer[1] = 0; //選択肢２
	//	quiz[2][2].answer[2] = 1; //選択肢３
	//	quiz[2][2].answer[3] = 0; //選択肢４

	//	break;
	//case 3:
	//	quiz[2][3].Img = LoadGraph("image/Quiz/WordExchange/WordExchange4.png");
	//	quiz[2][3].answer[0] = 1; //選択肢１
	//	quiz[2][3].answer[1] = 0; //選択肢２
	//	quiz[2][3].answer[2] = 0; //選択肢３
	//	quiz[2][3].answer[3] = 0; //選択肢４
	//	break;
	//case 4:
	//	quiz[2][4].Img = LoadGraph("image/Quiz/WordExchange/WordExchange5.png");
	//	quiz[2][4].answer[0] = 0; //選択肢１
	//	quiz[2][4].answer[1] = 0; //選択肢２
	//	quiz[2][4].answer[2] = 1; //選択肢３
	//	quiz[2][4].answer[3] = 0; //選択肢４
	//	break;
	//case 5:
	//	quiz[2][5].Img = LoadGraph("image/Quiz/WordExchange/WordExchange6.png");
	//	quiz[2][5].answer[0] = 0; //選択肢１
	//	quiz[2][5].answer[1] = 0; //選択肢２
	//	quiz[2][5].answer[2] = 0; //選択肢３
	//	quiz[2][5].answer[3] = 1; //選択肢４
	//	break;
	//case 6:
	//	quiz[2][6].Img = LoadGraph("image/Quiz/WordExchange/WordExchange7.png");
	//	quiz[2][6].answer[0] = 1; //選択肢１
	//	quiz[2][6].answer[1] = 0; //選択肢２
	//	quiz[2][6].answer[2] = 0; //選択肢３
	//	quiz[2][6].answer[3] = 0; //選択肢４
	//	break;
	//case 7:
	//	quiz[2][7].Img = LoadGraph("image/Quiz/WordExchange/WordExchange8.png");
	//	quiz[2][7].answer[0] = 0; //選択肢１
	//	quiz[2][7].answer[1] = 0; //選択肢２
	//	quiz[2][7].answer[2] = 1; //選択肢３
	//	quiz[2][7].answer[3] = 0; //選択肢４
	//	break;
	//case 8:
	//	quiz[2][8].Img = LoadGraph("image/Quiz/WordExchange/WordExchange9.png");
	//	quiz[2][8].answer[0] = 0; //選択肢１
	//	quiz[2][8].answer[1] = 0; //選択肢２
	//	quiz[2][8].answer[2] = 0; //選択肢３
	//	quiz[2][8].answer[3] = 1; //選択肢４
	//	break;
	//default:
	//	break;
	//}

	int i2 = i;
	int y2 = y;
	int x2 = x;


    if (GenreSelect::Selectgenre == 0)
    {
		for (int i = 0; i < 4; i++)
		{
			door[i].Img = LoadGraph("image/Dummy/DummyDoor.png");
			door[i].Y = 550;
			door[i].answer = quiz[i2].answer[i];
		}
	}
	else if (GenreSelect::Selectgenre == 1)
	{
		for (int i = 0; i < 4; i++)
		{
			door[i].Img = LoadGraph("image/Dummy/DummyDoor.png");
			door[i].Y = 550;
			door[i].answer = quiz2[y2].answer[i];
		}
	}
	else if (GenreSelect::Selectgenre == 2)
	{
		for (int i = 0; i < 4; i++)
		{
			door[i].Img = LoadGraph("image/Dummy/DummyDoor.png");
			door[i].Y = 550;
			door[i].answer = quiz3[x2].answer[i];
		}
	}
	

	block = new Block();
	Stage1Img = LoadGraph("image/Dummy/FirstStage(temporary).png");
	Stage1X = 0.0; // 最初の画像のX座標を0にする
	StopStage1Xflg = FALSE;
	TestImg = LoadGraph("image/Quiz/Anime&Game/AnimeGame1.png");
	GameMain::NowStage = 1;

	S1DecisionToAnswerFlg = FALSE; // 回答を決定していない状態にする
}