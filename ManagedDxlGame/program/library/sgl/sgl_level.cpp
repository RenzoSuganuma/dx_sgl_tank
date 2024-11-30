#include "string"
#include "../../dxe/dxe.h"
#include "DxLib.h"
#include "sgl_actor.h"
#include "sgl_level.h"

Level::Level() {}
Level::~Level() {}

void  Level::Initialize()
{
	m_camera = std::make_shared<FPSCamera>(DXE_WINDOW_WIDTH_F, DXE_WINDOW_HEIGHT_F);
	m_actors.emplace_back(m_camera.get());

	auto itr = m_actors.begin();
	while (itr != m_actors.end())
	{
		(*itr)->__initialize();
		itr++;
	}
}

void  Level::Update(float deltaTime)
{
	auto itr = m_actors.begin();
	while (itr != m_actors.end())
	{
		(*itr)->__update(deltaTime);
		(*itr)->__draw();
		itr++;
	}
}

void  Level::Draw()
{
	auto itr = m_actors.begin();
	while (itr != m_actors.end())
	{
		(*itr)->__draw();
		itr++;
	}
}

void  Level::Finalize()
{
	auto it = m_actors.begin();
	while (it != m_actors.end())
	{
		(*it)->__finalize();
		++it;
	}
}

void  Level::Release()
{
	auto it = m_actors.begin();
	while (it != m_actors.end())
	{
		(*it)->__release();
		++it;
	}
	m_actors.clear();
}

void Level::DrawActorList()
{
	auto count_str = (std::to_string(m_actors.size()) + "Actors");

	DxLib::DrawString(DXE_WINDOW_WIDTH - 200, 30, count_str.c_str(), -1);
	auto c = m_actors.begin();
	for (int i = 1; i <= m_actors.size(); i++) {
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
	m_actors.emplace_back(const_cast<Actor*>(obj));
	auto it = m_actors.end();
	it--;
	return it;
}

void const Level::RemoveActor(const Actor* obj)
{
	m_actors.remove(const_cast<Actor*>(obj));
}

void const Level::RemoveActor(const std::list< Actor* >::iterator place)
{
	m_actors.erase(place);
}
