#pragma once

class Help : public AbstractScene
{
private:
	int HelpImg;
	int ModoruImg;
	int BackgroundImg;       //画像

	int TitleBGM;       //タイトルBGM
	int MenuSE;         //決定音SE

	int S_FPS;
	int S_Seconas;

public:
	Help();
	~Help();
	//
	AbstractScene* Update() override;

	//
	void Draw() const override;


};