#pragma once

class Stage
{
private:
	int Stage1Image; // 1面の画像読み込み
	int Stage2Image; // ２面の画像読み込み
	int Stage3Image; // ３面の画像読み込み

	int BlockImage; // 分割読み込み用

	int NowStageNumber; // 今のステージ数

public:
	Stage();

	~Stage();

	void Update(); // 描画以外の更新処理を行う
	void Draw(); // 描画しているものを更新

	void MoveXStage(); // 横軸にステージを動かす
};
