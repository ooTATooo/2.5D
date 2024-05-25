#include "ImGuiManager.h"

void ImGuiManager::Update()
{
	// デバッグウィンドウ
	if (ImGui::Begin("Debug Window"))
	{
		// FPS
		ImGui::Text("PlayerPosX : %f", m_playerPos.x);
		ImGui::Text("PlayerPosZ : %f", m_playerPos.z);
		//ImGui::Text("FPS : %d", m_fpsController.m_nowfps);
		ImGui::Text((const char*)u8"あああああ");
	}
	ImGui::End();
}
