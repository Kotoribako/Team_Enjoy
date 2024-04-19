#pragma once

class Stage1
{
private:

	int Stage1Img; //ステージ１画像
	//↑か↓のどちらかを使う
	int FloorImg; //床画像

	int BlockImg; //ブロック（障害物）画像（床画像を使うなら確実に使う）

	float Stage1X; // ステージのX座標のデータ

	int MoveFlgX; // 画像を左に動かすかどうか
	

public:
	static int NowStageNumber; //ステージ数の表示
	Stage1();

	~Stage1();

	void Update(); // �`��ȊO�̍X�V������s��
	void Draw(); // �`�悵�Ă����̂�X�V

	void MoveXStage(); // �����ɃX�e�[�W�𓮂���
};
