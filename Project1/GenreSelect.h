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
	"ANIMEGAME",
	"EXCHANGE",
	"GREATMAN",
	"RANDOM"
	};

	int r; // 乱数の値
	int r2;// 乱数の値2
	int r3;// 乱数の値3
	int max; //乱数の下限値
	int min; //乱数の上限値
	
	int Genre1; //ジャンルの反映

	int Enter; // ジャンル決定

	int CauserX; //ジャンル選択用のカーソルX
	int CauserY; //ジャンル選択用のカーソルY
	int Causer;
	int input_margin;  
	int now_menu; 
	int MenuFont;

public:

	static int Selectgenre;
	int AnimeGame[3];
	int WordExchange[3];
	int ijin[3];
	int random[9];

	int Anime_Answer[3];
	int Ex_Answer[3];
	int ijin_Answer[3];
	//int Genre[6][10];
	GenreSelect();
	virtual ~GenreSelect() {};
	virtual AbstractScene* Update() override;
	virtual void Draw() const override;
};

