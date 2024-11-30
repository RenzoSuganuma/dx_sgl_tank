#pragma once

// sglライブラリで管理できるモジュールすべてが継承すべきインタフェース
class IManagableModule {
	/* --- ユーザー定義モジュールでoverrideする関数 --- */
protected:
	// モジュールの初期化
	virtual void Initialize() = 0;
	// モジュールの更新
	virtual void Update(float delta_time) = 0;
	// モジュールの描画
	virtual void Draw() = 0;
	// モジュールの内での解放
	virtual void Release() = 0;
	// モジュールの破棄
	virtual void Finalize() = 0;

	/*
	// モジュールの初期化
	virtual void Initialize();
	// モジュールの更新
	virtual void Update(float delta_time);
	// モジュールの描画
	virtual void Draw();
	// モジュールの内での解放
	virtual void Release();
	// モジュールの破棄
	virtual void Finalize();
	*/
};