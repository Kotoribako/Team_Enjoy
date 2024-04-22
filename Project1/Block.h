#pragma once
class Block
{
private:

public:
		float px;
		float px2;
		float py;
		float py2;
	typedef struct BLOCK
	{
		int X;  //ブロック左
		int X2; //ブロック右
		int Y;  //ブロック上
		int Y2; //ブロック下
	}BLOCK;
	struct BLOCK block[11];
	Block();
	~Block();
	void Update();
	void Draw();
	void PlayerStand();
};