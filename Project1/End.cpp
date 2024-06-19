#include "DxLib.h"
#include "PadInput.h"
#include "End.h"
#include "Title.h"
#include "GameMain.h"

End::End()
{
	S_FPS = 0;
	S_Seconas = 0;
}

End::~End()
{

}

AbstractScene* End::Update()
{
	return nullptr;
}

void End::Draw() const
{

}
