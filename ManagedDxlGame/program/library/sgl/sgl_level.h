#pragma once
#include "list"
#include "memory"
#include "sgl_lang_extention.h"
#include "sgl_managableModules.h"
// 前方定義
class Actor;
// Unityでいうシーン、すべてのアクタが存在するクラス。（構造体でもいいかも）
struct Level final : IManagableModule {
private:
	std::list< Actor* > actors_;

public:
	Level();
	~Level();

	static Level* Create() {
		return new Level;
	}

	DEF_Create_shared_ptr(Level)

	void  Initialize();
	void  Update(float deltaTime);
	void  Draw();
	void  Finalize();
	void  Release();

	void DrawActorList();
	const std::list< Actor* >::iterator
		const AddActor(const Actor * obj);
	void const RemoveActor(const Actor * obj);
	void const RemoveActor(const std::list< Actor* >::iterator place);
};
