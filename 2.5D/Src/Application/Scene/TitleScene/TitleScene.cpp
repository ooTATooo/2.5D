#include "TitleScene.h"
#include "../SceneManager.h"

#include "../../Object/Effect/Fade/Fade.h"
#include "../../Object/UI/TitleLogo/TitleLogo.h"

void TitleScene::Event()
{
	if (GetAsyncKeyState(VK_RETURN) & 0x8000)
	{
		Fade::Instance().BootFade(SceneManager::SceneType::Game);
	}
}

void TitleScene::Init()
{
	std::shared_ptr<TitleLogo> titleLogo = std::make_shared<TitleLogo>();
	AddObject(titleLogo);
}
