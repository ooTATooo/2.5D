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
	SetMaterial("PlayerHit", { 0.8f,1.0f }, pivot, 6, 1);
	SetAnimation("PlayerHit", 0, 6, 0.2f);
	// ===プレイヤー

	// ===エネミー１
	LoadMaterial("SlimeAttack", "Asset/Textures/Enemy/Slime/Slime.png");
	SetMaterial("SlimeAttack", { 1.0f,1.0f }, pivot, 9, 1);
	SetAnimation("SlimeAttack", 4, 5, 0.1f);

	LoadMaterial("SlimeRun", "Asset/Textures/Enemy/Slime/Slime.png");
	SetMaterial("SlimeRun", { 1.0f,1.0f }, pivot, 9, 1);
	SetAnimation("SlimeRun", 0, 4, 0.1f);

	LoadMaterial("SlimeHit", "Asset/Textures/Enemy/Slime/SlimeHit.png");
	SetMaterial("SlimeHit", { 1.0f,1.0f }, pivot, 6, 1);
	SetAnimation("SlimeHit", 0, 6, 0.2f);

	LoadMaterial("SlimeDie", "Asset/Textures/Enemy/Slime/SlimeDie.png");
	SetMaterial("SlimeDie", { 1.0f,1.0f }, pivot, 2, 1);
	SetAnimation("SlimeDie", 0, 2, 0.2f);
	// ===エネミー１

	// ===エネミー２
	LoadMaterial("WitchAttack", "Asset/Textures/Enemy/Witch/Witch.png");
	SetMaterial("WitchAttack", { 2.0f,2.0f }, pivot, 10, 1);
	SetAnimation("WitchAttack", 6, 4, 0.1f);

	LoadMaterial("WitchRun", "Asset/Textures/Enemy/Witch/Witch.png");
	SetMaterial("WitchRun", { 2.0f,2.0f }, pivot, 10, 1);
	SetAnimation("WitchRun", 0, 6, 0.1f);

	LoadMaterial("WitchHit", "Asset/Textures/Enemy/Witch/WitchHit.png");
	SetMaterial("WitchHit", { 2.0f,2.0f }, pivot, 6, 1);
	SetAnimation("WitchHit", 0, 6, 0.2f);

	LoadMaterial("WitchDie", "Asset/Textures/Enemy/Witch/WitchDie.png");
	SetMaterial("WitchDie", { 2.0f,2.0f }, pivot, 2, 1);
	SetAnimation("WitchDie", 0, 2, 0.2f);
	// ===エネミー２

	// ===エネミー３
	LoadMaterial("KnightAttack", "Asset/Textures/Enemy/Knight/Knight.png");
	SetMaterial("KnightAttack", { 2.0f,2.0f }, pivot, 10, 1);
	SetAnimation("KnightAttack", 6, 4, 0.1f);

	LoadMaterial("KnightRun", "Asset/Textures/Enemy/Knight/Knight.png");
	SetMaterial("KnightRun", { 2.0f,2.0f }, pivot, 10, 1);
	SetAnimation("KnightRun", 0, 6, 0.1f);

	LoadMaterial("KnightHit", "Asset/Textures/Enemy/Knight/KnightHit.png");
	SetMaterial("KnightHit", { 2.0f,2.0f }, pivot, 6, 1);
	SetAnimation("KnightHit", 0, 6, 0.2f);

	LoadMaterial("KnightDie", "Asset/Textures/Enemy/Knight/KnightDie.png");
	SetMaterial("KnightDie", { 2.0f,2.0f }, pivot, 2, 1);
	SetAnimation("KnightDie", 0, 2, 0.1f);

	LoadMaterial("KnightIdol", "Asset/Textures/Enemy/Knight/KnightIdol.png");
	SetMaterial("KnightIdol", { 2.0f,2.0f }, pivot, 4, 1);
	SetAnimation("KnightIdol", 0, 4, 0.1f);
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
	SetMaterial("EnemyBulletHit", { 1.5f,1.5f }, pivot, 6, 1);
	SetAnimation("EnemyBulletHit", 0, 6, 0.3f);
	// ===エネミー弾

	LoadMaterial("PlayerAtkEffect", "Asset/Textures/Effect/PlayerAtk.png");
	SetMaterial("PlayerAtkEffect", { 2.0f,2.0f }, pivot, 5, 1);
	SetAnimation("PlayerAtkEffect", 0, 5, 0.3f);

	LoadMaterial("PlayerAtkImpact", "Asset/Textures/Effect/PlayerAtkImpact.png");
	SetMaterial("PlayerAtkImpact", { 1.5f,1.5f }, pivot, 6, 1);
	SetAnimation("PlayerAtkImpact", 0, 6, 0.3f);

	LoadMaterial("KnightAtk", "Asset/Textures/Effect/KnightAtk.png");
	SetMaterial("KnightAtk", { 1.0f,1.0f }, pivot, 8, 1);
	SetAnimation("KnightAtk", 0, 8, 0.2f);

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

	LoadTex("Fade", "Asset/Textures/Effect/Fade.png");

	LoadTex("TitleLogo", "Asset/Textures/UI/Title.png");
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
