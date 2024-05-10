#pragma once
#include"DxLib.h"

class DOOR
{
private:

	struct Door
	{
		int Img;
		int X;
		int Y;
		int answer;
	};

	struct QUIZ
	{
		int Img;
		int X;
		int Y;
		int answer[4];
	};
public:
	DOOR();
	~DOOR();
	void Update();
	void Draw();

	Door door[4];
	QUIZ quiz[3];
};