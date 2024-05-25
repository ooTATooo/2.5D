#pragma once

class Player :public KdGameObject
{
public:

	Player() { Init(); }
	~Player()override {}

	void Update()override;
	void Init()override;
	void GenerateDepthMapFromLight()override;
	void DrawLit()override;

private:

	std::shared_ptr<KdSquarePolygon> m_poly;

	float m_moveSpd;
	Math::Vector3 m_pos;
	Math::Vector3 m_moveVec;
	Math::Matrix m_scaleMat;
	Math::Matrix m_rotMatX;
	Math::Matrix m_rotMatY;
	Math::Matrix m_transMat;
	float m_size;
	float m_angX;
	float m_angY;

	int frame;
	int ani;

};