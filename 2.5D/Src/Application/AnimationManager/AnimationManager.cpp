#include "AnimationManager.h"

AnimationManager::AnimationManager()
{
	m_cntSpeed = 0.1f;
	m_anime = 0;
	m_state = State::None;
}

void AnimationManager::CreateAnime(std::string _name, State _state, Dir _dir, std::shared_ptr<KdSquarePolygon> _polygon)
{
	if (m_state != _state)
	{
		std::string str;
		m_state = _state;

		switch (m_state)
		{
		case AnimationManager::State::Idol:
			str = _name + "Idol";
			*_polygon = AssetManager::Instance().GetMaterial(str);
			m_animeFrame = AssetManager::Instance().GetAnimation(str);
			break;
		case AnimationManager::State::Attack:
			str = _name + "Attack";
			*_polygon = AssetManager::Instance().GetMaterial(str);
			m_animeFrame = AssetManager::Instance().GetAnimation(str);
			break;
		case AnimationManager::State::Run:
			str = _name + "Run";
			*_polygon = AssetManager::Instance().GetMaterial(str);
			m_animeFrame = AssetManager::Instance().GetAnimation(str);
			break;
		}

		m_cntSpeed = 0.1f;
		m_anime = 0;

		if (_dir == Dir::Left)_polygon->TurnScale();
	}

	_polygon->SetUVRect(m_animeFrame[(int)m_anime]);

	m_anime += m_cntSpeed;
	if (m_anime >= m_animeFrame.size())
	{
		m_anime = 0;
	}
}