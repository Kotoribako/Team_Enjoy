#include "Door.h"
#include"Stage1.h"
DOOR::DOOR()
{
	for (int i = 0; i < 3; i++) {
		switch(i)
			case 0:
				quiz[0].Img = LoadGraph("image/Quiz/Anime&Game/AnimeGame1.png");
				quiz[0].X =
				quiz[0].Y =
				quiz[0].answer
	}
	
	for (int i = 0; i < 4; i++)
	{
		door[i].Img = LoadGraph("image/Dummy/DummyDoor.png");
		door[i].X = 1300 + Stage1::Stage1X + i * 80;
		door[i].Y = 550;
		door[i].answer = 
	}
	
}

DOOR::~DOOR()
{
}

void DOOR::Update()
{
}

void DOOR::Draw()
{
}
