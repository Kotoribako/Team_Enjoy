#pragma once
#pragma once
#include "AbstractScene.h"

//�^�C�g�����j���[
enum class TITLE_MENU
{
    GAME_START,
    /*RANKING,
    HELP,*/
    GAME_END,
    TITLE_SIZE
};

class Title : public AbstractScene
{
private:
    const char* menu_items[static_cast<int>(TITLE_MENU::TITLE_SIZE)] = {
    "スタート",
    "エンド"
    };

    //int Select;     //�I��
    //int OldKey;		//�O�̓��̓L�[
    //int NowKey;		//���̓��̓L�[
    //int KeyFlg;		//���̓L�[���

    //bool Once;      //L�X�e�B�b�N�ŃJ�[�\���𓮂����p

    int TitleBGM;       //BGM
    int MenuSE;       //�I��SE�p
    //int TitleImg;     //�^�C�g���摜
    //int CursorImg;    //�J�[�\���摜

    int now_menu; //���ݑI����Ă郁�j���[
    int MenuFont; //���j���[�p�̃t�H���g
    int input_margin;  //���쎞�ԊԊu

public:
    //�R���X�g���N�^
    Title();

    //�f�X�g���N�^
    ~Title();

    //�`��ȊO�̍X�V����s
    AbstractScene* Update() override;

    //�`��Ɋւ��邱�Ƃ����
    void Draw() const override;
};


