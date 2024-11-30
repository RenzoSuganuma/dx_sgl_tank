#include "string"
#include "../../dxe/dxe.h"
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
	auto count_str = (std::to_string(actors_.size()) + "Actors");

	DxLib::DrawString(DXE_WINDOW_WIDTH - 200, 30, count_str.c_str(), -1);
	auto c = actors_.begin();
	for (int i = 1; i <= actors_.size(); i++) {
		DxLib::DrawString(DXE_WINDOW_WIDTH - 200, 50 + (15 * i),
			(std::to_string(i) + ":" + (*c)->getName()).c_str()
			, -1);
		c++;
	}

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
