#include "AssetManager.h"

void AssetManager::Init()
{
	// ポリゴン====================
	KdSquarePolygon::PivotType pivot = KdSquarePolygon::PivotType::Center_Bottom;
	LoadMaterial("PlayerIdol", "Asset/Textures/Player/player.png");
	SetMaterial("PlayerIdol", { 1.0f,1.0f }, pivot, { 9, 6 });
	SetAnimation("PlayerIdol", 0, 3);

	LoadMaterial("Enemy01Idol", "Asset/Textures/Enemy01/slime01.png");
	SetMaterial("Enemy01Idol", { 1.0f,1.0f }, pivot, { 12, 1 });
	SetAnimation("Enemy01Idol", 9, 3);

	LoadMaterial("Enemy01Attack", "Asset/Textures/Enemy01/slime01.png");
	SetMaterial("Enemy01Attack", { 1.0f,1.0f }, pivot, { 12, 1 });
	SetAnimation("Enemy01Attack", 4, 5);

	LoadMaterial("Enemy01Run", "Asset/Textures/Enemy01/slime01.png");
	SetMaterial("Enemy01Run", { 1.0f,1.0f }, pivot, { 12, 1 });
	SetAnimation("Enemy01Run", 0, 4);

	LoadMaterial("Enemy02Idol", "Asset/Textures/Enemy02/witch01.png");
	SetMaterial("Enemy02Idol", { 2.0f,2.0f }, pivot, { 14, 1 });
	SetAnimation("Enemy02Idol", 10, 4);

	LoadMaterial("Enemy02Attack", "Asset/Textures/Enemy02/witch01.png");
	SetMaterial("Enemy02Attack", { 2.0f,2.0f }, pivot, { 14, 1 });
	SetAnimation("Enemy02Attack", 6, 4);

	LoadMaterial("Enemy02Run", "Asset/Textures/Enemy02/witch01.png");
	SetMaterial("Enemy02Run", { 2.0f,2.0f }, pivot, { 14, 1 });
	SetAnimation("Enemy02Run", 0, 6);

	LoadMaterial("Enemy03Idol", "Asset/Textures/Enemy03/knight01.png");
	SetMaterial("Enemy03Idol", { 2.0f,2.0f }, pivot, { 14, 1 });
	SetAnimation("Enemy03Idol", 10, 4);

	LoadMaterial("Enemy03Attack", "Asset/Textures/Enemy03/knight01.png");
	SetMaterial("Enemy03Attack", { 2.0f,2.0f }, pivot, { 14, 1 });
	SetAnimation("Enemy03Attack", 6, 4);

	LoadMaterial("Enemy03Run", "Asset/Textures/Enemy03/knight01.png");
	SetMaterial("Enemy03Run", { 2.0f,2.0f }, pivot, { 14, 1 });
	SetAnimation("Enemy03Run", 0, 6);

	LoadMaterial("BossIdol", "Asset/Textures/Boss/dragon02.png");
	SetMaterial("BossIdol", { 8.0f,6.0f }, pivot, { 15, 1 });
	SetAnimation("BossIdol", 11, 4);

	LoadMaterial("BossAttack", "Asset/Textures/Boss/dragon02.png");
	SetMaterial("BossAttack", { 8.0f,6.0f }, pivot, { 15, 1 });
	SetAnimation("BossAttack", 7, 5);

	LoadMaterial("BossRun", "Asset/Textures/Boss/dragon02.png");
	SetMaterial("BossRun", { 8.0f,6.0f }, pivot, { 15, 1 });
	SetAnimation("BossRun", 0, 6);

	LoadMaterial("PlayerBullet01Idol", "Asset/Textures/PlayerBullet01/bullet.png");
	SetMaterial("PlayerBullet01Idol", { 1.0f,1.0f }, pivot, { 4,1 });
	SetAnimation("PlayerBullet01Idol", 0, 4);

	LoadMaterial("EnemyBulletIdol", "Asset/Textures/PlayerBullet01/bullet.png");
	SetMaterial("EnemyBulletIdol", { 1.0f,1.0f }, pivot, { 4,1 });
	SetAnimation("EnemyBulletIdol", 0, 4);

	LoadMaterial("BackGround", "Asset/Textures/BackGround/BackGround.png");
	SetMaterial("BackGround", { 250.0f,100.0f }, KdSquarePolygon::PivotType::Center_Middle, { 1,1 });
	// ============================

	// モデル======================

	// ============================

	// 2Dテクスチャ================
	LoadTex("BarBack", "Asset/Textures/HpBar/hpbar01.png");

	LoadTex("Bar", "Asset/Textures/HpBar/hpbar02.png");

	LoadTex("MapBackGround", "Asset/Textures/MiniMap/MapBack.png");

	LoadTex("MapPlayerIcon", "Asset/Textures/MiniMap/PlayerIcon.png");
	
	LoadTex("MapMonolithPoint", "Asset/Textures/MiniMap/MonolithPoint.png");

	LoadTex("MapEnemyPoint", "Asset/Textures/MiniMap/EnemyPoint.png");
	// ============================

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

std::shared_ptr<KdTexture> AssetManager::GetTex(std::string _name)
{
	if (m_texList.find(_name) != m_texList.end())
	{
		return m_texList.at(_name);
	}
}

std::vector<int> AssetManager::GetAnimation(std::string _name)
{
	if (m_animationList.find(_name) != m_animationList.end())
	{
		return m_animationList.at(_name);
	}
}

void AssetManager::SetMaterial(std::string _name, Math::Vector2 _scale, KdSquarePolygon::PivotType _pivot, Math::Vector2 _split)
{
	m_materialList[_name].SetScale({ _scale.x, _scale.y });
	m_materialList[_name].SetPivot(_pivot);
	m_materialList[_name].SetSplit(_split.x, _split.y);
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

void AssetManager::LoadTex(std::string _name, std::string _path)
{
	m_texList[_name] = std::make_shared<KdTexture>();
	m_texList[_name]->Load(_path);
}
