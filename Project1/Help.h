#pragma once

class Help : public AbstractScene
{
private:

public:
	Help();
	~Help();
	//
	AbstractScene* Update() override;

	//
	void Draw() const override;


};