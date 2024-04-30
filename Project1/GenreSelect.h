#pragma once
#include"AbstractScene.h"

enum class SELECT
{
	ANIMEGAME,
	WORDEXCHANGE,
	GREATMAN,
	RANDOMSELECT,
	SELECT_SIZE

};

class GenreSelect :public AbstractScene
{
private:

	const char* select_items [static_cast<int>(SELECT::SELECT_SIZE)] = {
	"GAME",
	"QUIZ",
	"GREAT",
	"RANDOM"
	};

	int r; // 乱数の値
	int r2;// 乱数の値2
	int r3;// 乱数の値3
	int max; //乱数の下限値
	int min; //乱数の上限値
	int result; //乱数の結果
	int result2;//乱数の結果2
	int result3;//乱数の結果3
	int Genre1; //ジャンルの反映

	int Enter; // ジャンル決定

	int CauserX; //ジャンル選択用のカーソルX
	int CauserY; //ジャンル選択用のカーソルY
	int Causer;
	int input_margin;  
	int now_menu; 
	int MenuFont; 


	int AnimeGame[3];
	int WordExchange[3];
	int ijin[3];

public:

	int Quiz1[3];
	int Quiz2[3];
	int Quiz3[3];
	int Quiz4[3];
	
	//int Genre[6][10];

	GenreSelect();
	virtual ~GenreSelect() {};
	virtual AbstractScene* Update() override;
	virtual void Draw() const override;
	void greflection();
};

