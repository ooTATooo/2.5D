#include "TitleLogo.h"

void TitleLogo::Init()
{
	m_tex = AssetManager::Instance().GetTex("TitleLogo");

	m_pos = { 300,200,0 };
}
