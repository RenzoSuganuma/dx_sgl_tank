#if 0

//---------------------------------------------------------------------------------------------------------------
//
//
// [ ���� ] �L�[�{�[�h���͂����m�����{�I�T���v��
// 
//
//---------------------------------------------------------------------------------------------------------------


#include <time.h>
#include <string>
#include "../dxe/dxe.h"
#include "gm_main.h"

// �L�[���������ςȂ��ŃJ�E���g�A�b�v��������ϐ�
int on_keep_count_up_value = 0;

// �L�[�������ꂽ�u�Ԃ����J�E���g�A�b�v����ϐ�
int on_trigger_count_up_value = 0;

// �L�[�������ꂽ�u�Ԃ����J�E���g�A�b�v����ϐ�
int on_trigger_release_count_up_value = 0;

//------------------------------------------------------------------------------------------------------------
// �Q�[���N�����ɂP�x�������s����܂�
void gameStart() {
	srand(time(0));

	// �`�悳��镶����̃T�C�Y��ύX
	SetFontSize(50);
}



//------------------------------------------------------------------------------------------------------------
// ���t���[�����s����܂�
void gameMain(float delta_time) {

	// �������ςȂ������m
	if (tnl::Input::IsKeyDown(eKeys::KB_Z)) {
		on_keep_count_up_value++;
	}

	// �������u�Ԃ����m ( ���̊֐��ł������L�[�ɑΉ� )
	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_X, eKeys::KB_C)) {
		on_trigger_count_up_value++;
	}

	// �������u�Ԃ����m
	if (tnl::Input::IsKeyReleaseTrigger(eKeys::KB_V)) {
		on_trigger_release_count_up_value++;
	}


	DrawFormatString(0, 0, -1, "�������ςȂ�(Z�L�[) %d", on_keep_count_up_value);
	DrawFormatString(0, 50, -1, "�������u�� (X�L�[ �������� C�L�[) %d", on_trigger_count_up_value);
	DrawFormatString(0, 100, -1, "�������u�� (V�L�[) %d", on_trigger_release_count_up_value);


	dxe::DrawFpsIndicator({ 10, DXE_WINDOW_HEIGHT - 10 });
}


//------------------------------------------------------------------------------------------------------------
// �Q�[���I�����ɂP�x�������s����܂�
void gameEnd() {
}


#endif