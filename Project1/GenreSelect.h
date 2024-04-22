#pragma once
#include"AbstractScene.h"
class GenreSelect :public AbstractScene
{
private:
	int r; // 乱数の値
	int max; //乱数の下限値
	int min; //乱数の上限値
	int result; //乱数の結果
	int Select;// ジャンル選択
	int Genre1; //ジャンルの反映

	int AnimeGame1;
	int AnimeGame2;
	int AnimeGame3;
	int Quiz1[3] = { AnimeGame1,AnimeGame2,AnimeGame3 };

	int Quiz2[3];
	int Quiz3[3]; 
	int Quiz4[3];
	int Quiz5[3];
	int Quiz6[3];

public:

	//int Genre[6][10];

	GenreSelect();
	virtual ~GenreSelect() {};
	virtual AbstractScene* Update() override;
	virtual void Draw() const override;
	void gSelect();
	void greflection();
};

