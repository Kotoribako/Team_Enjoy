#pragma once
#include "AbstractScene.h"

class Clear : public AbstractScene
{
private:
	int ClearImg;
	int BackImg;

	int S_FPS;
	int S_Seconas;

public:
	Clear();
	~Clear();
	//
	AbstractScene* Update() override;

	//
	void Draw() const override;


};