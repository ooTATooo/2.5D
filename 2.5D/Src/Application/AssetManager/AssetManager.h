#pragma once
class KdTexture;

class AssetManager
{
public:

	// 向き
	enum class Dir
	{
		Right,
		Left,
	};

	// ポリゴン
	KdSquarePolygon GetMaterial(std::string _name);

	// モデル
	KdModelData GetModel(std::string _name);

	// テクスチャ
	KdTexture* GetTex(std::string _name);

	// アニメーションの配列取得
	std::vector<int> GetAnimation(std::string _name);

	// アニメーション作成
	void GatAnimation(std::string _name, std::shared_ptr<KdSquarePolygon> _polygon);

private:

	// ポリゴン
	std::unordered_map<std::string, KdSquarePolygon> m_materialList;
	std::unordered_map<std::string, std::vector<int>> m_animationList;
	void LoadMaterial(std::string _name, std::string _path) { m_materialList[_name].SetMaterial(_path); }
	void SetMaterial(std::string _name, float _scale, KdSquarePolygon::PivotType _pivot, int _splitX, int _splitY);
	void SetAnimation(std::string _name, int _start, int _count);

	// モデル
	std::unordered_map<std::string, KdModelData> m_modelList;
	void LoadModel(std::string _name, std::string _path) { m_modelList[_name].Load(_path); }

	// テクスチャ
	std::unordered_map<std::string, KdTexture> m_texList;
	void LoadTex(std::string _name, std::string _path) { m_texList[_name].Load(_path); }

	void Init();						// 初期化

	std::vector<int> m_animeFrame;		// アニメーション配列格納用

	float m_cntSpeed = 0.1f;			// アニメのスピード

	float m_anime = 0;					// アニメーションカウント

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