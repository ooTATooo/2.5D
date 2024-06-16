#include "MapBackGround.h"

void MapBackGround::PostUpdate()
{
	BaseMap::PostUpdate();
}

void MapBackGround::Init()
{
	BaseMap::Init();
	m_tex = AssetManager::Instance().GetTex("MapBackGround");
	m_pos = { MinMap_X,MinMap_Y,0 };
	m_scale = { 1,1,1 };
}

void MapBackGround::DrawSprite()
{
	m_color = { 1.0f,1.0f,1.0f,0.7f };
	BaseMap::DrawSprite();
}
