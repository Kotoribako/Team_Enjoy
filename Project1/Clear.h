#pragma once
#include "AbstractScene.h"

class Clear : public AbstractScene
{
private:
	int BackImg;
	int ClearImg;
	int ModoruImg;
	

	int S_FPS;
	int S_FPS1;
	int S_Seconas;
	int S_Seconas1;

public:
	Clear();
	~Clear();
	//
	AbstractScene* Update() override;

	//
	void Draw() const override;
};