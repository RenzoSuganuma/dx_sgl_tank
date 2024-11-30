#if 0


#include <time.h>
#include <string>
#include "../dxe/dxe.h"
#include "gm_main.h"
// sglライブラリ展開---
#include "../../sgl/sgl_level.h"
#include "../../sgl/sgl_actor.h"
#include "../../sgl/sgl_component.h"
// ゲーム変数宣言---
auto level = Level::CreateShared();
auto actor = Actor::CreateShared();
auto component = Component::CreateShared();

//------------------------------------------------------------------------------------------------------------
// ゲーム起動時に１度だけ実行されます
void gameStart() {
	srand(time(0));
	// ゲーム変数セットアップ---
	level->AddActor(actor.get());
	level->MainLoopEntry();
}


//------------------------------------------------------------------------------------------------------------
// 毎フレーム実行されます
void gameMain(float delta_time) {
	dxe::DrawFpsIndicator({ 10, DXE_WINDOW_HEIGHT - 10 });
	level->MainLoopUpdate(delta_time);
}


//------------------------------------------------------------------------------------------------------------
// ゲーム終了時に１度だけ実行されます
void gameEnd() {
	level->MainLoopExit();
}


#endif
