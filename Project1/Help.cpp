#include "DxLib.h"
#include "PadInput.h"
#include "Title.h"
#include "Help.h"

Help::Help()
{

}

Help::~Help()
{

}

AbstractScene* Help::Update()
{
	return this;
}

void Help::Draw() const
{
	SetFontSize(100);
	DrawFormatString(500, 300, 0xffffff, "Help");
}
