#pragma once
#include "../library/sgl/sgl_actor.h"
#include "../library/sgl/sgl_lang_extention.h"

// 戦車のクラス
class Tank final : public Actor {
public:
	DEF_Create_shared_ptr(Tank)

	// モジュールの初期化
	void Initialize() override {
		m_name = "tank1";
	}
	// モジュールの更新
	void Update(float delta_time) override {

	}
	// モジュールの描画
	void Draw() override {

	}
	// モジュールの内での解放
	void Release() override {

	}
	// モジュールの破棄
	void Finalize() override {

	}
};

