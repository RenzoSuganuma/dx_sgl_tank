#pragma once
#include "gm_main.h"
#include "../dxe/dxe.h"
#include "../library/sgl/sgl_actor.h"
#include "../library/sgl/sgl_lang_extention.h"

// 戦車のクラス
class Tank final : public Actor {
public:
	DEF_Create_shared_ptr(Tank)
public:
	std::shared_ptr<dxe::Mesh> m_mesh;

	// モジュールの初期化
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
	// モジュールの更新
	void Update(float delta_time) override {

	}
	// モジュールの描画
	void Draw() override {
		m_mesh->render(camera);
	}
	// モジュールの内での解放
	void Release() override {

	}
	// モジュールの破棄
	void Finalize() override {

	}
};

