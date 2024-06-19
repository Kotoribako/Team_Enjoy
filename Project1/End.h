#pragma once
#include "AbstractScene.h"

class End : public AbstractScene
{
private:

	int EndImg;       //画像
	int ThankImg;       //画像

	int S_FPS;
	int S_Seconas;

public:
	End();
	~End();
	//
	AbstractScene* Update() override;

	//
	void Draw() const override;


};