#include "Map.h"

void Map::Init()
{
	m_model.Load("Asset/Models/Cobblestone/Cobblestone.gltf");
}

void Map::DrawLit()
{
	KdShaderManager::Instance().m_StandardShader.DrawModel(m_model);
}
