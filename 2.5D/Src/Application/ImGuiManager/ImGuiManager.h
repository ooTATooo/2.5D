#pragma once

class ImGuiManager
{
public:

	void Update();

	void SetPlayerPos(Math::Vector3 _playerPos) { m_playerPos = _playerPos; }

private:

	Math::Vector3 m_playerPos;

private:

	ImGuiManager() {}
	~ImGuiManager() {}

public:

	static ImGuiManager& Instance()
	{
		static ImGuiManager instance;
		return instance;
	}

};