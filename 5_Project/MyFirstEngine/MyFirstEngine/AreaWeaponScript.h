#pragma once
#include "WeaponScript.h"

//웨폰 상속
class AreaWeaponScript : public WeaponScript 
{
public:
	static Vector3 s_vPlayerPos; // 플레이어 위치 파악

	AreaWeaponScript(GameObject* pOwner, std::string ObjName); // 생성자
	virtual void Start(); // 시작 업데이트
	virtual void FixedUpdate(float fixedDeltaTime){};
	virtual void Update(float deltaTime) {};
	virtual void Render(){}; // 렌더는 안사용함 이미지 로드 해서

	virtual void OnCollision(ColliderComponent* src) {};
	virtual void OnCollisionEnter(ColliderComponent* src) { m_pOwner->SetStatus(game::Status::InActive); };
	virtual void OnCollisionExit(ColliderComponent* src) {};

	virtual void Reset(){}; // 초기화 용도

private:

protected:
	int m_iAreaWeaponType;  // 타입에 따른 이미지 렌더 변경 0번 경고 ~ 나머지 공격
	float m_fImageChangeTime; // 경고시간이 지나면 폭발

	float m_fInActiveTime; // 사라지는 타임 ※ 기획에서 수정하기 좋게 만듬
//	int m_iRandomPosition;  // 용도 타입에 따른 랜덤 위치 잡기
};

