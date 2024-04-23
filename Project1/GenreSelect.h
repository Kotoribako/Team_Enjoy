#pragma once
#include"AbstractScene.h"
class GenreSelect :public AbstractScene
{
private:
	int r; // 乱数の値
	int max; //乱数の下限値
	int min; //乱数の上限値
	int result; //乱数の結果
	int Genre1; //ジャンルの反映

	int CauserX; //ジャンル選択用のカーソルX
	int CauserY; //ジャンル選択用のカーソルY
	int Causer;

	int Select[6]; // セレクト表示

	int AnimeGame1;
	int AnimeGame2;
	int AnimeGame3;

	int WordExchange1;
	int WordExchange2;
	int WordExchange3;



public:
	int Quiz1[3];
	int Quiz2[3];
	int Quiz3[3];
	int Quiz4[3];
	int Quiz5[3];
	int Quiz6[3];
	//int Genre[6][10];

	GenreSelect();
	virtual ~GenreSelect() {};
	virtual AbstractScene* Update() override;
	virtual void Draw() const override;
	void greflection();
};

