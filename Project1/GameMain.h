#pragma once
#include"AbstractScene.h"
#include"Player.h"
#include"Stage1.h"
class GameMain :public AbstractScene
{
private:
	Player* player;
	Stage1* stage1;
	Block* block;

	int mouseX, mouseY;

	//bool IsHitCheck(Player* p, Block* b);
public:
	GameMain();
	virtual ~GameMain();
	virtual AbstractScene* Update() override;
	virtual void Draw() const override;

	static int NowStage; // 今もステージ

	
};