#include "Block.h"
#include"Dxlib.h"
#include"Player.h"
int Block::flg;
//struct Block::BLOCK block[11];
Block::Block()/*98787876re)/*:type(type),speed(0.0f),location(0.0f),box_size(0.0f)*/
{			  //左、右、上、下
	/*block[0] = { 0,270,630,720 };
	block[1] = { 340,440,565,615 };
	block[2] = { 475,555,510,555 };
	block[3] = { 510,555,470,510 };
	block[4] = { 580,735,420,455 };
	block[5] = { 780,845,365,415 };
	block[6] = { 875,940,310,360 };
	block[7] = { 950,1010,425,480 };
	block[8] = { 980,1035,235,290 };
	block[9] = { 1055,1120,350,410 };
	block[10] = { 1125,1700,610,720 };*/

	location = Vector2D(0.0f, 630.0f);
	box_size = Vector2D(270.0f, 90.0f);
	bx = location.x;
	bx2 = location.x + 270;
	by = location.y;
	by2 = location.y + 90;
}

Block::~Block()
{
}

void Block::Update(/*float speed*/)
{
	/*if(Player::)*/
	
	/*PlayerStand();*/
	/*px = Player::playerX + 15;
	px2 = Player::playerX2 - 15;
	py = Player::playerY;
	py2 = Player::playerY2;*/

}

void Block::Draw()
{

	//for (int i = 0; i < 11; i++) {
	//	DrawBox(block[i].X, block[i].Y, block[i].X2, block[i].Y2, GetColor(255, 0, 0), TRUE);
	//}
	DrawFormatString(0, 70, GetColor(255, 0, 0), "Standflg:%d", flg);
	DrawBox(bx,by, bx2,by2, GetColor(255, 0, 0), TRUE);
	DrawFormatString(0, 100, GetColor(255, 0, 0), "Boxsize.x:%f Boxsize.y:%f ", box_size.x,box_size.y);
}

Vector2D Block::GetLocation()const
{
	return location;
}

Vector2D Block::GetBoxSize()const
{
	return box_size;
}

//void Block::PlayerStand()
//{
//	if (px > block[0].X && px2 < block[0].X2 && py < block[0].Y) {
//		flg = 1;
//		Player::playerY = block[0].Y;
//	}
//}
