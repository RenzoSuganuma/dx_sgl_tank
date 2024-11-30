#if 1


#include <time.h>
#include <string>
#include "../dxe/dxe.h"
#include "gm_main.h"
// sglライブラリ展開---
#include "../library/sgl/sgl_actor.h"
#include "../library/sgl/sgl_level.h"
// 展開
#include "Tank.h"
// ゲーム変数宣言---
auto level = Level::CreateShared();
auto player = Tank::CreateShared();

void placeActorToLevel() {
	level->AddActor(player.get());
}

//------------------------------------------------------------------------------------------------------------
// ゲーム起動時に１度だけ実行されます
void gameStart() {
	srand(time(0));
	placeActorToLevel();
	level->Initialize();
}


//------------------------------------------------------------------------------------------------------------
// 毎フレーム実行されます
void gameMain(float delta_time) {
	level->Update(delta_time);
}

// 毎フレームコールされる。 描画処理
void gameRender() {
	dxe::DrawGridGround(level->mainCamera(), 50, 20, -1);
	dxe::DrawFpsIndicator({ 10, DXE_WINDOW_HEIGHT - 10 });
	level->Draw();
	level->DrawActorList();
}


//------------------------------------------------------------------------------------------------------------
// ゲーム終了時に１度だけ実行されます
void gameEnd() {
	level->Finalize();
	level->Release();
}


#endif
