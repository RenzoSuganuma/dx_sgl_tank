#pragma once
#include "memory"
#include "../library/sgl/sgl_fpsCamera.h"

 std::shared_ptr<FPSCamera> camera;

void gameStart();
void gameMain( float delta_time );
void gameRender();
void gameEnd();
