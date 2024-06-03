#pragma once

class ImGuiManager
{
public:

	void Update();

	void SetPlayerPos(Math::Vector3 _playerPos) { m_playerPos = _playerPos; }
	void SetSize(float _size) { m_size = _size; }
private:

	Math::Vector3 m_playerPos;
	float m_size;

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