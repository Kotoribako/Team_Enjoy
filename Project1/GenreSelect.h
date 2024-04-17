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

	struct Genre1 {
		int img;
	};
	struct Genre1 genre1;

	struct Genre2 {
		int img;
	};
	struct Genre2 genre2;

	struct Genre3 {
		int img;
	};
	struct Genre3 genre3;

	struct Genre4 {
		int img;
	};
	struct Genre4 genre4;

	struct Genre5 {
		int img;
	};
	struct Genre5 genre5;

	struct Genre6 {
		int img;
	};
	struct Genre6 genre6;

	struct GenreRand {
		int img;
	};
	struct GenreRand genrerand;

	GenreSelect();
	virtual ~GenreSelect() {};
	virtual AbstractScene* Update() override;
	virtual void Draw() const override;
	void gSelect();
};

