#pragma once
#include "ScriptComponent.h"
#include "ResourceManager.h"
#include "SceneBase.h"

class TextureUIScript : public ScriptComponent
{
public :
    TextureUIScript(GameObject* pOwner, std::string ObjName);

    virtual void Start(); // 시작 업데이트
    virtual void FixedUpdate(float fixedDeltaTime);
    virtual void Update(float deltaTime){};

    TextureComponent* m_TexComp;

    std::wstring m_sObjName; // 용도 오브젝트 이름
    std::wstring m_sRoute;   // 경로 이름

    void SetMyLoadScene(game::SCENE_TYPE name); // 전환 씬 전달용
    void SetMySceneChange(); // 씬 체인지

    void SetMyTextureTransform(float _PositionX, float _PositionY); // 이미지 포지션 위치 변경용

    // 만든 용도 같은 이미지 반복해서 넣기 좋게 만든 함수
    void SetMyPoldeo(std::wstring _m_sObjName, std::wstring _m_sRoute, int _m_iTextureSize); 
    // 오브젝트 이름, 경로위치, 사이지 갯수 사용시 참고 : 파일경로 파일이름 넘버 숫자가 순차적으로 올라가야 한다

    //##### 중요 
    bool m_bObjectType = 0;     // 0 번일 경우 이미지 변경 없으면 1번일 경우 변경 애니메이션처럼 이미지 변경

    int m_iTextureSize = 0;    // 이미지 갯수가 몇개인지 전달 해야 됨
    float m_fMovieMAXDelayTime = 0.f; // 이미지 변경 딜레이 타임 전용

    float m_fSceneDelayTime = 0.f; // 씬 전환 전용 딜레이 타임

    game::SCENE_TYPE m_eScene_Type; // 씬 타입 전환용

    void PlayMusic();

protected:
    float m_fDelayTime = 0; // 이미지 변경 초기화용
};

