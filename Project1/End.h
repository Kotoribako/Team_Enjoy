#pragma once
#include "AbstractScene.h"

class End : public AbstractScene
{
private:

public:
	End();
	~End();
	//
	AbstractScene* Update() override;

	//
	void Draw() const override;


};