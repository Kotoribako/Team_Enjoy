#pragma once
#include "AbstractScene.h"

//�^�C�g�����j���[
enum class TITLE_MENU
{
    GAME_START,
    HELP,
    RANKING,
    GAME_END,
    TITLE_SIZE
};

class Title : public AbstractScene
{
private:
    const char* menu_items[static_cast<int>(TITLE_MENU::TITLE_SIZE)] = {
    "START",
    "HELP",
    "RANKING",
    "END"
    };

    //int Select;     //�I��
    //int OldKey;		//�O�̓��̓L�[
    //int NowKey;		//���̓��̓L�[
    //int KeyFlg;		//���̓L�[���

    //bool Once;      //L�X�e�B�b�N�ŃJ�[�\���𓮂����p

    int TitleBGM;       //タイトルBGM
    int TitleImg;       //タイトル画像

    int MenuSE;         //決定音
    int CursorSE;       //カーソル移動音

    int now_menu;       //
    int MenuFont;       //
    int input_margin;   //

public:
    //
    Title();

    //
    ~Title();

    //
    AbstractScene* Update() override;

    //
    void Draw() const override;
};


