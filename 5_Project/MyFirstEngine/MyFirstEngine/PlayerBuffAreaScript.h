#pragma once
#include "AreaWeaponScript.h"

// 에리어 무기를 상속
class PlayerBuffAreaScript : public AreaWeaponScript
{

private:
	

public :

	PlayerBuffAreaScript(GameObject* pOwner, std::string ObjName);
	virtual void Start(); // 시작 업데이트
	virtual void FixedUpdate(float fixedDeltaTime);
	virtual void Update(float deltaTime) {};
	virtual void Render() {}; // 렌더는 안사용함 이미지 로드 해서

	virtual void OnCollision(ColliderComponent* src) {};
	virtual void OnCollisionEnter(ColliderComponent* src) {};
	virtual void OnCollisionExit(ColliderComponent* src) {};

	virtual void Reset();
};

