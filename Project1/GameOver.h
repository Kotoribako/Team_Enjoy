#pragma once
#pragma once
#include "AbstractScene.h"

class GameOver : public AbstractScene
{
private:
	int BackImg;
	int GameOverImg;
	int ModoruImg;

	int S_FPS;
	int S_FPS1;
	int S_Seconas;
	int S_Seconas1;

public:
	GameOver();
	~GameOver();
	
	AbstractScene* Update() override;

	void Draw() const override;
};