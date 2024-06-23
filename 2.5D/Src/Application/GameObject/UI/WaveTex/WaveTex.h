#pragma once

#include "../BaseUI.h"
#include "../../../EnemyManager/EnemyManager.h"

class WaveTex :public BaseUI
{
public:

	WaveTex() { Init(); }
	~WaveTex() {}

	void Update()override;
	void Init()override;
	void DrawSprite()override;

	void SetWave(EnemyManager::WaveType _wave);

private:

	float m_alpha;
	float m_alphaAdd;

	int m_frame;
	bool m_frameFlg;
	bool m_alphaFlg;

	EnemyManager::WaveType m_wave;
	Math::Color m_color;
};