#include "AssetManager.h"

void AssetManager::Init()
{
	// ポリゴン====================
	KdSquarePolygon::PivotType pivot = KdSquarePolygon::PivotType::Center_Bottom;

	// ===プレイヤー
	LoadMaterial("PlayerIdol", "Asset/Textures/Player/Idol.png");
	SetMaterial("PlayerIdol", { 1.5f,1.3f }, pivot, 4, 1);
	SetAnimation("PlayerIdol", 0, 4, 0.1f);

	LoadMaterial("PlayerAttack", "Asset/Textures/Player/attack.png");
	SetMaterial("PlayerAttack", { 4.0f,2.0f }, pivot, 8, 1);
	SetAnimation("PlayerAttack", 0, 8, 0.3f);

	LoadMaterial("PlayerRun", "Asset/Textures/Player/run.png");
	SetMaterial("PlayerRun", { 1.0f,1.2f }, pivot, 8, 1);
	SetAnimation("PlayerRun", 0, 8, 0.2f);

	LoadMaterial("PlayerHit", "Asset/Textures/Player/hit.png");
	SetMaterial("PlayerHit", { 1.0f,1.2f }, pivot, 2, 1);
	SetAnimation("PlayerHit", 0, 2, 0.01f);
	// ===プレイヤー

	// ===エネミー１
	LoadMaterial("Enemy01Idol", "Asset/Textures/Enemy01/Slime01.png");
	SetMaterial("Enemy01Idol", { 1.0f,1.0f }, pivot, 12, 1);
	SetAnimation("Enemy01Idol", 9, 3, 0.1f);

	LoadMaterial("Enemy01Attack", "Asset/Textures/Enemy01/Slime01.png");
	SetMaterial("Enemy01Attack", { 1.0f,1.0f }, pivot, 12, 1);
	SetAnimation("Enemy01Attack", 4, 5, 0.1f);

	LoadMaterial("Enemy01Run", "Asset/Textures/Enemy01/Slime01.png");
	SetMaterial("Enemy01Run", { 1.0f,1.0f }, pivot, 12, 1);
	SetAnimation("Enemy01Run", 0, 4, 0.1f);

	LoadMaterial("Enemy01Hit", "Asset/Textures/Enemy01/SlimeHit.png");
	SetMaterial("Enemy01Hit", { 1.0f,1.0f }, pivot, 6, 1);
	SetAnimation("Enemy01Hit", 0, 6, 0.2f);
	// ===エネミー１

	// ===エネミー２
	LoadMaterial("Enemy02Idol", "Asset/Textures/Enemy02/Witch01.png");
	SetMaterial("Enemy02Idol", { 2.0f,2.0f }, pivot, 14, 1);
	SetAnimation("Enemy02Idol", 10, 4, 0.1f);

	LoadMaterial("Enemy02Attack", "Asset/Textures/Enemy02/Witch01.png");
	SetMaterial("Enemy02Attack", { 2.0f,2.0f }, pivot, 14, 1);
	SetAnimation("Enemy02Attack", 6, 4, 0.1f);

	LoadMaterial("Enemy02Run", "Asset/Textures/Enemy02/Witch01.png");
	SetMaterial("Enemy02Run", { 2.0f,2.0f }, pivot, 14, 1);
	SetAnimation("Enemy02Run", 0, 6, 0.1f);

	LoadMaterial("Enemy02Hit", "Asset/Textures/Enemy02/WitchHit.png");
	SetMaterial("Enemy02Hit", { 2.0f,2.0f }, pivot, 6, 1);
	SetAnimation("Enemy02Hit", 0, 6, 0.2f);
	// ===エネミー２

	// ===エネミー３
	LoadMaterial("Enemy03Idol", "Asset/Textures/Enemy03/Knight01.png");
	SetMaterial("Enemy03Idol", { 2.0f,2.0f }, pivot, 14, 1);
	SetAnimation("Enemy03Idol", 10, 4, 0.1f);

	LoadMaterial("Enemy03Attack", "Asset/Textures/Enemy03/Knight01.png");
	SetMaterial("Enemy03Attack", { 2.0f,2.0f }, pivot, 14, 1);
	SetAnimation("Enemy03Attack", 6, 4, 0.1f);

	LoadMaterial("Enemy03Run", "Asset/Textures/Enemy03/Knight01.png");
	SetMaterial("Enemy03Run", { 2.0f,2.0f }, pivot, 14, 1);
	SetAnimation("Enemy03Run", 0, 6, 0.1f);

	LoadMaterial("Enemy03Hit", "Asset/Textures/Enemy03/KnightHit.png");
	SetMaterial("Enemy03Hit", { 2.0f,2.0f }, pivot, 6, 1);
	SetAnimation("Enemy03Hit", 0, 6, 0.2f);
	// ===エネミー３

	// ===ボス
	LoadMaterial("BossIdol", "Asset/Textures/Boss/dragon01.png");
	SetMaterial("BossIdol", { 8.0f,6.0f }, pivot, 15, 1);
	SetAnimation("BossIdol", 11, 4, 0.1f);

	LoadMaterial("BossAttack", "Asset/Textures/Boss/dragon02.png");
	SetMaterial("BossAttack", { 8.0f,6.0f }, pivot, 15, 1);
	SetAnimation("BossAttack", 7, 5, 0.1f);

	LoadMaterial("BossRun", "Asset/Textures/Boss/dragon02.png");
	SetMaterial("BossRun", { 8.0f,6.0f }, pivot, 15, 1);
	SetAnimation("BossRun", 0, 6, 0.1f);
	// ===ボス

	// ===エネミー弾
	LoadMaterial("EnemyBulletIdol", "Asset/Textures/Bullet/EnemyBullet.png");
	SetMaterial("EnemyBulletIdol", { 2.0f,2.0f }, pivot, 8, 4);
	SetAnimation("EnemyBulletIdol", 0, 27, 1.0f);

	LoadMaterial("EnemyBulletHit", "Asset/Textures/Bullet/EnemyBulletHit.png");
	SetMaterial("EnemyBulletHit", { 1.0f,1.0f }, pivot, 6, 1);
	SetAnimation("EnemyBulletHit", 0, 6, 0.3f);
	// ===エネミー弾

	LoadMaterial("PlayerAtkEffect", "Asset/Textures/Effect/PlayerAtk.png");
	SetMaterial("PlayerAtkEffect", { 1.0f,1.0f }, pivot, 5, 1);
	SetAnimation("PlayerAtkEffect", 0, 5, 0.3f);

	LoadMaterial("PlayerAtkImpact", "Asset/Textures/Effect/PlayerAtkImpact.png");
	SetMaterial("PlayerAtkImpact", { 0.5f,0.5f }, pivot, 6, 1);
	SetAnimation("PlayerAtkImpact", 0, 6, 0.3f);

	LoadMaterial("BackGround", "Asset/Textures/BackGround/BackGround.png");
	SetMaterial("BackGround", { 250.0f,100.0f }, KdSquarePolygon::PivotType::Center_Middle, 1, 1);
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

std::tuple<KdSquarePolygon, std::vector<int>, float> AssetManager::GetMaterialAnime(std::string _name)
{
	return std::tuple(m_materialList.at(_name), m_animationList.at(_name), m_animeSpdList.at(_name));
}

void AssetManager::SetMaterial(std::string _name, Math::Vector2 _scale, KdSquarePolygon::PivotType _pivot, UINT _splitX, UINT _splitY)
{
	m_materialList[_name].SetScale({ _scale.x, _scale.y });
	m_materialList[_name].SetPivot(_pivot);
	m_materialList[_name].SetSplit(_splitX, _splitY);
}

void AssetManager::SetAnimation(std::string _name, int _start, int _count, float _speed)
{
	std::vector<int> num;
	for (int a = 0; a < _count; a++)
	{
		num.push_back(_start + a);
	}
	m_animationList[_name] = num;
	m_animeSpdList[_name] = _speed;
}

void AssetManager::LoadTex(std::string _name, std::string _path)
{
	m_texList[_name] = std::make_shared<KdTexture>();
	m_texList[_name]->Load(_path);
}
