#pragma once

class Monument :public KdGameObject
{
public:

	Monument() { Init(); }
	~Monument()override {};

	void Update()override;
	void PostUpdate()override;
	void Init()override;
	void GenerateDepthMapFromLight()override;
	void DrawLit()override;
	void DrawBright()override;

	void SetPlayer(const std::weak_ptr<KdGameObject> _player) { m_player = _player; }

private:

	std::shared_ptr<KdModelData> m_model01 = nullptr;
	std::shared_ptr<KdModelData> m_model02 = nullptr;

	std::weak_ptr<KdGameObject> m_player;

	Math::Vector3 m_pos;
	float m_ang;
	float m_speed;
	float alpha;

	Math::Color m_color01;
	Math::Color m_color02;

};