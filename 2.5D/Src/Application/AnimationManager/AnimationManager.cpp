#include "AnimationManager.h"

//void AnimationManager::CreateAnime(Dir _dir, State _state, std::shared_ptr<KdSquarePolygon> _polygon)
//{
//	// 現在の状態と異なっていたら
//	if (m_state != _state)
//	{
//		m_state = _state;
//
//		switch (m_state)
//		{
//		case State::Idle:
//			*_polygon = AssetManager::Instance().GetMaterial("enemy01Idol");
//			m_animeFrame = AssetManager::Instance().GetAnimation("enemy01Idol");
//			m_cntSpeed = 0.1f;
//			break;
//		case State::Run:
//			*_polygon = AssetManager::Instance().GetMaterial("enemy01Run");
//			m_animeFrame = AssetManager::Instance().GetAnimation("enemy01Run");
//			m_cntSpeed = 0.1f;
//			break;
//		case State::Attack:
//			*_polygon = AssetManager::Instance().GetMaterial("enemy01Attack");
//			m_animeFrame = AssetManager::Instance().GetAnimation("enemy01Attack");
//			m_cntSpeed = 0.01f;
//			break;
//		}
//
//		if (_dir == Dir::Left) { _polygon->TurnScale(); }
//	}
//
//	_polygon->SetUVRect(m_animeFrame[(int)m_anime]);
//
//	m_anime += m_cntSpeed;
//	if (m_anime >= m_animeFrame.size())
//	{
//		m_anime = 0;
//	}
//}
//
//void AnimationManager::Init()
//{
//	m_state = State::None;
//
//	m_cntSpeed = 0.2f;
//}

Anime Animation::GetAnimation(std::string _name)
{
	return m_animationList[_name];
}

void Animation::LoadAnimation(std::string _name, Anime::State _state)
{
}

void Animation::Init()
{
}

void Anime::CreateAnime(State _state, std::shared_ptr<KdSquarePolygon> _polygon)
{
	// 現在の状態と異なっていたら
	if (m_state != _state)
	{
		m_state = _state;

		switch (m_state)
		{
		case State::Idle:
			*_polygon = AssetManager::Instance().GetMaterial("enemy01Idol");
			m_animeFrame = AssetManager::Instance().GetAnimation("enemy01Idol");
			m_cntSpeed = 0.1f;
			break;
		case State::Run:
			*_polygon = AssetManager::Instance().GetMaterial("enemy01Run");
			m_animeFrame = AssetManager::Instance().GetAnimation("enemy01Run");
			m_cntSpeed = 0.1f;
			break;
		case State::Attack:
			*_polygon = AssetManager::Instance().GetMaterial("enemy01Attack");
			m_animeFrame = AssetManager::Instance().GetAnimation("enemy01Attack");
			m_cntSpeed = 0.01f;
			break;
		}
	}

	_polygon->SetUVRect(m_animeFrame[(int)m_anime]);

	m_anime += m_cntSpeed;
	if (m_anime >= m_animeFrame.size())
	{
		m_anime = 0;
	}
}

void Anime::Init()
{
	m_state = State::None;

	m_cntSpeed = 0.2f;
}
