#if 0

//---------------------------------------------------------------------------------------------------------------
//
//
// 3D スタートアップサンプル
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
Shared<dxe::Mesh> mesh = nullptr;
Shared<dxe::Texture> texture = nullptr;


//------------------------------------------------------------------------------------------------------------
// ゲーム起動時に１度だけ実行されます
void gameStart() {
	srand(time(0));

	SetFogEnable(true);
	SetFogColor(32, 32, 32);
	SetFogStartEnd(500.0f, 1500.0f);
	ChangeLightTypeDir(VGet(0.0f, -1.0f, 0.0f));
	SetBackgroundColor(32, 32, 32);


	camera = std::make_shared<dxe::Camera>(DXE_WINDOW_WIDTH_F, DXE_WINDOW_HEIGHT_F);

	texture = dxe::Texture::CreateFromFile("resource/graphics/example/test.jpg");

	mesh = dxe::Mesh::CreateSphereMV(100, 20, 20);
	mesh->setTexture(texture);

}


//------------------------------------------------------------------------------------------------------------
// 毎フレーム実行されます
void gameMain(float delta_time) {

	mesh->mulRotation(tnl::Quaternion::RotationAxis({ 0, 1, 0 }, tnl::ToRadian(1)));

	camera->update();


	DrawGridGround(camera, 50, 20);

	mesh->render(camera);
	mesh->drawGuiMaterialControlloer();

	dxe::DrawFpsIndicator({ 10, DXE_WINDOW_HEIGHT - 10 });

}

//------------------------------------------------------------------------------------------------------------
// ゲーム終了時に１度だけ実行されます
void gameEnd() {

}

#endif