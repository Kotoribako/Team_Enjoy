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
		S1bloc[0] = { 0,270,630,720 };
		S1bloc[1] = { 340,440,565,615 };
		S1bloc[2] = { 475,555,510,555 };
		S1bloc[3] = { 510,555,470,510 };
		S1bloc[4] = { 580,735,420,455 };
		S1bloc[5] = { 780,845,365,415 };
		S1bloc[6] = { 875,940,310,360 };
		S1bloc[7] = { 950,1010,425,480 };
		S1bloc[8] = { 980,1035,235,290 };
		S1bloc[9] = { 1055,1120,350,410 };
		S1bloc[10] = { 1125,1700,610,720 };
		break;
	case 2:
	case 5:
		          //左、右、上、下
		S2bloc[0] = { 0,455,565,720 };
		S2bloc[1] = { 500,565,450,493 };
		S2bloc[2] = { 613,676,345,390 };
		S2bloc[3] = { 769,795,338,380 };
		S2bloc[4] = { 840,865,400,440 };
		S2bloc[5] = { 911,937,459,500 };
		S2bloc[6] = { 987,1038,359,400 };
		S2bloc[7] = { 1008,1353,600,640 };
		S2bloc[8] = { 1193,1245,360,400 };
		S2bloc[9] = { 1295,1332,460,486 };
		S2bloc[10] = { 1312,1746,236,268 };
		S2bloc[11] = { 1376,1396,520,541 };
		S2bloc[12] = { 1443,1564,463,484 };
		S2bloc[13] = { 1528,1550,567, 588};
		S2bloc[14] = { 1570,1590,513,534 };
		S2bloc[15] = { 1621,1638,444,461 };
		S2bloc[16] = { 1702,1718,399,415 };
		S2bloc[17] = { 1773,1791,515,532 };
		S2bloc[18] = { 1881,2560,523,720 };
		break;
	case 3:
	case 6:
		//左、右、上、下
		S3bloc[0] = { 0,276,560,720 };
		S3bloc[1] = { 304,335,477,508 };
		S3bloc[2] = { 374,396,418,448 };
		S3bloc[3] = { 428,848,381,480 };
		S3bloc[4] = { 533,556,292,315 };
		S3bloc[5] = { 627,651,292,315 };
		S3bloc[6] = { 719,742,292,315 };
		S3bloc[7] = { 909,930,296,329 };
		S3bloc[8] = { 943,982,511,541 };
		S3bloc[9] = { 970,990,222,253 };
		S3bloc[10] = { 1035,1055,175,195 };
		S3bloc[11] = { 1040,1063,550,508 };
		S3bloc[12] = { 1121,1660,140,214 };
		S3bloc[13] = { 1121,1722,563,660 };
		S3bloc[14] = { 1176,1215,471,560 };
		S3bloc[15] = { 1589,1629,471,560 };
		S3bloc[16] = { 1732,1797,203,224 };
		S3bloc[17] = { 1759,1781,500,518 };
		S3bloc[18] = { 1830,1864,625,645 };
		S3bloc[19] = { 1878,1894,0,188 };
		S3bloc[20] = { 1873,1898,279,298 };
		S3bloc[21] = { 1900,1911,587,604 };
		S3bloc[22] = { 1946,1957,532,551 };
		S3bloc[23] = { 1945,1957,656,676 };
		S3bloc[24] = { 1993,2005,621,639 };
		S3bloc[25] = { 2047,2062,587,596 };
		S3bloc[26] = { 2062,2560,561,720 };


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
