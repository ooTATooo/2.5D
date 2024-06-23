#include "EnemyManager.h"

#include "../GameObject/Enemy/Slime/Slime.h"
#include "../GameObject/Enemy/Witch/Witch.h"
#include "../GameObject/Enemy/Knight/Knight.h"
#include "../GameObject/Map/MapEnemyPoint/MapEnemyPoint.h"

void EnemyManager::Init()
{
	Load("Asset/Data/EnemyManager.csv");
}

void EnemyManager::AddEnemy(SpawnType _type, KdGameObject::ObjType _enemyType)
{
	std::shared_ptr<Slime> slime = std::make_shared<Slime>();
	std::shared_ptr<Witch> witch = std::make_shared<Witch>();
	std::shared_ptr<Knight> knight = std::make_shared<Knight>();
	std::shared_ptr<MapEnemyPoint> mapEnemyPoint = std::make_shared<MapEnemyPoint>();

	switch (_enemyType)
	{
	case KdGameObject::ObjType::Slime:
		for (auto& obj: SceneManager::Instance().GetObjList())
		{
			if (obj->GetObjType() == KdGameObject::ObjType::Player)
			{
				slime->SetPlayer(obj);

			}
			if (obj->GetObjType() == KdGameObject::ObjType::Monolith)
			{
				slime->SetBeacon(obj);
			}
		}
		slime->SetPos(m_spawnPosList[_type]);
		SceneManager::Instance().AddObject(slime);

		mapEnemyPoint->SetEnemy(slime);
		SceneManager::Instance().AddObject(mapEnemyPoint);

		break;
	case KdGameObject::ObjType::Witct:
		for (auto& obj : SceneManager::Instance().GetObjList())
		{
			if (obj->GetObjType() == KdGameObject::ObjType::Player)
			{
				witch->SetPlayer(obj);

			}
			if (obj->GetObjType() == KdGameObject::ObjType::Monolith)
			{
				witch->SetBeacon(obj);
			}
		}
		witch->SetPos(m_spawnPosList[_type]);
		SceneManager::Instance().AddObject(witch);

		mapEnemyPoint->SetEnemy(witch);
		SceneManager::Instance().AddObject(mapEnemyPoint);

		break;
	case KdGameObject::ObjType::Knight:
		for (auto& obj : SceneManager::Instance().GetObjList())
		{
			if (obj->GetObjType() == KdGameObject::ObjType::Player)
			{
				knight->SetPlayer(obj);

			}
			if (obj->GetObjType() == KdGameObject::ObjType::Monolith)
			{
				knight->SetBeacon(obj);
			}
		}
		knight->SetPos(m_spawnPosList[_type]);
		SceneManager::Instance().AddObject(knight);

		mapEnemyPoint->SetEnemy(knight);
		SceneManager::Instance().AddObject(mapEnemyPoint);

		break;
	}
}

EnemyManager::SpawnType EnemyManager::GetSpawnType()
{
	int num = rand() % 12;

	switch (num)
	{
	case 0:
		m_spawn = SpawnType::Top_Left;
		break;
	case 1:
		m_spawn = SpawnType::Top_Center;
		break;
	case 2:
		m_spawn = SpawnType::Top_Right;
		break;
	case 3:
		m_spawn = SpawnType::Bottom_Left;
		break;
	case 4:
		m_spawn = SpawnType::Bottom_Center;
		break;
	case 5:
		m_spawn = SpawnType::Bottom_Right;
		break;
	case 6:
		m_spawn = SpawnType::Left_Top;
		break;
	case 7:
		m_spawn = SpawnType::Left_Center;
		break;
	case 8:
		m_spawn = SpawnType::Left_Bottom;
		break;
	case 9:
		m_spawn = SpawnType::Right_Top;
		break;
	case 10:
		m_spawn = SpawnType::Right_Center;
		break;
	case 11:
		m_spawn = SpawnType::Right_Bottom;
		break;
	}

	return m_spawn;
}

KdGameObject::ObjType EnemyManager::GetObjType(bool _flg)
{
	int num = 0;
	if (!_flg)
	{
		num = rand() % 2;
	}
	else
	{
		num = rand() % 3;
	}

	switch (num)
	{
	case 0:
		m_objType = KdGameObject::ObjType::Slime;
		break;
	case 1:
		m_objType = KdGameObject::ObjType::Witct;
		break;
	case 2:
		m_objType = KdGameObject::ObjType::Knight;
		break;
	}

	return m_objType;
}

void EnemyManager::Load(std::string a_filePath)
{
	std::ifstream ifs(a_filePath);
	if (!ifs.is_open()) { return; }

	std::vector<float> data;
	std::vector<Math::Vector3> pos;
	std::string str;

	while (getline(ifs, str))
	{
		std::istringstream iss(str);//ファイルから取ってきた文字列を操る
		std::string conmaString;//コンマ区切りになった変数を格納

		while (getline(iss, conmaString, ','))
		{
			float tempData = stof(conmaString);

			data.push_back(tempData);
		}
	}

	ifs.close();

	for (int i = 0; i < (int)data.size(); i += 3)
	{
		pos.push_back({ data[i],data[i + 1],data[i + 2] });
	}

	m_spawnPosList[SpawnType::Top_Left] = pos[0];
	m_spawnPosList[SpawnType::Top_Center] = pos[1];
	m_spawnPosList[SpawnType::Top_Right] = pos[2];
	m_spawnPosList[SpawnType::Bottom_Left] = pos[3];
	m_spawnPosList[SpawnType::Bottom_Center] = pos[4];
	m_spawnPosList[SpawnType::Bottom_Right] = pos[5];
	m_spawnPosList[SpawnType::Left_Top] = pos[6];
	m_spawnPosList[SpawnType::Left_Center] = pos[7];
	m_spawnPosList[SpawnType::Left_Bottom] = pos[8];
	m_spawnPosList[SpawnType::Right_Top] = pos[9];
	m_spawnPosList[SpawnType::Right_Center] = pos[10];
	m_spawnPosList[SpawnType::Right_Bottom] = pos[11];
}
