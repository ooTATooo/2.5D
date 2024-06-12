#include "AnimationManager.h"

AnimationManager::AnimationManager()
{
	m_cntSpeed = 0.1f;
	m_anime = 0;
	m_charaState = CharaState::None;
	m_bulletState = BulletState::None;
}

void AnimationManager::CreateCharaAnimation(std::string _name, CharaState _state, Dir _dir, std::shared_ptr<KdSquarePolygon> _polygon)
{
	if (m_charaState != _state)
	{
		std::string str;
		m_charaState = _state;

		switch (m_charaState)
		{
		case AnimationManager::CharaState::Idol:
			str = _name + "Idol";
			*_polygon = AssetManager::Instance().GetMaterial(str);
			m_animeFrame = AssetManager::Instance().GetAnimation(str);
			break;
		case AnimationManager::CharaState::Attack:
			str = _name + "Attack";
			*_polygon = AssetManager::Instance().GetMaterial(str);
			m_animeFrame = AssetManager::Instance().GetAnimation(str);
			break;
		case AnimationManager::CharaState::Run:
			str = _name + "Run";
			*_polygon = AssetManager::Instance().GetMaterial(str);
			m_animeFrame = AssetManager::Instance().GetAnimation(str);
			break;
		}

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

void AnimationManager::CreateBulletAnimation(std::string _name, BulletState _state, Dir _dir, std::shared_ptr<KdSquarePolygon> _polygon)
{
	if (m_bulletState != _state)
	{
		std::string str;
		m_bulletState = _state;

		switch (m_bulletState)
		{
		case AnimationManager::BulletState::Idol:
			str = _name + "Idol";
			*_polygon = AssetManager::Instance().GetMaterial(str);
			m_animeFrame = AssetManager::Instance().GetAnimation(str);
			break;
		case AnimationManager::BulletState::Shot:
			str = _name + "Shot";
			*_polygon = AssetManager::Instance().GetMaterial(str);
			m_animeFrame = AssetManager::Instance().GetAnimation(str);
			break;
		case AnimationManager::BulletState::Hit:
			str = _name + "Hit";
			*_polygon = AssetManager::Instance().GetMaterial(str);
			m_animeFrame = AssetManager::Instance().GetAnimation(str);
			break;
		}

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
