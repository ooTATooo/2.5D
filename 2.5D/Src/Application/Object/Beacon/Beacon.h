#pragma once

class Beacon :public KdGameObject
{
public:

	Beacon() { Init(); }
	~Beacon()override {};

	void Init()override;
	void GenerateDepthMapFromLight()override;
	void DrawLit()override;
	void DrawBright()override;

	void SetPlayer(const std::weak_ptr<KdGameObject> _player) { m_player = _player; }

private:

	std::shared_ptr<KdModelData> m_model;

	std::weak_ptr<KdGameObject> m_player;

	Math::Color m_color = { 1,1,1,0.35f };

};