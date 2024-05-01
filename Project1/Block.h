#pragma once
#include"Vector2D.h"
class Block
{
private:
	//C++の範囲↓
	//bool is_active; //有効状態か
	int type;        //ブロックタイプ
	int image;      //画像データ
	Vector2D location; //位置座標
	Vector2D box_size; //当たり判定の大きさ
	float speed;
	//C++の範囲↑


	float bx;
	float bx2;
	float by;
	float by2;

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
	Block(/*int type*/);
	~Block();
	void Update(/*float speed*/);
	void Draw();
	/*void PlayerStand();*/

	//C++の範囲↓
	Vector2D GetLocation()const;
	Vector2D GetBoxSize()const;
	//C++の範囲↑
};