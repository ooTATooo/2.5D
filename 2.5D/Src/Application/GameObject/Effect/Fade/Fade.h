#pragma once


class Fade
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
    Math::Color m_blackColor;
    float m_blackAlpha;
    bool m_bFade;               // フェード中かどうか？
    bool m_bFadeOut;            // フェードアウト？
    bool m_bFadeIn;             // フェードイン？

private:

    Fade() { Init(); }
    ~Fade() {}

public:

    static Fade& Instance()
    {
        static Fade instance;
        return instance;
    }
};