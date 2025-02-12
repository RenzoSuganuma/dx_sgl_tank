#if 0

//---------------------------------------------------------------------------------------------------------------
//
//
// ベクトルの補間サンプル
//
//
//---------------------------------------------------------------------------------------------------------------

#include <time.h>
#include <string>
#include <numbers>
#include <functional>
#include "../dxe/dxe.h"
#include "gm_main.h"

Shared<dxe::Camera> camera = nullptr;
Shared<dxe::Mesh> mesh[6] = { nullptr };

tnl::Vector3 start_line[2] = { {-500, 0, -250}, { -250, 0, -500} };
tnl::Vector3 goal_line[2] = { {250, 0, 500}, { 500, 0, 250} };

tnl::Vector3 start[6];
tnl::Vector3 goal[6];

//------------------------------------------------------------------------------------------------------------
// ゲーム起動時に１度だけ実行されます
void gameStart() {
	srand(time(0));

	ChangeLightTypeDir(VGet(0.0f, -1.0f, 0.0f));
	SetBackgroundColor(32, 32, 32);


	camera = std::make_shared<dxe::Camera>(DXE_WINDOW_WIDTH, DXE_WINDOW_HEIGHT);
	camera->pos_ = { 400, 500, -500 };

	mesh[0] = dxe::Mesh::CreateSphereMV(25, 20, 20);
	mesh[0]->setTexture(dxe::Texture::CreateFromFile("resource/graphics/example/test.jpg"));
	for (int i = 1; i < 6; ++i) mesh[i] = mesh[0]->createClone();

	for (int i = 0; i < 6; ++i) {
		start[i] = start_line[0] + (start_line[1] - start_line[0]) / 6 * i;
		goal[i] = goal_line[0] + (goal_line[1] - goal_line[0]) / 6 * i;
	}

}

// 経過時間
float ct = 0;

//------------------------------------------------------------------------------------------------------------
// 毎フレーム実行されます
void gameMain(float delta_time) {

	float time_limit = 3.0f;

	mesh[0]->setPosition(tnl::Vector3::UniformLerp(start[0], goal[0], time_limit, ct));
	mesh[1]->setPosition(tnl::Vector3::SmoothLerp(start[1], goal[1], time_limit, ct));
	mesh[2]->setPosition(tnl::Vector3::SmoothLerp(start[2], goal[2], time_limit, ct, 1));
	mesh[3]->setPosition(tnl::Vector3::AccelLerp(start[3], goal[3], time_limit, ct));
	mesh[4]->setPosition(tnl::Vector3::AccelLerp(start[4], goal[4], time_limit, ct, 1));
	mesh[5]->setPosition(tnl::Vector3::DecelLerp(start[5], goal[5], time_limit, ct));

	camera->update();

	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) ct = 0;

	ct += delta_time;
	ct = (ct > time_limit) ? time_limit : ct;

	DrawFormatString(900, 0, -1, "経過時間 : %.2f", ct);
	DrawFormatString(900, 20, -1, "Enterキーでリセット");

	DrawGridGround(camera, 50, 20);

	DrawLine3DEx(camera, start_line[0], start_line[1], 0xffff00ff);
	DrawLine3DEx(camera, goal_line[0], goal_line[1], 0xffff00ff);

	for (int i = 0; i < 6; ++i) mesh[i]->render(camera);

	dxe::DrawFpsIndicator({ 10, DXE_WINDOW_HEIGHT - 10 });

}

//------------------------------------------------------------------------------------------------------------
// ゲーム終了時に１度だけ実行されます
void gameEnd() {

}

#endif