#pragma once
#include "list"
#include "memory"
#include "string"
#include "DxLib.h"
#include "../tnl_vector3.h"
#include "../tnl_quaternion.h"
#include "sgl_lang_extention.h"
#include "sgl_managableModules.h"
class Level;
class Component;
// ゲーム内のオブジェクトとして扱うクラスの基底クラスインスタンスはスマートポインタで
class Actor : public IManagableModule {
protected:
	std::list< Component* > m_components;
	tnl::Vector3 m_position{ 0 };
	tnl::Quaternion m_rotation;
	Level* m_placedLevel = nullptr;
	std::string m_name = "";
	bool m_enabled = true;
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
	AutoProperty(tnl::Vector3, Position, m_position)
		AutoProperty(tnl::Quaternion, Rotation, m_rotation)
		Getter(std::string, Name, m_name)
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
		auto it = getComponentFrom->m_components.begin();
		while (it != getComponentFrom->m_components.end())
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
