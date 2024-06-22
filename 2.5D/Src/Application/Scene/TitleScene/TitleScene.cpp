#include "TitleScene.h"
#include "../SceneManager.h"

#include "../../GameObject/Effect/Fade/Fade.h"
#include "../../TitleObject/TitleUI/TitleLogo/TitleLogo.h"
#include "../../TitleObject/TitleUI/TitleStart/TitleStart.h"
#include "../../TitleObject/TitleCamera/TitleCamera.h"
#include "../../TitleObject/TitleStage/TitleBackGround/TitleBackGround.h"
#include "../../TitleObject/TitleStage/TitleGround/TitleGround.h"
#include "../../TitleObject/TitleStage/TitleWallFrame/TitleWallFrame.h"
#include "../../TitleObject/TitleStage/TitlePillar/TitlePillar.h"
#include "../../TitleObject/TitleStage/TitleMonolith/TitleMonolith.h"
#include "../../TitleObject/TitlePlayer/TitlePlayer.h"

void TitleScene::Event()
{
	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
	{
		if (!m_keyFlg)
		{
			Fade::Instance().BootFade(SceneManager::SceneType::Game);

			m_keyFlg = true;
		}
	}
	else
	{
		m_keyFlg = false;
	}
}

void TitleScene::Init()
{
	std::shared_ptr<TitleCamera> camera = std::make_shared<TitleCamera>();
	AddObject(camera);

	std::shared_ptr<TitleLogo> title = std::make_shared<TitleLogo>();
	AddObject(title);

	std::shared_ptr<TitleStart> start = std::make_shared<TitleStart>();
	AddObject(start);

	std::shared_ptr<TitleBackGround> back = std::make_shared<TitleBackGround>();
	AddObject(back);

	std::shared_ptr<TitleGround> ground = std::make_shared<TitleGround>();
	AddObject(ground);

	std::shared_ptr<TitleWallFrame> wall = std::make_shared<TitleWallFrame>();
	AddObject(wall);

	static const int width = 4;
	static const int height = 2;
	float posX[width] = { -20.0f,-10.0f,10.0f,20.0f };
	float posZ[height] = { 20.0f,10.0f};

	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			std::shared_ptr<TitlePillar> pillar = std::make_shared<TitlePillar>();
			pillar->SetPos({ posX[i], 0, posZ[j] });
			AddObject(pillar);
		}
	}

	std::shared_ptr<TitleMonolith> monolith = std::make_shared<TitleMonolith>();
	AddObject(monolith);

	Math::Vector3 pos = { 2,0,0 };
	std::shared_ptr<TitlePlayer> player = std::make_shared<TitlePlayer>();
	player->SetPos(pos);
	AddObject(player);

}
