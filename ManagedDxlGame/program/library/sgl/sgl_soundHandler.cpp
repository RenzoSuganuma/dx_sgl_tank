#include "string"
#include "DxLib.h"
#include "sgl_soundHandler.h"

namespace sgl {
	std::unordered_map< std::string, int > soundHandlers;

	const void LoadSoundToMemory(const std::string filePath, const std::string soundKey)
	{
		int num = LoadSoundMem(filePath.c_str());
		soundHandlers.insert(std::make_pair(soundKey, num));
	}

	void PlaySoundFromMemory(const int soundHandler, const SoundPlayMode soundPlayMode)
	{
		int mode;
		switch (soundPlayMode)
		{
		case SoundPlayMode::Normal:
			mode = DX_PLAYTYPE_NORMAL;
			break;
		case SoundPlayMode::BackGround:
			mode = DX_PLAYTYPE_BACK;
			break;
		default:	// Loop
			mode = DX_PLAYTYPE_LOOP;
			break;
		}
		PlaySoundMem(soundHandler, mode);
	}

	void PlaySoundFromMemory(const std::string soundKey, const SoundPlayMode soundPlayMode) {
		int mode;
		switch (soundPlayMode)
		{
		case SoundPlayMode::Normal:
			mode = DX_PLAYTYPE_NORMAL;
			break;
		case SoundPlayMode::BackGround:
			mode = DX_PLAYTYPE_BACK;
			break;
		default:	// Loop
			mode = DX_PLAYTYPE_LOOP;
			break;
		}

		if (soundHandlers.find(soundKey) != soundHandlers.end()) {
			auto soundHandler = soundHandlers[soundKey];
			PlaySoundMem(soundHandler, mode);
		}
	}

}
