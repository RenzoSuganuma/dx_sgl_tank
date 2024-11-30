#pragma once
#include "list"
#include "string"
namespace sgl::runtime::system {

	// サウンド再生モード
	extern enum class SoundPlayMode {
		Normal,
		BackGround,
		Loop
	};

	extern std::list< int > soundHandlers;

	extern const int LoadSoundToMemory(const std::string filePath);

	extern void PlaySoundFromMemory(const int soundHandler, const SoundPlayMode soundPlayMode);

}

