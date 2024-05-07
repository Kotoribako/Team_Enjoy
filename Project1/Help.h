#pragma once

class Help : public AbstractScene
{
private:
	int HelpImg;

public:
	Help();
	~Help();
	//
	AbstractScene* Update() override;

	//
	void Draw() const override;


};