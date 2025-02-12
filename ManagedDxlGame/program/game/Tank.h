#pragma once
#include "gm_main.h"
#include "../dxe/dxe.h"
#include "../library/sgl/sgl_level.h"
#include "../library/sgl/sgl_actor.h"
#include "../library/sgl/sgl_lang_extention.h"
#include "../library/sgl/sgl_soundHandler.h"

// 戦車のクラス
class Tank final : public Actor {
private :
	std::string fireSFXName_ = "tank_fire_sfx";

public:
	DEF_Create_shared_ptr(Tank)
public:
	enum class eParts {
		Body,
		Burrel,
		BurrelBase,
		Max,
	};

	std::shared_ptr<dxe::Mesh> m_mesh[static_cast<int>(eParts::Max)];
	tnl::Vector3 m_partsSize[static_cast<int>(eParts::Max)] = { { 100,50,200 }, { 10,10,200 }, { 10,10,200 } };

	tnl::Vector3 m_partsOffset_pos[static_cast<int>(eParts::Max)];
	tnl::Quaternion m_partsOffset_rot[static_cast<int>(eParts::Max)];
	float barrel_rot[2]{ 0 }; // x,y

	// モジュールの初期化
	void Initialize() override {
		m_name = "Tank";

		// 効果音の読み込み
		sgl::LoadSoundToMemory(FILE_PATH_WAV_SE_SAMPLE_2, fireSFXName_);

		// ボディ
		m_mesh[static_cast<int>(eParts::Body)] = dxe::Mesh::CreateBoxMV(
			{ 100,50,200 }
			, dxe::Texture::CreateFromFile(FILE_PATH_BMP_BOX_LEFT)
			, dxe::Texture::CreateFromFile(FILE_PATH_BMP_BOX_RIGHT)
			, dxe::Texture::CreateFromFile(FILE_PATH_BMP_BOX_UP)
			, dxe::Texture::CreateFromFile(FILE_PATH_BMP_BOX_DOWN)
			, dxe::Texture::CreateFromFile(FILE_PATH_BMP_BOX_BACK)
			, dxe::Texture::CreateFromFile(FILE_PATH_BMP_BOX_FORWORD));

		// 砲身
		m_mesh[static_cast<int>(eParts::Burrel)] = dxe::Mesh::CreateCylinderMV(
			m_partsSize[static_cast<int>(eParts::Burrel)].x,
			m_partsSize[static_cast<int>(eParts::Burrel)].z
		);
		// 砲身ベース
		m_mesh[static_cast<int>(eParts::BurrelBase)] = dxe::Mesh::CreateBoxMV(
			{ 50,50,50 }
			, dxe::Texture::CreateFromFile(FILE_PATH_BMP_BOX_LEFT)
			, dxe::Texture::CreateFromFile(FILE_PATH_BMP_BOX_RIGHT)
			, dxe::Texture::CreateFromFile(FILE_PATH_BMP_BOX_UP)
			, dxe::Texture::CreateFromFile(FILE_PATH_BMP_BOX_DOWN)
			, dxe::Texture::CreateFromFile(FILE_PATH_BMP_BOX_BACK)
			, dxe::Texture::CreateFromFile(FILE_PATH_BMP_BOX_FORWORD));
		// Tex貼り付け
		m_mesh[static_cast<int>(eParts::Burrel)]->setTexture(dxe::Texture::CreateFromFile(FILE_PATH_JPG_TEST));
		m_mesh[static_cast<int>(eParts::BurrelBase)]->setTexture(dxe::Texture::CreateFromFile(FILE_PATH_JPG_TEST));

		// オフセット指定
		m_partsOffset_pos[static_cast<int>(eParts::Body)] = tnl::Vector3{ 0 };
		m_partsOffset_pos[static_cast<int>(eParts::Burrel)] =
			tnl::Vector3{ 0 ,
			m_partsSize[static_cast<int>(eParts::Body)].y * 0.5f + m_partsSize[static_cast<int>(eParts::Burrel)].x,
			m_partsSize[static_cast<int>(eParts::Burrel)].z * 0.5f
		};
		m_partsOffset_pos[static_cast<int>(eParts::BurrelBase)] =
			tnl::Vector3{ 0 ,
			m_partsSize[static_cast<int>(eParts::Body)].y * 0.5f + m_partsSize[static_cast<int>(eParts::Burrel)].x,
			0
		};
	}
	// モジュールの更新
	void Update(float delta_time) override {
		auto ind_barrel = static_cast<int>(eParts::Burrel);
		auto ind_body = static_cast<int>(eParts::Body);
		auto mesh_body = m_mesh[ind_body];
		auto mesh_barrel = m_mesh[ind_barrel];
		auto mesh_barrel_base = m_mesh[ind_barrel + 1];

		// 砲身の回転を計算
		m_partsOffset_rot[ind_barrel] =
			tnl::Quaternion::RotationAxis(
				tnl::Vector3::TransformCoord({ 1,0,0 }, m_rotation), tnl::ToRadian(90)
			);
		m_partsOffset_rot[ind_barrel + 1] =
			tnl::Quaternion::RotationAxis(
				tnl::Vector3::TransformCoord({ 1,0,0 }, m_rotation), tnl::ToRadian(90)
			);

		// 姿勢の計算
		mesh_body->setRotation(m_rotation * m_partsOffset_rot[ind_body]);
		// 砲身の姿勢計算
		// 砲身ワールドY軸
		tnl::Quaternion bar_rot_y = tnl::Quaternion::RotationAxis({ 0,1,0 }, barrel_rot[1]);
		// 砲身ワールド空間の基本姿勢の計算
		tnl::Quaternion bar_w_rot = m_rotation * m_partsOffset_rot[ind_barrel] * bar_rot_y;
		// 砲身ローカルX軸
		tnl::Quaternion bar_rot_x = tnl::Quaternion::RotationAxis(
			tnl::Vector3::TransformCoord({ 1 , 0, 0 }, bar_w_rot), barrel_rot[0]
		);
		mesh_barrel->setRotation(bar_w_rot * bar_rot_x);
		mesh_barrel_base->setRotation(bar_w_rot * bar_rot_x);

		// 位置計算
		mesh_body->setPosition(m_position + m_partsOffset_pos[ind_body]);

		float barr_x = m_partsOffset_pos[ind_barrel].x;
		float barr_y = m_partsOffset_pos[ind_barrel].y;
		float barr_z = m_partsOffset_pos[ind_barrel].z;
		mesh_barrel->setPosition(
			m_position + tnl::Vector3(0, barr_y, 0) + tnl::Vector3::TransformCoord
			({ 0,0,barr_z }, m_rotation * bar_rot_y * bar_rot_x));
		mesh_barrel_base->setPosition(
			m_position + tnl::Vector3(0, barr_y, 0) + tnl::Vector3::TransformCoord
			({ 0,0,0 }, m_rotation * bar_rot_y * bar_rot_x));


		// 移動処理
		if (!tnl::Input::IsMouseDown(eMouse::RIGHT)) {
			if (tnl::Input::IsKeyDown(eKeys::KB_W)) {
				m_position += tnl::Vector3::TransformCoord({ 0,0,1 }, m_rotation) * 3;
			}
			if (tnl::Input::IsKeyDown(eKeys::KB_S)) {
				m_position += tnl::Vector3::TransformCoord({ 0,0,-1 }, m_rotation) * 3;
			}
			if (tnl::Input::IsKeyDown(eKeys::KB_A)) {
				m_rotation *= m_rotation.RotationAxis({ 0,1,0 }, tnl::ToRadian(-1 * 3));
			}
			if (tnl::Input::IsKeyDown(eKeys::KB_D)) {
				m_rotation *= m_rotation.RotationAxis({ 0,1,0 }, tnl::ToRadian(1 * 3));
			}
		}

		// 発射
		if (tnl::Input::IsMouseTrigger(eMouseTrigger::IN_LEFT)) {
			sgl::PlaySoundFromMemory(fireSFXName_);
		}
	}
	// モジュールの描画
	void Draw() override {
		for (auto m : m_mesh) {
			m->render(m_placedLevel->mainCamera());
		}
	}
	// モジュールの内での解放
	void Release() override {
	}
	// モジュールの破棄
	void Finalize() override {

	}
};

