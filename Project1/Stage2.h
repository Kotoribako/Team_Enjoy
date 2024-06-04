#pragma once

#pragma once
#include"Block.h"
class Stage2
{
private:
	struct Door
	{
		int Img;
		int X;
		int Y;
		int answer;
	};
	struct Door door[4];

	struct QUIZ
	{
		int Img;
		int X;
		int Y;
		int answer[4];
	};
	struct QUIZ quiz[3];
	Block* block;
	int Stage2Img; //ステージ2画像
	//↑か↓のどちらかを使う
	int FloorImg; //床画像

	int BlockImg; //ブロック（障害物）画像（床画像を使うなら確実に使う）

	int Stage2BGM;
	int SeikaiSE;
	int HazureSE;

	int TestImg;

	int janruImg[3];

public:

	static int StopStage2Xflg; // ステージの横が動いてるかどうか

	static float Stage2X; // ステージのX座標のデータ

	static int S2DecisionToAnswerFlg; // ステージ１の答えを決定したかどうか確認するフラグ

	Stage2();

	~Stage2();

	void Update(); // 描画以外をアップデート
	void Draw(); // 描画をアップデート

	void MoveXStage(); // ステージ画像を横に移動するための関数

	void ChangeStage(); // ステージ遷移

	void Initialize(); // ステージ初期化
};
