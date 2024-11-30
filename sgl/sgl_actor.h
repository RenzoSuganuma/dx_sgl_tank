#pragma once
#include "list"
#include "memory"
#include "string"
#include "DxLib.h"
#include "tnl_vector3.h"
#include "tnl_quaternion.h"
#include "sgl_lang_extention.h"
#include "sgl_managableModules.h"
class Level;
class Component;
// ゲーム内のオブジェクトとして扱うクラスの基底クラスインスタンスはスマートポインタで
class Actor : public IManagableModule {
protected:
	std::list< Component* > components_;
	tnl::Vector3 position_{ 0 };
	tnl::Quaternion rotation_;
	Level* placedLevel_ = nullptr;
	std::string name_ = "";
	bool enabled_ = true;
	/* virtual functions FOR override */
	// モジュールの初期化
	virtual void Initialize();
	// モジュールの更新
	virtual void Update(float delta_time);
	// モジュールの描画
	virtual void Draw();
	// モジュールの内での解放
	virtual void Release();
	// モジュールの破棄
	virtual void Finalize();
	/* auto properties */
public:
	AutoProperty(tnl::Vector3, Position, position_)
		AutoProperty(tnl::Quaternion, Rotation, rotation_)
		Getter(std::string, Name, name_)
		DEF_Create_shared_ptr(Actor)
public:

	Actor();
	~Actor();

	// モジュールの初期化
	void __initialize();
	// モジュールの更新
	void __update(float delta_time);
	// モジュールの描画
	void __draw();
	// モジュール内での解放
	void __release();
	// モジュールの破棄
	void __finalize();

	/* statics */
	//
	static Actor* Create() {
		return new Actor;
	}

	std::list< Component* >::iterator
		const AddComponent(Component* component);
	void const RemoveComponent(const std::list<Component*>::iterator place);
	void const SetPlacedLevel(const Level* level);
	/* templates */
	//
	template<typename T>
	static T GetComponent(const Actor* getComponentFrom)
	{
		auto it = getComponentFrom->components_.begin();
		while (it != getComponentFrom->components_.end())
		{
			auto r = static_cast<T>(*it);
			if (r != nullptr)
			{
				return r;
				break;
			}
			it++;
		}
		return nullptr;
	}
};
