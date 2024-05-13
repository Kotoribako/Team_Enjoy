#include "Door.h"
#include"DxLib.h"
#include"GenreSelect.h"
#include"Stage1.h"
Door::Door()
{
	//アニメゲームのクイズ情報
	quiz[0].Img = LoadGraph("image/Quiz/Anime&Game/AnimeGame1.png");
	quiz[0].Answer[0] = 0; //選択肢１
	quiz[0].Answer[1] = 0; //選択肢２
	quiz[0].Answer[2] = 1; //選択肢３
	quiz[0].Answer[3] = 0; //選択肢４
	//偉人のクイズ情報
	quiz[1].Img = LoadGraph("image/Quiz/Greatman/Ijin1.png");
	quiz[1].Answer[0] = 0; //選択肢１
	quiz[1].Answer[1] = 0; //選択肢２
	quiz[1].Answer[2] = 1; //選択肢３
	quiz[1].Answer[3] = 0; //選択肢４
	//並び替えのクイズ情報
	quiz[2].Img = LoadGraph("image/Quiz/WordExchange/WordExchange1.png");
	quiz[2].Answer[0] = 0; //選択肢１
	quiz[2].Answer[1] = 0; //選択肢２
	quiz[2].Answer[2] = 1; //選択肢３
	quiz[2].Answer[3] = 0; //選択肢４
	for (int i = 0; i < 4; i++)
	{
		door[i].Img = LoadGraph("image/Dummy/DummyDoor.png");
		door[i].answer = quiz[GenreSelect::Selectgenre].Answer[i];
			door[i].x = 1300 + Stage1::Stage1X + i * 80;
			door[i].y = 550;
	}
}

Door::~Door()
{
}

void Door::Update()
{
	for (int i = 0; i < 4; i++)
	{
		door[i].x = 1300 + Stage1::Stage1X + i * 80;
		door[i].y = 550;
	}
}

void Door::Draw()
{
	for (int i = 0; i < 4; i++) {
		DrawGraph(/*1300 + Stage1X + i * 80, 550*/door[i].x, door[i].y, door[i].Img, TRUE);
	}
	if (GenreSelect::Selectgenre == 0) {
		DrawGraph(700, 0, quiz[0].Img, TRUE);
	}
	else if (GenreSelect::Selectgenre == 1)
	{
		DrawGraph(700, 0, quiz[1].Img, TRUE);
	}
	else if (GenreSelect::Selectgenre == 2)
	{
		DrawGraph(700, 0, quiz[2].Img, TRUE);
	}

}
