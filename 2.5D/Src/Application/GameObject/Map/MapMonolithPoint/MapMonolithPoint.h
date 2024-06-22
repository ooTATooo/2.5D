#pragma once

#include "../BaseMap.h"
class Monolith;

class MapMonolithPoint :public BaseMap
{
public:

	MapMonolithPoint() { Init(); }
	~MapMonolithPoint()override {}

	void Update()override;
	void PostUpdate()override;
	void Init()override;
	void DrawSprite()override;

	void SetMomolith(const std::shared_ptr<Monolith> _monolith) { m_monolith = _monolith; }

private:

	std::weak_ptr<Monolith> m_monolith;
};