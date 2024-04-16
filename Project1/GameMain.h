#pragma once
#include"AbstractScene.h"
#include"Player.h"
class GameMain :public AbstractScene
{
private:
	Player* player;
public:
	GameMain();
	virtual ~GameMain();
	virtual AbstractScene* Update() override;
	virtual void Draw() const override;
};