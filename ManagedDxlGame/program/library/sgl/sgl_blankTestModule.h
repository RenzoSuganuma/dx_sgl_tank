#pragma once
#include "DxLib.h"
#include "sgl_actor.h"
#include "sgl_lang_extention.h"
class BlankTestModule : public Actor
{
public:
	DEF_Create_shared_ptr(BlankTestModule)
protected:
	// モジュールの初期化
	void initialize() override;
	// モジュールの更新
	void update(float delta_time) override;
	// モジュールの描画
	void draw() override;
	// モジュールの内での解放
	void release() override;
	// モジュールの破棄
	void finalize() override;
};

// モジュールの初期化
void BlankTestModule::initialize() {}
// モジュールの更新
void BlankTestModule::update(float delta_time) {
	DrawString(10, 10, "test__", -1);
}
// モジュールの描画
void BlankTestModule::draw() {}
// モジュールの内での解放
void BlankTestModule::release() {}
// モジュールの破棄
void BlankTestModule::finalize() {}
