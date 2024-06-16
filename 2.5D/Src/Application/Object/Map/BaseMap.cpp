#include "BaseMap.h"

void BaseMap::Update()
{
}

void BaseMap::PostUpdate()
{
	Math::Matrix transMat = Math::Matrix::CreateTranslation(m_pos);

	Math::Matrix scaleMat = Math::Matrix::CreateScale(m_scale);

	m_mWorld = scaleMat * transMat;
}

void BaseMap::Init()
{
	m_tex = std::make_shared<KdTexture>();
	m_moveVec = Math::Vector3::Zero;

}

void BaseMap::DrawSprite()
{
	m_rect = { 0,0,(int)m_tex->GetWidth(),(int)m_tex->GetHeight() };
	KdShaderManager::Instance().m_spriteShader.SetMatrix(m_mWorld);
	KdShaderManager::Instance().m_spriteShader.DrawTex(m_tex, 0, 0, &m_rect, &m_color);
}

const Math::Vector3 BaseMap::Convert2D(const Math::Vector3 _pos)
{
	Math::Vector3 pos;
	pos.x = _pos.x * 5.0f + MinMap_X;
	pos.y = _pos.z * 5.0f + MinMap_Y;
	return pos;
}
