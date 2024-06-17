#include "BaseStage.h"

void BaseStage::Init()
{
	m_alpha = 1.0f;
	m_alphaSpd = 0.05f;
	m_alphaFlg = false;
	m_color = { 1.0f,1.0f,1.0f,m_alpha };
}
