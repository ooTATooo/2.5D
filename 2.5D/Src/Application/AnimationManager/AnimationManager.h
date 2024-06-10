#pragma once

//class AnimationManager
//{
//public:
//
//	// キャラク
//	enum class Chara
//	{
//		None,
//		Player,
//		Enemy01,
//		Enemy02,
//		Enemy03,
//		Boss,
//	};
//
//	// 状態
//	enum class State
//	{
//		None,
//		Idle,
//		Run,
//		Attack,
//	};
//
//	// 向き
//	enum class Dir
//	{
//		Right,
//		Left,
//	};
//
//	// アニメーション作成
//	void CreateAnime(Dir _dir, State _state, std::shared_ptr<KdSquarePolygon> _polygon);
//
//private:
//
//	void Init();				// 初期化
//
//	std::vector<int> m_animeFrame;		// アニメーション配列格納用
//
//	State m_state;				// キャラの状態
//	float m_cntSpeed;			// アニメのスピード
//
//	float m_anime = 0;
//
//private:
//
//	AnimationManager() { Init(); }		// コンストラクタ
//	~AnimationManager() {}				// デストラクタ
//
//public:
//
//	// シングルトンパターン
//	static AnimationManager& Instance()
//	{
//		static AnimationManager instance;
//		return instance;
//	}
//};

class Anime
{
public:

	// 状態
	enum class State
	{
		None,
		Idle,
		Run,
		Attack,
	};

	// 向き
	enum class Dir
	{
		Right,
		Left,
	};

	// アニメーション作成
	void CreateAnime(State _state, std::shared_ptr<KdSquarePolygon> _polygon);

private:

	void Init();				// 初期化

	std::vector<int> m_animeFrame;		// アニメーション配列格納用

	State m_state;				// キャラの状態
	float m_cntSpeed;			// アニメのスピード

	float m_anime = 0;

//private:
//
//	Anime() { Init(); }		// コンストラクタ
//	~Anime() {}				// デストラクタ
//
//public:
//
//	// シングルトンパターン
//	static Anime& Instance()
//	{
//		static Anime instance;
//		return instance;
//	}
};

class Animation
{
public:

	Anime GetAnimation(std::string _name);

private:

	void LoadAnimation(std::string _name, Anime::State _state);
	void Init();				// 初期化

	std::unordered_map<std::string, Anime> m_animationList;

private:

	Animation() { Init(); }		// コンストラクタ
	~Animation() {}				// デストラクタ

public:

	// シングルトンパターン
	static Animation& Instance()
	{
		static Animation instance;
		return instance;
	}
};