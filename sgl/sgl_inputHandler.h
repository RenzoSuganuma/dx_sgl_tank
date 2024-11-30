#pragma once
#include "map"
#include "list"
#include "string"
#include "DxLib.h"
#include "tnl_vector3.h"
#include "sgl_component.h"

// 入力デバイスのタイプ
enum class InputDeviceType {
	Mouse,
	KeyBoard,
	GamePad,
	XInput,
};

// キーボードのキーの列挙型
enum class KeyboardKey : int {
	A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
	Num_1, Num_2, Num_3, Num_4, Num_5, Num_6, Num_7, Num_8, Num_9, Num_0,
	Tab, Shift, Ctrl, Alt, Space,
};

// 入力ハンドラー、入力デバイスからの入力処理を実行する。
class InputHandler final : public Component {
private:
#pragma region -キーボード入力まわり-
	// 入力立ち上がり
	bool started_[41]{ false };
	// 入力が１のとき
	bool performed_[41]{ false };
	// 入力立下り
	bool canceled_[41]{ false };
	// 入力が入っているフレーム数
	int performedFrames_[41]{ 0 };

	// キーボード入力受付処理
	void const CheckKeyboardInput();
	// 入力の 立ち上がり、立下りの入力を更新する
	void const CheckInputStarted();
	// 入力の立下りを調べて状態の更新をする	
	void const CheckInputCanceled();
#pragma endregion

public:
	const bool const GetInput(int inputAction, InputDeviceType inputType);
	const bool const GetInputStarted(const KeyboardKey key);
	const bool const GetInputPerformed(const KeyboardKey key);
	const bool const GetInputCanceled(const KeyboardKey key);
	// モジュールの初期化
	void Initialize() override;
	// モジュールの更新
	void Update(float delta_time) override;
	// モジュールの描画
	void Draw() override;
	// モジュールの内での解放
	void Release() override;
	// モジュールの破棄
	void Finalize() override;
};

