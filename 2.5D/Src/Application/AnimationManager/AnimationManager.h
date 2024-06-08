#pragma once

class AnimationManager
{
public:

	// 状態
	enum class State
	{
		Idle,
		Run,
		Attack,
	};

	enum class Dir
	{
		Right,
		Left,
	};

	State GetState() { return m_state; }

	bool GetAction() { return m_bAction; }
	bool GetStiff() { return m_bStiff; }

	// アニメーション作成
	void CreateAnime(Dir _dir, State _state, std::shared_ptr<KdSquarePolygon> _polygon);

private:

	void Init();				// 初期化

	void AnimeCnt();

	State m_state;				// プレイヤーの状態
	float m_cnt;				// アニメのカウント
	float m_cntSpeed;			// アニメのスピード
	int m_maxAnime;				// 最大のアニメ数

	bool m_bAction;				// アクション可能か？(true:可能 false:不可能)
	bool m_bStiff;				// 硬直中か？(true:はい false:いいえ)
	int m_wait;					// 硬直時間

private:

	AnimationManager() { Init(); }		// コンストラクタ
	~AnimationManager() {}				// デストラクタ

public:

	// シングルトンパターン
	static AnimationManager& Instance()
	{
		static AnimationManager instance;
		return instance;
	}
};