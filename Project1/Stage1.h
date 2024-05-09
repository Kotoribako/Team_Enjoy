#pragma once
#include"Block.h"
#include"GameMain.h"
class Stage1
{
private:

	Block* block;
	int Stage1Img; //ステージ１画像
	//↑か↓のどちらかを使う
	int FloorImg; //床画像

	int BlockImg; //ブロック（障害物）画像（床画像を使うなら確実に使う）

	int DoorImg;

	int TestImg;

	int janruImg[3];
	struct QUIZ
	{
		int Img;
		int X;
		int Y;
		int Answer[4]; //答え格納場所
	};

	typedef struct DOOR 
	{
		int Img;
		int X;
		int Y;
		int answer;
	};

public:

	static int StopStage1Xflg; // ステージの横が動いてるかどうか

	static float Stage1X; // ステージのX座標のデータ

	Stage1();

	~Stage1();

	void Update(); // 描画以外をアップデート
	void Draw(); // 描画をアップデート

	void MoveXStage(); // ステージ画像を横に移動するための関数
	DOOR door[4];
	QUIZ quiz[3];
};
