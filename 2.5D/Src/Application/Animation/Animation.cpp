#include "Animation.h"

void Animation::CreateAnimation(std::string _name, std::shared_ptr<KdSquarePolygon> _polygon, bool _flg)
{
	if (!_flg)
	{
		m_flg = true;
	}

	if (str != _name)
	{
		str = _name;

		std::tie(*_polygon, m_animeFrame, m_cntSed) = AssetManager::Instance().GetMaterialAnime(_name);

		m_anime = 0;
	}

	_polygon->SetUVRect(m_animeFrame[(int)m_anime]);

	m_anime += m_cntSed;
	if (m_anime >= m_animeFrame.size())
	{
		m_anime = 0;

		if (!_flg)
		{
			m_flg = false;
		}
	}
}
