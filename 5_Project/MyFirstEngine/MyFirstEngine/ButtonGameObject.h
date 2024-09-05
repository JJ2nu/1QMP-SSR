#pragma once
#include "GameObject.h"
#include "TextureComponent.h"
#include "TextComponent.h"

class ButtonGameObject :
    public GameObject
{
public:
    enum ButtonStatus
    {
        Default,
        EnterMouse,
        OnMouse,
        ExitMouse,
    };
    ButtonStatus curStatus;
    bool        PrevOnMouse;
    TextureComponent* m_cTexture;
    TextComponent* m_cText;
    Vector3 m_vButtonScale;

public:
    virtual void FixedUpdate(float fixedDeltaTime);
    virtual void Update(float DeltaTime);
    virtual void OnClick() = 0;

private:
    int m_iflag;
    bool IsButtonOnMouse(Vector3 mousePos);
    void CurButtonStatus();

public:
    ButtonGameObject(std::string ObjName, SceneBase* Scene);
    virtual ~ButtonGameObject();
};

