#include "AnimationManager.h"

void AnimationManager::CreateAnime(Dir _dir, State _state, std::shared_ptr<KdSquarePolygon> _polygon)
{
	// 現在の状態と異なっていたら
	if (m_state != _state)
	{
		m_state = _state;

		switch (m_state)
		{
		case State::Idle:
			*_polygon = AssetManager::Instance().GetMaterial("enemy01Idol");
			m_cntSpeed = 0.1f;
			break;
		case State::Run:
			*_polygon = AssetManager::Instance().GetMaterial("enemy01Run");
			m_cntSpeed = 0.1f;
			break;
		case State::Attack:
			*_polygon = AssetManager::Instance().GetMaterial("enemy01Attack");
			m_cntSpeed = 0.1f;
			break;
		}

		if (_dir == Dir::Left) { _polygon->TurnScale(); }

		m_maxAnime = _polygon->GetSplitX();
		m_cnt = 0.0f;
	}

	AnimeCnt();

	_polygon->SetUVRect((int)m_cnt);
}

void AnimationManager::Init()
{
	m_state = State::Idle;

	m_cnt = 0.0f;
	m_cntSpeed = 0.2f;
	m_maxAnime = 0;

	m_bAction = true;
	m_bStiff = false;
	m_wait = 0;
}

void AnimationManager::AnimeCnt()
{
	if (m_bStiff)
	{
		m_wait--;
		if (m_wait <= 0)
		{
			m_bStiff = false;
		}
		return;
	}

	m_cnt += m_cntSpeed;		// カウントを進める

	if (m_cnt >= m_maxAnime)	// アニメーションが１週したら
	{
		m_cnt = 0.0f;

		//if (m_state == State::Roll)
		//{
		//	m_bStiff = true;
		//	m_bAction = true;
		//	m_wait = 20;
		//}
		//if (m_state == State::Attack1)
		//{
		//	m_bStiff = true;
		//	m_bAction = true;
		//	m_wait = 10;
		//}
		//if (m_state == State::Attack2)
		//{
		//	m_bStiff = true;
		//	m_bAction = true;
		//	m_wait = 10;
		//}
		//if (m_state == State::Attack3)
		//{
		//	m_bStiff = true;
		//	m_bAction = true;
		//	m_wait = 10;
		//}
	}
}
