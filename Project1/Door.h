#pragma once

class Door
{
private:
	struct QUIZ
	{
		int Img;
		int x;
		int y;
		int Answer[4];
	};

	struct DOOR
	{
		int Img;
		int x;
		int y;
		int answer;
	};
public:
	Door();
	~Door();
	void Update();
	void Draw();

	QUIZ quiz[3];
	DOOR door[4];
};