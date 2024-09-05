#pragma once
#include "AreaWeaponScript.h"
#include "Observer.h"

// 에리어 무기를 상속
class LaserWeaponScript : public AreaWeaponScript
{
private:
	float m_fInActiveTime = 4.f; // ※ (기획) 사라지는 수치 조정
	AnimationComponent* m_CRender;
	//temp
	TextComponent* m_cTextRender;

	TextureComponent* m_cWarningTexture;

	std::wstring* curstr = nullptr;

	int m_iHitCount = 20;

public:
	LaserWeaponScript(GameObject* pOwner, std::string ObjName);
	virtual void Start(); // 시작 업데이트
	virtual void FixedUpdate(float fixedDeltaTime);
	virtual void Update(float deltaTime){};
	virtual void Render(){}; // 렌더는 안사용함 이미지 로드 해서

	void OnHit();

	virtual void OnCollision(ColliderComponent* src) {};
	virtual void OnCollisionEnter(ColliderComponent* src) {};
	virtual void OnCollisionExit(ColliderComponent* src) {};
	
	virtual void Reset();
	void AnimationUpdate(float fixedDeltaTime);

public:
	float   m_fTextureRenderTime = 0;
	bool chargeFlag = false;
	float   m_bWarningTime = 0;
	bool m_bWarningFlag = false;
	int m_bWarningAlphaFlag = -1;
};



