#include "Block.h"
#include"Dxlib.h"
#include"Player.h"
#include"GameMain.h"
int Block::flg;
Block::Block()
{	
	switch (GameMain::NowStage)
	{
	case 1:
	case 4:
		//左、右、上、下
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
		break;
	case 2:
	case 5:
		          //左、右、上、下
		bloc[0] = { 0,455,565,720 };
		bloc[1] = { 500,565,450,493 };
		bloc[2] = { 613,676,345,390 };
		bloc[3] = { 769,795,338,380 };
		bloc[4] = { 840,865,400,440 };
		bloc[5] = { 911,937,459,500 };
		bloc[6] = { 987,1038,359,400 };
		bloc[7] = { 1008,1353,600,640 };
		bloc[8] = { 1193,1245,360,400 };
		bloc[9] = { 1295,1332,460,486 };
		bloc[10] = { 1312,1746,236,268 };
		bloc[11] = { 1376,1396,520,541 };
		bloc[12] = { 1443,1564,463,484 };
		bloc[13] = { 1528,1550,567, 588};
		bloc[14] = { 1570,1590,513,534 };
		bloc[15] = { 1621,1638,444,461 };
		bloc[16] = { 1702,1718,399,415 };
		bloc[17] = { 1773,1791,515,532 };
		bloc[18] = { 1881,2560,523,720 };
		break;
	case 3:
	case 6:
		//左、右、上、下
		bloc[0] = { 0,276,560,720 };
		bloc[1] = { 304,335,477,508 };
		bloc[2] = { 374,396,418,448 };
		bloc[3] = { 428,848,381,480 };
		bloc[4] = { 533,556,292,315 };
		bloc[5] = { 627,651,292,315 };
		bloc[6] = { 719,742,292,315 };
		bloc[7] = { 909,930,296,329 };
		bloc[8] = { 943,982,511,541 };
		bloc[9] = { 970,990,222,253 };
		bloc[10] = { 1035,1055,175,195 };
		bloc[11] = { 1040,1063,550,508 };
		bloc[12] = { 1121,1660,140,214 };
		bloc[13] = { 1121,1722,563,660 };
		bloc[14] = { 1176,1215,471,560 };
		bloc[15] = { 1589,1629,471,560 };
		bloc[16] = { 1732,1797,203,224 };
		bloc[17] = { 1759,1781,500,518 };
		bloc[18] = { 1830,1864,625,645 };
		bloc[19] = { 1878,1894,0,188 };
		bloc[20] = { 1873,1898,279,298 };
		//
		bloc[21] = { 1900,1911,587,604 };
		bloc[22] = { 1946,1957,532,551 };
		bloc[23] = { 1945,1957,656,676 };
		bloc[24] = { 1993,2005,621,639 };
		bloc[25] = { 2047,2062,587,596 };
		bloc[26] = { 2062,2560,561,720 };


		break;

	}
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
		//DrawBox(bloc[i].X, bloc[i].Y, bloc[i].X2, bloc[i].Y2, GetColor(255, 0, 0), TRUE);
		//DrawBox(bloc[i].X, bloc[i].Y, bloc[i].X2, bloc[i].Y+10, GetColor(255, 0, 0), TRUE); // 上のブロックの当たり判定()
		//DrawBox(bloc[i].X, bloc[i].Y2, bloc[i].X2, bloc[i].Y2+10, GetColor(0, 255, 0), TRUE); // 下のブロックの当たり判定(緑)
		//DrawBox(bloc[i].X, bloc[i].Y, bloc[i].X+10, bloc[i].Y2, GetColor(0, 0, 255), TRUE); // 左のブロックの当たり判定(青)
		//DrawBox(bloc[i].X2, bloc[i].Y, bloc[i].X2+10, bloc[i].Y2, GetColor(255, 0, 255), TRUE); // 右のブロックの当たり判定(紫)
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
