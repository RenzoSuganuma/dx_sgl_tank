#pragma once
#include "list"
#include "string"
#include "unordered_map"
namespace sgl {

	// サウンド再生モード
	enum class SoundPlayMode {
		Normal,
		BackGround,
		Loop
	};

	extern std::unordered_map< std::string, int > soundHandlers;

	extern const void LoadSoundToMemory(const std::string filePath, const std::string soundKey);

	extern void PlaySoundFromMemory(const int soundHandler, const SoundPlayMode soundPlayMode = SoundPlayMode::BackGround);

	extern void PlaySoundFromMemory(const std::string soundKey, const SoundPlayMode soundPlayMode = SoundPlayMode::BackGround);

}

