#pragma once

class AnimationManager
{
public:

	AnimationManager();
	~AnimationManager() {}

	// 状態
	enum class State
	{
		None,
		Idol,
		Attack,
		Run,
	};

	// 向き
	enum class Dir
	{
		Right,
		Left,
	};

	// アニメーション作成
	void CreateAnime(std::string _name, State _state, Dir _dir, std::shared_ptr<KdSquarePolygon> _polygon);

private:

	std::vector<int> m_animeFrame;		// アニメーション配列格納用

	float m_cntSpeed = 0.1f;			// アニメのスピード

	float m_anime = 0;					// アニメーションカウント

	State m_state = State::None;

};