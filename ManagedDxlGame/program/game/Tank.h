#pragma once
#include "../library/sgl/sgl_actor.h"
#include "../library/sgl/sgl_lang_extention.h"

// ��Ԃ̃N���X
class Tank final : public Actor {
public:
	DEF_Create_shared_ptr(Tank)

	// ���W���[���̏�����
	void Initialize() override {
		m_name = "tank1";
	}
	// ���W���[���̍X�V
	void Update(float delta_time) override {

	}
	// ���W���[���̕`��
	void Draw() override {

	}
	// ���W���[���̓��ł̉��
	void Release() override {

	}
	// ���W���[���̔j��
	void Finalize() override {

	}
};

