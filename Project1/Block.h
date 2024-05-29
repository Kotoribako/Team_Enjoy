#pragma once

/*typedef */struct BLOCK
{
	float X;  //ブロック左
	float X2; //ブロック右
	float Y;  //ブロック上
	float Y2; //ブロック下
};
/*static struct BLOCK */;

class Block
{
private:
	float px;
	float px2;
	float py;
	float py2;

public:
	static int flg;
	Block();
	~Block();
	void Update();
	void Draw();

	BLOCK S1bloc[11];
	BLOCK S2bloc[19];
	BLOCK S3bloc[27];
	/*void PlayerStand();*/
};