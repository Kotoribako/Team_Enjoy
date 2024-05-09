#pragma once
class Enemy
{
private:

	int img;
	int enemyX, enemyY;
	int enemyX2, enemyY2;
	int count;
	int Hitflg;
	int speed;
public:
	Enemy();
	void Update();
	void Draw();
	void Enemyhit();
};

