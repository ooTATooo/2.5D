#pragma once


class WhiteFade
{
public:

	void Update();
    void DrawSprite();

    void BootFade(SceneManager::SceneType _type);
    bool GetFade()const { return m_bFade; }

private:

    void Init();

    SceneManager::SceneType m_nextScene;

    std::shared_ptr<KdTexture> m_tex;
    Math::Color m_color;
    float m_alpha;
    bool m_bFade;
    bool m_bFadeOut;
    bool m_bFadeIn;

private:

	WhiteFade() { Init(); }
    ~WhiteFade() {}

public:

    static WhiteFade& Instance()
    {
        static WhiteFade instance;
        return instance;
    }
};