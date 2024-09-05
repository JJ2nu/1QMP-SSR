#pragma once
#include "AreaWeaponScript.h"
#include <Queue>

// 에리어 무기를 상속
class CrossAreaWeaponScript : public AreaWeaponScript
{
	static int s_eAreaSoundChannel;
	static int s_eExplosionSoundChannel;
private:
	float m_fInActiveTime = 2.5f; // ※ (기획) 사라지는 수치 조정
	float m_frameDelay = 0.0f;
	bool flag = true;
	AnimationComponent* m_cRender;
	std::queue<float> m_fQueue;
	float m_fLastQueueTime;
	float m_fStandardTime = 0.0f;
	bool m_bQueueFlag = true;
public:
	CrossAreaWeaponScript(GameObject* pOwner, std::string ObjName);
	
	void ExplosionAnimation(float fixedDeltaTime);
	virtual void Start(); // 시작 업데이트
	virtual void FixedUpdate(float fixedDeltaTime);
	virtual void Update(float deltaTime) ;
	virtual void Render() {}; // 렌더는 안사용함 이미지 로드 해서

	virtual void OnCollision(ColliderComponent* src) {};
	virtual void OnCollisionEnter(ColliderComponent* src);
	virtual void OnCollisionExit(ColliderComponent* src) {};

	virtual void Reset();
};

