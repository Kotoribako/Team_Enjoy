#include "Block.h"
#include"Dxlib.h"
#include"Player.h"
int Block::flg;
Block::Block()
{			  //左、右、上、下
	bloc[0] = { 0,270,630,720 };
	bloc[1] = { 340,440,565,615 };
	bloc[2] = { 475,555,510,555 };
	bloc[3] = { 510,555,470,510 };
	bloc[4] = { 580,735,420,455 };
	bloc[5] = { 780,845,365,415 };
	bloc[6] = { 875,940,310,360 };
	bloc[7] = { 950,1010,425,480 };
	bloc[8] = { 980,1035,235,290 };
	bloc[9] = { 1055,1120,350,410 };
	bloc[10] = { 1125,1700,610,720 };

}

Block::~Block()
{
}

void Block::Update()
{
	
	/*PlayerStand();*/
	/*px = Player::playerX + 15;
	px2 = Player::playerX2 - 15;
	py = Player::playerY;
	py2 = Player::playerY2;*/

}

void Block::Draw()
{
	/*DrawBox(px, py, px2, py2, GetColor(255, 0, 0), TRUE);*/
	for (int i = 0; i < 11; i++) {
		DrawBox(bloc[i].X, bloc[i].Y, bloc[i].X2, bloc[i].Y2, GetColor(255, 0, 0), TRUE);
	}
	//DrawFormatString(0, 70, GetColor(255, 0, 0), "Standflg:%d", flg);
}

//void Block::PlayerStand()
//{
//	if (px > block[0].X && px2 < block[0].X2 && py < block[0].Y) {
//		flg = 1;
//		Player::playerY = block[0].Y;
//	}
//}
