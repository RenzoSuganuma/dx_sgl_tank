#include "DxLib.h"
#include "sgl_actor.h"
#include "sgl_component.h"

Component::Component() {}
Component::~Component() {}

#pragma region virtual-functions
void Component::Initialize() {}
void Component::Update(float deltaTime) {}
void Component::Finalize() {}
void Component::Release() {}
void Component::Draw() {}
#pragma endregion

void Component::__initialize()
{
	enabled_ = true;
	Initialize();
}

void Component::__update(float deltaTime)
{
	Update(deltaTime);
}

void Component::__finalize()
{
	attachedActor_ = nullptr;
	enabled_ = false;
	Finalize();
}

void Component::__draw()
{
	Draw();
}

void Component::__release()
{
	Release();
}

const Actor* const Component::GetActor() const
{
	return attachedActor_;
}

void const Component::SetActor(const Actor* actor)
{
	attachedActor_ = actor;
}

