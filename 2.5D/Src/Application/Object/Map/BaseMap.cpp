#include "BaseMap.h"

void BaseMap::Init()
{
	m_tex = std::make_shared<KdTexture>();
	m_moveVec = Math::Vector3::Zero;
}

void BaseMap::DrawSprite()
{
	KdShaderManager::Instance().m_spriteShader.DrawTex(m_tex, m_pos.x, m_pos.y, nullptr, &m_color);
}

const Math::Vector3 BaseMap::Convert2D(const Math::Vector3 _pos)
{
	Math::Vector3 pos;
	pos.x = _pos.x * 5.0f + MinMap_X;
	pos.y = _pos.z * 5.0f + MinMap_Y;
	return pos;
}
