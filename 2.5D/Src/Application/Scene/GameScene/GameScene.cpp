#include "GameScene.h"
#include "../SceneManager.h"

#include "../../Object/Player/Player.h"
#include "../../Object/Ground/Ground.h"
#include "../../Object/WallFawme/WallFrame.h"
#include "../../Object/Beacon/Beacon.h"
#include "../../Object/BeaconHp/BeaconHp.h"

void GameScene::Event()
{
	if (GetAsyncKeyState('T') & 0x8000)
	{
		SceneManager::Instance().SetNextScene
		(
			SceneManager::SceneType::Title
		);
	}

	Math::Vector3 playerPos;
	if (!m_player.expired())
	{
		playerPos = m_player.lock()->GetPos();
	}

	Math::Matrix rotMat = Math::Matrix::CreateRotationX(DirectX::XMConvertToRadians(45));

	Math::Matrix transMat = Math::Matrix::CreateTranslation(0, 8, -8);

	Math::Matrix pTransMat = Math::Matrix::CreateTranslation(playerPos);

	Math::Matrix mat;
	mat = rotMat * transMat * pTransMat;

	// カメラに行列をセット
	// この時点では画面には反映されない
	m_camera->SetCameraMatrix(mat);

}

void GameScene::Init()
{
	// カメラ生成＆視野角設定
	m_camera = std::make_unique<KdCamera>();	//1 メモリ確保
	m_camera->SetProjectionMatrix(60);			//2	視野角設定

	std::shared_ptr<Player> player = std::make_shared<Player>();
	AddObject(player);
	m_player = player;

	std::shared_ptr<Ground> ground = std::make_shared<Ground>();
	AddObject(ground);

	std::shared_ptr<WallFrame> wall = std::make_shared<WallFrame>();
	AddObject(wall);

	std::shared_ptr<Beacon> beacon = std::make_shared<Beacon>();
	AddObject(beacon);

	std::shared_ptr<BeaconHp> beaconHp = std::make_shared<BeaconHp>();
	AddObject(beaconHp);
}
