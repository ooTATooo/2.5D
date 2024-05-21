#pragma once

class Player :public KdGameObject
{
public:

	Player() {}
	~Player()override {}

	void Update()override;
	void Init()override;
	void GenerateDepthMapFromLight()override;
	void DrawLit()override;

	void KeyAction();

public:

	enum keyType
	{
		W,
		S,
		A,
		D,
		kind
	};

	KdModelData m_model;

	float m_moveSpd;
	Math::Vector3 m_nowPos;
	Math::Vector3 m_moveVec;
	Math::Matrix m_scaleMat;
	Math::Matrix m_rotMat;
	Math::Matrix m_trancMat;
	float m_size;
	float m_ang;
	bool m_keyFlg[keyType::kind];
};