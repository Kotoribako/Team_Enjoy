#pragma once

class Help : public AbstractScene
{
private:
	int helpImg;

public:
	Help();
	~Help();
	//
	AbstractScene* Update() override;

	//
	void Draw() const override;


};