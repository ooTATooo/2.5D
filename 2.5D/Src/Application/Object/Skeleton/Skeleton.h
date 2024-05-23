#pragma once

class Skeleton :public KdGameObject
{
public:

	Skeleton() { Init(); }
	~Skeleton()override {}

	void Update()override;
	void Init()override;
	void GenerateDepthMapFromLight()override;
	void DrawLit()override;

private:

	KdModelData m_model;

	float m_moveSpd;
	Math::Vector3 m_nowPos;
	Math::Vector3 m_moveVec;
	Math::Matrix m_scaleMat;
	Math::Matrix m_rotMat;
	Math::Matrix m_trancMat;
	float m_size;
	float m_ang;
};