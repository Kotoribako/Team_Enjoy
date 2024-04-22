#include "Block.h"
#include"Dxlib.h"
#include"Player.h"
Block::Block()
{			  //左、右、上、下
	block[0] = { 0,270,630,720 };
	block[1] = { 340,440,565,615 };
	block[2] = { 475,555,510,555 };
	block[3] = { 510,555,470,510 };
	block[4] = { 580,735,420,455 };
	block[5] = { 780,845,365,415 };
	block[6] = { 875,940,310,360 };
	block[7] = { 950,1010,425,480 };
	block[8] = { 980,1035,235,290 };
	block[9] = { 1055,1120,350,410 };
	block[10] = { 1125,1700,610,720 };

}

Block::~Block()
{
}

void Block::Update()
{
	px  = Player::playerX;
	px2 = Player::playerX2;
	py  = Player::playerY;
	py2 = Player::playerY2;
	PlayerStand();
}

void Block::Draw()
{
	DrawBox(block[0].X, block[0].Y, block[0].X2, block[0].Y2, GetColor(255, 0, 0), TRUE);
	DrawBox(block[1].X, block[1].Y, block[1].X2, block[1].Y2, GetColor(255, 0, 0), TRUE);
	DrawBox(block[2].X, block[2].Y, block[2].X2, block[2].Y2, GetColor(255, 0, 0), TRUE);
	DrawBox(block[3].X, block[3].Y, block[3].X2, block[3].Y2, GetColor(255, 0, 0), TRUE);
	DrawBox(block[4].X, block[4].Y, block[4].X2, block[4].Y2, GetColor(255, 0, 0), TRUE);
	DrawBox(block[5].X, block[5].Y, block[5].X2, block[5].Y2, GetColor(255, 0, 0), TRUE);
	DrawBox(block[6].X, block[6].Y, block[6].X2, block[6].Y2, GetColor(255, 0, 0), TRUE);
	DrawBox(block[7].X, block[7].Y, block[7].X2, block[7].Y2, GetColor(255, 0, 0), TRUE);
	DrawBox(block[8].X, block[8].Y, block[8].X2, block[8].Y2, GetColor(255, 0, 0), TRUE);
	DrawBox(block[9].X, block[9].Y, block[9].X2, block[9].Y2, GetColor(255, 0, 0), TRUE);
	DrawBox(block[10].X, block[10].Y, block[10].X2, block[10].Y2, GetColor(255, 0, 0), TRUE);

}

void Block::PlayerStand()
{
	//if (px < block[0].X && px2 >  && PlayerY + 8 < MoveY - 15 && PlayerY + 68 > MoveY + 15 || //��
	//	PlayerX + 5 < MoveX + 20 && PlayerX + 57 > MoveX - 20 && PlayerY + 8 < MoveY - 15 && PlayerY + 68 > MoveY + 15 || //�E
	//	PlayerX + 5 < MoveX - 20 && PlayerX + 57 > MoveX + 20 && PlayerY + 8 < MoveY - 15 && PlayerY + 68 > MoveY - 15 || //��
		//PlayerX + 5 < MoveX - 20 && PlayerX + 57 > MoveX + 20 && PlayerY + 8 < MoveY + 15 && PlayerY + 68 > MoveY + 15) { //��
	if (py < block[0].Y) {
		py = block[0].Y;
	}
}
