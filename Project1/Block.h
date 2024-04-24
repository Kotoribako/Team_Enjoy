#pragma once
class Block
{
private:
	float px;
	float px2;
	float py;
	float py2;

public:
	static int flg;
	typedef struct BLOCK
	{
		float X;  //ブロック左
		float X2; //ブロック右
		float Y;  //ブロック上
		float Y2; //ブロック下
	}BLOCK;
	 struct BLOCK block[11];
	Block();
	~Block();
	void Update();
	void Draw();
	/*void PlayerStand();*/
};