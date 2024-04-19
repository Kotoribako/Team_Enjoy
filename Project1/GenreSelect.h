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
public:

	//int Genre[6][10];

	GenreSelect();
	virtual ~GenreSelect() {};
	virtual AbstractScene* Update() override;
	virtual void Draw() const override;
	void gSelect();
};

