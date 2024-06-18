#pragma once
class KdTexture;

class AssetManager
{
public:

	// ポリゴン
	KdSquarePolygon GetMaterial(std::string _name) { return m_materialList.at(_name); }

	// モデル
	KdModelData GetModel(std::string _name) { return m_modelList.at(_name); }

	// テクスチャ
	std::shared_ptr<KdTexture> GetTex(std::string _name) { return m_texList.at(_name); }

	// アニメーションの配列取得
	std::vector<int> GetAnimation(std::string _name) { return m_animationList.at(_name); }

	std::tuple<KdSquarePolygon, std::vector<int>, float> GetMaterialAnime(std::string _name);

private:

	// ポリゴン
	std::unordered_map<std::string, KdSquarePolygon> m_materialList;
	std::unordered_map<std::string, std::vector<int>> m_animationList;
	std::unordered_map<std::string, float> m_animeSpdList;
	void LoadMaterial(std::string _name, std::string _path) { m_materialList[_name].SetMaterial(_path); }
	void SetMaterial(std::string _name, Math::Vector2 _scale, KdSquarePolygon::PivotType _pivot, UINT _splitX, UINT _splitY);
	void SetAnimation(std::string _name, int _start, int _count, float _speed);
	// モデル
	std::unordered_map<std::string, KdModelData> m_modelList;
	void LoadModel(std::string _name, std::string _path) { m_modelList[_name].Load(_path); }

	// テクスチャ
	std::unordered_map<std::string, std::shared_ptr<KdTexture>> m_texList;
	void LoadTex(std::string _name, std::string _path);

	void Init();						// 初期化

private:

	AssetManager() { Init(); }	// コンストラクタ
	~AssetManager() {}			// デストラクタ

public:

	// シングルトンパターン
	static AssetManager& Instance()
	{
		static AssetManager instance;
		return instance;
	}
};
