#pragma once

class Stage
{
private:
	int Stage1Image; // 1�ʂ̉摜�ǂݍ���
	int Stage2Image; // �Q�ʂ̉摜�ǂݍ���
	int Stage3Image; // �R�ʂ̉摜�ǂݍ���

	int BlockImage; // �����ǂݍ��ݗp

	int NowStageNumber; // ���̃X�e�[�W��

public:
	Stage();

	~Stage();

	void Update(); // �`��ȊO�̍X�V������s��
	void Draw(); // �`�悵�Ă����̂�X�V

	void MoveXStage(); // �����ɃX�e�[�W�𓮂���
};
