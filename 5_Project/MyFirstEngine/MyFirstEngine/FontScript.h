#pragma once
#include "ScriptComponent.h"

class FontScript : public ScriptComponent
{

public:
    FontScript(GameObject* pOwner, std::string ObjName);
    ~FontScript();

    virtual void Start() {};
    virtual void Update(float deltaTime) {};
    virtual void FixedUpdate(float fixedDeltaTime) {};

    void SetRectSizeAndTransform(int _Width, int _Height, float _TransformX, float _TransformY); // 문자 위치용
    void SetMyDialog(std::wstring* ObjectDialog, int strArrSize); 
    void SetMyColor(int R, int G, int B); // 글짜 색
    void SetFontSize(int _FontSize); // 글짜 크기 

    void SetMyTextureTransform(float _PositionX, float _PositionY); // 이미지 위치 수정용

    game::eSoundChannel m_eSoundChannel = game::eSoundChannel::End;
    game::eSoundList m_eSoundList = game::eSoundList::End;

protected:
    TextureComponent* m_TexComp; // 이미지 컴퍼너트
    TextComponent* m_TextComp;   // 텍스트 컴퍼너트

    //출력을 기다리는 모든 텍스트
    std::vector<std::wstring*> m_tString;

    std::wstring* m_sDialog = nullptr; // 문자열
    int m_iDialogArrSize;

    float delayTime = 0.f;  // 딜레이 타임 공용

     
};

