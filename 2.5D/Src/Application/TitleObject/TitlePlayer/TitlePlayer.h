#pragma once

class TitlePlayer :public KdGameObject
{
public:

	TitlePlayer() { Init(); }
	~TitlePlayer()override {}

	void Update()override;
	void Init()override;
	void GenerateDepthMapFromLight()override;
	void DrawLit()override;

private:

	std::shared_ptr<KdSquarePolygon> m_poly = nullptr;

	Math::Vector3 m_pos = Math::Vector3::Zero;
	float m_angX;

	std::shared_ptr<Animation> m_anime = nullptr;

};