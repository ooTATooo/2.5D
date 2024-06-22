#pragma once

class TitleCamera :public KdGameObject
{
public:

	TitleCamera() { Init(); }
	~TitleCamera()override {}

	void Init()override;
	void PreDraw()override;

private:

	std::shared_ptr<KdCamera> m_camera = nullptr;
};