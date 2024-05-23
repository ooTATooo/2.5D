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

	std::shared_ptr<KdSquarePolygon> m_poly;

	float m_moveSpd;
	Math::Vector3 m_nowPos;
	Math::Vector3 m_moveVec;
	Math::Matrix m_scaleMat;
	Math::Matrix m_rotMatX;
	Math::Matrix m_rotMatY;
	Math::Matrix m_trancMat;
	float m_size;
	float m_angX;
	float m_angY;
	bool m_keyFlg[keyType::kind];

	int frame;
	int ani;
};