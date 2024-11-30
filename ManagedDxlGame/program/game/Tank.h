#pragma once
#include "gm_main.h"
#include "../dxe/dxe.h"
#include "../library/sgl/sgl_actor.h"
#include "../library/sgl/sgl_lang_extention.h"

// ��Ԃ̃N���X
class Tank final : public Actor {
public:
	DEF_Create_shared_ptr(Tank)
public:
	std::shared_ptr<dxe::Mesh> m_mesh;

	// ���W���[���̏�����
	void Initialize() override {
		m_name = "tank1";
		m_mesh = dxe::Mesh::CreateBoxMV(
			{ 10,5,5 }
			, dxe::Texture::CreateFromFile(FILE_PATH_BMP_BOX_LEFT)
			, dxe::Texture::CreateFromFile(FILE_PATH_BMP_BOX_RIGHT)
			, dxe::Texture::CreateFromFile(FILE_PATH_BMP_BOX_UP)
			, dxe::Texture::CreateFromFile(FILE_PATH_BMP_BOX_DOWN)
			, dxe::Texture::CreateFromFile(FILE_PATH_BMP_BOX_BACK)
			, dxe::Texture::CreateFromFile(FILE_PATH_BMP_BOX_FORWORD));
	}
	// ���W���[���̍X�V
	void Update(float delta_time) override {

	}
	// ���W���[���̕`��
	void Draw() override {
		m_mesh->render(camera);
	}
	// ���W���[���̓��ł̉��
	void Release() override {

	}
	// ���W���[���̔j��
	void Finalize() override {

	}
};

