#pragma once

class ImGuiManager
{
public:

	void Update();

	void SetFps(int _fps) { m_fps = _fps; }
	void SetPlayerPos(Math::Vector3 _playerPos) { m_playerPos = _playerPos; }
	void SetSize(float _size) { m_size = _size; }
	void SetScrollType(int _sType) { m_scrollType = _sType; }
private:

	int m_fps = 0;
	Math::Vector3 m_playerPos;
	float m_size = 0;
	int m_scrollType = 0;

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