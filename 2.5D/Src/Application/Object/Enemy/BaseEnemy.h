﻿#pragma once

class BaseEnemy :public KdGameObject
{
public:

	BaseEnemy() {}
	~BaseEnemy()override {}

	void Update()override;
	void Init()override;
	void GenerateDepthMapFromLight()override;
	void DrawLit()override;

protected:

	std::shared_ptr<KdSquarePolygon> m_poly = nullptr;

	float m_moveSpd = 0;
	Math::Vector3 m_pos = m_mWorld.Translation();
	Math::Vector3 m_moveVec = Math::Vector3::Zero;
	Math::Matrix m_rotMatX = Math::Matrix::Identity;
	Math::Matrix m_rotMatY = Math::Matrix::Identity;
	Math::Matrix m_transMat = Math::Matrix::Identity;
	float m_angX = 0;
	float m_angY = 0;
	float m_anime = 0;
};