#include "AssetManager.h"

void AssetManager::Init()
{
	KdSquarePolygon::PivotType pivot = KdSquarePolygon::PivotType::Center_Bottom;
	LoadMaterial("enemy01Idol", "Asset/Textures/Enemy01/slime01.png");
	SetMaterial("enemy01Idol", 1.0f, pivot, 12, 1);
	SetAnimation("enemy01Idol", 9, 3);

	LoadMaterial("enemy01Attack", "Asset/Textures/Enemy01/slime01.png");
	SetMaterial("enemy01Attack", 1.0f, pivot, 12, 1);
	SetAnimation("enemy01Attack", 4, 5);

	LoadMaterial("enemy01Run", "Asset/Textures/Enemy01/slime01.png");
	SetMaterial("enemy01Run", 1.0f, pivot, 12, 1);
	SetAnimation("enemy01Run", 0, 4);

	LoadMaterial("enemy02Idol", "Asset/Textures/Enemy01/witch01.png");
	SetMaterial("enemy02Idol", 1.0f, pivot, 14, 1);
	SetAnimation("enemy02Idol", 11, 4);

	LoadMaterial("enemy02Attack", "Asset/Textures/Enemy01/witch01.png");
	SetMaterial("enemy02Attack", 1.0f, pivot, 14, 1);
	SetAnimation("enemy02Attack", 7, 4);

	LoadMaterial("enemy02Run", "Asset/Textures/Enemy01/witch01.png");
	SetMaterial("enemy02Run", 1.0f, pivot, 14, 1);
	SetAnimation("enemy02Run", 0, 6);

	LoadMaterial("enemy03Idol", "Asset/Textures/Enemy01/knight01.png");
	SetMaterial("enemy03Idol", 1.0f, pivot, 14, 1);
	SetAnimation("enemy03Idol", 11, 4);

	LoadMaterial("enemy03Attack", "Asset/Textures/Enemy01/knight01.png");
	SetMaterial("enemy03Attack", 1.0f, pivot, 14, 1);
	SetAnimation("enemy03Attack", 7, 4);

	LoadMaterial("enemy03Run", "Asset/Textures/Enemy01/knight01.png");
	SetMaterial("enemy03Run", 1.0f, pivot, 14, 1);
	SetAnimation("enemy03Run", 0, 6);

}

KdSquarePolygon AssetManager::GetMaterial(std::string _name)
{
	if (m_materialList.find(_name) != m_materialList.end())
	{
		return m_materialList.at(_name);
	}
}

KdModelData AssetManager::GetModel(std::string _name)
{
	if (m_modelList.find(_name) != m_modelList.end())
	{
		return m_modelList.at(_name);
	}
}

KdTexture* AssetManager::GetTex(std::string _name)
{
	if (m_texList.find(_name) != m_texList.end())
	{
		return &m_texList.at(_name);
	}
}

void AssetManager::SetMaterial(std::string _name, float _scale, KdSquarePolygon::PivotType _pivot, int _splitX, int _splitY)
{
	m_materialList[_name].SetScale(_scale);
	m_materialList[_name].SetPivot(_pivot);
	m_materialList[_name].SetSplit(_splitX, _splitY);
}

void AssetManager::SetAnimation(std::string _name, int _start, int _count)
{
	std::vector<int> num;
	for (int a = 0; a < _count; a++)
	{
		num.push_back(_start + a);
	}
	m_animationList[_name] = num;
}

std::vector<int> AssetManager::GetAnimation(std::string _name)
{
	return m_animationList[_name];
}

void AssetManager::GatAnimation(std::string _name, std::shared_ptr<KdSquarePolygon> _polygon)
{
	*_polygon = AssetManager::Instance().GetMaterial(_name);
	m_animeFrame = AssetManager::Instance().GetAnimation(_name);

	//if (_dir == Dir::Left) { _polygon->TurnScale(); }

	_polygon->SetUVRect(m_animeFrame[(int)m_anime]);

	m_anime += m_cntSpeed;
	if (m_anime >= m_animeFrame.size())
	{
		m_anime = 0;
	}
}