#include "GenreSelect.h"
#include<stdlib.h>
#include<time.h>
#include <DxLib.h>
#include"PadInput.h"
GenreSelect::GenreSelect()
{
	r = 0;
	max = 6;
	min = 1;
	result = 0;
	Select = 0;

	Genre1 = 0;
	
}


AbstractScene* GenreSelect::Update()
{
	gSelect();
	greflection();
	srand((unsigned)time(NULL)); // 乱数の仕組みの初期化

	r = (rand() % (max - min + 1)) + min;
	result = r;
	return this;
}

void GenreSelect::Draw() const
{



	if (result == 1) {
		DrawFormatString(200, 200, GetColor(255, 255, 255), "1", result);
	}
	else if (result == 2) {
		DrawFormatString(200, 200, GetColor(255, 255, 255), "2", result);

	}
	else if (result == 3) {
		DrawFormatString(200, 200, GetColor(255, 255, 255), "3", result);

	}
	else if (result == 4) {
		DrawFormatString(200, 200, GetColor(255, 255, 255), "4", result);

	}
	else if (result == 5) {
		DrawFormatString(200, 200, GetColor(255, 255, 255), "5", result);

	}
	else if (result == 6) {
		DrawFormatString(200, 200, GetColor(255, 255, 255), "6", result);

	}
}

void GenreSelect::gSelect()
{
	int x = 0;
	if (CheckHitKey(KEY_INPUT_DOWN)|| PAD_INPUT::GetLStick().ThumbY)
	{
		if (Select <= 6) {
			Select += 1;
		}
	}
	else if (CheckHitKey(KEY_INPUT_UP)|| PAD_INPUT::GetLStick().ThumbY)
	{
		if (Select >= 1) {
			Select -= 1;
		}
	}

	if (CheckHitKey(KEY_INPUT_3)) 
	{
		Genre1 = Select;
	}
}

void GenreSelect::greflection()
{
	int y{};

	if (Genre1 == 1)
	{

	}
	else if (Genre1 == 2)
	{

	}
	else if (Genre1 == 3)
	{

	}
	else if (Genre1 == 4)
	{

	}
	else if (Genre1 == 5) 
	{

	}
	else if (Genre1 == 6)
	{

	}

}
