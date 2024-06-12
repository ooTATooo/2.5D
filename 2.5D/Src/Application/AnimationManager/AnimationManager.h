#pragma once

class AnimationManager
{
public:

	AnimationManager();
	~AnimationManager() {}

	// キャラクター状態
	enum class CharaState
	{
		None,
		Idol,
		Attack,
		Run,
	};

	// 弾状態
	enum class BulletState
	{
		None,
		Idol,
		Shot,
		Hit,
	};

	// 向き
	enum class Dir
	{
		Right,
		Left,
	};

	// キャラクターアニメーション作成
	void CreateCharaAnimation(std::string _name, CharaState _state, Dir _dir, std::shared_ptr<KdSquarePolygon> _polygon);

	// 弾アニメーション作成
	void CreateBulletAnimation(std::string _name, BulletState _state, Dir _dir, std::shared_ptr<KdSquarePolygon> _polygon);

private:

	std::vector<int> m_animeFrame;		// アニメーション配列格納用

	float m_cntSpeed = 0.1f;			// アニメのスピード

	float m_anime = 0;					// アニメーションカウント

	CharaState m_charaState = CharaState::None;

	BulletState m_bulletState = BulletState::None;

};