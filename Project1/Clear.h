#pragma once
#include "AbstractScene.h"

class Clear : public AbstractScene
{
private:
	int ClearImg;
	int BackImg;

public:
	Clear();
	~Clear();
	//
	AbstractScene* Update() override;

	//
	void Draw() const override;


};