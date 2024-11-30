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
	auto it = m_components.begin();
	while (it != m_components.end())
	{
		(*it)->Initialize();
		it++;
	}
	m_enabled = true;
	Initialize();
}

void Actor::__update(float deltaTime)
{
	auto it = m_components.begin();
	while (it != m_components.end())
	{
		(*it)->Update(deltaTime);
		it++;
	}
	Update(deltaTime);
}

void Actor::__draw()
{
	auto it = m_components.begin();
	while (it != m_components.end())
	{
		(*it)->Draw();
		it++;
	}
	Draw();
}

void Actor::__release()
{
	auto it = m_components.begin();
	while (it != m_components.end())
	{
		(*it)->Release();
		it++;
	}
	m_components.clear();
	Release();
}

void Actor::__finalize()
{
	auto it = m_components.begin();
	while (it != m_components.end())
	{
		(*it)->Finalize();
		it++;
	}
	m_enabled = false;
	m_placedLevel = nullptr;
	Finalize();
}


std::list< Component* >::iterator
const Actor::AddComponent(Component* component)
{
	component->SetActor(this);
	m_components.emplace_back(component);
	auto it = m_components.end();
	it--;
	return it;
}

void const Actor::RemoveComponent(const std::list<Component*>::iterator place)
{
	m_components.erase(place);
}

void const Actor::SetPlacedLevel(const Level* level)
{
	m_placedLevel = const_cast<Level*>(level);
}
