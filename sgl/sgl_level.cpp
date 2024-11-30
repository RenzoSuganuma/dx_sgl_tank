#include "string"
#include "../dxe/dxe.h"
#include "DxLib.h"
#include "sgl_actor.h"
#include "sgl_level.h"

Level::Level() {}
Level::~Level() {}

void  Level::Initialize()
{
	auto itr = actors_.begin();
	while (itr != actors_.end())
	{
		(*itr)->__initialize();
		itr++;
	}
}

void  Level::Update(float deltaTime)
{
	auto itr = actors_.begin();
	while (itr != actors_.end())
	{
		(*itr)->__update(deltaTime);
		(*itr)->__draw();
		itr++;
	}
}

void  Level::Draw()
{
	auto itr = actors_.begin();
	while (itr != actors_.end())
	{
		(*itr)->__draw();
		itr++;
	}
}

void  Level::Finalize()
{
	auto it = actors_.begin();
	while (it != actors_.end())
	{
		(*it)->__finalize();
		++it;
	}
}

void  Level::Release()
{
	auto it = actors_.begin();
	while (it != actors_.end())
	{
		(*it)->__release();
		++it;
	}
	actors_.clear();
}

void Level::DrawActorList()
{
	std::string list;
	list += (std::to_string(actors_.size()) + "Actors\n");
	for (auto a : actors_) {
		list += (a->getName() + "\n");
	}
	DxLib::DrawString(DXE_WINDOW_WIDTH - 100, 100, list.c_str(), -1);
}

const std::list< Actor* >::iterator
const Level::AddActor(const Actor* obj)
{
	const_cast<Actor*>(obj)->SetPlacedLevel(this);
	actors_.emplace_back(const_cast<Actor*>(obj));
	auto it = actors_.end();
	it--;
	return it;
}

void const Level::RemoveActor(const Actor* obj)
{
	actors_.remove(const_cast<Actor*>(obj));
}

void const Level::RemoveActor(const std::list< Actor* >::iterator place)
{
	actors_.erase(place);
}
