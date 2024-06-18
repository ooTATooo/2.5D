#pragma once

class Animation
{
public:

	Animation() {}
	~Animation() {}

	// キャラクター状態
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
	void CreateAnimation(std::string _name, std::shared_ptr<KdSquarePolygon> _polygon, bool _flg);

	const bool GetAnimationFlg()const { return m_flg; }

private:

	std::vector<int> m_animeFrame;		// アニメーション配列格納用

	State m_
		= State::None;

	Dir m_dir = Dir::Right;

	float m_cntSed = 0;			// アニメのスピード
	float m_anime = 0;				// アニメーションカウント
	bool m_flg = false;

	std::string str;
};