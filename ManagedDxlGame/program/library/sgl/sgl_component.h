#pragma once
#include "memory"
#include "sgl_lang_extention.h"
#include "sgl_managableModules.h"
// 前方定義
class Actor;
// アクターへ機能を追加する際にこれに機能の実装をしてアクタへアタッチする
// コンポーネントクラスの基底クラス
class Component : public IManagableModule {
protected:
	const Actor* m_attachedActor = nullptr;

	// モジュールの初期化
	void __initialize();
	// モジュールの更新
	void __update(float delta_time);
	// モジュールの描画
	void __draw();
	// モジュール内での解放
	void __release();
	// モジュールの破棄
	void __finalize();
public:
	DEF_Create_shared_ptr(Component)
public:
	bool m_enabled = true;

	Component();
	~Component();

	static Component* Create() {
		return new Component;
	}

	// モジュールの初期化
	void Initialize();
	// モジュールの更新
	void Update(float delta_time);
	// モジュールの描画
	void Draw();
	// モジュールの内での解放
	void Release();
	// モジュールの破棄
	void Finalize();
	const Actor* const GetActor() const;
	void const SetActor(const Actor* actor);
};
