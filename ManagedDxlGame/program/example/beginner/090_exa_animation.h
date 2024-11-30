#if 0

//---------------------------------------------------------------------------------------------------------------
//
//
// [ ���� ] �A�j���[�V������{�T���v��
//
// �� �X�v���C�g�V�[�g�𕪊����[�h���ăA�j���[�V������`�悷��T���v���ł�
//
//
//---------------------------------------------------------------------------------------------------------------


#include <time.h>
#include <string>
#include "../dxe/dxe.h"
#include "gm_main.h"

// �A�j���[�V�����̍ő�t���[����
const int ANIM_FRAME_MAX = 4;

// ���[�h�����摜�����ʂ���n���h���ϐ��z��
// 1�̃t�@�C���ɕ����̊G���`���ꂽ�摜�f�[�^���X�v���C�g�V�[�g�Ƃ����܂�
// �X�v���C�g�V�[�g�̂��ꂼ��̊G�����[�h����ɂ͔z����g�p���܂�
int graphics_handle[ANIM_FRAME_MAX];

// ���ݍĐ����̃t���[����
int now_anim_frame = 0;

// �A�j���[�V�����̃t���[�����X�V����K�莞��
const float ANIM_FRAME_TIME = 0.25f;

// �A�j���[�V�����̃t���[�����X�V����ׂ̌o�ߎ��Ԃ����Z����ϐ�
float anim_time_count = 0;



//------------------------------------------------------------------------------------------------------------
// �Q�[���N�����ɂP�x�������s����܂�
void gameStart() {
	srand(time(0));
	SetFontSize(30);

	// �摜�t�@�C���̕������[�h
	// ! ���[�h�͏d�������Ń�����������܂��@�K�v�Ȏ��ɂP�x�������s���܂��傤 ( ���t���[�����s����Ȃ��悤�H�v���܂��傤 )
	// ��P����... �X�v���C�g�V�[�g�̃t�@�C���p�X
	// ��Q����... �S�̂̃t���[����
	// ��R����... �������̃t���[����
	// ��S����... �c�����̃t���[����
	// ��T����... �P�t���[��������̉����T�C�Y
	// ��U����... �P�t���[��������̍����T�C�Y
	// ��V����... ���[�h�����n���h�����i�[����z��
	LoadDivGraph("resource/graphics/example/c1_anim_down.png", 4, 4, 1, 32, 48, graphics_handle);

}


//------------------------------------------------------------------------------------------------------------
// ���t���[�����s����܂�
void gameMain(float delta_time) {

	// �A�j���[�V�����Đ��̎��Ԃ����Z
	anim_time_count += delta_time;

	// �t���[���̋K�莞�Ԃ𒴂����玟�̃t���[����`�悷��
	if (anim_time_count > ANIM_FRAME_TIME) {

		// �t���[�����X�V
		now_anim_frame++;

		// �ő�t���[���𒴂��Ȃ��悤�Ɍ��݂̃t���[�������ő吔�Ŋ������]��ŏ㏑������
		// �������邱�Ƃ� 0 ���� ( ANIM_FRAME_MAX - 1 ) �܂ł̒l�����[�v����
		now_anim_frame %= ANIM_FRAME_MAX;

		// �t���[��������̎��Ԃ����Z�b�g
		anim_time_count = 0;
	}


	// �`��Ɏw�肷��摜�n���h���͔z�񒆂� [ ���ݍĐ����̃t���[���ԍ� ] ���w�肷��
	// �� �T���v���p�ɑ�O�����łQ�{�Ɋg��`�悵�Ă��܂�
	DrawRotaGraph(600, 400, 2.0, 0, graphics_handle[now_anim_frame], true);


	dxe::DrawFpsIndicator({ 10, DXE_WINDOW_HEIGHT - 10 });
}


//------------------------------------------------------------------------------------------------------------
// �Q�[���I�����ɂP�x�������s����܂�
void gameEnd() {
}


#endif