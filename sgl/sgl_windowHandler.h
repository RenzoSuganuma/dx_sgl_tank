#pragma once
#include "map"
namespace sgl::runtime::system {

	extern unsigned int windowWidth_;
	extern unsigned int windowHeigth_;
	extern unsigned int refreshRate_;
	extern bool changeWindowMode_;
	extern int quitKey_;

	extern void const SetScreenSize(unsigned int width, unsigned int height);

	extern  std::pair< unsigned int, unsigned int >
		const GetScreenSize();

	extern void const SetChangeWindowMode(bool cond);

	extern  const bool const GetChangeWindowMode();

	extern  void const SetRefreshRate(unsigned int rate);

	extern  const int const GetQuitKey();

	extern  void const SetQuitKey(int keyCode);

}

