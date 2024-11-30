#include "DxLib.h"
#include "sgl_actor.h"
#include "sgl_component.h"
#include "sgl_level.h"

Actor::Actor() {}
Actor::~Actor() {}

#pragma region virtual-funcitons
void Actor::Initialize() {}
void Actor::Update(float deltaTime) {}
void Actor::Release() {}
void Actor::Finalize() {}
void Actor::Draw() {}
#pragma endregion

void Actor::__initialize()
{
	auto it = components_.begin();
	while (it != components_.end())
	{
		(*it)->Initialize();
		it++;
	}
	enabled_ = true;
	Initialize();
}

void Actor::__update(float deltaTime)
{
	auto it = components_.begin();
	while (it != components_.end())
	{
		(*it)->Update(deltaTime);
		it++;
	}
	Update(deltaTime);
}

void Actor::__draw()
{
	auto it = components_.begin();
	while (it != components_.end())
	{
		(*it)->Draw();
		it++;
	}
	Draw();
}

void Actor::__release()
{
	auto it = components_.begin();
	while (it != components_.end())
	{
		(*it)->Release();
		it++;
	}
	components_.clear();
	Release();
}

void Actor::__finalize()
{
	auto it = components_.begin();
	while (it != components_.end())
	{
		(*it)->Finalize();
		it++;
	}
	enabled_ = false;
	placedLevel_ = nullptr;
	Finalize();
}


std::list< Component* >::iterator
const Actor::AddComponent(Component* component)
{
	component->SetActor(this);
	components_.emplace_back(component);
	auto it = components_.end();
	it--;
	return it;
}

void const Actor::RemoveComponent(const std::list<Component*>::iterator place)
{
	components_.erase(place);
}

void const Actor::SetPlacedLevel(const Level* level)
{
	placedLevel_ = const_cast<Level*>(level);
}
