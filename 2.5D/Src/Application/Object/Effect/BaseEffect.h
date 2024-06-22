#pragma once

class BaseEffect :public KdGameObject
{
public:

	BaseEffect() {}
	~BaseEffect()override {}

	void Update()override {}
	void PostUpdate()override;
	void Init()override;
	void DrawUnLit()override;
	void DrawBright()override;
	void DrawSprite()override {}
	void OnHit()override {}

protected:

	std::shared_ptr<KdSquarePolygon> m_poly;
	std::shared_ptr<Animation> m_anime;

	Math::Vector3 m_pos;
	Math::Vector3 m_scale;
	Math::Vector3 m_dir;

	float m_attackArea;
	int m_wait;
};