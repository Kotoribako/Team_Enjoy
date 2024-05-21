#pragma once
#include"AbstractScene.h"
#include"Player.h"
#include"Stage1.h"
#include"Stage2.h"
#include"Stage3.h"
#include"Enemy.h"
class GameMain :public AbstractScene
{
private:
	Player* player;
	Stage1* stage1;
	Stage2* stage2;
	Stage3* stage3;
	Enemy* enemy;
	int mouseX, mouseY;

	//bool IsHitCheck(Player* p, Block* b);
public:
	GameMain();
	virtual ~GameMain();
	virtual AbstractScene* Update() override;
	virtual void Draw() const override;

	static int NowStage; // 今もステージ

	void Initialize();  //ステージ遷移用の初期化処理

	
};